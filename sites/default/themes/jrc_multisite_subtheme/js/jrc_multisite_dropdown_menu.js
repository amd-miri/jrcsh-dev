/**
 * @file
 * The dropdown menu JS functions.
 */

(function ($) {
  // Add some details to menu items.
  Drupal.behaviors.dropdownglyphicons = {
    attach: function (context, settings) {
      $('.block-menu-block a.dropdown-toggle, .block-og-menu a.dropdown-toggle, .block-menu a.dropdown-toggle').click(function () {
        // Restore links.
        location.href = $(this).attr('href');
      });
      // Add expanded class to parents in case a child menu is active.
      $('.list-group-item.active').parents('ul').addClass('expanded');
      $('.active-trail').last().addClass('active');
    }
  };

  // Make the menu parent clickable.
  Drupal.behaviors.dropdownparentclick = {
    attach: function (context, settings) {
      $(".block-menu-block .dropdown-toggle, .block-og-menu .dropdown-toggle, .block-menu .dropdown-toggle").click(function () {
        window.location.href = $(this).attr("href");
      });
    }
  };
})(jQuery);
