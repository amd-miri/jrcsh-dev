<?php

/**
 * @file
 * Code for the NexteuropaNewsroomBlock class.
 */

/**
 * NexteuropaNexteuropaNewsroomBlock class base class.
 */
class NexteuropaNewsroomSummaryBlock {

  protected $types = [];
  protected $topics = [];

  /**
   * Gets newsroom topics.
   *
   * @return array
   *   Newsroom topics.
   */
  public function getTopics() {
    return $this->topics;
  }

  /**
   * Sets newsroom topics.
   *
   * @param array $value
   *   Newsroom topics.
   */
  public function setTopics(array $value) {
    $this->topics = $value;
  }

  /**
   * Sets newsroom types.
   *
   * @param array $value
   *   Newsroom types.
   */
  public function setTypes(array $value) {
    $this->types = $value;
  }

  /**
   * Gets newsroom types.
   *
   * @return array
   *   Newsroom types
   */
  public function getTypes() {
    return $this->types;
  }

  /**
   * Generates RSS link based on topics.
   *
   * @return string
   *   RSS link.
   */
  protected function generateRss() {
    $topics = $this->getTopics();
    $topic_url = NULL;
    $topic_name = NULL;

    // We take only first topic if we have multiple.
    if (!empty($topics)) {
      $topic_name = $topics[0]->name;
      $topic_url = pathauto_cleanstring($topics[0]->name);
    }

    $rss_path = NexteuropaNewsroomHelper::getRssUrl([NEXTEUROPA_NEWSROOM_ALL, $topic_url]);
    $rss_title = !empty($topic_name) ? 'RSS feed : ' . $topic_name : 'RSS feed';

    $rss = '<div class="newsroom_rss">';
    $rss .= theme('feed_icon', [
      'url' => $rss_path,
      'title' => $rss_title,
    ]);
    $rss .= l($rss_title, $rss_path);
    $rss .= '</div>';

    return $rss;
  }

  /**
   * Get filters: type, topics based on the request.
   */
  protected function getFilters() {
    $path = md5(current_path());
    $cache_key = 'newsroom:summary_filter:' . $path;

    if ($cache = cache_get($cache_key, NEXTEUROPA_NEWSROOM_CACHE_TABLE)) {
      $config = $cache->data;
    }
    else {
      $selected_topics = [];

      if ($entity = $this->getEntityFromRequest()) {
        if ($associated_topic_id = NexteuropaNewsroomHelper::getFieldValue($entity, 'field_newsroom_associated_topic', 'tid')) {
          // If it has the associated field, try to load topic.
          $selected_topics[] = $associated_topic_id;
        }
      }

      $types = NexteuropaNewsroomVocabularyHelper::getNewsroomTypes();
      // We need only the first level of types.
      foreach ($types as $key => $type) {
        if ($type->depth > 0) {
          unset($types[$key]);
        }
      }

      $topics = [];
      foreach ($selected_topics as $topic_id) {
        if ($topic_term = NexteuropaNewsroomVocabularyHelper::getNewsroomTopic($topic_id)) {
          $topics[] = $topic_term;
        }
      }

      $config['topic'] = $topics;
      $config['type'] = $types;

      cache_set($cache_key, $config, NEXTEUROPA_NEWSROOM_CACHE_TABLE, time() + variable_get('nexteuropa_newsroom_ct_summary_filter', 3600));
    }

    $this->setTopics($config['topic']);
    $this->setTypes($config['type']);
  }

  /**
   * Tries to find the entity based on request.
   *
   * @return object
   *   Drupal entity: node, taxonomy term.
   */
  protected function getEntityFromRequest() {
    $entity = NULL;
    $current_path = menu_get_item();
    // We are on a view object, it's a term argument,
    // let's use to filter results.
    if ($current_path['page_callback'] === 'views_page' && $current_path['path'] === 'taxonomy/term/%') {
      $argument_values = array_values($current_path['page_arguments']);
      $last_argument_element = end($argument_values);
      // We may have a term page, let's try to load it.
      if (is_numeric($last_argument_element)) {
        $entity = taxonomy_term_load($last_argument_element);
      }
    }
    elseif ($current_path['page_callback'] === 'node_page_view') {
      // It is a node page take node entity from request.
      $entity = $current_path['map'][1];
    }
    elseif (!empty($current_path['page_arguments'][0]->tid)) {
      // It's taxonomy term without views.
      $entity = $current_path['page_arguments'][0];
    }

    return $entity;
  }

  /**
   * Generates the summary block.
   *
   * @return string
   *   The content of the block.
   */
  public function generateContent() {
    $this->getFilters();
    $events_terms = NexteuropaNewsroomVocabularyHelper::getEventsTermsIds();
    $blocks = [];
    $output = NULL;

    foreach ($this->getTypes() as $type) {
      // We exclude event content types, because we display them as agenda.
      if (!empty($events_terms) && in_array($type->tid, $events_terms)) {
        continue;
      }

      $blocks[] = new NexteuropaNewsroomBlock($type, $this->getTopics());
    }

    $blocks[] = new NexteuropaNewsroomBlockAgenda(NULL, $this->getTopics());

    usort($blocks, ['NexteuropaNewsroomSummaryBlock', 'sortBlocks']);
    foreach ($blocks as $block) {
      $output .= $block->generateContent();
    }
    return theme('newsroom_summary_block', [
      'content' => $output,
      'rss' => $this->generateRss(),
    ]);
  }

  /**
   * Callback: sorts newsroom boxes.
   */
  public function sortBlocks($a, $b) {
    $display_highlights_begin = variable_get('nexteuropa_newsroom_display_highlights_begin', 0);
    $agenda_after_highlights = variable_get('nexteuropa_newsroom_agenda_after_highlights', 0);
    $order_by_last_update = variable_get('nexteuropa_newsroom_order_by_last_update', 0);

    $type = !empty($a->getType()) && !empty($b->getType());

    if ($display_highlights_begin && $a->getHighlighted() != $b->getHighlighted()) {
      $value = $a->getHighlighted() > $b->getHighlighted() ? -1 : 1;
    }
    elseif ($agenda_after_highlights && $a->getIsAgenda() != $b->getIsAgenda()) {
      $value = ((int) $a->getIsAgenda()) > ((int) $b->getIsAgenda()) ? -1 : 1;
    }
    elseif ($order_by_last_update && $a->getLatestDate() != $b->getLatestDate()) {
      $value = $a->getLatestDate() > $b->getLatestDate() ? -1 : 1;
    }
    elseif ($type && $a->getType()->depth < $b->getType()->depth) {
      $value = 1;
    }
    elseif ($type && $a->getType()->depth > $b->getType()->depth) {
      $value = -1;
    }
    elseif ($type && $a->getType()->weight < $b->getType()->weight) {
      $value = -1;
    }
    elseif ($type && $a->getType()->weight > $b->getType()->weight) {
      $value = 1;
    }
    else {
      $value = 0;
    }

    return $value;
  }

}
