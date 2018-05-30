<?php

/**
 * @file
 * Adding BEM related custom field formatters.
 */

/**
 * Helper function to get the available view modes.
 *
 * @return array
 *   Array of items that can use the formatter.
 */
function _nexteuropa_formatters_get_listing_view_modes() {
  $items = [
    'title',
    'meta',
    'teaser',
    'image_label',
  ];

  drupal_alter('nexteuropa_formatters_view_modes', $items);

  return $items;
}

/**
 * Implements hook_field_formatter_info().
 */
function nexteuropa_formatters_field_formatter_info() {
  return [
    'context_nav_item' => [
      'label' => t('NE: Context nav item'),
      'field types' => [
        'text',
        'entityreference',
        'link_field',
        'datetime',
        'date',
        'datestamp',
        'taxonomy_term_reference',
      ],
      'settings' => [
        'expander_has_expander' => FALSE,
        'expander_trim_at' => 0,
        'expander_trim_to' => 0,
        'contextual_date' => '',
      ],
    ],
    'nexteuropa_tags' => [
      'label' => t('NE: Tags'),
      'field types' => [
        'taxonomy_term_reference',
        'entityreference',
        'link_field',
      ],
    ],
    'link_button_default' => [
      'label' => t('NE: Link button default'),
      'field types' => [
        'link_field',
        'taxonomy_term_reference',
        'entityreference',
      ],
      'settings' => [
        'link_title' => '',
        'force_language_default' => 0,
        'align_right' => 0,
      ],
    ],
    'link_button_download' => [
      'label' => t('NE: Download button'),
      'field types' => [
        'link_field',
        'file',
      ],
      'settings' => [
        'show_translations' => TRUE,
      ],
    ],
    'link_download' => [
      'label' => t('NE: Download file-link'),
      'field types' => [
        'link_field',
      ],
      'settings' => [
        'show_translations' => TRUE,
      ],
    ],
    'link_button_primary' => [
      'label' => t('NE: Link button primary'),
      'field types' => [
        'link_field',
        'taxonomy_term_reference',
      ],
      'settings' => [
        'align_right' => 0,
      ],
    ],
    'link_button_secondary' => [
      'label' => t('NE: Link button secondary'),
      'field types' => [
        'link_field',
        'taxonomy_term_reference',
      ],
      'settings' => [
        'align_right' => 0,
      ],
    ],
    'link_button_call_for_action' => [
      'label' => t('NE: Link button call for action'),
      'field types' => [
        'link_field',
        'taxonomy_term_reference',
      ],
      'settings' => [
        'align_right' => 0,
      ],
    ],
    'link_button_block' => [
      'label' => t('NE: Link button block'),
      'field types' => [
        'link_field',
        'taxonomy_term_reference',
      ],
      'settings' => [
        'align_right' => 0,
      ],
    ],
    'link_button_two_column' => [
      'label' => t('NE: Link button two column'),
      'field types' => [
        'link_field',
      ],
    ],
    'link_listing_title' => [
      'label' => t('NE: Listing title link'),
      'field types' => [
        'link_field',
        'text',
        'taxonomy_term_reference',
      ],
      'settings' => [
        'modifier' => '',
      ],
    ],
    'listing_title_with_link' => [
      'label' => t('NE: (h3) Listing title: with link'),
      'field types' => ['text', 'text_long'],
    ],
    'listing_title' => [
      'label' => t('NE: (h3) Listing title: no link'),
      'field types' => ['text', 'text_long'],
    ],
    'listing_title_element' => [
      'label' => t('NE: Listing title element'),
      'field types' => ['text'],
    ],
    'entity_reference_section' => [
      'label' => t('NE: Entity reference section group'),
      'field types' => [
        'entityreference',
      ],
      'settings' => [
        'use_content_language' => TRUE,
        'view_mode' => 'default',
        'links' => TRUE,
      ],
    ],
    'telephone' => [
      'label' => t('NE: Telephone link'),
      'field types' => ['text'],
    ],
    'text_number' => [
      'label' => t('NE: Text as number'),
      'field types' => ['text'],
      'settings' => [
        'suffix' => '',
      ],
    ],
    'label' => [
      'label' => t('NE: Label'),
      'field types' => [
        'text',
        'list_float',
        'list_integer',
        'list_text',
      ],
      'settings' => [
        'label_modifiers' => '',
      ],
    ],
    'feedback_counter' => [
      'label' => t('NE: Feedback counter'),
      'field types' => [
        'number_integer',
        'number_decimal',
        'number_float',
      ],
    ],
    'collapsed_term' => [
      'label' => t('NE: Collapsed term (displays taxonomy term description in a collapsible way)'),
      'field types' => [
        'taxonomy_term_reference',
      ],
    ],
    'bold_last' => [
      'label' => t('NE: Bold last word'),
      'field types' => [
        'taxonomy_term_reference',
        'text',
      ],
    ],
    'structured_content_links' => [
      'label' => t('NE: Structured content links'),
      'field types' => [
        'entityreference',
        'link_field',
      ],
    ],
  ];
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function nexteuropa_formatters_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = [];

  switch ($display['type']) {
    case 'context_nav_item':
      $element['expander_has_expander'] = [
        '#title' => t('NE: Has expander'),
        '#type' => 'checkbox',
        '#size' => 1,
        '#default_value' => $settings['expander_has_expander'],
      ];
      $element['expander_trim_at'] = [
        '#title' => t('NE: Trim at'),
        '#type' => 'textfield',
        '#size' => 2,
        '#default_value' => $settings['expander_trim_at'],
        '#element_validate' => ['element_validate_integer'],
      ];
      $element['expander_trim_to'] = [
        '#title' => t('NE: Trim to'),
        '#type' => 'textfield',
        '#size' => 2,
        '#default_value' => $settings['expander_trim_to'],
        '#element_validate' => ['element_validate_integer'],
      ];
      break;

    case 'link_button_default':
      if ($field['type'] == 'entityreference') {
        $element['link_title'] = [
          '#title' => t('NE: Title'),
          '#type' => 'textfield',
          '#default_value' => $settings['link_title'],
        ];
        $element['force_language_default'] = [
          '#title' => t('NE: Force the link to point to the default language.'),
          '#type' => 'checkbox',
          '#default_value' => $settings['force_language_default'],
        ];
      }
      $element['align_right'] = [
        '#title' => t('NE: Align the button to the right side of the page.'),
        '#type' => 'checkbox',
        '#size' => 1,
        '#default_value' => $settings['align_right'],
      ];
      break;

    case 'link_button_download':
    case 'link_download':
      $element['show_translations'] = [
        '#title' => t('NE: Show translations of the file'),
        '#type' => 'checkbox',
        '#size' => 1,
        '#default_value' => $settings['show_translations'],
      ];
      break;

    case 'link_button_primary':
    case 'link_button_secondary':
    case 'link_button_call_for_action':
    case 'link_button_block':
      $element['align_right'] = [
        '#title' => t('NE: Align the button to the right side of the page.'),
        '#type' => 'checkbox',
        '#size' => 1,
        '#default_value' => $settings['align_right'],
      ];
      break;

    case 'context_nav_item':
      if ($field['type'] == 'datetime') {
        module_load_include('inc', 'date', 'date_admin');
        $element[] = date_default_formatter_settings_form($field, $instance, $view_mode, $form, $form_state);
      }
      break;

    case 'entity_reference_section':
      $element['use_content_language'] = [
        '#title' => t('NE: Use the content language for referenced items.'),
        '#type' => 'checkbox',
        '#default_value' => $settings['use_content_language'],
      ];
      break;

    case 'text_number':
      $element['suffix'] = [
        '#title' => t('NE: Suffix'),
        '#type' => 'textfield',
        '#size' => 2,
        '#default_value' => '',
      ];
      break;

    case 'label':
      $element['label_modifiers'] = [
        '#title' => t('NE: Modifiers'),
        '#type' => 'textfield',
        '#description' => t('Separate multiple modifiers with commas'),
        '#default_value' => $settings['label_modifiers'],
      ];
      break;

    case 'link_listing_title':
      $element['modifier'] = [
        '#title' => t('NE: Modifier'),
        '#type' => 'select',
        '#description' => t('NE: Select the modifier'),
        '#options' => [
          '' => t('NE: None'),
          'two-columns' => t('NE: Two columns'),
        ],
        '#default_value' => $settings['modifier'],
      ];
      break;
  }

  return $element;
}

