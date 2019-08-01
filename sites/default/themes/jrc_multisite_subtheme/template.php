<?php

/**
 * @file
 * Default theme functions.
 */

/**
 * Implements template_preprocess_node().
 */
function jrc_multisite_subtheme_preprocess_node(&$variables, $hook) {
  // For all content types.
  // On ApacheSolr pages.
  if ($variables['view_mode'] == 'apache_solr_mode') {
    if (isset($variables['field_image'][0]['field_file_image_thumbnail'][LANGUAGE_NONE][0]['filename']) &&
    trim($variables['field_image'][0]['field_file_image_thumbnail'][LANGUAGE_NONE][0]['filename']) != '') {
      // Replace field_image if thumbnail available.
      $variables['content']['field_image'][0]['#item'] = (array) file_load($variables['field_image'][0]['field_file_image_thumbnail'][LANGUAGE_NONE][0]['fid']);
    }
    elseif (isset($variables['field_big_image'][0]['field_file_image_thumbnail'][LANGUAGE_NONE][0]['filename']) &&
    trim($variables['field_big_image'][0]['field_file_image_thumbnail'][LANGUAGE_NONE][0]['filename']) != '') {
      // Replace the field_big_image if thumbnail available.
      $variables['content']['field_big_image'][0]['#item'] = (array) file_load($variables['field_big_image'][0]['field_file_image_thumbnail'][LANGUAGE_NONE][0]['fid']);
    }
    elseif (isset($variables['field_jrc_staff_image'][0]['field_file_image_thumbnail'][LANGUAGE_NONE][0]['filename']) &&
    trim($variables['field_jrc_staff_image'][0]['field_file_image_thumbnail'][LANGUAGE_NONE][0]['filename']) != '') {
      // Replace the field_jrc_staff_image if thumbnail available.
      $variables['content']['field_jrc_staff_image'][0]['#item'] = (array) file_load($variables['field_jrc_staff_image'][0]['field_file_image_thumbnail'][LANGUAGE_NONE][0]['fid']);
    }
    elseif (isset($variables['field_images'][0]['filename']) && trim($variables['field_images'][0]['filename']) != '') {
      // We have to replace all images by the first one for the ApacheSolr view.
      // So first we remove all images.
      foreach ($variables['content']['field_images'] as $key => $value) {
        if (is_numeric($key) && $key != "0") {
          unset($variables['content']['field_images'][$key]);
        }
      }
      // Then check if there is thumbnail in the first image.
      if (isset($variables['field_images'][0]['field_file_image_thumbnail'][LANGUAGE_NONE][0]['filename']) &&
          trim($variables['field_images'][0]['field_file_image_thumbnail'][LANGUAGE_NONE][0]['filename']) != '') {
        // Replace the field_big_image if thumbnail available.
        $variables['content']['field_images'][0]['#item'] = (array) file_load($variables['field_images'][0]['field_file_image_thumbnail'][LANGUAGE_NONE][0]['fid']);
      }
    }
  }
  else {
    // Then we proceed for other view_modes than ApacheSolr one.
    // On Image Galleries,.
    // If the Normal image exist,
    // Then show the Normal image instead of the ORIGINAL.
    if ($variables['type'] == 'image_gallery') {
      if (isset($variables['field_images']) && !empty($variables['field_images'])) {
        $image_links = array();
        foreach ($variables['field_images'] as $id => $image) {
          if (isset($variables['field_images'][$id]['field_file_image_normal'][LANGUAGE_NONE][0]['filename']) &&
          trim($variables['field_images'][$id]['field_file_image_normal'][LANGUAGE_NONE][0]['filename']) != '') {
            // Replace the image thumbnail on the Image Gallery page.
            $variables['content']['field_images'][$id]['#item'] = (array) file_load($variables['field_images'][$id]['field_file_image_normal'][LANGUAGE_NONE][0]['fid']);
            // But keep the ORIGINAL image for colorbox.
            $image_links[$id + 1] = file_create_url($variables['field_images'][$id]['uri']);
          }
        }
        // Add the JS variable for colorbox and add the related JS file.
        drupal_add_js(array('jrcMultisiteSubthemeSwapImageGalleryLinks' => array('colorboxImageGalleryOriginalLinks' => $image_links)), 'setting');
        drupal_add_js(drupal_get_path('theme', 'jrc_multisite_subtheme') . '/js/jrc_multisite_colorbox_image_gallery.js');
      }
    }
    // Then for ALL other node pages,
    // If the NORMAL image exist,
    // Then show the NORMAL image instead of the ORIGINAL.
    elseif (isset($variables['field_image'][0]['field_file_image_normal'][LANGUAGE_NONE][0]['filename']) &&
        trim($variables['field_image'][0]['field_file_image_normal'][LANGUAGE_NONE][0]['filename']) != '') {
      $image_link = '';
      // Replace the image thumbnail on the Node page.
      $variables['content']['field_image'][0]['#item'] = (array) file_load($variables['field_image'][0]['field_file_image_normal'][LANGUAGE_NONE][0]['fid']);
      // But keep the ORIGINAL image for colorbox.
      $image_link = file_create_url($variables['field_image'][0]['uri']);
      // Add the JS variable for colorbox and add the related JS file.
      drupal_add_js(array('jrcMultisiteSubthemeSwapNodeLinks' => array('colorboxNodeOriginalLink' => $image_link)), 'setting');
      drupal_add_js(drupal_get_path('theme', 'jrc_multisite_subtheme') . '/js/jrc_multisite_colorbox_node.js');
    }
  }
  // Change the image URLs to Files for all Publication nodes.
  if ($variables['type'] == 'publication') {
    if (count($variables['field_publication_files']) >= 1) {
      // Local file.
      $variables['content']['field_image'][0]['#path']['path'] = file_create_url($variables['field_publication_files'][0]['uri']);
    }
    elseif (isset($variables['field_pubsy_doc_links'][0]['value'])) {
      // Pubsy file.
      $variables['content']['field_image'][0]['#path']['path'] = $variables['field_pubsy_doc_links'][0]['value'];
    }
  }
  // Add specific JS files to specific sections of the website.
  if ($variables['type'] == 'page') {
    // For all "Migration and demography" subsite pages.
    // Or "Territorial policies" subsite pages.
    if ((drupal_substr($variables['path']['alias'], 0, drupal_strlen('migration-and-demography')) === 'migration-and-demography')
    || (drupal_substr($variables['path']['alias'], 0, drupal_strlen('territorial-policies')) === 'territorial-policies')) {
      drupal_add_js('https://visualise.jrc.ec.europa.eu/javascripts/api/viz_v1.js', 'external');
    }
    // For Commission priorities page (node/113257)
    elseif ($variables['path']['alias'] === "research/commission-priorities") {
      drupal_add_js(drupal_get_path('theme', 'jrc_multisite_subtheme') . '/js/specific/commission_priorities.js');
    }
    // For contact form page (node/68390)
    elseif ($variables['path']['alias'] === "contact/form") {
      drupal_add_js(drupal_get_path('theme', 'jrc_multisite_subtheme') . '/js/jrc_multisite_contact_form.js');
    }
  }
  // Add a js to Open access call pages.
  if ($variables['type'] == 'open_access_call') {
    drupal_add_js(drupal_get_path('theme', 'jrc_multisite_subtheme') . '/js/jrc_multisite_opencall.js');
  }
  return $variables;
}

