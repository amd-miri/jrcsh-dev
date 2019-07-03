/**
 * @file
 * The function for publication redirections.
 */

(function ($) {
  // Add some details to menu items.
  Drupal.behaviors.openCallAccessStatus = {
    attach: function (context, settings) {
      /* If the call is open */
      if ($(".field-name-opencall-blue-box .button").text() == "Open") {
        $(".field-name-opencall-blue-box .button").text(Drupal.t("Make a proposal"));
      }
      /* If the call is closed */
      else {
        $(".field-name-opencall-blue-box .button").removeAttr("href");
        $(".field-name-opencall-blue-box .button").addClass("closed");
        $(".field-name-field-openaccess-call-apply").hide();
      }
      /* If the call is Market driven type */
      if ($(".field-name-opencall-blue-box #openaccess_mode a strong").text() == "Market driven") {
          $(".field-name-opencall-blue-box #openaccess_call_date_start strong").text(Drupal.t("Continuous"));
          $(".field-name-opencall-blue-box #openaccess_call_date_end").hide();
          $(".field-name-opencall-blue-box #openaccess_proposal").hide();
      }
      else {
        /* If the start date is empty */
        if ($(".field-name-opencall-blue-box #openaccess_call_date_start strong").text() == "") {
          $(".field-name-opencall-blue-box #openaccess_call_date_start").hide();
          $(".field-name-opencall-blue-box #openaccess_call_date_end").hide();
        }
        /* If the last date is empty */
        if ($(".field-name-opencall-blue-box #openaccess_call_date_end strong").text() == "") {
          $(".field-name-opencall-blue-box #openaccess_call_date_end").hide();
        }
        /* If the opencall proposal date is empty */
        if ($(".field-name-opencall-blue-box #openaccess_proposal strong").text() == "") {
          $(".field-name-opencall-blue-box #openaccess_proposal").hide();
        }
      }
    }
  };
})(jQuery);
