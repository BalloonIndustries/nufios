<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */


class lextext_handler_edit_link_field extends lextext_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = $values->{$this->aliases['type']};
    
    //Creating a dummy lextext to check access against
    $dummy_lextext = (object) array('type' => $type);
    if (!lextext_access('edit', $dummy_lextext)) {
      return;
    }
    
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $tid = $values->{$this->aliases['tid']};
    
    return l($text, 'admin/content/lextexts/lextext/' . $tid . '/edit');
  }
}
