<?php

/**
 * @file
 * Helper functions for installing and uninstalling updates for basic config.
 */

/**
 * Form for the installation profile task "Choose theme".
 *
 * This form is shared by both standard and communities profile, hence it is
 * exposed by the 'cce_basic_config' module.
 *
 * @see multisite_drupal_standard_install_tasks()
 * @see multisite_drupal_communities_install_tasks()
 */
function cce_basic_config_profile_theme_default_form() {
  $form = array();
  $form['container'] = array(
    '#type' => 'fieldset',
    '#title' => st('Choose theme'),
    '#collapsible' => FALSE,
    '#tree' => FALSE,
  );
  $form['container']['theme_default'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#options' => array(
      'ec_resp' => st('EC Resp'),
      'ec_europa' => st('EC Europa'),
    ),
    '#default_value' => 'ec_resp',
  );
  $form['container']['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Continue'),
  );
  return $form;
}

/**
 * Form submit.
 *
 * @see multisite_drupal_standard_install_tasks()
 */
function cce_basic_config_profile_theme_default_form_submit($form, &$form_state) {
  $theme_default = $form_state['values']['theme_default'];
  $theme_list = array($theme_default);
  if ($theme_default == 'ec_europa') {
    $theme_list[] = 'atomium';
  }
  theme_enable($theme_list);
  variable_set('theme_default', $theme_default);
  $theme_name = $form['container']['theme_default']['#options'][$theme_default];
  if ($theme_default == 'ec_europa') {
    module_enable(array('nexteuropa_ecl_migrate'));
    _nexteuropa_ecl_migrate_blocks();
  }
  drupal_set_message(st("'@name' has been set as default theme.", array('@name' => $theme_name)));
}

/**
 * Finalize profile installation by inserting some site configurations.
 *
 * Insert user roles, assign permission to roles, define themes,
 * define basic content type, etc...
 */
function cce_basic_config_post_install() {
  _cce_basic_config_post_install_theme();
  _cce_basic_config_post_install_default_blocks();
  _cce_basic_config_post_install_default_content_type();
  _cce_basic_config_post_install_user_config();
  _cce_basic_config_post_install_user_roles_perms();
  _cce_basic_config_post_install_users();
  _cce_basic_config_post_install_default_images();
  _cce_basic_config_post_install_default_menu_items();
  _cce_basic_config_post_install_default_terms();
}

/**
 * Initialize 'admin theme'.
 */
function _cce_basic_config_post_install_theme() {
  theme_enable(array('seven'));
  variable_set('admin_theme', 'seven');
}

/**
 * Initialize default blocks.
 */
function _cce_basic_config_post_install_default_blocks() {
  // Enable standard blocks.
  $default_theme = variable_get('theme_default', 'bartik');
  $admin_theme = 'seven';
  $blocks = array(
    array(
      'module' => 'system',
      'delta' => 'main',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'content',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'node',
      'delta' => 'recent',
      'theme' => $admin_theme,
      'status' => 1,
      'weight' => 10,
      'region' => 'dashboard_main',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'system',
      'delta' => 'help',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'help',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'system',
      'delta' => 'main',
      'theme' => $admin_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'content',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'system',
      'delta' => 'help',
      'theme' => $admin_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'help',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'user',
      'delta' => 'new',
      'theme' => $admin_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'dashboard_sidebar',
      'pages' => '',
      'cache' => -1,
    ),
  );
  $query = db_insert('block')->fields(array(
    'module',
    'delta',
    'theme',
    'status',
    'weight',
    'region',
    'pages',
    'cache',
  ));
  foreach ($blocks as $block) {
    $query->values($block);
  }
  $query->execute();

  // Disable the Workbench block.
  db_update('block')
    ->fields(array('region' => '-1'))
    ->condition('module', 'workbench', '=')
    ->condition('delta', 'block', '=')
    ->execute();

}

/**
 * Initialize content type.
 *
 * Add 'page' and ''article' CT and their body.
 */
