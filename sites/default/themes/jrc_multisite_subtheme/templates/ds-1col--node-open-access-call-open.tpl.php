<?php

/**
 * @file
 * Display Suite 1 column template with custom layout wrapper .
 *
 * A custom display type based on display suite template
 * with custom fields for Content type OpenAccess Calls.
 */
?>

<h1 class="title-page"><?php print $title; ?></h1>

<?php if(isset($variables['content']['field_openaccess_banner'])): ?>
  <?php $file_path = $variables['content']['field_openaccess_banner']['#items'][0]['uri']; ?>
  <?php $image_url = image_style_url('banner_home_page', $file_path); ?>
  <?php print '<img src="' . $image_url . '" class="opencall-banner" />'; ?>
<?php endif; ?>

<?php if ($variables['content']['field_openaccess_call_mode']['#items'][0]['value'] != 'MA') : ?>
  <div class="date">
    <?php $time = $variables['field_date_openaccess_call_open'][0]['value']; ?>
    <?php $time2 = $variables['field_date_openacces_call_closed'][0]['value']; ?>

    <?php if (isset($time2)&& $time != $time2) : ?>
      <div class="date-cont start-date-with-end">
    <?php else : ?>
      <div class="date-cont start-date-without-end">
    <?php
    endif; ?>

    <?php if (isset($time) && !empty($time)) : ?>
        <span class="month"><?php print format_date(strtotime($time), 'jrc_month'); ?></span>
        <span class="day"><?php print format_date(strtotime($time), 'jrc_day'); ?></span>
        <span class="year"><?php print format_date(strtotime($time), 'jrc_year'); ?></span>
      </div>
    <?php endif; ?>

    <?php if (isset($time2) && $time != $time2) : ?>
      <div class="event-dates-arrow"></div>
      <div class="date-cont end-date">
        <span class="month"><?php print format_date(strtotime($time2), 'jrc_month'); ?></span>
        <span class="day"><?php print format_date(strtotime($time2), 'jrc_day'); ?></span>
        <span class="year"><?php print format_date(strtotime($time2), 'jrc_year'); ?></span>
      </div>
    <?php endif; ?>
  </div>
<?php endif; ?>
<?php print render($body[0]['summary']); ?>

<div class="open-access">
    <div class="blue-gradient-border info-box" style="">
      <h2><?php print render($content['field_openaccess_facility']); ?></h2>
        <ul>
            <li>Mode: <strong> <a href="http://ec.europa.eu/jrc/en/research-facility/open-access"><?php print render($content['field_openaccess_call_mode']); ?></a> </strong></li>
            <li>Identifier: <strong><?php print render($content['field_openaccess_identifier']); ?></strong></li>
            <li>Location: <strong> <a href="<?php print render($content['field_openaccess_link_location'][0]['#element']['url']); ?>" > <?php print render($content['field_openaccess_link_location']); ?></a> </strong></li>
            <?php if ($variables['content']['field_openaccess_call_mode']['#items'][0]['value'] != 'MA') : ?>
              <li>Opening of the call: <strong><?php print render($content['field_date_openaccess_call_open']); ?></strong></li>
              <li>Closure of the call: <strong><?php print render($content['field_date_openacces_call_closed']); ?></strong></li>
              <li>Communication of the assessment of proposals: <strong><?php print render($content['field_date_openaccess_assessment']); ?></strong></li>
            <?php endif; ?>
            <?php if ($variables['content']['field_openaccess_call_mode']['#items'][0]['value'] == 'MA') : ?>
              <li>Opening of the call: <strong>continuous</strong></li>
            <?php endif; ?>
            <li class="button"><a href="#apply">Make a proposal</a></li>
        </ul>
    </div>
</div>

<?php print render($content['body']); ?>
<?php print render($content['field_openaccess_call_apply']); ?>
