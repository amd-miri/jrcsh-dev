<?php

/**
 * @file
 * Drush commands for nexteuropa_dashboard_agent module.
 */

/**
 * Implements hook_drush_command().
 */
function nexteuropa_dashboard_agent_drush_command() {
  $commands = array();

  $commands['ne-dashboard-agent-update-tokens'] = array(
    'aliases' => array('nedut'),
    'description' => dt('Update NextEuropa Dashboard tokens.'),
    'callback' => 'drush_ne_dashboard_agent_update_tokens',
    'examples' => array('To generate new tokens, just execute' => 'drush nedut'),
  );

  return $commands;
}

/**
 * Callback function for drush command ne_dashboard_agent_update_tokens.
 */
function drush_ne_dashboard_agent_update_tokens() {
  _nexteuropa_dashboard_agent_set_token('nexteuropa_dashboard_agent_token', NextEuropaDashboardAgentEncryption::getToken());
  _nexteuropa_dashboard_agent_set_token('nexteuropa_dashboard_agent_encrypt_token', NextEuropaDashboardAgentEncryption::getToken());

  module_load_include('inc', 'nexteuropa_dashboard_agent', 'nexteuropa_dashboard_agent.admin');
  drush_print('New siteUUID is: ' . nexteuropa_dashboard_agent_get_site_uu_id());
}
