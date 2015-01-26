<?php

/**
 * @file
 * Providing extra functionality for the Lextext UI via views.
 */


/**
 * Implements hook_views_data()
 */
function lextext_views_data_alter(&$data) { 
  $data['lextext']['link_lextext'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the lextext.'),
      'handler' => 'lextext_handler_link_field',
    ),
  );
  $data['lextext']['edit_lextext'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the lextext.'),
      'handler' => 'lextext_handler_edit_link_field',
    ),
  );
  $data['lextext']['delete_lextext'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the lextext.'),
      'handler' => 'lextext_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows lextexts/lextext/%tid/op
  $data['lextext']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this lextext.'),
      'handler' => 'lextext_handler_lextext_operations_field',
    ),
  );
}


/**
 * Implements hook_views_default_views().
 */
function lextext_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'lextexts';
  $view->description = 'A list of all lextexts';
  $view->tag = 'lextexts';
  $view->base_table = 'lextext';
  $view->human_name = 'Lextexts';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Lextexts';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create any lextext type';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'tid' => 'tid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No lextexts have been created yet';
  /* Field: Lextext: Lextext ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'lextext';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid']['empty_zero'] = 0;
  /* Field: Lextext: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'lextext';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  /* Field: Lextext: Link */
  $handler->display->display_options['fields']['link_lextext']['id'] = 'link_lextext';
  $handler->display->display_options['fields']['link_lextext']['table'] = 'lextext';
  $handler->display->display_options['fields']['link_lextext']['field'] = 'link_lextext';
  $handler->display->display_options['fields']['link_lextext']['label'] = 'View';
  $handler->display->display_options['fields']['link_lextext']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_lextext']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_lextext']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_lextext']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_lextext']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_lextext']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_lextext']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_lextext']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_lextext']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_lextext']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_lextext']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_lextext']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_lextext']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_lextext']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_lextext']['empty_zero'] = 0;
  /* Field: Lextext: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'lextext';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['operations']['empty_zero'] = 0;
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'lextexts_admin_page');
  $handler->display->display_options['path'] = 'admin/content/lextexts/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Lextexts';
  $handler->display->display_options['tab_options']['description'] = 'Manage lextexts';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['lextexts'] = array(
    t('Master'),
    t('Lextexts'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Empty '),
    t('No lextexts have been created yet'),
    t('Lextext ID'),
    t('.'),
    t(','),
    t('Name'),
    t('View'),
    t('Operations links'),
    t('Page'),
  );
  $views[] = $view;
  return $views;

}
