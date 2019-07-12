<?php

/**
 * @file
 * Display Suite JRC 4 rows template.
 */
?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="jrc-4-rows <?php print $classes; ?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <<?php print $row1_wrapper ?> class="rows-group group-first-row<?php print $row1_classes; ?>">
    <?php print $row1; ?>
  </<?php print $row1_wrapper ?>>

  <<?php print $row2_wrapper ?> class="rows-group group-second-row<?php print $row2_classes; ?>">
    <?php print $row2; ?>
  </<?php print $row2_wrapper ?>>

  <<?php print $row3_wrapper ?> class="rows-group group-third-row<?php print $row3_classes; ?>">
    <?php print $row3; ?>
  </<?php print $row3_wrapper ?>>

  <<?php print $row4_wrapper ?> class="rows-group group-fourth-row<?php print $row4_classes; ?>">
    <?php print $row4; ?>
  </<?php print $row4_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
