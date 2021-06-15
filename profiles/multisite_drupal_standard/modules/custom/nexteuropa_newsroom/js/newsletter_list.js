/**
 * @file
 * Newsroom newsletter list.
 */

(function ($) {
    Drupal.behaviors.nexteuropa_newsroom = {
        attach: function (context, settings) {
            if (Drupal.settings.nexteuropa_newsroom.user_is_logged_in) {
                // Disable all subscribe buttons before accepting privacy statement.
                $('.newsroom-service-page button[type="submit"]').each(function () {
                    if ($(this).text() != "Unsubscribe") {
                        $(this).prop('disabled', true);
                    }
                });
                // Logged user.
                $(".gdpr_checkbox input[type='checkbox']").each(function () {

                    $(this).change(function () {
                        var status = true;
                        if (!$(this).prop('checked')) {
                            status = true;
                        }
                        else {
                            status = false;
                        }
                        $(this).parents(".gdpr_checkbox").first().next('button[type="submit"]').prop("disabled", status);
                    });
                });
            }
            else {
                // Not logged user & no valid email entered yet.
                // Disable privacy policy agreement checkboxes.
                if ($('#newsroom-service-email').val() === '') {
                    $(".gdpr_checkbox input[type='checkbox']").each(function () {
                        $(this).prop("disabled", true);
                    })
                    // Give "disable look and feel" to these privacy policy labels.
                    $(".gdpr_checkbox label").css({opacity: 0.6});
                    $('.newsroom-service-page button[type="submit"]').each(function () {
                        if ($(this).text() != "Unsubscribe") {
                            $(this).prop('disabled', true);
                        }
                    });
                }
                // Test if valid email submitted.
                $('#newsroom-service-email').once('dsm_blur_status', function () {
                    $('#newsroom-service-email').blur(function () {
                        var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
                        var email = $(this).val();
                        if (regex.test(email)) {
                            $('.newsroom-service-page input[name="email"]').each(function () {
                                $(this).val(email);
                            });

                            $('.gdpr_checkbox label').animate({opacity: 1}, 300);
                            $(".gdpr_checkbox input[type='checkbox']").each(function () {

                                $(this).prop('disabled', false);
                                $(this).prop('checked', false);

                                $(this).change(function () {
                                    var status = true;
                                    if (!$(this).prop('checked')) {
                                        status = true;
                                    }
                                    else {
                                        status = false;
                                    }
                                    $(this).parents(".gdpr_checkbox").first().next('button[type="submit"]').prop("disabled", status);
                                });
                            });
                        }
                        else {
                            $('.newsroom-service-page button[type="submit"]').each(function () {
                                if ($(this).text() != "Unsubscribe") {
                                    $(this).prop('disabled', true);
                                }
                            });
                            $(".gdpr_checkbox input[type='checkbox']").each(function () {
                                $(this).prop("disabled", true);
                            });
                            $(".gdpr_checkbox label").css({opacity: 0.6});
                            alert(Drupal.settings.nexteuropa_newsroom.error_message);
                        }
                    });
                });
            }
        }
    };
})(jQuery);