/**
 * Implements template_preprocess_field().
 */
function jrc_multisite_subtheme_preprocess_field(&$variables) {
  global $base_url, $language;
  switch ($variables['element']['#field_name']) {
    case 'field_country_iso':
      $variables['items'][0]['#markup'] = "(" . $variables['element']['#items'][0]['value'] . ")";

      break;

    case 'field_dc_contributor_author':
      foreach ($variables['items'] as $delta => $item) {
        $author_name = htmlspecialchars_decode(strip_tags($item['#markup']), ENT_QUOTES);
        $id = _jrc_multisite_subtheme_get_author_id_by_name($author_name);
        if (!empty($id)) {
          $variables['items'][$delta]['#markup'] = l($author_name, 'node/' . $id);
        }
      }

      break;

    case 'field_dc_identifier_doi':
      // DOI base root.
      $doi_root = "http://dx.doi.org/";
      foreach ($variables['items'] as $delta => $item) {
        $links = preg_split("/[,;]|\)\s/i", $item['#markup']);
        foreach ($links as $link) {
          // Found a valid DOI ?
          if (preg_match("/[0-9\.\-\/a-z]+/i", $link, $matches)) {
            $doi[] = l($link, $doi_root . $matches[0]);
          }
          else {
            $doi[] = $link;
          }
        }
        $variables['items'][$delta]['#markup'] = implode("<br />", $doi);
      }

      break;

    case 'field_dc_identifier_uri':
      $html_to_render = '';
      $i = 0;
      foreach ($variables['items'] as $delta => $item) {
        foreach ($item as $link) {
          if (stripos($link, 'http://publications.jrc.ec.europa.eu/repository/handle/') === FALSE) {
            $decoded_link = htmlspecialchars_decode($link);
            if (strpos($decoded_link, 'http') === FALSE) {
              $decoded_link = 'http://' . $decoded_link;
            }
            $html_to_render .= '<a class="uri-link" href="' . $decoded_link . '">' . $decoded_link . '</a><br/>';
            $i++;
          }
        }
        unset($variables['items'][$delta]);
      }
      $variables['items'][0]['#markup'] = $html_to_render;

      break;

    case 'field_jrc_staff_image':
      $field = $variables['element']['#object']->field_jrc_staff_image[LANGUAGE_NONE][0];
    case 'field_image':
      if (!isset($field)) {
        $field = $variables['element']['#object']->field_image[LANGUAGE_NONE][0];
      }
      // Always prepare IMG tag formating.
      // Get the image Alt.
      $img_alt = isset($field['field_file_image_alt_text'][LANGUAGE_NONE][0]['value']) ? $field['field_file_image_alt_text'][LANGUAGE_NONE][0]['value'] : '';
      // Get the image Title.
      $img_title = isset($field['field_file_image_title_text'][LANGUAGE_NONE][0]['value']) ? $field['field_file_image_title_text'][LANGUAGE_NONE][0]['value'] : '';
      // If the image title is empty,.
      // And it's a publication content type,
      // Then set the default title for image title.
      if ($img_title == '' && $variables['element']['#bundle'] == 'publication') {
        if ($variables['element']['#view_mode'] == 'apache_solr_mode') {
          $img_title = $variables['element']['#object']->title;
        }
        else {
          $img_title = drupal_get_title();
        }
      }
      // If the image title isn't empty, then we send it to the template.
      if ($img_title != '') {
        $variables['items'][0]['img_title'] = $img_title;
      }
      $img_title = $variables['items'][0]['#item']['field_file_image_title_text']['en'][0]['safe_value'];
      $img_alt = $variables['items'][0]['#item']['field_file_image_alt_text']['en'][0]['safe_value'];
      $img_copyright = isset($field['field_file_copyright_info'][LANGUAGE_NONE][0]['value']) ? $field['field_file_copyright_info'][LANGUAGE_NONE][0]['value'] : '';
      // Remove copyright sign if present, template is doing this.
      $img_copyright = trim(preg_replace("/^(©|\&copy\;)/", "", $img_copyright));
      // If the image copyright is empty,.
      // And it's a publication content type,
      // Then set the EU value for image copyright.
      if ($img_copyright == '' && $variables['element']['#bundle'] == 'publication') {
        $img_copyright = "EU";
      }
      // If the image copyright isn't empty, then we send it to the template.
      if ($img_copyright != '') {
        $variables['items'][0]['img_copyright'] = $img_copyright;
      }
      // Update variables for template.
      $variables['items'][0]['#item']['title'] = $img_title;
      $variables['items'][0]['#item']['alt'] = $img_alt;

      break;

    case 'field_pubsy_doc_links':
      $path_to_theme = drupal_get_path('theme', $GLOBALS['theme']);
      $pdficon = '&nbsp;<img src="' . $base_url . '/' . $path_to_theme . '/images/f_pdf_16.gif" alt="file" height="16" width="16">';
      foreach ($variables['items'] as $delta => $item) {
        foreach ($item as $link) {
          $l = htmlspecialchars_decode($link);
          $t = urldecode(drupal_basename($l));
          if (drupal_strlen($t) < 1) {
            $t = $l;
          }
          $variables['items'][$delta]['#markup'] = l($t, $l, array('attributes' => array('class' => 'uri-link'))) . $pdficon . "<br />";
        }
      }

      break;

    case 'field_research_areas':
      foreach ($variables['items'] as $delta => $item) {
        $node = _jrc_multisite_subtheme_field_research_areas_node($item);
        foreach ($node as $nid => $content) {
          $variables['items'][$delta]['#href'] = $base_url . '/' . $language->language . '/' . drupal_get_path_alias('node/' . $nid);
        }
      }

      break;

    case 'field_research_topics':
      foreach ($variables['items'] as $delta => $item) {
        $node = _jrc_multisite_subtheme_field_research_topics_nodes($item);
        foreach ($node as $nid => $content) {
          $variables['items'][$delta]['#href'] = $base_url . '/' . $language->language . '/' . drupal_get_path_alias('node/' . $nid);
        }
      }

      break;

    case 'field_tags':
      foreach ($variables['items'] as $delta => $item) {
        $variables['items'][$delta]['#href'] = $base_url . '/' . $language->language . '/search/site?f' . urlencode('[0]') . '=im_field_tags:' . $item['#options']['entity']->tid;
      }

      break;

    case 'field_rm_an_documents':
      $variables = _jrc_multisite_subtheme_convert_into_multilangual_pdf($variables);

      break;

    case 'field_related_documents':
    case 'field_publication_files':
      $variables = _jrc_multisite_subtheme_convert_related_docs_and_publication_files_into_multilangual_pdf($variables);

      break;
  }
}

