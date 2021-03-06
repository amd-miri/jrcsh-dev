<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_options_none(array $existing, $type, $theme, $path) {
  return array(
    'options_none' => array(
      'template' => 'options-none',
      'variables' => array('instance' => NULL, 'option' => NULL),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_options_none() {
  return array(
    'label' => 'Options none',
    'description' => 'Options none description.',
    'preview' => array(
      'instance' => array(
        'widget' => array(
          'type' => 'options_buttons',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_options_none(array &$variables, $hook) {
  $instance = $variables['instance'];
  $option = $variables['option'];

  $output = '';

  switch ($instance['widget']['type']) {
    case 'options_buttons':
      $output = t('N/A');

      break;

    case 'options_select':
      $output = ($option === 'option_none' ? t('- None -') : t('- Select a value -'));

      break;
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#markup' => $output,
    ),
  );
}