function _cce_basic_config_post_install_default_content_type() {
  // Insert default pre-defined node types into the database. For a complete
  // list of available node type attributes, refer to the node type API
  // documentation at: http://api.drupal.org/api/HEAD/function/hook_node_info.
  $t = get_t();
  $types = array(
    array(
      'type' => 'article',
      'name' => $t('Article'),
      'base' => 'node_content',
      'description' => $t('Use <em>articles</em> for time-sensitive content.'),
      'custom' => 1,
      'modified' => 1,
      'locked' => 0,
    ),
  );

  foreach ($types as $type) {
    $type = node_type_set_defaults($type);
    node_type_save($type);
    node_add_body_field($type);
  }

  if (module_exists('scheduler')) {
    // Set up scheduler configuration for articles.
    multisite_config_service('scheduler')->enableSchedulerForContentType('article');
    // Set unpublish moderation state to "expired".
    // This call cannot be included in the API method above since it is
    // a configuration specific to NextEuropa .
    variable_set('scheduler_unpublish_moderation_state_article', 'expired');
  }

  // Insert default pre-defined RDF mapping into the database.
  $rdf_mappings = array(
    array(
      'type' => 'node',
      'bundle' => 'page',
      'mapping' => array(
        'rdftype' => array('foaf:Document'),
      ),
    ),
    array(
      'type' => 'node',
      'bundle' => 'article',
      'mapping' => array(
        'field_image' => array(
          'predicates' => array('og:image', 'rdfs:seeAlso'),
          'type' => 'rel',
        ),
        'field_tags' => array(
          'predicates' => array('dc:subject'),
          'type' => 'rel',
        ),
      ),
    ),
  );
  foreach ($rdf_mappings as $rdf_mapping) {
    rdf_mapping_save($rdf_mapping);
  }
}

/**
 * Initialize user configuration (picture, registration...).
 */
function _cce_basic_config_post_install_user_config() {
  // Enable user picture support and set the default to a square thumbnail
  // option.
  variable_set('user_pictures', '1');
  variable_set('user_picture_dimensions', '1024x1024');
  variable_set('user_picture_file_size', '800');
  variable_set('user_picture_style', 'thumbnail');
  // Allow visitor account creation with administrative approval.
  variable_set('user_register', USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL);
  // Remove the realname extra field from the display.
  $profile_settings = field_bundle_settings('user', 'user');
  $profile_settings['extra_fields']['display']['realname']['default'] = array(
    'visible' => 0,
    'weight' => -1,
  );
  field_bundle_settings('user', 'user', $profile_settings);
}

/**
 * Initialize default images.
 */
function _cce_basic_config_post_install_default_images() {
  // The private stream wrapper is not set during installation
  // so we must do it manually before creating the default files.
  drupal_static_reset('file_get_stream_wrappers');
  file_get_stream_wrappers();
  // Set default images.
  $path = drupal_get_path('module', 'cce_basic_config') . '/assets/images/default_images';

  $default_images = array(
    'user_picture_default' => array(
      'scheme' => 'public://',
      'dest_directory' => 'default_images',
      'source_path' => $path . '/user_default.png',
      'filename' => 'user_default.png',
      'variable' => 'user_picture_default',
    ),
    'empty_gallery_default' => array(
      'scheme' => 'public://',
      'dest_directory' => 'default_images',
      'source_path' => $path . '/empty_gallery.png',
      'filename' => 'empty_gallery.png',
      'variable' => 'empty_gallery_default',
    ),
  );

  _cce_basic_config_import_images($default_images);
}

/**
 * Initialize user roles and permissions.
 */