/**
 * Implements template_preprocess_page().
 */
function jrc_multisite_subtheme_preprocess_page(&$variables) {
  $title = drupal_get_title();
  $node = menu_get_object();
  // Format regions.
  $regions = array();
  $regions['header_right'] = (isset($variables['page']['header_right']) ? render($variables['page']['header_right']) : '');
  $regions['header_top'] = (isset($variables['page']['header_top']) ? render($variables['page']['header_top']) : '');
  $regions['featured'] = (isset($variables['page']['featured']) ? render($variables['page']['featured']) : '');
  $regions['sidebar_left'] = (isset($variables['page']['sidebar_left']) ? render($variables['page']['sidebar_left']) : '');
  $regions['tools'] = (isset($variables['page']['tools']) ? render($variables['page']['tools']) : '');
  $regions['content_top'] = (isset($variables['page']['content_top']) ? render($variables['page']['content_top']) : '');
  $regions['help'] = (isset($variables['page']['help']) ? render($variables['page']['help']) : '');
  $regions['content'] = (isset($variables['page']['content']) ? render($variables['page']['content']) : '');
  $regions['content_right'] = (isset($variables['page']['content_right']) ? render($variables['page']['content_right']) : '');
  $regions['content_bottom'] = (isset($variables['page']['content_bottom']) ? render($variables['page']['content_bottom']) : '');
  $regions['sidebar_right'] = (isset($variables['page']['sidebar_right']) ? render($variables['page']['sidebar_right']) : '');
  $regions['footer'] = (isset($variables['page']['footer']) ? render($variables['page']['footer']) : '');
  $regions['page_header'] = (isset($variables['page']['page_header']) ? render($variables['page']['page_header']) : '');
  $regions['landing_page_banner'] = (isset($variables['page']['landing_page_banner']) ? render($variables['page']['landing_page_banner']) : '');
  $regions['landing_page_banner_text'] = (isset($variables['page']['landing_page_banner_text']) ? render($variables['page']['landing_page_banner_text']) : '');
  // Check if there is a responsive sidebar or not.
  $has_responsive_sidebar = ($regions['header_right'] || $regions['sidebar_left'] || $regions['sidebar_right'] ? 1 : 0);
  // Calculate size of regions.
  $cols = array();
  // Sidebars.
  $cols['sidebar_left'] = array(
    'lg' => (!empty($regions['sidebar_left']) ? 3 : 0),
    'md' => (!empty($regions['sidebar_left']) ? 3 : 0),
    'sm' => 0,
    'xs' => 0,
  );
  $cols['sidebar_right'] = array(
    'lg' => (!empty($regions['sidebar_right']) ? 3 : 0),
    'md' => (!empty($regions['sidebar_right']) ? (!empty($regions['sidebar_left']) ? 3 : 3) : 0),
    'sm' => 0,
    'xs' => 0,
  );
  // Page header.
  $cols['page_header'] = array(
    'lg' => 12 - $cols['sidebar_left']['lg'],
    'md' => 12 - $cols['sidebar_left']['md'],
    'sm' => 12,
    'xs' => 12,
  );
  // Page header.
  $cols['landing_page_banner'] = array(
    'lg' => 12 - $cols['sidebar_left']['lg'],
    'md' => 12,
    'sm' => 12,
    'xs' => 12,
  );
  // Page header.
  $cols['landing_page_banner_text'] = array(
    'lg' => 12 - $cols['sidebar_left']['lg'],
    'md' => 12,
    'sm' => 12,
    'xs' => 12,
  );
  // Content.
  $cols['content_main'] = array(
    'lg' => 12 - $cols['sidebar_left']['lg'] - $cols['sidebar_right']['lg'],
    'md' => 12 - $cols['sidebar_right']['md'] - $cols['sidebar_left']['md'],
    'sm' => 12,
    'xs' => 12,
  );
  $cols['content_right'] = array(
    'lg' => (!empty($regions['content_right']) ? 6 : 0),
    'md' => (!empty($regions['content_right']) ? 6 : 0),
    'sm' => (!empty($regions['content_right']) ? 12 : 0),
    'xs' => (!empty($regions['content_right']) ? 12 : 0),
  );
  $cols['content'] = array(
    'lg' => 12 - $cols['content_right']['lg'],
    'md' => 12 - $cols['content_right']['md'],
    'sm' => 12,
    'xs' => 12,
  );
  // Tools.
  $cols['sidebar_button'] = array('sm' => ($has_responsive_sidebar ? 2 : 0), 'xs' => ($has_responsive_sidebar ? 2 : 0));
  $cols['tools'] = array(
    'lg' => (empty($title) ? 12 : 4),
    'md' => (empty($title) ? 12 : 4),
    'sm' => 12,
    'xs' => 12,
  );
  // Title.
  $cols['title'] = array(
    'lg' => 12 - $cols['tools']['lg'],
    'md' => 12 - $cols['tools']['md'],
    'sm' => 12,
    'xs' => 12,
  );
  // Add variables to template file.
  $variables['regions'] = $regions;
  $variables['cols'] = $cols;
  $variables['has_responsive_sidebar'] = $has_responsive_sidebar;
  $variables['menu_visible'] = FALSE;
  if (!empty($variables['page']['featured'])) {
    foreach ($variables['page']['featured'] as $key => $value) {
      if ($key == 'system_main-menu' ||
      strpos($key, 'om_maximenu') !== FALSE) {
        $variables['menu_visible'] = TRUE;
      }
    }
  }
  // Hide the node_export tab
  // It's breaking the theme and it's not useful for JRC website.
  // (Solution suggested by Digit).
  if (!empty($variables['tabs']['#primary'])) {
    foreach ($variables['tabs']['#primary'] as $tabnum => $tablink) {
      if ($tablink['#link']['title'] == 'Node export') {
        unset($variables['tabs']['#primary'][$tabnum]);
      }
    }
  }
  // Adding pathToTheme for Drupal.settings to be used in js files.
  $base_theme = multisite_drupal_toolbox_get_base_theme();
  drupal_add_js('jQuery.extend(Drupal.settings, { "pathToTheme": "' . drupal_get_path('theme', $base_theme) . '" });', 'inline');
  if ($node && $node->nid == 68390) {
    drupal_add_js('https://webtools.ec.europa.eu/captcha/js/captcha.js', external);
  }

  if (isset($variables['view_mode'])) {
    // Add css class "node--NODETYPE--VIEWMODE" to nodes.
    $variables['classes_array'][] = 'node--' . $variables['type'] . '--' . $variables['view_mode'];
    // Make "node--NODETYPE--VIEWMODE.tpl.php" templates available for nodes.
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];
  }
}

