<?php

/**
 * @file
 * jrc_sh_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function jrc_sh_permissions_user_default_roles() {
  $roles = array();

  // Exported role: Open access editor.
  $roles['Open access editor'] = (object) array(
    'name' => 'Open access editor',
    'weight' => 15,
  );

  // Exported role: Webtool creator.
  $roles['Webtool creator'] = (object) array(
    'name' => 'Webtool creator',
    'weight' => 16,
  );

  return $roles;
}
