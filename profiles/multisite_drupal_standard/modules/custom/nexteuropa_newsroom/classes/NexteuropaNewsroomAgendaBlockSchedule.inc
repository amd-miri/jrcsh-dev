<?php

/**
 * @file
 * Code for the NexteuropaNewsroomAgendaBlockSchedule class.
 */

/**
 * NexteuropaNewsroomAgendaBlockSchedule class.
 */
class NexteuropaNewsroomAgendaBlockSchedule extends NexteuropaNewsroomAgenda {

  /**
   * NexteuropaNewsroomAgendaBlockSchedule constructor.
   *
   * @param object $type
   *   Newsroom type taxonomy term.
   * @param array $topics
   *   Newsroom topic taxonomy term.
   * @param object $current_day
   *   Current date.
   */
  public function __construct($type, array $topics, $current_day) {
    $this->setIsBlock(TRUE);
    parent::__construct($type, $topics, $current_day);
  }

  /**
   * Returns the number of items per block.
   *
   * @return int
   *   Number of items.
   */
  public function getItemsNumber() {
    return NexteuropaNewsroomHelper::getBlockItemsNumber(FALSE);
  }

  /**
   * Preprocessing of the query before the execution.
   *
   * @param object $query
   *   Query object.
   *
   * @return object
   *   Query object.
   */
  protected function processQuery($query) {

    if (empty($this->getTopics())) {
      return $query;
    }
    else {
      $query->condition('topic_data.tid', $this->getTopicsId());
    }

    return $query;
  }

}
