<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>

<div class="opencall-date">
<?php if (isset($row->field_field_date_openaccess_call[0]['raw']['value2']) && $row->field_field_date_openaccess_call[0]['raw']['value'] != $row->field_field_date_openaccess_call[0]['raw']['value2']) : ?>
  <div class="date-cont start-date-with-end">
<?php elseif (isset($row->field_field_date_openaccess_call[0]['raw']['value']) && !empty($row->field_field_date_openaccess_call[0]['raw']['value'])) : ?>
  <div class="date-cont start-date-without-end">
<?php endif; ?>

<?php if (isset($row->field_field_date_openaccess_call[0]['raw']['value']) && !empty($row->field_field_date_openaccess_call[0]['raw']['value'])) : ?>
    <span class="month"><?php print format_date(strtotime(check_plain($row->field_field_date_openaccess_call[0]['raw']['value'])), 'jrc_month'); ?></span>
    <span class="day"><?php print format_date(strtotime(check_plain($row->field_field_date_openaccess_call[0]['raw']['value'])), 'jrc_day'); ?></span>
    <span class="year"><?php print format_date(strtotime(check_plain($row->field_field_date_openaccess_call[0]['raw']['value'])), 'jrc_year'); ?></span>
  </div>
<?php endif; ?>

<?php if (isset($row->field_field_date_openaccess_call[0]['raw']['value2']) && $row->field_field_date_openaccess_call[0]['raw']['value'] != $row->field_field_date_openaccess_call[0]['raw']['value2']) : ?>
  <div class="event-dates-arrow"></div>
  <div class="date-cont end-date">
    <span class="month"><?php print format_date(strtotime(check_plain($row->field_field_date_openaccess_call[0]['raw']['value2'])), 'jrc_month'); ?></span>
    <span class="day"><?php print format_date(strtotime(check_plain($row->field_field_date_openaccess_call[0]['raw']['value2'])), 'jrc_day'); ?></span>
    <span class="year"><?php print format_date(strtotime(check_plain($row->field_field_date_openaccess_call[0]['raw']['value2'])), 'jrc_year'); ?></span>
  </div>
<?php endif; ?>
</div>