/**
 * Helper function to select the right class.
 *
 * @param string $formatter
 *   Formatter name.
 *
 * @return string Class connected to formatter.
 *   Class connected to formatter.
 */
function _nexteuropa_formatters_field_formatter_view_classes($formatter) {
  $class = '';
  switch ($formatter) {
    case 'link_button_default':
      $class = 'btn btn-default';
      break;

    case 'link_button_primary':
      $class = 'btn btn-primary';
      break;

    case 'link_button_secondary':
      $class = 'btn btn-secondary';
      break;

    case 'link_button_call_for_action':
      $class = 'btn btn-ctn';
      break;

    case 'link_button_block':
      $class = 'btn btn-default btn-block';
      break;

    case 'link_button_two_column':
      $class = 'btn btn-default';
      break;

    case 'label':
      $class = 'label';
      break;

    case 'feedback_counter':
      $class = 'icon--feedback icon--text-small';
      break;

    case 'link_listing_title':
    case 'listing_title':
    case 'listing_title_element':
    case 'listing_title_element':
    case 'listing_title_with_link':
      $class = 'listing__title';
      break;

    case 'entity_reference_section':
      $class = 'section__item';
      break;
  }

  return $class;
}

/**
 * Implements hook_field_formatter_prepare_view().
 */
function nexteuropa_formatters_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays) {
  if ($field['type'] == 'entityreference') {
    $target_ids = [];

    // Collect every possible entity attached to any of the entities.
    foreach ($entities as $id => $entity) {
      foreach ($items[$id] as $delta => $item) {
        if (isset($item['target_id'])) {
          $target_ids[] = $item['target_id'];
        }
      }
    }

    if ($target_ids) {
      $target_entities = entity_load($field['settings']['target_type'], $target_ids);
    }
    else {
      $target_entities = [];
    }

    // Iterate through the fieldable entities again to attach the loaded data.
    foreach ($entities as $id => $entity) {
      $rekey = FALSE;

      foreach ($items[$id] as $delta => $item) {
        // Check whether the referenced entity could be loaded.
        if (isset($target_entities[$item['target_id']])) {
          // Replace the instance value with the term data.
          $items[$id][$delta]['entity'] = $target_entities[$item['target_id']];
          // Check whether the user has access to the referenced entity.
          $has_view_access = (entity_access('view', $field['settings']['target_type'], $target_entities[$item['target_id']]) !== FALSE);
          $has_update_access = (entity_access('update', $field['settings']['target_type'], $target_entities[$item['target_id']]) !== FALSE);
          $items[$id][$delta]['access'] = ($has_view_access || $has_update_access);
        }
        // Otherwise, unset the instance value, since the entity does not exist.
        else {
          unset($items[$id][$delta]);
          $rekey = TRUE;
        }
      }

      if ($rekey) {
        // Rekey the items array.
        $items[$id] = array_values($items[$id]);
      }
    }
  }
}

