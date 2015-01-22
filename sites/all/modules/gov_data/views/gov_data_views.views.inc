<?php

/**
 * Implements hook_views_data().
 */
function gov_data_views_views_data() {
  $data['gov_data_bill']['table']['group'] = t('Congressional Bills');
  $data['gov_data_bill']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Congressional Bills'),
    'weight' => -10,
    'defaults' => array(
      'field' => 'id',
    ),
  );
  $data['gov_data_bill']['table']['join'] = array(
    'gov_data_person' => array(
      'left_field' => 'id',
      'field' => 'sponsor',
    )
  );
  $data['gov_data_bill']['id'] = array(
    'title' => t('ID number of the government bill'),
    'help' => t('The ID number.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['congress'] = array(
    'title' => t('Congress'),
    'help' => t('The congress that the bill belongs to.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['introduced_date'] = array(
    'title' => t('Introduced Date'),
    'help' => t('Date the bill was introduced.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click_sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['gov_data_bill']['number'] = array(
    'title' => t('Number'),
    'help' => t('Order that the bill was introduced into congress.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['sponsor'] = array(
    'title' => t('Sponsor'),
    'help' => t('The ID of the sponsor to this bill.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'gov_data_person',
      'base field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('Sponsor'),
    ),
  );
  $data['gov_data_bill']['current_status_date'] = array(
    'title' => t('Current Status Date'),
    'help' => t('Date the current status was set.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click_sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['gov_data_bill']['bill_resolution_type'] = array(
    'title' => t('Bill/Resolution Type'),
    'help' => t('Whether a bill is a bill or resolution.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['bill_type'] = array(
    'title' => t('Bill Type'),
    'help' => t('More information about a bill.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['bill_type_label'] = array(
    'title' => t('Label for the Bill'),
    'help' => t('Prepended to the bill to determine if it is a House or Senate Bill.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['current_status'] = array(
    'title' => t('Current Status'),
    'help' => t('The current status of the bill.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['current_status_description'] = array(
    'title' => t('Current Status Description'),
    'help' => t('More information about why a bill is in current status.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['current_status_label'] = array(
    'title' => t('Current Status Label'),
    'help' => t('A less sortable, cleaned up version of the bill status.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['is_alive'] = array(
    'title' => t('Is Alive'),
    'help' => t('Is the bill still alive and active.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['current'] = array(
    'title' => t('Is Current'),
    'help' => t('Is the bill still current.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['noun'] = array(
    'title' => t('Noun'),
    'help' => t('Noun that refers to a bill.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['link'] = array(
    'title' => t('Link'),
    'help' => t('Link to the government page with more information.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_bill']['title'] = array(
    'title' => t('Title'),
    'help' => t('This is the official title of the bill.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['gov_data_person']['table']['group'] = t('Elected Officials');
  $data['gov_data_person']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Elected Officials'),
    'weight' => -10,
    'defaults' => array(
      'field' => 'id',
    ),
  );
  $data['gov_data_person']['id'] = array(
    'title' => t('ID number of the elected person'),
    'help' => t('The ID number.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_person']['birthday'] = array(
    'title' => t('Birthday of the Person'),
    'help' => t('This is the day that the person was born.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click_sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['gov_data_person']['bioguideid'] = array(
    'title' => t('Bioguide ID'),
    'help' => t('ID of the person on congress.gov.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_person']['firstname'] = array(
    'title' => t('First name'),
    'help' => t('First name of the elected official.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_person']['middlename'] = array(
    'title' => t('Middle Name'),
    'help' => t('Middle name or initial of the elected official.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_person']['lastname'] = array(
    'title' => t('Last Name'),
    'help' => t('Last name of the elected official.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_person']['name'] = array(
    'title' => t('Name'),
    'help' => t('Full name and title, along with political party.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_person']['gender'] = array(
    'title' => t('Gender'),
    'help' => t('Gender of the elected official.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_person']['namemod'] = array(
    'title' => t('Suffix'),
    'help' => t('Suffix on the name of the elected official.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_person']['nickname'] = array(
    'title' => t('Nickname'),
    'help' => t('Nickname of the elected official.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_person']['twitterid'] = array(
    'title' => t('Twitter Handle'),
    'help' => t('Name for the Twitter account of the elected official.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_person']['youtubeid'] = array(
    'title' => t('Youtube Channel'),
    'help' => t('Name for the Youtube Channel of the elected official.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['gov_data_vote']['table']['group'] = t('Congressional Votes');
  $data['gov_data_vote']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Congressional Votes'),
    'weight' => -10,
    'defaults' => array(
      'field' => 'id',
    ),
  );
    $data['gov_data_vote']['table']['join'] = array(
    'gov_data_bill' => array(
      'left_field' => 'id',
      'field' => 'related_bill',
    )
  );
  $data['gov_data_vote']['id'] = array(
    'title' => t('ID number of the vote'),
    'help' => t('The ID number.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['created'] = array(
    'title' => t('Created Date'),
    'help' => t('Date that the vote started.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click_sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['gov_data_vote']['category'] = array(
    'title' => t('Category'),
    'help' => t('Category of the vote.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['required'] = array(
    'title' => t('Voting Majority'),
    'help' => t('The required majority for a vote.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['result'] = array(
    'title' => t('Result'),
    'help' => t('Result of the vote.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['source'] = array(
    'title' => t('Source'),
    'help' => t('Source of the vote.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['vote_type'] = array(
    'title' => t('Vote Type'),
    'help' => t('Type of vote.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['session'] = array(
    'title' => t('Session'),
    'help' => t('Session the vote was held in.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['total_minus'] = array(
    'title' => t('Total Minus'),
    'help' => t('Total negative votes.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['total_plus'] = array(
    'title' => t('Total Plus'),
    'help' => t('Total positive votes.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['number'] = array(
    'title' => t('Number'),
    'help' => t('Order of the vote in congress.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['total_other'] = array(
    'title' => t('Total Other'),
    'help' => t('Total other votes.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['category_label'] = array(
    'title' => t('Category Label'),
    'help' => t('Formatted version of the category name.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['chamber'] = array(
    'title' => t('Chamber'),
    'help' => t('Chamber the vote occurred in.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['congress'] = array(
    'title' => t('Congress'),
    'help' => t('Congress the vote happened in.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['missing_data'] = array(
    'title' => t('Missing Data'),
    'help' => t('Missing Data.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['question'] = array(
    'title' => t('Question'),
    'help' => t('What the vote was about.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['question_details'] = array(
    'title' => t('Question Details'),
    'help' => t('Details about the vote.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['related_amendment'] = array(
    'title' => t('Related Amendment'),
    'help' => t('Related amendments to the vote.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_vote']['related_bill'] = array(
    'title' => t('Related Bill'),
    'help' => t('Related bill to the vote.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['gov_data_voter']['table']['group'] = t('Congressional Voters');
  $data['gov_data_voter']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Congressional Voters'),
    'weight' => -10,
    'defaults' => array(
      'field' => 'id',
    ),
  );
  $data['gov_data_voter']['table']['join'] = array(
    'gov_data_person' => array(
      'left_field' => 'id',
      'field' => 'person',
    ),
    'gov_data_vote' => array(
      'left_field' => 'id',
      'field' => 'vote',
    ),
    'gov_data_role' => array(
      'left_field' => 'id',
      'field' => 'person_role',
    ),
  );
  $data['gov_data_voter']['id'] = array(
    'title' => t('ID number of the voter'),
    'help' => t('The ID number.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_voter']['created'] = array(
    'title' => t('Created Date'),
    'help' => t('Date that the vote started.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click_sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['gov_data_voter']['voting_result'] = array(
    'title' => t('Voting Result'),
    'help' => t('How the person voted.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_voter']['voter_type'] = array(
    'title' => t('Voter Type'),
    'help' => t('The type of voter.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_voter']['person'] = array(
    'title' => t('Person'),
    'help' => t('ID of the voter person.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_voter']['person_role'] = array(
    'title' => t('Role'),
    'help' => t('ID of the voter role.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_voter']['vote'] = array(
    'title' => t('Vote'),
    'help' => t('ID of the voter vote.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'gov_data_vote',
      'base field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('Vote'),
    ),
  );

  $data['gov_data_role']['table']['group'] = t('Elected Role');
  $data['gov_data_role']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Elected Role'),
    'weight' => -10,
    'defaults' => array(
      'field' => 'id',
    ),
  );
  $data['gov_data_role']['table']['join'] = array(
    'gov_data_person' => array(
      'left_field' => 'id',
      'field' => 'person',
    )
  );
  $data['gov_data_role']['id'] = array(
    'title' => t('ID number of the role'),
    'help' => t('The ID number.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_role']['enddate'] = array(
    'title' => t('End Date'),
    'help' => t('Date that the role ended.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click_sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['gov_data_role']['description'] = array(
    'title' => t('Description'),
    'help' => t('Description of the role.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_role']['district'] = array(
    'title' => t('District'),
    'help' => t('District of the role.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_role']['state'] = array(
    'title' => t('State'),
    'help' => t('The state that the role is in.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_role']['leadership_title'] = array(
    'title' => t('Leadership Title'),
    'help' => t('The title that the role has to go with it.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_role']['party'] = array(
    'title' => t('Party'),
    'help' => t('The political party.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_role']['person'] = array(
    'title' => t('Person'),
    'help' => t('ID of the person with the role.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'gov_data_person',
      'base field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('Person'),
    ),
  );
  $data['gov_data_role']['startdate'] = array(
    'title' => t('Start Date'),
    'help' => t('Start date of the role.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click_sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['gov_data_role']['phone'] = array(
    'title' => t('Phone'),
    'help' => t('Phone number.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_role']['role_type'] = array(
    'title' => t('Role Type'),
    'help' => t('Political office the role corresponds to.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_role']['senator_class'] = array(
    'title' => t('Senator Class'),
    'help' => t('Which election the senator came into office.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_role']['senator_rank'] = array(
    'title' => t('Senator Rank'),
    'help' => t('The rank of the senator.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_role']['title'] = array(
    'title' => t('title'),
    'help' => t('Short title of the role.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_role']['title_long'] = array(
    'title' => t('Long Title'),
    'help' => t('The long title of the role.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['gov_data_role']['website'] = array(
    'title' => t('Website'),
    'help' => t('Official website of the role.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['gov_data_cosponsor']['table']['group'] = t('Cosponsors');
  $data['gov_data_cosponsor']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Bill Cosponsors'),
    'weight' => -10,
    'defaults' => array(
      'field' => 'id',
    ),
  );
  $data['gov_data_cosponsor']['table']['join'] = array(
    'gov_data_person' => array(
      'left_field' => 'id',
      'field' => 'person',
    ),
    'gov_data_bill' => array(
      'left_field' => 'id',
      'field' => 'bill',
    ),
    'gov_data_role' => array(
      'left_field' => 'id',
      'field' => 'person_role',
    ),
  );
  $data['gov_data_cosponsor']['id'] = array(
    'title' => t('ID number of the cosponsor'),
    'help' => t('The ID number.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_cosponsor']['bill'] = array(
    'title' => t('ID number of the bill'),
    'help' => t('The ID number.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'gov_data_bill',
      'base field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('Bill'),
    ),
  );
  $data['gov_data_cosponsor']['person'] = array(
    'title' => t('ID number of the person'),
    'help' => t('The ID number of the person.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'gov_data_person',
      'base field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('Person'),
    ),
  );
  $data['gov_data_cosponsor']['role'] = array(
    'title' => t('ID number of the role'),
    'help' => t('The ID number of the role.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'gov_data_role',
      'base field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('Role'),
    ),
  );
  $data['gov_data_cosponsor']['joined'] = array(
    'title' => t('Joined Date'),
    'help' => t('Date that the cosponsor joined the bill.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click_sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['gov_data_cosponsor']['withdrawn'] = array(
    'title' => t('Withdrawal Date'),
    'help' => t('Date that the cosponsor withdrew from the bill.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click_sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['gov_data_committee']['table']['group'] = t('Committee');
  $data['gov_data_committee']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Committee'),
    'weight' => -10,
    'defaults' => array(
      'field' => 'id',
    ),
  );
  $data['gov_data_committee']['table']['join'] = array(
    'gov_data_committee' => array(
      'left_field' => 'id',
      'field' => 'parent',
    ),
  );
  $data['gov_data_committee']['id'] = array(
    'title' => t('ID number of the committee'),
    'help' => t('The ID number.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_committee']['abbrev'] = array(
    'title' => t('Abbreviation'),
    'help' => t('Abbreviation of the Committee.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_committee']['parent'] = array(
    'title' => t('Parent Committee'),
    'help' => t('ID of the parent committee.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'gov_data_committee',
      'base field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('Parent Committee'),
    ),
  );
  $data['gov_data_committee']['code'] = array(
    'title' => t('Code'),
    'help' => t('Committee code on government sites.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_committee']['committee_type'] = array(
    'title' => t('Committee Type'),
    'help' => t('The type of committee.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_committee']['jurisdiction'] = array(
    'title' => t('Jurisdiction'),
    'help' => t('The jurisdiction of the committee.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_committee']['name'] = array(
    'title' => t('Name'),
    'help' => t('Name of the committee.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_committee']['url'] = array(
    'title' => t('URL'),
    'help' => t('URL of the committee.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_committee']['obsolete'] = array(
    'title' => t('Obsolete'),
    'help' => t('Boolean to determine if committee exists or not.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['gov_data_committee_member']['table']['group'] = t('Committee Member');
  $data['gov_data_committee_member']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Committee Member'),
    'weight' => -10,
    'defaults' => array(
      'field' => 'id',
    ),
  );
  $data['gov_data_committee_member']['table']['join'] = array(
    'gov_data_person' => array(
      'left_field' => 'id',
      'field' => 'person',
    ),
    'gov_data_committee' => array(
      'left_field' => 'id',
      'field' => 'committee',
    ),
    'gov_data_role' => array(
      'left_field' => 'id',
      'field' => 'person_role',
    ),
  );
  $data['gov_data_committee_member']['id'] = array(
    'title' => t('ID number of the committee member'),
    'help' => t('The ID number.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_committee_member']['role'] = array(
    'title' => t('Role'),
    'help' => t('Role of the committee member.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'gov_data_role',
      'base field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('Role'),
    ),
  );
  $data['gov_data_committee_member']['committee'] = array(
    'title' => t('Committee'),
    'help' => t('ID of the parent committee.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'gov_data_committee',
      'base field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('Committee'),
    ),
  );
  $data['gov_data_committee_member']['committee_type'] = array(
    'title' => t('Committee Type'),
    'help' => t('Committee type.'),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'name', // the field to display in the summary.
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['gov_data_committee_member']['person'] = array(
    'title' => t('Person'),
    'help' => t('ID of the member of the committee.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'gov_data_person',
      'base field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('Person'),
    ),
  );


  return $data;
}
