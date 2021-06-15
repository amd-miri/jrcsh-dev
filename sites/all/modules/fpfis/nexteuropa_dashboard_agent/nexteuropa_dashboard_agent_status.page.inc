<?php

/**
 * @file
 * Logic for nexteuropa_dashboard_agent output.
 */

/**
 * Return JSON formatted module informations.
 */
function nexteuropa_dashboard_agent_status_page() {
  $system_modules = system_rebuild_module_data();
  $system_themes = list_themes(TRUE);

  // Needless initialisation, but hey.
  $res = array(
    'core' => array(),
    'module' => array(),
    'profile' => array(),
    'theme' => array(),
  );

  // Go over Themes.
  foreach ($system_themes as $theme) {
    $res['theme'][$theme->name] = array(
      'name' => $theme->info['name'],
      'version' => isset($theme->info['version']) ? $theme->info['version'] : NULL,
      'status' => $theme->status,
      'schema_version' => $theme->schema_version,
      'location' => $theme->filename,
      'base_themes' => !empty($theme->base_themes) ? array_keys($theme->base_themes) : array(),
    );
  }

  // Go over Modules.
  foreach ($system_modules as $module => $module_info) {

    // Match for core modules.
    if (drupal_strtolower($module_info->info['package']) == 'core') {
      $res['core'][$module] = array(
        'name' => $module_info->info['name'],
        'version' => $module_info->info['version'],
        'status' => $module_info->status,
        'schema_version' => $module_info->schema_version,
        'location' => $module_info->filename,
        'package' => $module_info->info['package'],
        'requires' => array_keys($module_info->requires),
      );
      continue;
    }

    // Match for installation profiles.
    if (strpos($module_info->filename, '.profile') !== FALSE) {
      $res['profile'][$module] = array(
        'name' => $module_info->info['name'],
        'version' => $module_info->info['version'],
        'status' => $module_info->status,
        'schema_version' => $module_info->schema_version,
        'location' => $module_info->filename,
        'package' => $module_info->info['package'],
        'requires' => array_keys($module_info->requires),
      );
      continue;
    }

    // What now remains must be modules.
    $res['module'][$module] = array(
      'name' => $module_info->info['name'],
      'version' => $module_info->info['version'],
      'status' => $module_info->status,
      'schema_version' => $module_info->schema_version,
      'location' => $module_info->filename,
      'package' => $module_info->info['package'],
      'requires' => array_keys($module_info->requires),
    );
  }

  $drupal_version = array('drupal_version' => 'D' . VERSION);

  $platform_tag = array('platform_tag' => NULL);
  $platform_commit_number = array('platform_commit_number' => NULL);
  $platform_installation_time = array('platform_installation_time' => NULL);

  if (module_exists('cce_basic_config')) {
    module_load_include('install', 'cce_basic_config', 'cce_basic_config');
    $requirements = cce_basic_config_requirements('runtime');
    if (isset($requirements['install_tag']['value'])
      && ($requirements['install_tag']['value'] != 'Information not available on the server.')) {
      $platform_tag = array('platform_tag' => $requirements['install_tag']['value']);
    }
    if (isset($requirements['commit_nr']['value'])
      && ($requirements['commit_nr']['value'] != 'Information not available on the server.')) {
      $platform_commit_number = array('platform_commit_number' => $requirements['commit_nr']['value']);
    }
    if (isset($requirements['install_stamp']['value'])
      && ($requirements['install_stamp']['value'] != 'Information not available on the server.')) {
      $platform_installation_time = array('platform_installation_time' => $requirements['install_stamp']['value']);
    }
  }

  $php_version = array('php_version' => phpversion());

  $res = array_merge(
    $res,
    $drupal_version,
    $platform_tag,
    $platform_commit_number,
    $platform_installation_time,
    $php_version
  );

  if (variable_get('nexteuropa_dashboard_agent_use_encryption', FALSE)
    && function_exists('openssl_random_pseudo_bytes')) {
    $res = NextEuropaDashboardAgentEncryption::encrypt(drupal_json_encode(array('nexteuropa_dashboard' => $res)));
    $output_array = array('nexteuropa_dashboard' => 'encrypted_openssl', 'data' => $res);
  }
  else {
    $output_array = array('nexteuropa_dashboard' => $res);
  }

  drupal_json_output($output_array);
}
