<?php

/**
 * @file
 * API documentation for the Scheduler module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allow modules to react to Scheduler node operations.
 *
 * Modules can implement hook_scheduler_api() to react to the Scheduler action
 * being performed on a node. This hook is invoked during cron processing for
 * 'pre_publish', 'publish', 'pre_unpublish' and 'unpublish' and from
 * scheduler_node_presave() for 'publish_immediately'.
 *
 * @param object $node
 *   The scheduled node object that is being processed.
 * @param string $action
 *   $action determines what is being done to the node. The value will be
 *   'pre_publish', 'publish', 'publish_immediately', 'pre_unpublish'
 *   or 'unpublish'.
 */
function hook_scheduler_api($node, $action) {
  switch ($action) {
    case 'pre_publish':
      break;

    case 'publish':
      break;

    case 'publish_immediately':
      break;

    case 'pre_unpublish':
      break;

    case 'unpublish':
      break;

    default:
  }
}

/**
 * Allow modules to add node ids to the list being processed.
 *
 * Modules can implement hook_scheduler_nid_list() to add more node ids into the
 * list to be processed in the current cron run. This hook is invoked during
 * cron runs only. It is maintained for backwards compatibility but has been
 * superceded by hook_scheduler_nid_list_alter(), which has more functionality.
 *
 * @param string $action
 *   Indicates what is being done to the node.
 *   The value will be 'publish' or 'unpublish'.
 *
 * @return array
 *   Array of node ids to add to the existing list of nodes to be processed.
 */
function hook_scheduler_nid_list($action) {
  $nids = array();
  // Do some processing to add new node ids.
  return $nids;
}

/**
 * Allows modules to add or remove node ids from the list to be processed.
 *
 * Modules can implement hook_scheduler_nid_list_alter() to add or remove node
 * ids from the list to be processed in the current cron run. This hook is
 * invoked during cron runs only.
 *
 * @param array $nids
 *   Array of node ids being processed.
 * @param string $action
 *   Indicates what is being done to the node.
 *   The value will be 'publish' or 'unpublish'.
 *
 * @return array
 *   The full array of node ids to process, adjusted as required.
 */
function hook_scheduler_nid_list_alter(array &$nids, $action) {
  // Do some processing to add or removed node ids from the $nids array.
  return $nids;
}

/**
 * Allows modules to prevent publication of a scheduled node.
 *
 * Modules can implement hook_scheduler_allow_publishing() to prevent publishing
 * of a scheduled node. The node can be scheduled for publishing as usual, and
 * an attempt to publish it will be made during the first cron run after the
 * publishing time. If this hook returns FALSE the node will not be published.
 * Attempts at publishing will continue on each subsequent cron run until this
 * hook returns TRUE.
 *
 * @param object $node
 *   The scheduled node that is about to be published.
 *
 * @return bool
 *   TRUE if the node can be published, FALSE if it should not be published.
 */
function hook_scheduler_allow_publishing($node) {
  $allowed = TRUE;

  // Prevent publication of nodes that do not have the 'Approved for publication
  // by the CEO' checkbox ticked.
  if ($items = field_get_items('node', $node, 'field_approved')) {
    $allowed = !empty($items[0]['value']);

    // If publication is denied then inform the user why. This message will be
    // displayed during node edit and save.
    if (!$allowed) {
      drupal_set_message(t('The content will only be published after approval by the CEO.'), 'status', FALSE);
    }
  }

  return $allowed;
}

/**
 * Allows modules to prevent unpublication of a scheduled node.
 *
 * Modules can implement hook_scheduler_allow_unpublishing() to prevent
 * unpublishing of a scheduled node. The node can be scheduled for unpublishing
 * as usual, and an attempt to unpublish it will be made during the first cron
 * run after the unpublishing time. If this hook returns FALSE the node will not
 * be unpublished. Attempts at unpublishing will continue on each subsequent
 * cron run until this hook returns TRUE.
 *
 * @param object $node
 *   The scheduled node that is about to be unpublished.
 *
 * @return bool
 *   TRUE if the node can be unpublished, FALSE if it should not be unpublished.
 */
function hook_scheduler_allow_unpublishing($node) {
  $allowed = TRUE;

  // Prevent unpublication of competition entries if not all prizes have been
  // claimed.
  if ($node->type == 'competition' && $items = field_get_items('node', $node, 'field_competition_prizes')) {
    $allowed = (bool) count($items);

    // If unpublication is denied then inform the user why. This message will be
    // displayed during node edit and save.
    if (!$allowed) {
      drupal_set_message(t('The competition will only be unpublished after all prizes have been claimed by the winners.'));
    }
  }

  return $allowed;
}

/**
 * @} End of "addtogroup hooks".
 */
