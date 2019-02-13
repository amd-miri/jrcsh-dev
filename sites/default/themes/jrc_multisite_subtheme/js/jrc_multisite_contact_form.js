/**
 * @file
 * The contact form JS functions.
 */

(function ($) {
  // Add some functionalities to contact form.
  Drupal.behaviors.jrcshContactForm = {
    attach: function (context, settings) {
      var changeTopic = function (e) {
        if (msg = $(e.target).attr("data")) {
          $("#message_info").text(msg).slideDown();
        }
        else {
          $("#message_info").slideUp();
        }
      };

      var URL = window.location.search.substring(1).split('&');
      URL.forEach(
        function (e,i,a) {
          a[i] = e.split("=");
          a[a[i][0]] = a[i][1];
        }
      );

      $("#message_info").hide();
      var obj, objt;
      var group = (URL["g"] && (obj = $("#top-" + URL["g"])).length);
      var topic = (URL["t"] && (objt = $("#topic_" + URL["t"])).length);
      // Get a possible selected radio option (if browser back function is used)
      if (group || topic) {
        var newTopic = $('li#topic').clone().html("");
        newTopic.append("<div class='radioboxes'>");
        var inner = $("div", newTopic);
        if (group) {
          // Copy and select topic.
          if (URL["g"] != "gen") {
            inner.append('<strong id="top-more">' + obj.prev().prev(".othertopic").text() + '</strong><br />');
          }
          inner.append(obj.clone());
          if (topic) {
            $("#topic_" + URL["t"], inner).attr('checked', true);
          }
        }
        else if (URL["t"]) {
          // Specific topic.
          if (objt.parent().attr("id") != "top-gen") {
            inner.append('<strong id="top-more">' + objt.parent().prev().prev(".othertopic").text() + '</strong><br />');
          }
          inner.append(objt.attr('checked', true).clone());
          inner.append($("#topic label[for=topic_" + URL["t"] + "]").clone());
        }
        if ((tc = $("input", newTopic).length) <= 1) {
          if (tc < 1) {
            $("fieldset:not(:first)", $("#contact")).hide();
          }
          else {
            changeTopic({target:$("input", newTopic).attr('checked', true)});
          }
          $("fieldset:first p:first", $("#contact")).hide();
        }
        $('li#topic').html(newTopic.html());
      }

      // If a radio button was checked, rechek after HTML changes.
      if (window.location.hash) {
          $("input#topic_" + window.location.hash.substring(1)).prop('checked', true);
      }

      else {
        $("#top-more").append(" <em>(click to expand)</em>");
        $(".othertopic").prepend("<span>+</span> ").next("div").hide();
      }

      $('input[type=radio]').change(changeTopic);

      // Helps to understand the context of the request, if available.
      ref = $("input#url_referer");
      if (document.referrer && ref && !ref.val()) {
          ref.val(document.referrer);
      }

      // Expand the choices.
      $('#contact .othertopic').click(
        function (e) {
          var n = $(this).attr("id");
          var v = (x = $('#top-' + n)).is(':visible');
          x.slideToggle();
          $('span', e).html(v ? "+ " : "&ndash; ");
          if (v && $('input:checked', x).length) {
            changeTopic({target:$('#topic_253').attr("checked", "checked")});
          }
        }
      );
        $("input[type='radio']").click(
        function () {
          window.location.hash = $(this).val();
        }
     );

    }

  };
})(jQuery);