function _cce_basic_config_post_install_user_roles_perms() {
  // Create a default role for site administrators, with all available
  // permissions assigned.
  $admin_role = new stdClass();
  $admin_role->name = 'administrator';
  $admin_role->weight = 2;
  user_role_save($admin_role);

  $all_permissions = array_keys(module_invoke_all('permission'));
  user_role_grant_permissions($admin_role->rid, $all_permissions);

  // Set this as the administrator role.
  variable_set('user_admin_role', $admin_role->rid);

  // Assign user 1 the "administrator" role.
  db_insert('users_roles')
    ->fields(array('uid' => 1, 'rid' => $admin_role->rid))
    ->execute();

  // Revoke permissions for administrators.
  user_role_revoke_permissions($admin_role->rid, array(
    'administer features',
    'administer modules',
    'administer software updates',
    'manage features',
  ));

  // Grant permissions for contributors.
  $contributor_permissions = array(
    'access media browser',
    'access own broken links report',
    'create article content',
    'create files',
    'delete own article content',
    'delete own image files',
    'edit own article content',
    'edit own image files',
    'moderate content from draft to needs_review',
    'moderate content from needs_review to draft',
    'revert revisions',
    'show format selection for comment',
    'show format selection for file',
    'show format selection for taxonomy_term',
    'show format selection for user',
    'show format tips',
    'show more format tips link',
    'use workbench_moderation my drafts tab',
    'use workbench_moderation needs review tab',
    'view all unpublished content',
    'view own files',
    'view own private files',
    'use media wysiwyg',
    'use text format full_html',
  );
  multisite_config_service('user')->grantPermission('contributor', $contributor_permissions);

  // Grant permissions for editors.
  $editor_permissions = array(
    'access broken links report',
    'access media browser',
    'access own broken links report',
    'create article content',
    'create files',
    'delete any article content',
    'delete own article content',
    'delete own image files',
    'delete revisions',
    'edit any article content',
    'edit own article content',
    'edit own image files',
    'moderate content from draft to needs_review',
    'moderate content from needs_review to draft',
    'moderate content from needs_review to published',
    'revert revisions',
    'show format selection for comment',
    'show format selection for file',
    'show format selection for taxonomy_term',
    'show format selection for user',
    'show format tips',
    'show more format tips link',
    'use media wysiwyg',
    'use text format full_html',
    'use workbench_moderation my drafts tab',
    'use workbench_moderation needs review tab',
    'view all unpublished content',
    'view own files',
    'view own private files',
  );
  multisite_config_service('user')->grantPermission('editor', $editor_permissions);

  // Grant permissions for authenticated users.
  $authenticated_permissions = array(
    'access comments',
    'access PDF version',
    'access print',
    'access send by email',
    'access user profiles',
    'access workbench',
    'post comments',
    'search content',
    'show format selection for node',
    'use advanced search',
    'use text format basic_html',
    'use text format filtered_html',
    'view files',
    'view moderation history',
    'view moderation messages',
    'view own unpublished content',
    'view revisions',
  );
  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, $authenticated_permissions);

  // Grant permissions for anonymous users.
  $anonymous_permissions = array(
    'access comments',
    'access PDF version',
    'access print',
    'post comments',
    'search content',
    'use advanced search',
    'use text format basic_html',
    'use text format filtered_html',
  );
  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, $anonymous_permissions);

}

/**
 * Initialize users.
 */
