<?php

/**
 * @file
 * Admin forms for nexteuropa_dashboard_agent.
 */

/**
 * Page callback: NextEuropa Dashboard Agent settings.
 *
 * @see nexteuropa_dashboard_agent_menu()
 */
function nexteuropa_dashboard_agent_form($form, &$form_state) {

  $form['nexteuropa_dashboard_agent_service'] = array(
    '#type' => 'textfield',
    '#title' => t('Your siteUUID'),
    '#description' => nexteuropa_dashboard_agent_get_site_uu_id(),
    '#default_value' => nexteuropa_dashboard_agent_get_site_uu_id(),
    '#attributes' => array('style' => array('display:none;')),
    '#size' => 60,
    '#maxlength' => 60,
    '#disabled' => TRUE,
  );

  $form['update_tokens'] = array(
    '#type' => 'submit',
    '#value' => t('Update tokens'),
    '#name' => 'update_tokens',
  );
  $form['#submit'][] = '_nexteuropa_dashboard_agent_update_tokens';

  $form['nexteuropa_dashboard_agent_use_encryption'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use encryption'),
    '#description' => t('Encrypt the data before sending this back to the requester.'),
    '#default_value' => variable_get('nexteuropa_dashboard_agent_use_encryption', FALSE),
  );

  $form['nexteuropa_dashboard_agent_allowed_ip_range'] = array(
    '#type' => 'textfield',
    '#title' => t('List of IPs allowed to request the services'),
    '#description' => t('Defines the allowed IPs from where the request can be made.<br>If the variable is empty, then all requests are blocked.<br>IP-address range is entered in the form of 100.100.100.100 - 100.100.101.150, 158.167.213.96, 158.167.217.43, 158.167.315.02 - 158.167.315.80'),
    '#default_value' => variable_get('nexteuropa_dashboard_agent_allowed_ip_range'),
    '#size' => 180,
    '#maxlength' => 200,
    '#attributes' => array(
      'placeholder' => t('100.100.100.100 - 100.100.101.150, 158.167.213.96, 158.167.217.43, 158.167.315.02 - 158.167.315.80'),
    ),
  );

  return system_settings_form($form);
}

/**
 * Retrieve the site UUID.
 *
 * @return string
 *   The site UUID.
 */
function nexteuropa_dashboard_agent_get_site_uu_id() {
  $siteUUID = _nexteuropa_dashboard_agent_get_token('nexteuropa_dashboard_agent_token');
  $siteUUID .= "-";
  $siteUUID .= _nexteuropa_dashboard_agent_get_token('nexteuropa_dashboard_agent_encrypt_token');

  return $siteUUID;
}

/**
 * Custom submit function to generate new tokens.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function _nexteuropa_dashboard_agent_update_tokens($form, $form_state) {
  if ($form_state['clicked_button']['#name'] == 'update_tokens') {
    _nexteuropa_dashboard_agent_set_token('nexteuropa_dashboard_agent_token', NextEuropaDashboardAgentEncryption::getToken());
    _nexteuropa_dashboard_agent_set_token('nexteuropa_dashboard_agent_encrypt_token', NextEuropaDashboardAgentEncryption::getToken());
  }
}
