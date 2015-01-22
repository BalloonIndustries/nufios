<?php

/**
 * @file
 * Lextext editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

/**
 * UI controller.
 */
class LextextUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    
    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'Lextexts',
      'description' => 'Add edit and update lextexts.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );
    
    // Change the overview menu type for the list of lextexts.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    
    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add a lextext',
      'description' => 'Add a new lextext',
      'page callback'  => 'lextext_add_page',
      'access callback'  => 'lextext_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'lextext.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])

    );
    
    // Add menu items to add each different type of entity.
    foreach (lextext_get_types() as $type) {
      $items[$this->path . '/add/' . $type->type] = array(
        'title' => 'Add ' . $type->label,
        'page callback' => 'lextext_form_wrapper',
        'page arguments' => array(lextext_create(array('type' => $type->type))),
        'access callback' => 'lextext_access',
        'access arguments' => array('edit', 'edit ' . $type->type),
        'file' => 'lextext.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
      );
    }

    // Loading and editing lextext entities
    $items[$this->path . '/lextext/' . $wildcard] = array(
      'page callback' => 'lextext_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'lextext_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'lextext.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/lextext/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );
    
    $items[$this->path . '/lextext/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'lextext_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'lextext_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'lextext.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    // Menu item for viewing lextexts
    $items['lextext/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'lextext_page_title',
      'title arguments' => array(1),
      'page callback' => 'lextext_page_view',
      'page arguments' => array(1),
      'access callback' => 'lextext_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }
  
  
  /**
   * Create the markup for the add Lextext Entities page within the class
   * so it can easily be extended/overriden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('lextext_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a lextext.
 *
 * @param $lextext
 *   The lextext object being edited by this form.
 *
 * @see lextext_edit_form()
 */
function lextext_form_wrapper($lextext) {
  // Add the breadcrumb for the form's location.
  lextext_set_breadcrumb();
  return drupal_get_form('lextext_edit_form', $lextext);
}


/**
 * Form callback wrapper: delete a lextext.
 *
 * @param $lextext
 *   The lextext object being edited by this form.
 *
 * @see lextext_edit_form()
 */
function lextext_delete_form_wrapper($lextext) {
  // Add the breadcrumb for the form's location.
  //lextext_set_breadcrumb();
  return drupal_get_form('lextext_delete_form', $lextext);
}


/**
 * Form callback: create or edit a lextext.
 *
 * @param $lextext
 *   The lextext object to edit or for a create form an empty lextext object
 *     with only a lextext type defined.
 */
function lextext_edit_form($form, &$form_state, $lextext) {
  // Add the default field elements.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Lextext Name'),
    '#default_value' => isset($lextext->name) ? $lextext->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
  
  $form['data']['#tree'] = TRUE;

  // Add the field related form elements.
  $form_state['lextext'] = $lextext;
  field_attach_form('lextext', $lextext, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save lextext'),
    '#submit' => $submit + array('lextext_edit_form_submit'),
  );
  
  if (!empty($lextext->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete lextext'),
      '#suffix' => l(t('Cancel'), 'admin/content/lextexts'),
      '#submit' => $submit + array('lextext_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'lextext_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the lextext form
 */
function lextext_edit_form_validate(&$form, &$form_state) {
  $lextext = $form_state['lextext'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('lextext', $lextext, $form, $form_state);
}


/**
 * Form API submit callback for the lextext form.
 * 
 * @todo remove hard-coded link
 */
function lextext_edit_form_submit(&$form, &$form_state) {
  
  $lextext = entity_ui_controller('lextext')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the lextext and go back to the list of lextexts
  
  // Add in created and changed times.
  if ($lextext->is_new = isset($lextext->is_new) ? $lextext->is_new : 0){
    $lextext->created = time();
  }

  $lextext->changed = time();
  
  $lextext->save();
  $form_state['redirect'] = 'admin/content/lextexts';
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function lextext_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/lextexts/lextext/' . $form_state['lextext']->lextext_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a lextext.
 *
 * @param $lextext
 *   The lextext to delete
 *
 * @see confirm_form()
 */
function lextext_delete_form($form, &$form_state, $lextext) {
  $form_state['lextext'] = $lextext;

  $form['#submit'][] = 'lextext_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete lextext %name?', array('%name' => $lextext->name)),
    'admin/content/lextexts/lextext',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for lextext_delete_form
 */
function lextext_delete_form_submit($form, &$form_state) {
  $lextext = $form_state['lextext'];

  lextext_delete($lextext);

  drupal_set_message(t('The lextext %name has been deleted.', array('%name' => $lextext->name)));
  watchdog('lextext', 'Deleted lextext %name.', array('%name' => $lextext->name));

  $form_state['redirect'] = 'admin/content/lextexts';
}



/**
 * Page to add Lextext Entities.
 *
 * @todo Pass this through a proper theme function
 */
function lextext_add_page() {
  $controller = entity_ui_controller('lextext');
  return $controller->addPage();
}


/**
 * Displays the list of available lextext types for lextext creation.
 *
 * @ingroup themeable
 */
function theme_lextext_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="lextext-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer lextext types')) {
      $output = '<p>' . t('Lextext Entities cannot be added because you have not created any lextext types yet. Go to the <a href="@create-lextext-type">lextext type creation page</a> to add a new lextext type.', array('@create-lextext-type' => url('admin/structure/lextext_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No lextext types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}





/**
 * Sets the breadcrumb for administrative lextext pages.
 */
function lextext_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Lextexts'), 'admin/content/lextexts'),
  );

  drupal_set_breadcrumb($breadcrumb);
}