function _cce_basic_config_post_install_users() {
  // Create a default users, with all available roles assigned.
  include_once DRUPAL_ROOT . '/includes/password.inc';
  // Dummy domain used for default email addresses.
  $default_email_domain = 'nomail.nodomain.notld';

  // Add user accounts.
  $account = new stdClass();
  $account->is_new = TRUE;
  $account->status = TRUE;
  $account->name = 'user_administrator';
  $account->pass = user_password();
  $account->mail = 'administrator@' . $default_email_domain;
  $account->init = $account->mail;
  $role = user_role_load_by_name('administrator');
  $account->roles[$role->rid] = $role->name;
  $account->field_firstname[LANGUAGE_NONE][0]['value'] = 'John';
  $account->field_lastname[LANGUAGE_NONE][0]['value'] = 'Smith';
  user_save($account);

  $account1 = new stdClass();
  $account1->is_new = TRUE;
  $account1->status = TRUE;
  $account1->name = 'user_contributor';
  $account1->pass = user_password();
  $account1->mail = 'contributor@' . $default_email_domain;
  $account1->init = $account1->mail;
  $role1 = user_role_load_by_name('contributor');
  $account1->roles[$role1->rid] = $role1->name;
  $account1->field_firstname[LANGUAGE_NONE][0]['value'] = 'John';
  $account1->field_lastname[LANGUAGE_NONE][0]['value'] = 'Doe';
  user_save($account1);

  $account2 = new stdClass();
  $account2->is_new = TRUE;
  $account2->status = TRUE;
  $account2->name = 'user_editor';
  $account2->pass = user_password();
  $account2->mail = 'editor@' . $default_email_domain;
  $account2->init = $account2->mail;
  $role2 = user_role_load_by_name('editor');
  $account2->roles[$role2->rid] = $role2->name;
  $account2->field_firstname[LANGUAGE_NONE][0]['value'] = 'John';
  $account2->field_lastname[LANGUAGE_NONE][0]['value'] = 'Blake';
  user_save($account2);

  // Assign dummy content to the 'administrator' user.
  $query = db_select('node', 'n');
  $query->condition('n.type', 'article', '=')
    ->fields('n', array('nid', 'title', 'uid'));
  $results = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  foreach ($results as $result) {
    $node = node_load($result['nid']);
    $node->uid = $account->uid;
    node_save($node);
  }
}

/**
 * Initialize menu items.
 */
function _cce_basic_config_post_install_default_menu_items() {
  $t = get_t();
  // Create a Home link in the main menu.
  $item = array(
    'link_title' => $t('Home'),
    'link_path' => '<front>',
    'menu_name' => 'main-menu',
  );
  menu_link_save($item);

  // Add login link to the user menu.
  $options = array();
  $options['attributes']['title'] = $t('Login');
  $options['attributes']['class'][] = 'btn';
  $options['attributes']['class'][] = 'btn-default';
  $options['attributes']['data-image'] = 'log-in';
  $options['attributes']['data-toggle'] = 'tooltip';
  $options['attributes']['data-placement'] = 'bottom';
  $options['attributes']['data-container'] = 'body';
  $item = array(
    'link_path' => 'user/login',
    'link_title' => $t('Login'),
    'menu_name' => 'user-menu',
    'options' => $options,
  );
  menu_link_save($item);

  // Add workbench link to the user menu.
  $options = array();
  $options['attributes']['title'] = $t('My workbench');
  $options['attributes']['class'][] = 'btn';
  $options['attributes']['class'][] = 'btn-info';
  $options['attributes']['data-image'] = 'list-alt';
  $options['attributes']['data-display-title'] = 0;
  $options['attributes']['data-toggle'] = 'tooltip';
  $options['attributes']['data-placement'] = 'bottom';
  $options['attributes']['data-container'] = 'body';

  $item = array(
    'link_path' => 'admin/workbench',
    'link_title' => $t('My workbench'),
    'menu_name' => 'user-menu',
    'weight' => '-30',
    'options' => $options,
  );
  menu_link_save($item);

  // Add search links to the main menu.
  $item = array(
    'link_path' => 'search/site',
    'link_title' => $t('Search'),
    'menu_name' => 'main-menu',
    'weight' => '19999',
  );
  menu_link_save($item);

  // Update home link in the main menu.
  $options = array();
  $options['attributes']['data-display-title'] = 0;
  $options['attributes']['data-image'] = 'home';
  db_update('menu_links')
    ->fields(array('options' => serialize($options), 'weight' => '-50'))
    ->condition('link_title', 'Home')
    ->condition('menu_name', 'main-menu')
    ->execute();

}

/**
 * Insert default terms.
 */
function _cce_basic_config_post_install_default_terms() {
  // Add dummy terms in 'tags' vocabulary.
  $vocabulary = taxonomy_vocabulary_machine_name_load('tags');
  $term = new stdClass();
  $term->name = "sport";
  $term->vid = $vocabulary->vid;
  taxonomy_term_save($term);

  $term = new stdClass();
  $term->name = "economic";
  $term->vid = $vocabulary->vid;
  taxonomy_term_save($term);
}

