<?php

/**
 * @file
 * Rules integration for the file module.
 *
 * @addtogroup rules
 *
 * @{
 */

/**
 * Implements hook_rules_event_info() on behalf of the file module.
 */
function rules_file_event_info() {
  $items = array(
    'file_insert' => array(
      'label' => t('After saving new file'),
      'group' => t('File'),
      'variables' => rules_events_file_variables(t('created file')),
      'access callback' => 'rules_file_integration_access',
    ),
    'file_update' => array(
      'label' => t('After updating existing file'),
      'group' => t('File'),
      'variables' => rules_events_file_variables(t('updated file'), TRUE),
      'access callback' => 'rules_file_integration_access',
    ),
    'file_presave' => array(
      'label' => t('Before saving file'),
      'group' => t('File'),
      'variables' => rules_events_file_variables(t('saved file'), TRUE),
      'access callback' => 'rules_file_integration_access',
    ),
  );

  return $items;
}

/**
 * Returns some parameter suitable for using it with a file.
 */
function rules_events_file_variables($file_label, $update = FALSE) {
  $args = array(
    'file' => array('type' => 'file', 'label' => $file_label),
  );

  if ($update) {
    $args += array(
      'file_unchanged' => array(
        'type' => 'file',
        'label' => t('unchanged file'),
        'handler' => 'rules_events_entity_unchanged',
      ),
    );
  }
  return $args;
}

/**
 * File integration access callback.
 */
function rules_file_integration_access($type, $name) {
  if ($type == 'event' || $type == 'condition') {
    return entity_access('view', 'file');
  }
}
