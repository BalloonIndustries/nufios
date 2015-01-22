<?php

/**
 * @file
 * Lextext type editing UI.
 */

/**
 * UI controller.
 */
class LextextTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
		$items[$this->path]['description'] = 'Manage lextext entity types, including adding
		and removing fields and the display of fields.';
    return $items;
  }
}

/**
 * Generates the lextext type editing form.
 */
function lextext_type_form($form, &$form_state, $lextext_type, $op = 'edit') {

  if ($op == 'clone') {
    $lextext_type->label .= ' (cloned)';
    $lextext_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $lextext_type->label,
    '#description' => t('The human-readable name of this lextext type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($lextext_type->type) ? $lextext_type->type : '',
    '#maxlength' => 32,
//    '#disabled' => $lextext_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'lextext_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this lextext type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['data']['#tree'] = TRUE;

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save lextext type'),
    '#weight' => 40,
  );

  //Locking not supported yet
  /*if (!$lextext_type->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete lextext type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('lextext_type_form_submit_delete')
    );
  }*/
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function lextext_type_form_submit(&$form, &$form_state) {
  $lextext_type = entity_ui_form_submit_build_entity($form, $form_state);
  $lextext_type->save();
  $form_state['redirect'] = 'admin/structure/lextext_types';
}

/**
 * Form API submit callback for the delete button.
 */
function lextext_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/lextext_types/manage/' . $form_state['lextext_type']->type . '/delete';
}