/**
 * Implements hook_field_formatter_view().
 */
function nexteuropa_formatters_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = [];

  if (!empty($items)) {
    $formatter = $display['type'];
    $pull_right = !empty($display['settings']['align_right']) ? ' pull-right' : '';
    $entity_uri = entity_uri($entity_type, $entity);
    $entity_path = url($entity_uri['path']);

    switch ($formatter) {
      // Formatter for the structured content view mode.
      case 'structured_content_links':

        // Default link config.
        $options = [
          'attributes' => [
            'class' => [
              'listing__title',
            ],
          ],
        ];

        // Default render array.
        $render_array = [
          '#prefix' => '<li class="listing__item">',
          '#suffix' => '</li>',
        ];

        switch ($field['type']) {
          case 'entityreference':
            $handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);
            foreach ($items as $delta => $item) {
              if ($item['access']) {
                // Check if it is a legacy link.
                $uri = entity_uri($field['settings']['target_type'], $item['entity']);
                $link_url = isset($item['entity']->legacy) ? $item['entity']->legacy : $uri['path'];
                // Add the default options.
                $uri['options'] += $options;
                // Format the link.
                $render_array['#markup'] = l($handler->getLabel($item['entity']), $link_url, $uri['options']);
                // Add the render array to the element.
                $element[$delta] = $render_array;
              }
            }
            break;

          case 'link_field':
            foreach ($items as $delta => $item) {
              // Merge the default options with the item attributes.
              $options['attributes'] += $item['attributes'];
              // Build the link and add it to the render array.
              $render_array['#markup'] = l($item['title'], $item['url'], $options);
              // Add the render array to the element.
              $element[$delta] = $render_array;
            }
            break;
        }
        break;

      case 'context_nav_item':
        $layout_field_settings = ds_get_field_settings($entity_type, $entity->type, 'full');
        $field_name = $field['field_name'];
        if (isset($layout_field_settings[$field_name]['formatter_settings']['ft']['lb'])) {
          // @codingStandardsIgnoreLine
          $label_altered = t($layout_field_settings[$field_name]['formatter_settings']['ft']['lb']);
        }
        //@codingStandardsIgnoreLine
        $wrapper_label = isset($label_altered) ? $label_altered : t($instance['label']);

        // Apply custom label to the element.
        $element = array_merge(
          $element,
          _nexteuropa_formatters_get_context_nav_wrapper(
            $wrapper_label,
            isset($display['settings']['expander_has_expander']) ? $display['settings']['expander_has_expander'] : FALSE,
            isset($display['settings']['expander_trim_at']) ? $display['settings']['expander_trim_at'] : FALSE,
            isset($display['settings']['expander_trim_to']) ? $display['settings']['expander_trim_to'] : FALSE
          )
        );

        switch ($field['type']) {
          case 'entityreference':
            $handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);
            foreach ($items as $delta => $item) {
              if ($label = $handler->getLabel($item['entity'])) {
                if ($uri = entity_uri($field['settings']['target_type'], $item['entity'])) {
                  $link_url = isset($item['entity']->legacy) ? $item['entity']->legacy : $uri['path'];
                  $link = l($label, $link_url, $uri['options']);
                  $element[$delta] = [
                    '#prefix' => '<span class="context-nav__item">',
                    '#markup' => $link,
                    '#suffix' => '</span>',
                  ];
                }
                else {
                  $element[$delta] = ['#markup' => check_plain($label)];
                }
              }
            }
            break;

          case 'taxonomy_term_reference':
            $terms = taxonomy_term_load_multiple($items);
            foreach ($terms as $delta => $item) {
              $element[$delta] = [
                '#markup' => '<span class="context-nav__item">' . $item->name . '</span>',
              ];
            }
            break;

          case 'link_field':
            foreach ($items as $delta => $item) {
              $link = l($item['title'], $item['url'], ['attributes' => $item['attributes']]);
              $element[$delta] = [
                '#markup' => '<span class="context-nav__item">' . $link . '</span>',
              ];
            }
            // End of context_nav_item.
            break;

          case 'text':
            foreach ($items as $delta => $item) {
              $element[$delta] = [
                '#markup' => '<span class="context-nav__item">' . $item['safe_value'] . '</span>',
              ];
            }
            break;

          case 'date':
          case 'datestamp':
          case 'datetime':
            // @TODO: Make date format flexible based on formatter options.
            foreach ($items as $delta => $item) {
              $node_wrapper = entity_metadata_wrapper('node', $entity);
              $date = format_date($item['value'], 'ec_date_j_f_y');

              if ($node_wrapper->__isset('field_core_date_updated') && $date_updated = $node_wrapper->field_core_date_updated->value()) {
                $last_update_text = t('(last update on: @date)', ['@date' => format_date($date_updated, 'ec_date_j_f_y')]);
                $element[$delta] = [
                  '#markup' => '<span class="context-nav__item">' . $date . ' ' . $last_update_text . '</span>',
                ];
              }
              else {
                $element[$delta] = [
                  '#markup' => '<span class="context-nav__item">' . $date . '</span>',
                ];
              }
            }
            break;
        }
        break;

      case 'nexteuropa_tags':
        switch ($field['type']) {

          case 'taxonomy_term_reference':
            foreach ($items as $delta => $item) {
              $term = taxonomy_term_load($item['tid']);
              $link_url = isset($term->legacy) ? $term->legacy : url('taxonomy/term/' . $item['tid']);
              $element[$delta] = _nexteuropa_formatters_tags_item_link($term->name, $link_url);
            }
            break;

          case 'entityreference':
            $handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);
            foreach ($items as $delta => $item) {
              if ($label = $handler->getLabel($item['entity'])) {
                if ($uri = entity_uri($field['settings']['target_type'], $item['entity'])) {
                  $link_url = isset($item['entity']->legacy) ? $item['entity']->legacy : $uri['path'];
                  $element[$delta] = _nexteuropa_formatters_tags_item_link($label, $link_url);
                }
                else {
                  $element[$delta] = ['#markup' => check_plain($label)];
                }
              }
            }
            break;

          case 'link_field':
            foreach ($items as $delta => $item) {
              $element[$delta] = _nexteuropa_formatters_tags_item_link($item['title'], $item['url']);
            }
            break;
        }
        break;

      case 'telephone':
        foreach ($items as $delta => $item) {
          // Label to display.
          $label = isset($instance['label']) ? $instance['label'] : '';
          // Make the phone value a link, if possible.
          $telf = _nexteuropa_theme_functions_phonetohtml($label, $item['safe_value']);
          $element[$delta] = [
            '#markup' => $telf,
          ];
        }
        break;

      case 'text_number':
        foreach ($items as $delta => $item) {
          $element[$delta] = [
            '#markup' => number_format($item['safe_value'], 0, ".", ",") . $display['settings']['suffix'],
          ];
        }
        break;

      case 'label':
        foreach ($items as $delta => $item) {
          $user_modifiers = $display['settings']['label_modifiers'];
          $classes = _nexteuropa_formatters_field_formatter_view_classes($formatter);

          if (!empty($user_modifiers)) {
            if (strpos($user_modifiers, ',')) {
              $modifiers = explode(',', $user_modifiers);

              foreach ($modifiers as $modifier) {
                $classes .= ' label--' . check_plain(trim($modifier));
              }
            }
            else {
              $classes .= $user_modifiers != '' ? ' label--' . check_plain($user_modifiers) : '';
            }
          }

          $element[$delta] = [
            '#markup' => '<span class="' . $classes . '">' . $item['value'] . '</span>',
          ];
        }
        break;

      case 'collapsed_term':
        $term = i18n_taxonomy_localize_terms(taxonomy_term_load($items[0]['tid']));
        $format = $term->format ? $term->format : 'full_html';
        $element[0] = [
          '#markup' => '<a data-toggle="collapse" data-target="#' . drupal_clean_css_identifier($term->name) . '">' . $term->name . ' <span class="icon icon--down"></span></a>
            <div id="' . drupal_clean_css_identifier($term->name) . '" class="collapse">' . check_markup($term->description, $format) . '</div>',
        ];
        break;

      case 'listing_title':
        $class = _nexteuropa_formatters_field_formatter_view_classes($formatter);
        foreach ($items as $delta => $item) {
          $element[$delta] = [
            '#markup' => '<h3 class="' . $class . '">' . $item['value'] . '</h3>',
          ];
        }
        break;

      case 'listing_title_with_link':
        $class = _nexteuropa_formatters_field_formatter_view_classes($formatter);

        foreach ($items as $delta => $item) {
          $link = l($item['value'], $entity_path);
          $element[$delta] = [
            '#markup' => '<h3 class="' . $class . '">' . $link . '</h3>',
          ];
        }
        break;

      case 'listing_title_element':
        $class = _nexteuropa_formatters_field_formatter_view_classes($formatter);

        foreach ($items as $delta => $item) {
          $link = l($item['value'], $entity_path, ['attributes' => ['class' => $class]]);

          $element[$delta] = [
            '#markup' => $link,
          ];
        }
        break;

      case 'feedback_counter':
        $class = _nexteuropa_formatters_field_formatter_view_classes($formatter);
        foreach ($items as $delta => $item) {
          if ($item['value'] > 0) {
            $element[$delta] = [
              '#prefix' => '<span class="icon ' . $class . '">',
              '#markup' => t('Feedback (!item_value)', ['!item_value' => $item['value']]),
              '#suffix' => '</span>',
            ];
          }
        }
        break;

      case 'link_button_download':
      case 'link_download':
        if (isset($field['type']) && $field['type'] == 'file') {
          foreach ($items as $delta => $item) {
            $file = (object) $item;
            $file->entity = $entity;
            $element[$delta] = [
              '#markup' => _nexteuropa_formatters_file_markup($file),
            ];
          }
        }
        elseif (isset($field['type']) && $field['type'] == 'link_field') {
          foreach ($items as $delta => $item) {
            // Emulate the file array.
            $file = new stdClass();
            $file->type = 'document';
            $file->uri = $item['url'];
            $file->filename = $item['title'];
            $file->entity = $entity;

            $url = [];
            $url['path'] = $item['url'];
            $url['options'] = [];

            // Add modifier.
            $modifier = ($formatter == "link_download" ? "file--link" : "");
            drupal_alter('nexteuropa_formatters_modifier', $modifier, $entity_type, $entity);

            $element[$delta] = [
              '#markup' => _nexteuropa_formatters_file_markup($file, $modifier, FALSE, TRUE, $url),
            ];
          }
        }
        break;

      case 'link_button_default':
      case 'link_button_primary':
      case 'link_button_secondary':
      case 'link_button_call_for_action':
      case 'link_button_two_column':
      case 'link_button_block':
        switch ($field['type']) {
          case 'link_field':
            foreach ($items as $delta => $item) {
              // Set attribute from formatter settings.
              $item['attributes']['class'] = _nexteuropa_formatters_field_formatter_view_classes($formatter) . $pull_right;

              // Call theme function of link module
              // (theme_link_formatter_link_default).
              $element[$delta] = [
                '#theme' => 'link_formatter_link_default',
                '#element' => $item,
                '#field' => $instance,
                '#display' => $display,
              ];
            }
            break;

          case 'taxonomy_term_reference':
            foreach ($items as $delta => $item) {
              $term = taxonomy_term_load($item['tid']);
              $link = isset($term->legacy) ? $term->legacy : url('taxonomy/term/' . $item['tid']);

              $element[$delta] = [
                '#type' => 'link',
                '#title' => $term->name,
                '#href' => $link,
                '#options' => [
                  'attributes' => [
                    'class' => _nexteuropa_formatters_field_formatter_view_classes($formatter) . $pull_right,
                  ],
                ],
              ];
            }
            break;

          case 'entityreference':
            $lang = language_default();
            $settings = $display['settings'];
            foreach ($items as $delta => $item) {
              // Classes.
              $classes = _nexteuropa_formatters_field_formatter_view_classes($formatter) . $pull_right;
              // @codingStandardsIgnoreLine.
              $label = $settings['link_title'] != '' ? t($settings['link_title']) : $item['entity']->title;
              // Whether to force or not the language of the link.
              $force = isset($settings['force_language_default']) && $settings['force_language_default'];

              if (!$force) {
                $element[$delta] = [
                  '#type' => 'link',
                  '#title' => $label,
                  '#href' => 'node/' . $items[$delta]['target_id'],
                  '#options' => [
                    'attributes' => [
                      'class' => $classes,
                    ],
                  ],
                ];
              }
              else {
                $element[$delta] = [
                  '#markup' => l($label, 'node/' . $items[$delta]['target_id'], [
                    'language' => $lang,
                    'attributes' => ['class' => $classes],
                  ]),
                ];
              }
            }
            break;
        }
        // Multiple field wrapper.
        if (($field['cardinality'] == -1) && ($formatter != 'link_button_block')) {
          if ($formatter = 'link_button_two_column') {
            $element['#prefix'] = '<div class="btn-group btn-group-row-two">';
          }
          else {
            $element['#prefix'] = '<div class="btn-group">';
          }
          $element['#suffix'] = '</div>';
        }
        break;

      // Listing title item.
      case 'link_listing_title':
        $element[] = _nexteuropa_formatters_link_listing_title_field_formatter_view($field, $instance, $items, $display, $formatter);
        break;

      case 'entity_reference_section':
        // Preconfigure entityreference_field_formatter_view().
        // section__item
        $display['type'] = 'entityreference_entity_view';
        $element = entityreference_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display);
        foreach ($element as $delta => $item) {
          $key_of_node = key($element[$delta]['node']);
          $element[$delta]['node'][$key_of_node]['#prefix'] = '<div class="section__item">';
          $element[$delta]['node'][$key_of_node]['#suffix'] = '</div>';
        }

        // Multiple field wrapper.
        if ($field['cardinality'] == -1) {
          $element['#prefix'] = '<div class="section section--row-two">';
          $element['#suffix'] = '</div>';
        }
        break;

      case 'bold_last':
        switch ($field['type']) {
          case 'taxonomy_term_reference':
            foreach ($items as $delta => $item) {
              $term = taxonomy_term_load($item['tid']);
              $name_split = explode(' ', $term->name);
              $last_index = count($name_split) - 1;
              $name_split[$last_index] = '<strong>' . ($name_split[$last_index]) . '</strong>';
              $element[$delta] = ['#markup' => implode(' ', $name_split)];
            }
            break;

          case 'text':
            foreach ($items as $delta => $item) {
              $element[$delta] = ['#markup' => $item['safe_value']];
            }
            break;
        }
        break;
    }
  }

  return $element;
}

