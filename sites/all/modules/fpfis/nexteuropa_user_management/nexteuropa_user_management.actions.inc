<?php
/**
 * @file
 * Code for the NextEuropa Manage Roles feature, implemented actions.
 */

/**
 * Implements hook_action_info().
 */
function nexteuropa_user_management_action_info() {
  return array(
    'nexteuropa_user_management_block_selected_user_action' => array(
      'label' => t('Block the selected user'),
      'type' => 'user',
      'configurable' => FALSE,
      'triggers' => array(),
    ),
    'nexteuropa_user_management_unblock_selected_user_action' => array(
      'label' => t('Unblock the selected user'),
      'type' => 'user',
      'configurable' => FALSE,
      'triggers' => array(),
    ),
    'nexteuropa_user_management_change_user_roles_action' => array(
      'label' => t('Change user roles'),
      'type' => 'user',
      'configurable' => TRUE,
      'triggers' => array(),
    ),
  );
}

/**
 * Block a specific user.
 *
 * @param object $entity
 *   (optional) An entity object; if it is provided and it has a uid property,
 *   the user with that ID is blocked.
 * @param array $context
 *   (optional) An associative array; currently not used here.
 *
 * @ingroup actions
 *
 * @throws \Exception
 */
function nexteuropa_user_management_block_selected_user_action(&$entity, $context = array()) {
  // If there's no user or tries to modify himself then exit.
  if (!isset($entity->uid) || $entity->uid === $GLOBALS['user']->uid) {
    return;
  }

  $account = user_load($entity->uid);
  $account = user_save($account, array('status' => 0));
  watchdog('action', 'User %name blocked.', array('%name' => $account->name));
}

/**
 * Unblock a specific user.
 *
 * @param object $entity
 *   (optional) An entity object; if it is provided and it has a uid property,
 *   the user with that ID is unblocked.
 * @param array $context
 *   (optional) An associative array; currently not used here.
 *
 * @ingroup actions
 *
 * @throws \Exception
 */
function nexteuropa_user_management_unblock_selected_user_action(&$entity, $context = array()) {
  // If there's no user or tries to modify himself then exit.
  if (!isset($entity->uid) || $entity->uid === $GLOBALS['user']->uid) {
    return;
  }

  $account = user_load($entity->uid);
  $account = user_save($account, array('status' => 1));
  watchdog('action', 'Unblock user %name.', array('%name' => $account->name));
}

/**
 * Action settings form.
 *
 * @param array $context
 *   Provides a context for the action form.
 *
 * @return array
 *   Renderable array.
 */
function nexteuropa_user_management_change_user_roles_action_form($context, &$form_state) {
  if (!user_access('nexteuropa manage users non restricted operations') && !user_access('administer permissions')) {
    drupal_set_message(t('Your user does not have access to modify user roles.'), 'error');
    return array();
  }

  $roles = user_roles(TRUE);
  // Can't edit authenticated role.
  unset($roles[DRUPAL_AUTHENTICATED_RID]);

  // If the current user has access to grant any role (i.e. user 1 and
  // administrator role), it's useless to restrict here the list, however if it
  // has no this right, restrict it.
  if (!user_access('administer permissions')) {
    _nexteuropa_user_management_restrict_roles($roles);
  }

  if (empty($roles)) {
    return array(
      'message' => array(
        '#markup' => t("There's no role which you can assign."),
      ),
    );
  }

  // Save the roles $key => $value array for later use.
  $form_state['um_roles'] = $roles;

  $form = array();
  $form['add_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Add roles'),
    '#description' => t('Choose one or more roles you would like to assign to the selected users.'),
    '#options' => $roles,
  );
  $form['remove_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Remove roles'),
    '#description' => t('Choose one or more roles you would like to remove from the selected users.'),
    '#options' => $roles,
  );

  return $form;
}

/**
 * Provides a validation for the action form.
 *
 * @param array $form
 *   Action form, renderable array.
 * @param array $form_state
 *   Action form state.
 */
