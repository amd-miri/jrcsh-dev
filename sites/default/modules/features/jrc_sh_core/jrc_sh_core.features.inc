<?php

/**
 * @file
 * jrc_sh_core.features.inc
 */

/**
 * Implements hook_views_api().
 */
function jrc_sh_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_ctools_plugin_api().
 */
function maxm_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