/**
 * Implements template_preprocess_views_view().
 */
function jrc_multisite_subtheme_preprocess_views_view(&$variables) {
  $view = $variables['view'];
  if ($view->name == 'jrc_glossary') {
    $result = $variables['view']->result;
    $alpha_rows = array();
    foreach ($result as $id => $row) {
      $l = trim($row->node_title);
      $l = drupal_strtoupper(drupal_substr($l, 0, 1));
      if (!isset($alpha_rows[$l])) {
        $alpha_rows[$l] = array();
      }
      $alpha_rows[$l][$id] = l($row->node_title, 'node/' . $row->nid);
    }
    $l = '';
    ksort($alpha_rows);
    $keys = array_keys($alpha_rows);
    foreach ($keys as $key) {
      $variables['header'] .= l($key, 'glossary#' . $key) . ' ';
    }
    $variables['header'] = urldecode($variables['header']);
    $variables['alpha_rows'] = $alpha_rows;
  }
  if ($view->name == 'jrc_carousel' && $view->current_display == 'block_1') {
    $tid = (int) arg(2);
    $term = taxonomy_term_load($tid);
    // Carousel colors.
    $institute_carousel_bg = '#' . $term->field_institute_carousel_bg[LANGUAGE_NONE][0]['jquery_colorpicker'];
    $institute_carousel_bullet = '#' . $term->field_institute_carousel_bullet[LANGUAGE_NONE][0]['jquery_colorpicker'];
    $variables['institute_carousel_bg'] = $institute_carousel_bg;
    $variables['institute_carousel_bullet'] = $institute_carousel_bullet;
  }
  if ($view->name == 'jrc_news' && $view->current_display == 'page_1') {
    $tid = (int) arg(2);
    $term = taxonomy_term_load($tid);
    // News colors.
    $field_institute_central_news_lab = '#' . $term->field_institute_central_news_lab[LANGUAGE_NONE][0]['jquery_colorpicker'];
    $field_institute_news_button = '#' . $term->field_institute_news_button[LANGUAGE_NONE][0]['jquery_colorpicker'];
    $variables['field_institute_central_news_lab'] = $field_institute_central_news_lab;
    $variables['field_institute_news_button'] = $field_institute_news_button;
  }
  if ($view->name == 'jrc_publication_k4p') {
    drupal_add_js(drupal_get_path('theme', 'jrc_multisite_subtheme') . '/js/jrc_multisite_publication_redirect.js');
  }
}

