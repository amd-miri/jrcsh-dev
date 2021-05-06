<?php

/**
 * @file
 * jrc_sh_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jrc_sh_content_types_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|evaluation_reports|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_reports';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '9',
    'children' => array(
      0 => 'field_meta_creator',
      1 => 'field_mk',
      2 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta-data field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_meta_data|node|evaluation_reports|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|event|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '4',
    'children' => array(
      0 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta-data field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_meta_data|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|interlaboratory_comparisons|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'interlaboratory_comparisons';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '3',
    'children' => array(
      0 => 'field_meta_creator',
      1 => 'field_mk',
      2 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta-data field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_meta_data|node|interlaboratory_comparisons|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|network_bureau|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'network_bureau';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '10',
    'children' => array(
      0 => 'field_meta_creator',
      1 => 'field_mk',
      2 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta-data field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_meta_data|node|network_bureau|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|news|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '4',
    'children' => array(
      0 => 'field_meta_creator',
      1 => 'field_mk',
      2 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta-data field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_meta_data|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|page|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '5',
    'children' => array(
      0 => 'field_meta_creator',
      1 => 'field_mk',
      2 => 'field_brexit_revision',
      3 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta-data field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_meta_data|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|patent|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patent';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '4',
    'children' => array(
      0 => 'field_meta_creator',
      1 => 'field_mk',
      2 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta-data field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_meta_data|node|patent|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|publication|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '4',
    'children' => array(
      0 => 'field_appears_in_collections',
      1 => 'field_dc_contributor_author',
      2 => 'field_dc_description_abstract',
      3 => 'field_dc_description_sponsorship',
      4 => 'field_dc_format_medium',
      5 => 'field_dc_identifier_citation',
      6 => 'field_dc_identifier_doi',
      7 => 'field_dc_identifier_isbn',
      8 => 'field_dc_identifier_issn',
      9 => 'field_dc_identifier_other',
      10 => 'field_dc_identifier_uri',
      11 => 'field_dc_language',
      12 => 'field_dc_publisher',
      13 => 'field_dc_relation_ispartofseries',
      14 => 'field_dc_title',
      15 => 'field_dc_type',
      16 => 'field_meta_creator',
      17 => 'field_mk',
      18 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta-data field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_meta_data|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|research_facility|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'research_facility';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '9',
    'children' => array(
      0 => 'field_meta_creator',
      1 => 'field_mk',
      2 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta-data field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_meta_data|node|research_facility|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|science_updates|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'science_updates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '5',
    'children' => array(
      0 => 'field_mk',
      1 => 'field_meta_creator',
      2 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta-data field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_meta_data|node|science_updates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|scientific_tool|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'scientific_tool';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '11',
    'children' => array(
      0 => 'field_meta_creator',
      1 => 'field_mk',
      2 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta-data field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_meta_data|node|scientific_tool|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|topic|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '7',
    'children' => array(
      0 => 'field_meta_creator',
      1 => 'field_mk',
      2 => 'field_pubsy_id',
      3 => 'field_migration_status',
      4 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_meta_data|node|topic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|action|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '20',
    'children' => array(
      0 => 'field_action_type',
      1 => 'field_identities',
      2 => 'field_institutes',
      3 => 'field_research_areas',
      4 => 'field_tags',
      5 => 'field_related_topics',
      6 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|evaluation_reports|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_reports';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '7',
    'children' => array(
      0 => 'field_identities',
      1 => 'field_institutes',
      2 => 'field_research_areas',
      3 => 'field_tags',
      4 => 'field_related_topics',
      5 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|evaluation_reports|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|event|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '2',
    'children' => array(
      0 => 'field_tags',
      1 => 'field_highlighted',
      2 => 'field_identities',
      3 => 'field_institutes',
      4 => 'field_related_topics',
      5 => 'field_research_areas',
      6 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|f_a_q|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'f_a_q';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '1',
    'children' => array(
      0 => 'field_identities',
      1 => 'field_institutes',
      2 => 'field_research_areas',
      3 => 'field_related_topics',
      4 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|f_a_q|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|image_gallery|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'image_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '5',
    'children' => array(
      0 => 'field_identities',
      1 => 'field_institutes',
      2 => 'field_tags',
      3 => 'field_research_areas',
      4 => 'field_related_topics',
      5 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|image_gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|interlaboratory_comparisons|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'interlaboratory_comparisons';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '1',
    'children' => array(
      0 => 'field_identities',
      1 => 'field_il_category',
      2 => 'field_il_participation',
      3 => 'field_il_reference_laboratories',
      4 => 'field_il_status',
      5 => 'field_il_type',
      6 => 'field_institutes',
      7 => 'field_tags',
      8 => 'field_research_areas',
      9 => 'field_related_topics',
      10 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|interlaboratory_comparisons|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|jrc_staff|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'jrc_staff';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '14',
    'children' => array(
      0 => 'field_archived',
      1 => 'field_identities',
      2 => 'field_institutes',
      3 => 'field_related_topics',
      4 => 'field_research_areas',
      5 => 'field_tags',
      6 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|jrc_staff|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|network_bureau|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'network_bureau';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '9',
    'children' => array(
      0 => 'field_identities',
      1 => 'field_institutes',
      2 => 'field_research_areas',
      3 => 'field_tags',
      4 => 'field_related_topics',
      5 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|network_bureau|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|news|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '3',
    'children' => array(
      0 => 'field_tags',
      1 => 'field_identities',
      2 => 'field_institutes',
      3 => 'field_research_areas',
      4 => 'field_related_topics',
      5 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|open_access_call|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'open_access_call';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxomnomies',
    'weight' => '4',
    'children' => array(
      0 => 'field_research_areas',
      1 => 'field_related_topics',
      2 => 'field_openaccess_lab_section',
      3 => 'field_apen_access_projects',
      4 => 'field_related_topics_nexus_issue',
      5 => 'field_openaccess_show_projects',
      6 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|open_access_call|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|open_access_project|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'open_access_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '2',
    'children' => array(
      0 => 'field_openaccess_ref_facility',
      1 => 'field_related_topics',
      2 => 'field_research_areas',
      3 => 'field_openaccess_related_call',
      4 => 'field_related_topics_nexus_issue',
      5 => 'field_migration_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|open_access_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|page|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '4',
    'children' => array(
      0 => 'field_tags',
      1 => 'field_identities',
      2 => 'field_institutes',
      3 => 'field_research_areas',
      4 => 'field_related_topics',
      5 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|patent|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patent';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '3',
    'children' => array(
      0 => 'field_identities',
      1 => 'field_institutes',
      2 => 'field_research_areas',
      3 => 'field_tags',
      4 => 'field_archived',
      5 => 'field_related_topics',
      6 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|patent|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|press_release|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '4',
    'children' => array(
      0 => 'field_identities',
      1 => 'field_institutes',
      2 => 'field_research_areas',
      3 => 'field_tags',
      4 => 'field_related_topics',
      5 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|press_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|publication|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '3',
    'children' => array(
      0 => 'field_identities',
      1 => 'field_institutes',
      2 => 'field_research_areas',
      3 => 'field_tags',
      4 => 'field_publication_type',
      5 => 'field_related_topics',
      6 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|research_area|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'research_area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '5',
    'children' => array(
      0 => 'field_identities',
      1 => 'field_institutes',
      2 => 'field_research_areas',
      3 => 'field_tags',
      4 => 'field_related_topics',
      5 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|research_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|research_facility|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'research_facility';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '8',
    'children' => array(
      0 => 'field_archived',
      1 => 'field_identities',
      2 => 'field_institutes',
      3 => 'field_research_areas',
      4 => 'field_tags',
      5 => 'field_related_topics',
      6 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|research_facility|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|science_updates|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'science_updates';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '3',
    'children' => array(
      0 => 'field_tags',
      1 => 'field_related_topics',
      2 => 'field_research_areas',
      3 => 'field_institutes',
      4 => 'field_identities',
      5 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|science_updates|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|scientific_tool|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'scientific_tool';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '10',
    'children' => array(
      0 => 'field_archived',
      1 => 'field_identities',
      2 => 'field_institutes',
      3 => 'field_research_areas',
      4 => 'field_tags',
      5 => 'field_related_topics',
      6 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|scientific_tool|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|training_programme|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'training_programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '8',
    'children' => array(
      0 => 'field_archived',
      1 => 'field_identities',
      2 => 'field_institutes',
      3 => 'field_tags',
      4 => 'field_research_areas',
      5 => 'field_related_topics',
      6 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|training_programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|video_gallery|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '5',
    'children' => array(
      0 => 'field_identities',
      1 => 'field_institutes',
      2 => 'field_research_areas',
      3 => 'field_tags',
      4 => 'field_related_topics',
      5 => 'field_related_topics_nexus_issue',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomies field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomies|node|video_gallery|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Meta data');
  t('Taxomnomies');
  t('Taxonomies');

  return $field_groups;
}
