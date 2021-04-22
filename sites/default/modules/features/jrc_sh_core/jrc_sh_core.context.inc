<?php

/**
 * @file
 * Test.context.inc.
 */

/**
 * Implements hook_context_default_contexts().
 */
function jrc_sh_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'people_page';
  $context->description = 'Left menu for People details page and list';
  $context->tag = 'People';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'jrc_staff' => 'jrc_staff',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'person/*' => 'person/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-jrc_related_content_new-block' => array(
          'module' => 'views',
          'delta' => 'jrc_related_content_new-block',
          'region' => 'sidebar_right',
          'weight' => '-9',
        ),
        'views-jrc_related_to_topics-block' => array(
          'module' => 'views',
          'delta' => 'jrc_related_to_topics-block',
          'region' => 'sidebar_right',
          'weight' => '-8',
        ),
      ),
    ),
    'menu' => array(
      0 => 'menu-jrc-main-menu:people',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Left menu for People details page and list');
  t('People');
  $export['people_page'] = $context;

  return $export;
}
