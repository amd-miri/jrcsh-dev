/**
 * @file
 * The Image gallery JS function called through the template.php.
 *
 * Requested to be in a seperate file by Digit (MULTISITE-13632).
 */

(function ($) {
  Drupal.behaviors.jrcMultisiteSubthemeSwapImageGalleryLinks = {
    attach: function (context, settings) {
      if ($.type(settings.jrcMultisiteSubthemeSwapImageGalleryLinks.colorboxImageGalleryOriginalLinks) !== 'undefined') {
        $.each(settings.jrcMultisiteSubthemeSwapImageGalleryLinks.colorboxImageGalleryOriginalLinks, function (key, value) {
          $('.node-image-gallery .field-name-field-images .field-item:nth-child(' + key + ') a').first().attr('href', value);
        });
      }
    }
  }
})(jQuery);
