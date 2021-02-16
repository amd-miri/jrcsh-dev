<?php

/**
 * @file
 * jrc_sh_content_types.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function jrc_sh_content_types_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-evaluation_reports-field_migration_status'.
  $field_instances['node-evaluation_reports-field_migration_status'] = array(
    'bundle' => 'evaluation_reports',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 27,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 48,
    ),
  );

  // Exported field_instance: 'node-event-field_migration_status'.
  $field_instances['node-event-field_migration_status'] = array(
    'bundle' => 'event',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'apache_solr_mode' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 43,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 222,
    ),
  );

  // Exported field_instance:
  // 'node-interlaboratory_comparisons-field_migration_status'.
  $field_instances['node-interlaboratory_comparisons-field_migration_status'] = array(
    'bundle' => 'interlaboratory_comparisons',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'apache_solr_mode' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-network_bureau-field_migration_status'.
  $field_instances['node-network_bureau-field_migration_status'] = array(
    'bundle' => 'network_bureau',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'apache_solr_mode' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 28,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-news-field_migration_status'.
  $field_instances['node-news-field_migration_status'] = array(
    'bundle' => 'news',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'apache_solr_mode' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 35,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-open_access_call-field_migration_status'.
  $field_instances['node-open_access_call-field_migration_status'] = array(
    'bundle' => 'open_access_call',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'apache_solr_mode' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 36,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-open_access_project-field_migration_status'.
  $field_instances['node-open_access_project-field_migration_status'] = array(
    'bundle' => 'open_access_project',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 29,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-page-field_migration_status'.
  $field_instances['node-page-field_migration_status'] = array(
    'bundle' => 'page',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'apache_solr_mode' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 35,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 43,
    ),
  );

  // Exported field_instance: 'node-patent-field_migration_status'.
  $field_instances['node-patent-field_migration_status'] = array(
    'bundle' => 'patent',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'apache_solr_mode' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 30,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-publication-field_migration_status'.
  $field_instances['node-publication-field_migration_status'] = array(
    'bundle' => 'publication',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'apache_solr_mode' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 53,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 66,
    ),
  );

  // Exported field_instance: 'node-research_facility-field_migration_status'.
  $field_instances['node-research_facility-field_migration_status'] = array(
    'bundle' => 'research_facility',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'apache_solr_mode' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 29,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-science_updates-field_migration_status'.
  $field_instances['node-science_updates-field_migration_status'] = array(
    'bundle' => 'science_updates',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'apache_solr_mode' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-scientific_tool-field_migration_status'.
  $field_instances['node-scientific_tool-field_migration_status'] = array(
    'bundle' => 'scientific_tool',
    'default_value' => array(
      0 => array(
        'tid' => 3337,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'apache_solr_mode' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-topic-field_migration_status'.
  $field_instances['node-topic-field_migration_status'] = array(
    'bundle' => 'topic',
    'default_value' => array(
      0 => array(
        'tid' => 3339,
      ),
    ),
    'deleted' => 0,
    'description' => 'Define import status for EWPP (Drupal 8) migration',
    'display' => array(
      'apache_solr_mode' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 28,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_migration_status',
    'label' => 'Migration status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'mediafront' => array(
        'custom' => '',
        'field_type' => 0,
        'media_type' => 'media',
        'preview' => 0,
        'thumbnail' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 35,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Define import status for EWPP (Drupal 8) migration');
  t('migration_status');

  return $field_instances;
}
