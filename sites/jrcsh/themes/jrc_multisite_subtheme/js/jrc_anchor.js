/**
 * @file
 * Code for fixing the anchor link.
 *
 * Code for move from behind the navbar to the anchor link.
 */

(function ($) {
  Drupal.behaviors.jrc_anchorModule = {
    attach: function (context, settings) {
      // Wait for images to load for proper offsets.
      $(window).load(function () {
        var hashVal = window.location.hash.substring(1).toLowerCase();
        var anchorEl = $("a[name]").toArray().filter(function (a) {
          return $(a).attr('name').toLowerCase() == hashVal.toLowerCase();
        });
        var elOffset = $(anchorEl).offset();
        if (anchorEl.length > 0) {
          var offsetTop = elOffset.top;
          $(document).scrollTop(offsetTop - 90);
        }

      });
    }
  }
}(jQuery));