function nexteuropa_user_management_change_user_roles_action_validate($form, $form_state) {
  $add_roles = array_filter($form_state['values']['add_roles']);
  $remove_roles = array_filter($form_state['values']['remove_roles']);
  if (!$add_roles && !$remove_roles) {
    form_set_error('add_roles', t('You have not chosen any role to add or remove. Please select something to do.'));
  }

  $double_selected = array_intersect($add_roles, $remove_roles);
  if ($double_selected) {
    $double_selected_stringified = array_intersect_key($form_state['um_roles'], $double_selected);
    form_set_error('remove_roles', format_plural(count($double_selected), 'You chose the same role for both actions, please remove from one of the action the following role: %roles.', 'You chose the same roles for both actions, please remove from one of the action the following roles: %roles.', array(
      '%roles' => implode(', ', $double_selected_stringified),
    )));
  }
}

/**
 * Action form submit handler, it will returns roles.
 *
 * @param array $form
 *   Action form's renderable array.
 * @param array $form_state
 *   Action form's state.
 *
 * @return array
 *   Returns the action form results. Roles to remove and add to the selected
 *   users.
 */
function nexteuropa_user_management_change_user_roles_action_submit($form, $form_state) {
  return array(
    'add_roles' => array_filter($form_state['values']['add_roles']),
    'remove_roles' => array_filter($form_state['values']['remove_roles']),
  );
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function nexteuropa_user_management_form_views_form_nexteuropa_user_management_neum_alter(&$form, &$form_state, $form_id) {
  // This will replace the confirmation form's content. To prevent to have two
  // confirmation form we overwrite the provided one.
  if ($form['#theme'] === 'confirm_form') {
    $confirm = array();

    $confirm['intro'] = array(
      '#markup' => t('The following changes will be applied:'),
    );

    // This will return back to as the rid => role name pairs, respecting which
    // was selected for add and remove by the user.
    $selected_to_add = array_intersect_key($form_state['um_roles'], $form_state['operation']->formOptions['add_roles']);
    $selected_to_remove = array_intersect_key($form_state['um_roles'], $form_state['operation']->formOptions['remove_roles']);

    // Table header.
    $header = array(t('Displayed name (ecas name)'), t('Current roles'));
    if ($selected_to_add) {
      $header[] = t('Added roles');
    }
    if ($selected_to_remove) {
      $header[] = t('Removed roles');
    }
    $header[] = t('Result');
    $rows = array();

    if (count($form_state['selection']) > 50) {
      // If we have large amount of data, then don't make comparision.
      $rows[] = array(
        array(
          'data' => t('The comparison page only works, if the selected amount of user is not greater then 50.'),
          'colspan' => count($header),
        ),
      );
    }
    else {
      // If we have small amount of data, then let's make a 'fast' comparision
      // to show the differences.
      $users = user_load_multiple($form_state['selection']);
      foreach ($users as $user) {
        $row = array();

        // Display current user name and ecas username.
        $row[] = format_username($user) . ' (' . $user->name . ')';

        // Get current user's roles and remove authenticated from the list.
        $roles = $user->roles;
        unset($roles[DRUPAL_AUTHENTICATED_RID]);

        // Display current role.
        $current_roles = array(
          'list_type' => 'ol',
          'items' => array_values($roles),
        );
        $row[] = $roles ? theme('item_list', $current_roles) : '-';

        // Calculate changes.
        $role_changes = _nexteuropa_user_management_calculate_roles($roles, $selected_to_add, $selected_to_remove);

        // Display new (added) roles.
        if ($selected_to_add) {
          $added_roles = array(
            'list_type' => 'ol',
            'items' => array_values($role_changes['added']),
            'attributes' => array('class' => array('um_role_add')),
          );
          $row[] = $role_changes['added'] ? theme('item_list', $added_roles) : '-';
        }

        // Display removed roles.
        if ($selected_to_remove) {
          $removed_roles = array(
            'list_type' => 'ol',
            'items' => array_values($role_changes['removed']),
            'attributes' => array('class' => array('um_role_remove')),
          );
          $row[] = $role_changes['removed'] ? theme('item_list', $removed_roles) : '-';
        }

        // Display final result.
        if ($role_changes['result']) {
          // If we have roles after the operations.
          $result_roles = array(
            'list_type' => 'ol',
            'items' => array_values($role_changes['result']),
          );
          if ($role_changes['added'] || $role_changes['removed']) {
            // If the role was changed, then we color it.
            $result_roles['attributes'] = array('class' => array('um_role_result'));
          }
          $row[] = theme('item_list', $result_roles);
        }
        else {
          // If we don't have roles after the operations.
          $result_roles = array(
            '#tag' => 'span',
            '#value' => '-',
          );
          if (!$role_changes['result'] && $roles) {
            // If the role was changed, then we color it.
            $result_roles['#attributes'] = array('class' => array('um_role_result'));
          }
          $row[] = theme('html_tag', array('element' => $result_roles));
        }

        // Add this row to the others.
        $rows[] = $row;
      }
    }

    // Add comparision table.
    $confirm['changes'] = array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
    );

    $form['description']['#markup'] = drupal_render($confirm);
    $form['#attached']['css'][] = drupal_get_path('module', 'nexteuropa_user_management') . '/css/um_style.css';
  }
}

