/**
 * @file
 * Code for building a glossary.
 *
 * Code for building a glossary from a JSON or table.
 */

(function ($) {
  Drupal.behaviors.jrc_multisiteModule = {
    attach: function (context, settings) {
      var glossarySource = $('h2.glossary-title > a').attr('href');
      var glossaryDataTable = $('table.glossary-table');
      glossaryDataTable.hide();
      if (glossarySource && glossaryDataTable.length == 0) {
        processJson(glossarySource);
      }
      if (glossaryDataTable.length) {
        var glossaryTable = [];
        var index = [];
        $('table.glossary-table tr > th').each(function populateTableParentTree(k) {
          index[k] = $(this).text();
        });
        $('table.glossary-table tr:has(td)').each(function populateTableChildrenTree(i) {
            glossaryTable[i] = {};
            $('td', this).each(
              function (j) {
                glossaryTable[i][index[j]] = $(this).text();
              }
            );
        });
        processTable(glossaryTable);
      }
      $('#glossary-container li').each(
        function () {
          $(this).attr('data-search-term', $(this).text().toLowerCase());
        }
      );
      $('#live-search-box').on('keyup',
        function () {
          var searchTerm = $(this).val().toLowerCase();
          $('#glossary-container li').each(function filterBySearchTerm() {
            if ($(this).filter('[data-search-term *= ' + searchTerm + ']').length > 0 || searchTerm.length < 1) {
              $(this).show();
            }
            else {
              $(this).hide();
            }
          });
        }
      );
    }
  };

  function processJson(jsonObj) {
    $.getJSON(jsonObj, function done(data) {
      data.sort(compareValues('code'));
      var dictionary = createDictionary(data);
      var glossary = nestedJson(dictionary);
      var ul = $("<ul></ul>");
      ul.appendTo("#glossary-container");
      buildGlossaryTree(ul, glossary);
      accordeon();
    });
  }

  function processTable(data) {
    data.sort(compareValues('code'));
    var dictionary = createDictionary(data);
    var glossary = nestedJson(dictionary);
    var ul = $("<ul></ul>");
    ul.appendTo("#glossary-container");
    buildGlossaryTree(ul, glossary);
    accordeon();
  }

  function compareValues(key, order='asc') {
    return function (a, b) {
      if (isPropertyMissingOnEitherObjects(key, a, b)) {
        // Property doesn't exist on either object.
        return 0;
      }
      const varA = (typeof a[key] === 'string') ? a[key].toUpperCase() : a[key];
      const varB = (typeof b[key] === 'string') ? b[key].toUpperCase() : b[key];
      let comparison = 0;
      if (varA > varB) {
        comparison = 1;
      }
      else if (varA < varB) {
        comparison = -1;
      }
      return (
        (order == 'desc') ? (comparison * -1) : comparison
      );
    };
  }

  function createDictionary(obj) {
    var dictionary = [];
    for (var i = 0; i < obj.length; i++) {
      var code = obj[i].code;
      dictionary[i] = obj[i];
      var parent = code.substring(0, code.length - 2);
      if (parent.length == 1) {
        parent = 0;
      }
      dictionary[i]['parentid'] = parent;
    }
    return dictionary;
  }

  function nestedJson(obj) {
    var glossary = {};
    var children = [];
    for (i = 0; i < obj.length; i++) {
      var newChildrenValue = obj[i];
      var term = newChildrenValue["term"];
      var parentid = newChildrenValue["parentid"];
      var id = newChildrenValue["code"];
      var definition = newChildrenValue["definition"];
      newChildrenValue = { id: id, parentid: parentid, term: term, definition: definition };
      if (children[parentid]) {
        if (!children[parentid].children) {
          children[parentid].children = [];
        }
        children[parentid].children[children[parentid].children.length] = newChildrenValue;
        children[id] = newChildrenValue;
      }
      else {
        children[id] = newChildrenValue;
        glossary[id] = children[id];
      }
    }
    return glossary;
  }

  function buildGlossaryTree(parent, items) {
    $.each(
      items,
      function () {
        if (this.term) {
          // Create LI element and append it to the parent element.
          var li = $("<li data-search-term='" + this.id + ' ' + this.term + ' ' + this.definition + "'> <h3>" + this.id + ' - ' + this.term + "</h3><div>" + this.definition + "</div></li>");
          li.appendTo(parent);
          // If there are sub items, call the buildGlossaryTree function.
          if (this.children && this.children.length > 0) {
            var ul = $("<ul></ul>");
            ul.appendTo(li);
            buildGlossaryTree(ul, this.children);
          }
        }
      }
    );
  }

  function onListItemClick(e) {
    e.stopPropagation();
    var el = $(this).children('ul');
    if (el.is(":visible")) {
      el.slideUp();
      $('i', this).text('► ');
    }
    else {
      el.slideDown();
      $('i', this).first().text('▼ ');
    }
  }

  function accordeon() {
    var ico = $('<i>► </i>');
    $('#glossary-container li:has(ul)').addClass('glossary-parent');
    $('#glossary-container li:has(ul) > h3').prepend(ico).addClass('glossary-parent');
    $('#glossary-container li:has(ul)').on('click', onListItemClick);
    $('#glossary-container a').on('click',
      function (e) {
        e.preventDefault();
      }
    );
  }

  function isPropertyMissingOnEitherObjects(key, a ,b) {
    return (!a.hasOwnProperty(key) || !b.hasOwnProperty(key));
  }
}(jQuery));
