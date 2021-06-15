<?php

/**
 * @file
 * nexteuropa_dashboard_agent_uli.page.inc
 */

define('NEXTEUROPA_DASHBOARD_AGENT_USER_UID1', 'superadmin');
define('NEXTEUROPA_DASHBOARD_AGENT_USER_ADMIN', 'admin');

/**
 * Provides a user login url for the given user type in JSON format.
 *
 * User types:
 * - super administrator;
 * - administrator.
 *
 * @param string $user_type
 */
function nexteuropa_dashboard_agent_uli_page($user_type) {
  $available_user_types = [NEXTEUROPA_DASHBOARD_AGENT_USER_UID1, NEXTEUROPA_DASHBOARD_AGENT_USER_ADMIN];
  if (!in_array($user_type, $available_user_types)) {
    drupal_json_output(['error' => 412, 'msg' => sprintf('Invalid user type given %s.', $user_type)]);
    drupal_exit();
  }

  if ($user_type === NEXTEUROPA_DASHBOARD_AGENT_USER_ADMIN) {
    $query = db_select('users', 'u')
      ->fields('u', ['uid']);
    $query->innerJoin('users_roles', 'ur', 'ur.uid = u.uid');
    $query->innerJoin('role', 'r', 'r.rid = ur.rid');
    $query->condition('u.mail', 'administrator@nomail.nodomain.notld', '=')
      ->condition('u.init', 'root@localhost', '=')
      ->condition('r.name', 'administrator', '=');
    $uid = $query->execute()->fetchField();
    if (!empty($uid)) {
      $account = user_load($uid);
      drupal_json_output(user_pass_reset_url($account) . '/login');
      drupal_exit();
    }
  }

  $account = user_load(1);
  drupal_json_output(user_pass_reset_url($account) . '/login');
}
