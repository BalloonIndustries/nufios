<?php

/**
 * This field handler aggregates operations that can be done on a lextext
 * under a single field providing a more flexible way to present them in a view
 */
class lextext_handler_lextext_operations_field extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['tid'] = 'tid';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('lextext', 'admin/content/lextexts/lextext', array($this->get_value($values, 'tid')));
    
    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