/**
 * Find a Pubsy author ID by its name.
 *
 * @param string $author_name
 *   Name of an author.
 *
 * @return string
 *   The entity_id of the related author name.
 */
function _jrc_multisite_subtheme_get_author_id_by_name($author_name) {
  $record = db_select('field_data_field_pubsy_author', 'f')->fields('f', array('entity_id'))->condition('field_pubsy_author_value', $author_name, '=')->execute()->fetchAssoc();
  $id = NULL;
  if (!empty($record)) {
    $id = $record['entity_id'];
  }
  return $id;
}

/**
 * Get Science Area pages related to their taxonomies.
 *
 * We load the respective res. area node
 * because we need to get it's nid
 * to generate the corresponding res. area page link.
 *
 * @param string $item
 *   All Science Area items.
 *
 * @return string
 *   Related Science Area page.
 */
function _jrc_multisite_subtheme_field_research_areas_node($item) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node', '=')->propertyCondition('type', 'research_area', '=')->fieldCondition('field_research_areas', 'tid', array($item['#options']['entity']->tid), 'IN');
  $result = $query->execute();
  $nodes = array();
  if (!empty($result['node'])) {
    $nodes = node_load_multiple(array_keys($result['node']));
  }
  return $nodes;
}

/**
 * Get Research topic pages related to their taxonomies.
 *
 * We load the respective res. topic node
 * because we need to get it's nid
 * to generate the corresponding res. topic page link.
 *
 * @param string $item
 *   All Science Topic items.
 *
 * @return string
 *   Related Science Topic pages.
 */
