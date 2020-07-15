<?php

/**
 * @file
 * jrc_sh_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function jrc_sh_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any webtools bean'.
  $permissions['create any webtools bean'] = array(
    'name' => 'create any webtools bean',
    'roles' => array(
      'Webtool creator' => 'Webtool creator',
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create open_access_call content'.
  $permissions['create open_access_call content'] = array(
    'name' => 'create open_access_call content',
    'roles' => array(
      'Open access editor' => 'Open access editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create open_access_project content'.
  $permissions['create open_access_project content'] = array(
    'name' => 'create open_access_project content',
    'roles' => array(
      'Open access editor' => 'Open access editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any open_access_call content'.
  $permissions['delete any open_access_call content'] = array(
    'name' => 'delete any open_access_call content',
    'roles' => array(
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any open_access_project content'.
  $permissions['delete any open_access_project content'] = array(
    'name' => 'delete any open_access_project content',
    'roles' => array(
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any webtools bean'.
  $permissions['delete any webtools bean'] = array(
    'name' => 'delete any webtools bean',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete own open_access_call content'.
  $permissions['delete own open_access_call content'] = array(
    'name' => 'delete own open_access_call content',
    'roles' => array(
      'Open access editor' => 'Open access editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own open_access_project content'.
  $permissions['delete own open_access_project content'] = array(
    'name' => 'delete own open_access_project content',
    'roles' => array(
      'Open access editor' => 'Open access editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in open_calls_section_labs'.
  $permissions['delete terms in open_calls_section_labs'] = array(
    'name' => 'delete terms in open_calls_section_labs',
    'roles' => array(
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any open_access_call content'.
  $permissions['edit any open_access_call content'] = array(
    'name' => 'edit any open_access_call content',
    'roles' => array(
      'Open access editor' => 'Open access editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any open_access_project content'.
  $permissions['edit any open_access_project content'] = array(
    'name' => 'edit any open_access_project content',
    'roles' => array(
      'Open access editor' => 'Open access editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webtools bean'.
  $permissions['edit any webtools bean'] = array(
    'name' => 'edit any webtools bean',
    'roles' => array(
      'Webtool creator' => 'Webtool creator',
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit own open_access_call content'.
  $permissions['edit own open_access_call content'] = array(
    'name' => 'edit own open_access_call content',
    'roles' => array(
      'Open access editor' => 'Open access editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own open_access_project content'.
  $permissions['edit own open_access_project content'] = array(
    'name' => 'edit own open_access_project content',
    'roles' => array(
      'Open access editor' => 'Open access editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in open_calls_section_labs'.
  $permissions['edit terms in open_calls_section_labs'] = array(
    'name' => 'edit terms in open_calls_section_labs',
    'roles' => array(
      'temp admin' => 'temp admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'upload webtools custom js'.
  $permissions['upload webtools custom js'] = array(
    'name' => 'upload webtools custom js',
    'roles' => array(
      'Webtool creator' => 'Webtool creator',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'nexteuropa_webtools',
  );

  // Exported permission: 'view any webtools bean'.
  $permissions['view any webtools bean'] = array(
    'name' => 'view any webtools bean',
    'roles' => array(
      'Webtool creator' => 'Webtool creator',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