/**
 * Helper function returns render array of type link for a tag item.
 *
 * @param string $item_title
 *   The title of the link.
 * @param string $item_link
 *    The href value of the link.
 *
 * @see theme_link()
 *
 * @return array
 *    Render array constructing a link.
 */
function _nexteuropa_formatters_tags_item_link($item_title, $item_link) {
  return [
    '#type' => 'link',
    '#title' => $item_title,
    '#href' => $item_link,
    '#options' => [
      'attributes' => [
        'class' => ['tags__item'],
      ],
    ],
  ];
}

/**
 * Helper function to link listing title field view.
 *
 * @param array $field
 *   The field structure.
 * @param array $instance
 *   The field instance.
 * @param array $items
 *   Array of values for this field.
 * @param array $display
 *   The display settings to use, as found in the 'display' entry of instance
 *   definitions. The array notably contains the following keys and values;
 *   - type: The name of the formatter to use.
 *   - settings: The array of formatter settings.
 * @param array $formatter
 *   The formatter settings.
 *
 * @return array A renderable array for the element.
 *   A renderable array for the element.
 */
function _nexteuropa_formatters_link_listing_title_field_formatter_view($field, $instance, $items, $display, $formatter) {
  $settings = $display['settings'];
  $settings = [
    'modifier' => 'listing--title',
    'layout' => empty($settings['modifier']) ? 'default' : $settings['modifier'],
    'view_mode' => 'title',
  ];

  $settings['modifier'] .= !empty($display['settings']['nexteuropa_title_listing_modifier']) ? ' ' . $display['settings']['nexteuropa_title_listing_modifier'] : '';

  foreach ($items as &$item) {
    $item['attributes']['class'] = isset($item['attributes']['class']) ? $item['attributes']['class'] . ' listing__title' : 'listing__title';

    switch ($field['type']) {
      case 'link_field':
        // Set attribute from formatter settings.
        $formatter_class_default = _nexteuropa_formatters_field_formatter_view_classes($formatter);
        $title_item_link_modifier = $display['settings']['nexteuropa_title_item_link_modifier'];

        if (isset($title_item_link_modifier) && $title_item_link_modifier !== '') {
          $item['attributes']['class'] = $formatter_class_default . ' ' . $title_item_link_modifier;
        }
        else {
          $item['attributes']['class'] = $formatter_class_default;
        }

        $item = [
          '#theme' => 'link_formatter_link_default',
          '#element' => $item,
          '#field' => $instance,
          '#display' => $display,
        ];

        break;

      case 'taxonomy_term_reference':
        $title_item_link_modifier = $display['settings']['nexteuropa_title_item_link_modifier'];
        $term = entity_metadata_wrapper('taxonomy_term', taxonomy_term_load($item['tid']));
        $link_url = isset($term->legacy) ? $term->legacy : url('taxonomy/term/' . $item['tid']);

        if (isset($term->field_core_top_task_link)) {
          $link_url = $term->field_core_top_task_link->url->value();
        }

        $item = [
          '#theme' => 'link',
          '#text' => $term->name->value(),
          '#path' => $link_url,
          '#options' => [
            'attributes' => [
              'title' => $term->name->value(),
            ],
          ],
          '#field' => $instance,
          '#display' => $display,
        ];

        if (!empty($title_item_link_modifier)) {
          $item['#options']['attributes']['class'] = 'listing__item-link' . ' ' . $title_item_link_modifier;
        }
        else {
          $item['#options']['attributes']['class'] = 'listing__item-link';
        }

        break;
    }
  }

  $variables = [
    'items' => $items,
  ];

  return [
    '#markup' => _nexteuropa_formatters_field_component_listing($variables, $settings),
  ];
}