function _jrc_multisite_subtheme_field_research_topics_nodes($item) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node', '=')->propertyCondition('type', 'topic', '=')->propertyCondition('title', $item['#title'], '=');
  $result = $query->execute();
  $nodes = array();
  if (!empty($result['node'])) {
    $nodes = node_load_multiple(array_keys($result['node']));
  }
  return $nodes;
}

/**
 * Implements hook_menu_link().
 */
function jrc_multisite_subtheme_menu_link(array $variables) {
  // Add a class to menu links that link to unpublished nodes.
  $element = $variables['element'];
  $sub_menu = '';
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
    $sub_menu = str_replace('<ul class="', '<ul class="dropdown-menu ', $sub_menu);
  }
  if (preg_match('@^node/(\d+)$@', $element['#href'], $matches)) {
    $node = node_load((int) $matches[1]);
    if ($node && $node->status == NODE_NOT_PUBLISHED) {
      // There appear to be some inconsistency.
      // Sometimes the classes come through
      // As an array and sometimes as a string.
      if (empty($element['#localized_options']['attributes']['class'])) {
        $element['#localized_options']['attributes']['class'] = array();
      }
      elseif (is_string($element['#localized_options']['attributes']['class'])) {
        $element['#localized_options']['attributes']['class'] = explode(' ', $element['#localized_options']['attributes']['class']);
      }
      $element['#localized_options']['attributes']['class'][] = 'menu-node-unpublished';
    }
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  $output = html_entity_decode($output);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function jrc_multisite_subtheme_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
  // We still need to check.
  // If we're calling the right page of the "views exposed form" view.
  if ($form['#id'] == 'views-exposed-form-jrc-rss-feed-page-1') {
    $form['#action'] = 'rss.xml';
  }
}

