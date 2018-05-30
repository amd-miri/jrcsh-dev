<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($wrapper): ?>
  <div<?php print $wrapper_attributes; ?>>
<?php endif; ?>
  <?php if ($title): ?>
      <?php print render($title); ?>
  <?php endif; ?>

  <?php if (!empty($variables['items'])): ?>
    <?php if ($type): ?>
      <<?php print $type; ?><?php print $attributes; ?>>
    <?php endif; ?>
    <?php foreach ($variables['items'] as $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>
    <?php if ($type): ?>
      </<?php print $type; ?>>
    <?php endif; ?>
  <?php endif; ?>
<?php if ($wrapper): ?>
  </div>
<?php endif; ?>