/**
 * Implements hook_field_formatter_info_alter().
 */
function nexteuropa_formatters_field_formatter_info_alter(&$info) {
  $additonal_options = [
    'show_translations' => '',
    'nexteuropa_listing_columns' => 'default',
    'nexteuropa_listing_modifier' => '',
    'nexteuropa_listing_wrapper_modifier' => '',
    'nexteuropa_listing_item_modifier' => '',
  ];

  if (isset($info['entityreference_entity_view_ifl']['settings'])) {
    $info['entityreference_entity_view_ifl']['settings'] += $additonal_options;
  }

  // The check avoids breaking ctools in Dynamic Display Suite fields.
  if (isset($info['entityreference_entity_view']['settings'])) {
    $info['entityreference_entity_view']['settings'] += $additonal_options;

    $info['link_listing_title']['settings'] += [
      'nexteuropa_title_listing_modifier' => '',
      'nexteuropa_title_item_modifier' => '',
      'nexteuropa_title_item_link_modifier' => '',
    ];
  }
}

/**
 * Implements hook_field_formatter_settings_form_alter().
 */
function nexteuropa_formatters_field_formatter_settings_form_alter(&$settings_form, $context) {
  if (
    isset($context['instance']['display'][$context['view_mode']]['type']) &&
    _nexteuropa_formatters_is_entityreference($context['instance']['display'][$context['view_mode']]['type']) &&
    in_array($context['instance']['display'][$context['view_mode']]['settings']['view_mode'], _nexteuropa_formatters_get_listing_view_modes())
  ) {
    $display = $context['instance']['display'][$context['view_mode']];
    $settings = $display['settings'];
    $settings_form['nexteuropa_listing_columns'] = [
      '#type' => 'select',
      '#title' => t('BEM: Listing layout'),
      '#options' => [
        'default' => t('Default'),
        'two_columns' => t('Two Columns'),
        'three_columns' => t('Three Columns'),
        'row_two' => t('Row with two items'),
        'row_three' => t('Row with three items'),
      ],
      '#default_value' => $settings['nexteuropa_listing_columns'],
    ];

    $settings_form['nexteuropa_listing_modifier'] = [
      '#type' => 'textfield',
      '#title' => t('BEM: Listing Modifier'),
      '#default_value' => $settings['nexteuropa_listing_modifier'],
      '#description' => t('Class names separated by spaces.'),
    ];

    $settings_form['nexteuropa_listing_wrapper_modifier'] = [
      '#type' => 'textfield',
      '#title' => t('BEM: Listing Wrapper Modifier'),
      '#default_value' => $settings['nexteuropa_listing_wrapper_modifier'],
      '#description' => t('Class names separated by spaces.'),
    ];

    $settings_form['nexteuropa_listing_item_modifier'] = [
      '#type' => 'textfield',
      '#title' => t('BEM: Listing item Modifier'),
      '#default_value' => $settings['nexteuropa_listing_item_modifier'],
      '#description' => t('Class names separated by spaces.'),
    ];
  }
  elseif (
    isset($context['instance']['display'][$context['view_mode']]['type']) &&
    $context['instance']['display'][$context['view_mode']]['type'] == 'link_listing_title'
  ) {
    $display = $context['instance']['display'][$context['view_mode']];
    $settings = $display['settings'];

    $settings_form['nexteuropa_title_listing_modifier'] = [
      '#type' => 'textfield',
      '#title' => t('List modifier'),
      '#default_value' => $settings['nexteuropa_title_listing_modifier'],
      '#description' => t('Class names separated by spaces.'),
    ];

    $settings_form['nexteuropa_title_item_modifier'] = [
      '#type' => 'textfield',
      '#title' => t('Item modifier'),
      '#default_value' => $settings['nexteuropa_title_item_modifier'],
      '#description' => t('Class names separated by spaces.'),
    ];

    $settings_form['nexteuropa_title_item_link_modifier'] = [
      '#type' => 'textfield',
      '#title' => t('Item link modifier'),
      '#default_value' => $settings['nexteuropa_title_item_link_modifier'],
      '#description' => t('Class names separated by spaces.'),
    ];
  }
}