/**
 * Set the field base settings for the "body" field.
 *
 * It allows "soft" configuring the default settings of the field in order to
 * avoid conflicts with existing sites that have different settings (NEPT-640).
 */
function _cce_basic_config_body_field_base_add() {
  $body = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 1,
    'type' => 'text_with_summary',
  );

  field_create_field($body);
}

/**
 * Creates the text format filters for the platform.
 *
 * Import configuration from feature export
 * https://webgate.ec.europa.eu/CITnet/jira/browse/NEPT-544
 */
function _cce_basic_config_text_formats() {
  $formats = array();
  $formats['filtered_html'] = (object) array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'toolbox_sanitize' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <abbr> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );
  $formats['full_html'] = (object) array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'toolbox_sanitize' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_tokens' => array(
        'weight' => 20,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );
  $formats['plain_text'] = (object) array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );
  $formats['basic_html'] = (object) array(
    'format' => 'basic_html',
    'name' => 'Basic HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 5,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'toolbox_sanitize' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <abbr> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );
  foreach ($formats as $value) {
    filter_format_save($value);
  }
  $full_html = array(
    'full_html' => 'full_html',
    'plain_text' => 'plain_text',
    'filtered_html' => 0,
    'basic_html' => 0,
  );
  // Variables export.
  variable_set('i18n_string_allowed_formats', $full_html);
  variable_set('filter_fallback_format', 'plain_text');
}

/**
 * Set the field instance settings for the "comment_body" field.
 *
 * It allows "soft" configuring the default settings of the field instance.
 */
function _cce_basic_config_comment_body_field_instance_add() {
  // Exported field_instance: 'comment-comment_node_article-comment_body'.
  $field_instances['comment-comment_node_article-comment_body'] = array(
    'bundle' => 'comment_node_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Comment',
    'required' => TRUE,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  field_create_instance($field_instances['comment-comment_node_article-comment_body']);
}

/**
 * Set the field settings for the "field_video_description" field.
 *
 * It allows "soft" configuring the default settings of the field instance.
 */
function _cce_basic_config_video_description_field_add() {
  if (!field_info_field('field_video_description')) {
    // Exported field_base: 'field_video_description'.
    $field_video_description_base = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_video_description',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 1,
      'module' => 'text',
      'settings' => array(),
      'translatable' => 1,
      'type' => 'text_long',
    );

    field_create_field($field_video_description_base);
  }

  if (!field_info_instance('file', 'field_video_description', 'video')) {
    // Exported field_instance: 'file-video-field_video_description'.
    $field_video_description_instance = array(
      'bundle' => 'video',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
        'media_large' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_original' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_small' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_video_description',
      'label' => 'Video Description',
      'required' => 0,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => -4,
      ),
    );

    field_create_instance($field_video_description_instance);
  }
}

/**
 * Set the field settings for the "field_tags" field.
 *
 * It allows "soft" configuring the default settings of the field instance.
 */
function _cce_basic_config_video_tags_field_add() {
  if (!field_info_field('field_tags')) {
    // Exported field_base: 'field_tags'.
    $field_tags_base = array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => 1,
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'tags',
            'parent' => 0,
          ),
        ),
        'options_list_callback' => 'i18n_taxonomy_allowed_values',
      ),
      'translatable' => 0,
      'type' => 'taxonomy_term_reference',
    );

    field_create_field($field_tags_base);
  }

  if (!field_info_instance('file', 'field_tags', 'video')) {
    // Exported field_instance: 'file-video-field_tags'.
    $field_video_tags_instance = array(
      'bundle' => 'video',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'i18n_taxonomy',
          'settings' => array(),
          'type' => 'i18n_taxonomy_term_reference_link',
          'weight' => 1,
        ),
        'media_large' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_original' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_small' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_tags',
      'label' => 'Tags',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => 5,
      ),
    );

    field_create_instance($field_video_tags_instance);
  }
}

/**
 * Implements hook_update_dependencies().
 */
function cce_basic_config_update_dependencies() {
  $dependencies['cce_basic_config'][7235] = array(
    'password_policy' => 7208,
  );
  return $dependencies;
}
