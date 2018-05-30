<?php

/**
 * @file
 * This file contains examples of hooks that can be implemented.
 */

/**
 * This hook allows you to alter the modifier used by nexteuropa formatters.
 *
 * @param string $modifier
 *   Argument by reference containing the modifier.
 * @param string $entity_type
 *   Entity type, usually node.
 * @param object $entity
 *   The node instance.
 */
function hook_nexteuropa_formatters_modifier_alter(&$modifier, $entity_type, $entity) {
  $modifier = 'test';
}
