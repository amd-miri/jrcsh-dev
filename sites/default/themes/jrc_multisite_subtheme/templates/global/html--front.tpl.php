<?php

/**
 * @file
 * Default theme implementation of main page.
 */
?>
<!DOCTYPE html>
<html lang="<?php print (isset($language) ? $language->language : '') ?>">
<head>
  <meta name="google-site-verification" content="6hqpA1DBVfEE0rVkqVAde0YHOiJVLNaT10I_HYor-wM" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lt IE 9]>
    <script src="<?php print url(drupal_get_path('theme', 'ec_resp') . '/scripts/html5shiv.min.js', array('language' => (object) array('language' => FALSE))); ?>"></script>
    <script src="<?php print url(drupal_get_path('theme', 'ec_resp') . '/scripts/respond.min.js', array('language' => (object) array('language' => FALSE))); ?>"></script>
  <![endif]--> 
  <?php print $scripts; ?>
  <script src="//ec.europa.eu/wel/cookie-consent/consent.js" type="text/javascript"></script>
  <script src="//ec.europa.eu/wel/surveys/wr_survey01/wr_survey.js" type="text/javascript"></script>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>
