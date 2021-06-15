<?php

/**
 * @file
 * Drush commands for Scheduler.
 */

/**
 * Implements hook_drush_command().
 */
function scheduler_drush_command() {
  $items = array();

  $items['scheduler-cron'] = array(
    'description' => 'Lighweight cron to process the Scheduler module tasks.',
    'core' => array('7'),
    'aliases' => array('sch-cron'),
    'category' => 'scheduler',
    'options' => array(
      'nomsg' => 'to avoid the "cron completed" message being written to the terminal.',
    ),
  );

  return $items;
}

/**
 * Run lighweight scheduler cron.
 */
function drush_scheduler_cron() {
  // Load the cron functions file then run scheduler cron.
  module_load_include('inc', 'scheduler', 'scheduler.cron');
  // Running the lightweight cron function _scheduler_run_cron() gives the dblog
  // rows but also kills drush. If we wanted to use that function, we can check
  // function_exists('drush_main') to do conditional code.
  scheduler_cron();
  $nomsg = drush_get_option('nomsg', NULL);
  $nomsg ? NULL : drupal_set_message(t('Scheduler lightweight cron completed.'));
}
