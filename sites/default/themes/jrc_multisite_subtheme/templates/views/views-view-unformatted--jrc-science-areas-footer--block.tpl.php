<?php

/**
 * @file
 * Default simple view template to display the homepage footer.
 */
?>

<div class="clear"></div>
<?php if (count($rows) > 1) : ?>
  <div class="span-footer">
    <div class="span-footer-left">
      <ul>
        <?php $i = 0; ?>
        <?php foreach ($rows as $id => $row): ?>
          <?php if ($i == 0) : ?>
            <li class="<?php print $classes_array[$id]; ?>">
              <?php print $row; ?>
              <div class="clear"></div>
             </li>
          <?php endif; ?>
          <?php $i++; ?>
        <?php endforeach; ?>
      </ul>
    </div>
    <div class="span-footer-right">
      <ul>
        <?php $i = 0; ?>
        <?php foreach ($rows as $id => $row): ?>
          <?php if ($i != 0) : ?>
          <li class="<?php print $classes_array[$id]; ?>">
            <?php print $row; ?>
          </li>
          <?php endif; ?>
          <?php $i++; ?>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
<?php endif; ?>
