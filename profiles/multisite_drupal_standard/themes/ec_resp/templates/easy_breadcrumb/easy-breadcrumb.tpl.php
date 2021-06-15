<?php print drupal_render($menu_breadcrumb); ?>
<?php if ($segments_quantity > 0): ?>
  <span class="easy-breadcrumb_segment-separator"><?php print $separator; ?></span>
  <div itemscope class="easy-breadcrumb" itemtype="<?php print $list_type; ?>">
    <?php foreach ($breadcrumb as $i => $item): ?>
      <?php print $item; ?>
      <?php if ($i < $segments_quantity - $separator_ending): ?>
         <span class="easy-breadcrumb_segment-separator"><?php print $separator; ?></span>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
