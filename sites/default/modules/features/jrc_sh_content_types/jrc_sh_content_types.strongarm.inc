<?php

/**
 * @file
 * jrc_sh_content_types.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function jrc_sh_content_types_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_migration_status';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_taxonomy_term_migration_status'] = $strongarm;

  return $export;
}
