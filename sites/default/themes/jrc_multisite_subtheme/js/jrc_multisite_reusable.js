/**
 * @file
 * The reusable functions.
 */

(function ($) {
  Drupal.behaviors.resuableFeatures = {
    attach: function (context, settings) {
      // Various resuable features:
      // URL Query variable.
      var URL = window.location.search.substring(1).split('&');
      URL.forEach(function (e,i,a) {
        a[i] = e.split("=");
        a[a[i][0]] = a[i][1];
      });

      // This is how to assign the ColorBox event to elements.
      // Add the "colorbox-img" class to your media tag.
      $('.colorbox-img').click(function () {
        $(this).colorbox({href: $(this).attr('src')});
      });

      // Add the "colorbox-iframe" class to your media tag.
      $('.colorbox-iframe').click(function () {
        $(this).colorbox({iframe:true, width:"90%", height:"90%"});
      });

      // Sortable tables.
      $('table.sortable').tablesorter();

      // Searchable tables.
      $('table.searchable').each(function (i, table) {
        var searchBox = $('<input type="text" class="searchbox">');
        searchBox.keyup(function () {
          inputVal = searchBox.val();
          // trim, single space and breaks search terms.
          var inputs = inputVal.trim().replace(/\s{2,}/," ").split(/\s/);
          // Contruct terms.
          $.each(inputs, function (i,v) {
            inputs[i] = new RegExp(v, 'gi');
          });
          // Browse table contents.
          $(table).children("tbody").children("tr").each(function (index, row) {
            var nRow = $(row);
            var text = nRow.text();
            // Each terms.
            for (var i = 0; i < inputs.length; i++) {
              if (!text.match(inputs[i])) {
                // Term not found.
                nRow.hide();
                return;
              }
            }
            // If we get here it's found all terms.
            nRow.show();
          });
        });
        if (URL['s']) {
          searchBox.val(unescape(URL['s'])).keyup();
        }
        $(table).before($('<div class="filterBox">Search : </div>').append(searchBox));
      });

      // Popup on tablecontents.
      $('table.popup .more').hide();

      // Display with colorbox.
      $('table.popup td a[href="#"]').click(function () {
        var content = $('td.more table', $(this).parents('tr'));
        if (content) {
          // Get header if any.
          var header = $("#" + $(this).parents('table').attr('id') + "-head").html();
          if (!header) {
            header = "<tr></tr>";
          }
          else {
            header = header.replace("#title", $(this).text());
          }
          $.colorbox({html:header.replace("<tr></tr>", content.html()), width:"70%"});
        }
        return false;
      });
    }
  };
})(jQuery);