/**
 * Implements hook_field_formatter_settings_summary_alter().
 */
function nexteuropa_formatters_field_formatter_settings_summary_alter(&$summary, $context) {
  if (
    _nexteuropa_formatters_is_entityreference($context['instance']['display'][$context['view_mode']]['type']) &&
    in_array($context['instance']['display'][$context['view_mode']]['settings']['view_mode'], _nexteuropa_formatters_get_listing_view_modes())
  ) {
    $display = $context['instance']['display'][$context['view_mode']];
    $settings = $display['settings'];
    if (isset($settings['nexteuropa_listing_columns'])) {
      if (!empty($summary)) {
        $summary .= '<br />';
      }
      $summary .= t('BEM: List layout: %columns', ['%columns' => $settings['nexteuropa_listing_columns']]);
    }

    if (isset($settings['nexteuropa_listing_modifier']) && !empty($settings['nexteuropa_listing_modifier'])) {
      if (!empty($summary)) {
        $summary .= '<br />';
      }
      $summary .= t('BEM: Listing Modifier: %modifier', ['%modifier' => $settings['nexteuropa_listing_modifier']]);
    }

    if (isset($settings['nexteuropa_listing_wrapper_modifier']) && !empty($settings['nexteuropa_listing_wrapper_modifier'])) {
      if (!empty($summary)) {
        $summary .= '<br />';
      }
      $summary .= t('BEM: Listing Wrapper Modifier: %wrapper_modifier', ['%wrapper_modifier' => $settings['nexteuropa_listing_wrapper_modifier']]);
    }

    if (isset($settings['nexteuropa_listing_item_modifier']) && !empty($settings['nexteuropa_listing_item_modifier'])) {
      if (!empty($summary)) {
        $summary .= '<br />';
      }
      $summary .= t('BEM: Listing Item Modifier: %item_modifier', ['%item_modifier' => $settings['nexteuropa_listing_item_modifier']]);
    }
  }
  elseif ($context['instance']['display'][$context['view_mode']]['type'] == 'link_listing_title') {
    $display = $context['instance']['display'][$context['view_mode']];
    $settings = $display['settings'];

    $modifiers = [
      'List modifier' => 'nexteuropa_title_listing_modifier',
      'Item modifier' => 'nexteuropa_title_item_modifier',
      'Item link modifier' => 'nexteuropa_title_item_link_modifier',
    ];

    foreach ($modifiers as $label => $modifier) {
      if (isset($settings[$modifier])) {
        if (!empty($summary)) {
          $summary .= '<br />';
        }
        $summary .= $label . ': ' . $settings[$modifier];
      }
    }
  }
}

