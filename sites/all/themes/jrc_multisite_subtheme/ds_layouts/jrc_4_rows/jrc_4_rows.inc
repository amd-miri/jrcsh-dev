<?php

 /**
  * @file
  * File for defining new DS templates.
  */

/**
 * Implements a new DS template.
 */
function ds_jrc_4_rows() {
  return array(
    'label' => t('JRC 4 rows template'),
    'regions' => array(
        // The key of this region name is also the variable used in
        // the template to print the content of that region.
      'row1' => t('First row'),
      'row2' => t('Second row'),
      'row3' => t('Third row'),
      'row4' => t('Fourth row'),
    ),
      // Add this if there is a default css file.
    'css' => TRUE,
      // Add this if there is a default preview image.
    'image' => TRUE,
  );
}
