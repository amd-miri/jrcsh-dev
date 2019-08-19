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
      $(".priority > a, .priority h2 a").addClass("link").click(function () {
        var parent = $(this).closest(".priority");
        var el1 = $("div.content", parent);
        var el2 = $("div.teaser", parent);
        var el3 = $("h2 span.pointer", parent);
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
      $(".priority h2").append("<span>►</span>");
      $(window).load(function() {
        if (document.location.hash) {
          var hash = document.location.hash;
          $(".priority" + hash + " div.content").slideDown();
          $(".priority" + hash + " div.teaser").slideUp();
          $(".priority" + hash + " h2 span").text("▼");
        }
      });
    }
  }
})(jQuery);