/**
 * Implements hook_preprocess_field().
 */
function nexteuropa_formatters_preprocess_field(&$variables) {
  if (isset($variables['element']['#field_type'])
    && $variables['element']['#field_type'] == 'file'
  ) {
    // Convenient access to the important elements of the $variables.
    $entity_type = $variables['element']['#entity_type'];
    $field_name = $variables['element']['#field_name'];
    $bundle = $variables['element']['#bundle'];
    $view_mode = $variables['element']['#view_mode'];

    // Fetch the instance settings.
    $info = field_info_instance($entity_type, $field_name, $bundle);
    // Get the settings, fall back to default TRUE.
    $show_translation = isset($info['display'][$view_mode]['settings']['show_translations']) ? $info['display'][$view_mode]['settings']['show_translations'] : TRUE;

    if ($show_translation
      && ($info['display'][$view_mode]['type'] == 'link_button_download'
      || $info['display'][$view_mode]['type'] == 'link_download')
    ) {
      foreach ($variables['items'] as $item_key => $item) {
        $variables['items'][$item_key]['#suffix'] = theme('nexteuropa_file_translations', ['node' => $variables['element']['#object']]);
      }
    }
  }
  elseif (isset($variables['element']['#formatter'])) {
    if (_nexteuropa_formatters_is_entityreference($variables['element']['#formatter'])) {
      // Convenient access to the important elements of the $variables.
      $entity_type = $variables['element']['#entity_type'];
      $field_name = $variables['element']['#field_name'];
      $bundle = $variables['element']['#bundle'];
      $view_mode = $variables['element']['#view_mode'];

      // Fetch the instance settings and default display settings.
      $info = field_info_instance($entity_type, $field_name, $bundle);
      $formatter_settings = $info['display']['default']['settings'];
      if (isset($info['display'][$view_mode]['settings'])) {
        $formatter_settings = $info['display'][$view_mode]['settings'] + $formatter_settings;
      }

      // Make the setting available in the field template.
      $settings = [
        'nexteuropa_listing_columns',
        'nexteuropa_listing_modifier',
        'nexteuropa_listing_wrapper_modifier',
        'nexteuropa_listing_item_modifier',
      ];
      foreach ($settings as $setting) {
        $variables[$setting] = isset($formatter_settings[$setting]) ? $formatter_settings[$setting] : '';
      }

      // Default the settings.
      if (!isset($formatter_settings['show_translations'])) {
        $formatter_settings['show_translations'] = 0;
      }

      // Attach file translations when required.
      if ($formatter_settings['show_translations'] == 1) {
        foreach ($variables['items'] as $item_key => $item) {
          $variables['items'][$item_key]['#suffix'] = _nexteuropa_formatters_attach_translations($item);
        }
      }
    }
  }
}

/**
 * Helper function to check if a entity reference formatter is supported.
 *
 * @param string $type
 *   The entity reference view type.
 *
 * @return bool
 *   If it is supported or not.
 */
function _nexteuropa_formatters_is_entityreference($type) {
  return in_array($type, [
    'entityreference_entity_view',
    'entityreference_entity_view_ifl',
  ]);
}
