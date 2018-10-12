<?php

/**
 * @file
 * Default template implementation to display the field_publication_files field.
 *
 * This file is not used and is here as a starting point for customization only.
 *
 * Available variables:
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 */
?>

<?php if (!empty($items)): ?>
  <div class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php if (!$label_hidden): ?>
      <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
    <?php endif; ?>
    <div class="field-items">
    <?php foreach ($pdf_titles_array as $filename => $file_titles) : ?>
      <div>
        <a id="link-<?php print $filename; ?>" href="<?php print $pdf_links_array[$filename][$current_lang]; ?>">
          <?php if (!empty($file_titles[$current_lang])): ?>
            <span><?php print $file_titles[$current_lang]; ?></span>
          <?php else : ?>
            <span><?php print $filename; ?></span>
          <?php endif; ?>
          <?php print theme('image', $doc_gif[$filename][$current_lang]); ?>
          <?php if ($file_sizes[$filename][$current_lang] != 0): ?>
            <span class="link-size">[<?php print $file_sizes[$filename][$current_lang]; ?>]</span>
          <?php endif; ?>
        </a>

        <?php if (count($pdf_links_array[$filename]) > 1) : ?>
        <span class="popup">
          <span id="popup-icon_<?php print $pdf_links_array[$filename][$current_lang]; ?>" title="<?php print t('Choose translations of the previous link'); ?>">
          <?php print theme('image', $popup_gif); ?>
            <span id="popup-links_<?php print $filename; ?>">
              <?php foreach ($pdf_links_array[$filename] as $lang => $link) : ?>
              <a class="lang" lang="<?php print $lang; ?>" title="<?php print $pdf_titles_array[$filename][$lang] . '(' . $lang . ')'; ?>" href="<?php print $link; ?>">
                <span><?php print $lang; ?></span>
              </a>
              <?php endforeach; ?>
            </span>
          </span>
        </span>
        <?php endif; ?>
      </div>
    <?php endforeach; ?>
    </div>
  </div>
<?php endif; ?>
