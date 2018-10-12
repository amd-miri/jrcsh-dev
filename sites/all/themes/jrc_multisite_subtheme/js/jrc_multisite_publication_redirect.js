/**
 * @file
 * The function for publication redirections.
 */

(function ($) {
  // Add some details to menu items.
  Drupal.behaviors.publicationRedirect = {
    attach: function (context, settings) {
      if (l = $(".view-jrc-publication-k4p .field-content a").attr("href")) {
          window.location.replace(l);
      }
    }
  };
})(jQuery);