/**
 * This function does the add and remove on the user's roles.
 *
 * NOTE: first it adds the roles and then removes to make sure the roles which
 * needs to be removed it will be removed.
 * This function also returns the added and removed roles separately.
 *
 * @param array $original
 *   This is the current user roles.
 * @param array $add
 *   Roles to be added to the user roles array.
 * @param array $remove
 *   Roles to be removed from the user roles array.
 *
 * @return array
 *   It returns in the array an added roles array keyed by 'added' a removed
 *   roles array keyed by 'removed' and a result roles array keyed by 'result'.
 */
function _nexteuropa_user_management_calculate_roles($original, $add, $remove) {
  $removed = array();
  $added = array();
  $roles = $original;
  if (is_array($add)) {
    $added = array_diff($add, $roles);
    $roles = array_merge($roles, $add);
  }
  if (is_array($remove)) {
    $removed = array_intersect($roles, $remove);
    $roles = array_diff($roles, $remove);
  }

  return [
    'added' => $added,
    'removed' => $removed,
    'result' => array_unique($roles),
  ];
}

/**
 * Add/remove roles for the 'Change user roles' action.
 *
 * @param object $entity
 *   An user entity, roles will be modified on this entity.
 * @param array $context
 *   Determinates which roles will be added, by the 'add_roles' array key, and
 *   which will be removed by the 'remove_roles' key. Changes will be made on
 *   the $entity object.
 */
function nexteuropa_user_management_change_user_roles_action($entity, $context = array()) {
  // Silently exit if:
  // - there's no user or
  // - tries to modify himself or
  // - nothing to be set or
  // - user does not have permission to change roles.
  if (
    !isset($entity->uid) ||
    $entity->uid === $GLOBALS['user']->uid ||
    empty($context['add_roles']) && empty($context['remove_roles']) ||
    !user_access('nexteuropa manage users non restricted operations') && !user_access('administer permissions')
  ) {
    return;
  }

  $wrapper = entity_metadata_wrapper('user', $entity);

  $original_roles = $roles = $wrapper->roles->value();
  $roles = _nexteuropa_user_management_calculate_roles($roles, $context['add_roles'], $context['remove_roles'])['result'];
  $wrapper->roles->set($roles);
  $wrapper->save();

  watchdog('action', 'Roles was modified on %name user, added: "%added_roles", removed: "%removed_roles" and original: "%original_roles".', array(
    '%name' => $wrapper->label(),
    '%added_roles' => implode(', ', $context['add_roles']),
    '%removed_roles' => implode(', ', $context['remove_roles']),
    '%original_roles' => implode(', ', $original_roles),
  ));
}
