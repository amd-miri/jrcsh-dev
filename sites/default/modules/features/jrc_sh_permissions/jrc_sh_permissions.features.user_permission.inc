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

  // Exported permission: 'create topic content'.
  $permissions['create topic content'] = array(
    'name' => 'create topic content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any topic content'.
  $permissions['delete any topic content'] = array(
    'name' => 'delete any topic content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own topic content'.
  $permissions['delete own topic content'] = array(
    'name' => 'delete own topic content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any topic content'.
  $permissions['edit any topic content'] = array(
    'name' => 'edit any topic content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own topic content'.
  $permissions['edit own topic content'] = array(
    'name' => 'edit own topic content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

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

  // Exported permission: 'create euwomen4future content'.
  $permissions['create euwomen4future content'] = array(
    'name' => 'create euwomen4future content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'administrator' => 'administrator',
      'cem' => 'cem',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create f_a_q content'.
  $permissions['create f_a_q content'] = array(
    'name' => 'create f_a_q content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create news content'.
  $permissions['create news content'] = array(
    'name' => 'create news content',
    'roles' => array(
      'News / Press' => 'News / Press',
      'administrator' => 'administrator',
      'cem' => 'cem',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create open_access_call content'.
  $permissions['create open_access_call content'] = array(
    'name' => 'create open_access_call content',
    'roles' => array(
      'Open access editor' => 'Open access editor',
      'administrator' => 'administrator',
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
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any euwomen4future content'.
  $permissions['delete any euwomen4future content'] = array(
    'name' => 'delete any euwomen4future content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'administrator' => 'administrator',
      'cem' => 'cem',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any f_a_q content'.
  $permissions['delete any f_a_q content'] = array(
    'name' => 'delete any f_a_q content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any news content'.
  $permissions['delete any news content'] = array(
    'name' => 'delete any news content',
    'roles' => array(
      'administrator' => 'administrator',
      'cem' => 'cem',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any open_access_call content'.
  $permissions['delete any open_access_call content'] = array(
    'name' => 'delete any open_access_call content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any open_access_project content'.
  $permissions['delete any open_access_project content'] = array(
    'name' => 'delete any open_access_project content',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'delete own euwomen4future content'.
  $permissions['delete own euwomen4future content'] = array(
    'name' => 'delete own euwomen4future content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'administrator' => 'administrator',
      'cem' => 'cem',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own f_a_q content'.
  $permissions['delete own f_a_q content'] = array(
    'name' => 'delete own f_a_q content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own news content'.
  $permissions['delete own news content'] = array(
    'name' => 'delete own news content',
    'roles' => array(
      'News / Press' => 'News / Press',
      'administrator' => 'administrator',
      'cem' => 'cem',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own open_access_call content'.
  $permissions['delete own open_access_call content'] = array(
    'name' => 'delete own open_access_call content',
    'roles' => array(
      'Open access editor' => 'Open access editor',
      'administrator' => 'administrator',
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
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in euwomen4future_categories'.
  $permissions['delete terms in euwomen4future_categories'] = array(
    'name' => 'delete terms in euwomen4future_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
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

  // Exported permission: 'edit any euwomen4future content'.
  $permissions['edit any euwomen4future content'] = array(
    'name' => 'edit any euwomen4future content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'administrator' => 'administrator',
      'cem' => 'cem',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any f_a_q content'.
  $permissions['edit any f_a_q content'] = array(
    'name' => 'edit any f_a_q content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any news content'.
  $permissions['edit any news content'] = array(
    'name' => 'edit any news content',
    'roles' => array(
      'News / Press' => 'News / Press',
      'administrator' => 'administrator',
      'cem' => 'cem',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any open_access_call content'.
  $permissions['edit any open_access_call content'] = array(
    'name' => 'edit any open_access_call content',
    'roles' => array(
      'Open access editor' => 'Open access editor',
      'administrator' => 'administrator',
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
      'administrator' => 'administrator',
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

  // Exported permission: 'edit own euwomen4future content'.
  $permissions['edit own euwomen4future content'] = array(
    'name' => 'edit own euwomen4future content',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'administrator' => 'administrator',
      'cem' => 'cem',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own f_a_q content'.
  $permissions['edit own f_a_q content'] = array(
    'name' => 'edit own f_a_q content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own news content'.
  $permissions['edit own news content'] = array(
    'name' => 'edit own news content',
    'roles' => array(
      'News / Press' => 'News / Press',
      'administrator' => 'administrator',
      'cem' => 'cem',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own open_access_call content'.
  $permissions['edit own open_access_call content'] = array(
    'name' => 'edit own open_access_call content',
    'roles' => array(
      'Open access editor' => 'Open access editor',
      'administrator' => 'administrator',
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
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in euwomen4future_categories'.
  $permissions['edit terms in euwomen4future_categories'] = array(
    'name' => 'edit terms in euwomen4future_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'temp admin' => 'temp admin',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
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