/**
 * Convert a set of document files into one multilingual document.
 *
 * For the doc files attached to a content in different languague,
 * instead of having several links to several languages,
 * we only show the doc file in the current language and
 * the rest of the files we'll be shown in a popup box.
 * Attetion : This functionality is not the same than
 * Digit's feature set "Multisite multilingual references".
 * Se the ticket for more info : MULTISITE-12444.
 *
 * @param array $variables
 *   All field's Drupal variables.
 *
 * @return array
 *   All field's Drupal variables, plus new variables for the field's template.
 */
function _jrc_multisite_subtheme_convert_into_multilangual_pdf(array $variables) {
  global $language;
  $current_lang = $language->language;
  $pdf_array = array();
  $pdf_titles_array = array();
  $file_types = array();
  $file_sizes = array();
  // Go through all documents.
  foreach ($variables['items'] as $item) {
    $pdf = file_create_url($item['#file']->uri);
    $parts = explode('.', $pdf);
    $ext = end($parts);
    // Skip the file if url is not available.
    if (!isset($item['#file']->uri)) {
      continue;
    }
    // Get the language from the filename.
    $count = count($parts);
    if ($count >= 2) {
      $parts = explode('_', $parts[$count - 2]);
      $count = count($parts);
      if (($count >= 2) && (drupal_strlen($parts[$count - 1]) == 2)) {
        $lang = $parts[$count - 1];
      }
      else {
        $lang = 'en';
      }
    }
    else {
      $lang = 'en';
    }
    // In case a file in this language doesn't exist yet in the array.
    $pdf_array[$lang] = $pdf;
    // If the file is properly attached to a content,.
    // Then get the title from the content.
    if (isset($variables['element']['#object']->title)) {
      $pdf_titles_array[$lang] = $variables['element']['#object']->title;;
    }
    // Otherwise add the filename as title.
    else {
      $pdf_titles_array[$lang] = $item['#file']->filename;
    }
    $ext = explode('.', $pdf);
    $ext = end($ext);
    $file_types[$lang] = $ext;
    $file_sizes[$lang] = _jrc_multisite_subtheme_ec_size_convert($item['#file']->filesize);
  }
  // Sorting the pdf_array by key using case-insensitive string comparison.
  uksort($pdf_array, "strcasecmp");
  // We set EN as the default lang for files,.
  // If there's no file in the current lang.
  if (count($pdf_array) && !isset($pdf_array[$current_lang])) {
    $current_lang = 'en';
  }
  // Let's put the images values in a variable for theme_image().
  $popup_gif = array(
    'path' => path_to_theme() . '/images/popup.gif',
    'alt' => 'Choose translations of the previous link',
    'title' => 'Choose translations of the previous link',
    'width' => '16px',
    'height' => '13px',
    'attributes' => array('class' => 'popup-gif'),
  );
  $doc_gif = array(
    'path' => path_to_theme() . '/images/doc_icons/f_' . $file_types[$current_lang] . '_16.gif',
    'alt' => 'Choose translations of the previous link',
    'title' => 'Choose translations of the previous link',
    'width' => '16px',
    'height' => '16px',
    'attributes' => array('class' => 'pdf-gif'),
  );
  // Send variables to the template.
  $variables['current_lang'] = $current_lang;
  $variables['pdf_titles_array'] = $pdf_titles_array;
  $variables['file_types'] = $file_types;
  $variables['file_sizes'] = $file_sizes;
  $variables['pdf_array'] = $pdf_array;
  $variables['popup_gif'] = $popup_gif;
  $variables['doc_gif'] = $doc_gif;
  return $variables;
}

