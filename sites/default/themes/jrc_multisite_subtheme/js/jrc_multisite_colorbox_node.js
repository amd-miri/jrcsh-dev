/**
 * @file
 * The Node thumbnail replacement function called through the template.php.
 *
 * Requested to be in a seperate file by Digit (MULTISITE-13632).
 */

(function ($) {
  Drupal.behaviors.jrcMultisiteSubthemeSwapNodeLinks = {
    attach: function (context, settings) {
      if ($.type(settings.jrcMultisiteSubthemeSwapNodeLinks.colorboxNodeOriginalLink) !== 'undefined') {
        $('.field-name-field-image a').first().attr('href', settings.jrcMultisiteSubthemeSwapNodeLinks.colorboxNodeOriginalLink);
      }
    }
  }
})(jQuery);
