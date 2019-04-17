<?php

/**
 * @file
 * Administration forms for the ecas_taxonomy module.
 */

/**
 * Form constructor for the taxonomy mapping.
 */
function ecas_taxonomy_admin() {
  $form = array();

  $form['taxonomy'] = array(
    '#type' => 'fieldset',
    '#title' => t('Taxonomy'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['taxonomy']['ecas_taxonomy_assign_voc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable term mapping'),
    '#default_value' => variable_get('ecas_taxonomy_assign_voc', FALSE),
  );

  // List of vocab allowed.
  $vocab_array = array();

  // Get user fields and iterate through vocabularies to get Vid and Name.
  foreach (field_info_instances('user')['user'] as $key => $value) {
    $field_info = field_info_field($key);
    if ($field_info['type'] == 'taxonomy_term_reference') {
      $vocab = taxonomy_vocabulary_machine_name_load($field_info['settings']['allowed_values'][0]['vocabulary']);
      $vocab_array[$vocab->vid] = $vocab->name;
    }
  }

  if (!count($vocab_array)) {
    $form['taxonomy']['ecas_taxonomy_voc']['#default_value'] = FALSE;
    $form['taxonomy']['ecas_taxonomy_voc']['#disabled'] = TRUE;
    $form['taxonomy']['ecas_taxonomy_voc']['#description'] =
      t('Term assignement cannot be done since the user entity has no term reference field');
    // Ensure value if false.
    variable_set('assign_voc', FALSE);
  }
  else {
    $form['taxonomy']['ecas_taxonomy_voc'] = array(
      '#type' => 'select',
      '#title' => t('Assing term to user entity from vocabulary'),
      '#default_value' => variable_get('ecas_taxonomy_voc', key($vocab_array)),
      '#options' => $vocab_array,
      '#description' => t("This will use the user's field corresponding."),
      '#ajax' => array(
        'callback' => '_ecas_role_taxonomy_update_terms',
        'wrapper' => 'dropdown-voc-default',
        'method' => 'replace',
        'event' => 'change',
      ),
    );
    $form['taxonomy']['ecas_taxonomy_voc_regex'] = array(
      '#type' => 'textfield',
      '#title' => t('Regex matching term from vocabulary'),
      '#default_value' => variable_get('ecas_taxonomy_voc_regex', '^[ecas:dg]\.[ecas:directorate]$'),
      '#description' => t('by default looks for a full match amoungs terms but this can be customised. uses tokens'),
    );

    $form['taxonomy']['token_help'] = array(
      '#title' => t('Replacement patterns'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['taxonomy']['token_help']['help'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('ecas'),
      '#global_types' => FALSE,
      '#click_insert' => FALSE,
    );

    $form['taxonomy']['ecas_taxonomy_voc_default'] = array(
      '#type' => 'select',
      '#prefix' => '<div id ="dropdown-voc-default">',
      '#suffix' => '</div>',
      '#title' => t('Default term if no match'),
      '#default_value' => variable_get('ecas_taxonomy_voc_default', 0),
      '#description' => t('The default term to assign to the user if no term matches from the condition above'),
      '#options' => _ecas_role_taxonomy_get_terms_admin($form['taxonomy']['ecas_taxonomy_voc']['#default_value']),

    );
  }
  return system_settings_form($form);
}

/**
 * Helper for admin usage of _ecas_role_taxonomy_get_terms.
 *
 * @param int $vid
 *   The vid of the vocabulary to get terms from.
 *
 * @return array
 *   the array retured by _ecas_role_taxonomy_get_terms
 *   with a 'none' element keyed 0.
 */
function _ecas_role_taxonomy_get_terms_admin($vid) {
  return [0 => t('--- none ---')] + _ecas_role_taxonomy_get_terms($vid);
}

/**
 * Ajax callback to fetch terms for selected vocab.
 *
 * @param array $form
 *   Drupal form array.
 * @param array $form_state
 *   Drupal form state array.
 *
 * @return string
 *   Return the Ajax response to be rendered in the form.
 */
function _ecas_role_taxonomy_update_terms(array $form, array &$form_state) {
  $form['taxonomy']['ecas_taxonomy_voc_default']['#options'] = _ecas_role_taxonomy_get_terms_admin($form_state['values']['ecas_taxonomy_voc']);
  // Reset choice.
  $form['taxonomy']['ecas_taxonomy_voc_default']['#default_value'] = 0;
  $form_state['values']['ecas_taxonomy_voc_default'] = 0;

  return $form['taxonomy']['ecas_taxonomy_voc_default'];
}
