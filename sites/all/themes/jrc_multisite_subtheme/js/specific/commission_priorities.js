/**
 * @file
 * The JRC and the Commission priorities.
 *
 * For specific pages:
 * node/113257 .
 */

(function ($) {
  Drupal.behaviors.commissionPriorities = {
    attach: function (context, settings) {
      $(".priority div.content").hide();
      // Check anchor selected.
      $(".priority > a").addClass("link").click(function () {
        var el1 = $("div.content", $(this).parent());
        var el2 = $("div.teaser", $(this).parent());
        var el3 = $("h2 span", $(this));
        if (el1.is(":visible")) {
          el1.slideUp();
          el2.slideDown();
          el3.text("►");
        }
        else {
          el1.slideDown();
          el2.slideUp();
          el3.text("▼");
        }
      });
      $(".priority h2").append(" <span>►</span>");
      if (h = document.location.hash) {
        $(".priority" + h + " a").click();
      }
    }
  }
})(jQuery);