/**
 * Convert the related document files into one multilingual document.
 *
 * For the doc files attached to a content in different languague,
 * instead of having several links to several languages,
 * we only show the doc file in the current language and
 * the rest of the files we'll be shown in a popup box.
 * Attetion : This functionality is not the same than
 * Digit's feature set "Multisite multilingual references".
 * Se the ticket for more info : MULTISITE-12444.
 *
 * @param array $variables
 *   All field's Drupal variables.
 *
 * @return array
 *   All field's Drupal variables, plus new variables for the field's template.
 */
function _jrc_multisite_subtheme_convert_related_docs_and_publication_files_into_multilangual_pdf(array $variables) {
  global $language;
  $current_lang = $language->language;
  $pdf_links_array = array();
  $pdf_titles_array = array();
  $file_types = array();
  $file_sizes = array();
  // Go through all documents.
  foreach ($variables['items'] as $item) {
    $filename = $item['#file']->filename;
    $parts = explode('.', $filename);
    $ext = end($parts);
    // Skip the file if url is not available.
    if (!isset($item['#file']->uri)) {
      continue;
    }
    $lang = 'en';
    $count = count($parts);
    // Check if the file is a valid file and has an extention.
    if ($count >= 2) {
      preg_match('/^(.*?)(_([a-z]{2}))?\.[a-z]+$/', $filename, $filename_parts);
      // Get the language from the file, if any.
      if (isset($filename_parts[3]) && (drupal_strlen($filename_parts[3]) == 2)) {
        $lang = $filename_parts[3];
      }
    }
    // In case a file in this language doesn't exist yet in the array.
    $pdf_links_array[$filename_parts[1]][$lang] = file_create_url($item['#file']->uri);
    $pdf_titles_array[$filename_parts[1]][$lang] = $item['#file']->title;
    $file_types[$filename_parts[1]][$lang] = $ext;
    $file_sizes[$filename_parts[1]][$lang] = _jrc_multisite_subtheme_ec_size_convert($item['#file']->filesize);
    // Let's put the document images values in a variable for theme_image().
    $doc_gif[$filename_parts[1]][$lang] = array(
      'path' => path_to_theme() . '/images/doc_icons/f_' . $file_types[$filename_parts[1]][$lang] . '_16.gif',
      'alt' => 'Choose translations of the previous link',
      'title' => 'Choose translations of the previous link',
      'width' => '16px',
      'height' => '16px',
      'attributes' => array('class' => 'pdf-gif'),
    );
  }
  // Sorting the pdf_array by key using case-insensitive string comparison.
  uksort($pdf_links_array, "strcasecmp");
  // Let's put the popup images values in a variable for theme_image().
  $popup_gif = array(
    'path' => path_to_theme() . '/images/popup.gif',
    'alt' => 'Choose translations of the previous link',
    'title' => 'Choose translations of the previous link',
    'width' => '16px',
    'height' => '13px',
    'attributes' => array('class' => 'popup-gif'),
  );
  // Send variables to the template.
  $variables['current_lang'] = $current_lang;
  $variables['pdf_titles_array'] = $pdf_titles_array;
  $variables['pdf_links_array'] = $pdf_links_array;
  $variables['file_types'] = $file_types;
  $variables['file_sizes'] = $file_sizes;
  $variables['popup_gif'] = $popup_gif;
  $variables['doc_gif'] = $doc_gif;
  return $variables;
}

/**
 * Correctly display file sizes.
 */
function _jrc_multisite_subtheme_ec_size_convert($bytes) {
  if ($bytes > 0) {
    $unit = intval(log($bytes, 1024));
    $units = array('B', 'KB', 'MB', 'GB');
    if (array_key_exists($unit, $units) === TRUE) {
      return sprintf('%d %s', $bytes / pow(1024, $unit), $units[$unit]);
    }
  }
  return $bytes;
}

/**
 * For sorting the files array correctly.
 */
function _jrc_multisite_subtheme_ec_lang_code_cmp_4($a, $b) {
  global $language;
  $current_lang = $language->language;
  if ($a == $current_lang) {
    return -1;
  }
  if ($b == $current_lang) {
    return 1;
  }
  return strcasecmp($a, $b);
}
