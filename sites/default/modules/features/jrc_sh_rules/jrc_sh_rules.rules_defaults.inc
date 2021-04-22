<?php

/**
 * @file
 * jrc_sh_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function jrc_sh_rules_default_rules_configuration() {
  $items = array();
  $items['rules_notification_message_on_contents'] = entity_import('rules_config', '{ "rules_notification_message_on_contents" : {
      "LABEL" : "Notification message on contents",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "user_has_role" : {
                  "account" : [ "site:current-user" ],
                  "roles" : { "value" : { "3" : "3", "4" : "4", "15" : "15", "5" : "5", "6" : "6" } },
                  "operation" : "OR"
                }
              },
              { "NOT node_is_published" : { "node" : [ "node" ] } }
            ],
            "DO" : [
              { "drupal_message" : { "message" : "This content is not published.", "type" : "warning" } }
            ],
            "LABEL" : "Not published node message"
          }
        },
        { "RULE" : {
            "IF" : [
              { "user_has_role" : {
                  "account" : [ "site:current-user" ],
                  "roles" : { "value" : { "3" : "3", "15" : "15", "5" : "5" } },
                  "operation" : "OR"
                }
              },
              { "node_is_published" : { "node" : [ "node" ] } },
              { "OR" : [
                  { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
                  { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
                ]
              }
            ],
            "DO" : [
              { "drupal_message" : {
                  "message" : "There is a unpublished Draft version of this content",
                  "type" : "warning"
                }
              }
            ],
            "LABEL" : "There\\u0027s a draft version of node"
          }
        },
        { "RULE" : {
            "IF" : [
              { "user_has_role" : {
                  "account" : [ "site:current-user" ],
                  "roles" : { "value" : { "3" : "3", "4" : "4", "15" : "15", "5" : "5" } },
                  "operation" : "OR"
                }
              },
              { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } }
            ],
            "DO" : [
              { "drupal_message" : { "message" : "This content has been sent to moderation for publication" } }
            ],
            "LABEL" : "In \\u0022Needs Review\\u0022 moderation"
          }
        },
        { "RULE" : {
            "IF" : [
              { "user_has_role" : {
                  "account" : [ "site:current-user" ],
                  "roles" : { "value" : { "3" : "3", "15" : "15", "5" : "5" } },
                  "operation" : "OR"
                }
              },
              { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_file_internal_note" } },
              { "NOT data_is_empty" : { "data" : [ "node:field-file-internal-note" ] } }
            ],
            "DO" : [
              { "drupal_message" : {
                  "message" : "Internal note: [node:field-file-internal-note]",
                  "type" : "warning"
                }
              }
            ],
            "LABEL" : "Internal comment message (logged in only)"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "variable_added" : { "date_will_publish" : "Added variable" } },
            "IF" : [
              { "node_is_of_type" : {
                  "node" : [ "node" ],
                  "type" : { "value" : { "news" : "news", "science_updates" : "science_updates" } }
                }
              },
              { "user_has_role" : {
                  "account" : [ "site:current-user" ],
                  "roles" : { "value" : { "3" : "3", "15" : "15", "5" : "5" } },
                  "operation" : "OR"
                }
              },
              { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
              { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "validated" } },
              { "NOT data_is_empty" : { "data" : [ "node:field-publish-date" ] } },
              { "data_is" : {
                  "data" : [ "node:field-publish-date" ],
                  "op" : "\\u003E",
                  "value" : "now"
                }
              }
            ],
            "DO" : [
              { "variable_add" : {
                  "USING" : { "type" : "date", "value" : [ "node:field-publish-date" ] },
                  "PROVIDE" : { "variable_added" : { "date_will_publish" : "Added variable" } }
                }
              },
              { "drupal_message" : { "message" : "This content has been programmed for auto publishing on [date-will-publish:value]" } }
            ],
            "LABEL" : "Content auto publication planned"
          }
        },
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "news" : "news" } } } },
              { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } },
              { "user_has_role" : {
                  "account" : [ "site:current-user" ],
                  "roles" : { "value" : { "3" : "3", "15" : "15", "5" : "5" } },
                  "operation" : "OR"
                }
              },
              { "data_is" : {
                  "data" : [ "node:field-news-publication-date" ],
                  "op" : "\\u003E",
                  "value" : "now"
                }
              }
            ],
            "DO" : [
              { "drupal_message" : {
                  "message" : "Date set for auto-publish but moderation is not set to validated !",
                  "type" : "warning"
                }
              }
            ],
            "LABEL" : "News autopublish plan but not validated"
          }
        },
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : {
                  "node" : [ "node" ],
                  "type" : { "value" : { "publication" : "publication" } }
                }
              },
              { "data_is" : { "data" : [ "node:status" ], "value" : "1" } },
              { "NOT data_is_empty" : { "data" : [ "node:field-dc-relation-ispartofseries" ] } },
              { "data_is" : { "data" : [ "node:author:uid" ], "value" : "1" } }
            ],
            "DO" : [
              { "drupal_message" : { "message" : "You are viewing this content because you are logged in. \\r\\nFor visitors, this page will redirect to https:\\/\\/publications.jrc.ec.europa.eu\\/repository\\/handle\\/[node:field-dc-relation-ispartofseries]" } }
            ],
            "LABEL" : "Pubsy redirect warning"
          }
        }
      ]
    }
  }');
  $items['rules_pubsy_publication_redirection'] = entity_import('rules_config', '{ "rules_pubsy_publication_redirection" : {
      "LABEL" : "Pubsy publication redirection",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_view--publication" : { "bundle" : "publication" } },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "2" : "2" } }
          }
        },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "data_is" : { "data" : [ "view-mode" ], "value" : "full" } },
        { "NOT data_is_empty" : { "data" : [ "node:field-dc-relation-ispartofseries" ] } },
        { "data_is" : { "data" : [ "node:author:uid" ], "value" : "1" } }
      ],
      "DO" : [
        { "redirect" : { "url" : "https:\\/\\/publications.jrc.ec.europa.eu\\/repository\\/handle\\/[node:field-dc-relation-ispartofseries]" } }
      ]
    }
  }');
  $items['rules_satus_messages_on_content'] = entity_import('rules_config', '{ "rules_satus_messages_on_content" : {
      "LABEL" : "Satus messages on content (Logged in users)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_view" : [] },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        },
        { "data_is" : { "data" : [ "view-mode" ], "value" : "full" } }
      ],
      "DO" : [
        { "component_rules_notification_message_on_contents" : { "node" : [ "node" ] } }
      ]
    }
  }');
  return $items;
}
