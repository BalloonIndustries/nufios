<?php

/**
 * @file
 * A wrapper API for the retreiving government data from GovTrackUS API
 */
function gov_data_vote_pull() {
  gov_data_pull("vote");
}

function gov_data_voter_pull() {
  gov_data_pull("voter");
}

function gov_data_person_pull() {
  gov_data_pull("person");
}

function gov_data_bill_pull() {
  gov_data_pull("bill");
}

function gov_data_role_pull() {
  gov_data_pull("role");
}

function gov_data_committee_pull() {
  gov_data_pull("committee");
}

function gov_data_committee_member_pull() {
  gov_data_pull("committee_member");
}

function gov_data_cosponsor_pull() {
  gov_data_pull("cosponsor");
}

function gov_data_term_pull() {
  gov_data_pull("term");
}

function gov_data_database($type, $bundle, $column, $filter = NULL) {
  switch ($type) {
    case "person":
      $key = "bid";
      $op = 1;
      break;
    case "term":
      $op = 2;
      $key = "bid";
      break;
    case "voter":
    case "cosponsor":
    case "committee_member":
      $key = "bid";
      $op = 0;
      break;
  }
  watchdog("cosponsor 2", print_r($type, true));
  $multiples = db_select("gov_data", "t")
      ->fields("t", array("bid", "gid", "type"))
      ->condition("type", $bundle, "=")
      ->execute();
  gov_data_multiple_process($multiples, $type, $op, $key, $filter);
  /* $query = new EntityFieldQuery();
    $query->entityCondition("entity_type", "gov_data");
    //->fieldCondition("field_data_gov_data_" . $column)
    $query->entityCondition("type", $bundle, "=");
    $multiples = $query->execute();
    watchdog("after", "<pre>" . print_r($bundle, true) . "</pre>");
    watchdog("multiples", "<pre>" . print_r($multiples, true) . "</pre>");
    gov_data_multiple_process($multiples['gov_data'], $type, $op, $key, $filter); */
}

function gov_data_gov_data_mapping_alter(&$item, $type) {
  $entity = entity_create("gov_data", array('type' => $type));
  $fields = field_info_field_map();
  $item->bid = $item->id;
  unset($item->id);
  if ($type == 'bill') {
    unset($item->major_actions);
    $item->sponsor = $item->sponsor->id;
    unset($item->sponsor_role);
    unset($item->titles);
    unset($item->title);
    $item->bill_title = $item->title_without_number;
    unset($item->title_without_number);
    unset($item->source);
    unset($item->source_link);
    unset($item->senate_floor_schedule_postdate);
    unset($item->link);
    $item->link = $item->thomas_link;
    unset($item->thomas_link);
    unset($item->docs_house_gov_postdate);
    unset($item->display_number);
    $item->bill_res_type = $item->bill_resolution_type;
    unset($item->bill_resolution_type);
    $item->current_status_desc = $item->current_status_description;
    unset($item->current_status_description);
    $item->current_status_date = strtotime($item->current_status_date);
    $item->introduced_date = strtotime($item->introduced_date);
    watchdog("full item for bill", "<pre>" . print_r($item, true) . "</pre>");
  }
  elseif ($type == 'role') {
    $item->person = $item->person->id;
    $item->role_title = $item->title;
    unset($item->title);
    unset($item->caucus);
    unset($item->congress_numbers);
    unset($item->role_type_label);
    unset($item->senator_class_label);
    unset($item->senator_rank_label);
    $item->enddate = strtotime($item->enddate);
    $item->startdate = strtotime($item->startdate);
  }
  elseif ($type == 'person') {
    unset($item->committeeassignments);
    unset($item->roles);
    unset($item->cspanid);
    unset($item->gender_label);
    unset($item->link);
    unset($item->osid);
    unset($item->pvsid);
    unset($item->sortname);
    $item->birthday = strtotime($item->birthday);
  }
  elseif ($type == "vote") {
    // Change these values
    unset($item->options);
    unset($item->chamber_label);
    unset($item->link);
    unset($item->source_label);
    $item->created = strtotime($item->created);
    unset($item->missing_data);
    if (isset($item->related_bill->id)) {
      $item->related_bill = $item->related_bill->id;
    }
    else {
      $item->related_bill = NULL;
    }
  }
  elseif ($type == "voter") {
    $item->person_role = $item->person_role->id;
    $item->vote = $item->vote->id;
    $item->person = $item->person->id;
    $item->option = $item->option->value;
    $item->created = strtotime($item->created);
    unset($item->voter_type_label);
    $item->voting_result = $item->option;
    unset($item->option);
  }
  elseif ($type == "cosponsor") {
    $item->joined = strtotime($item->joined);
    $item->withdrawn = (int) strtotime($item->withdrawn);
  }
  elseif ($type == "committee") {
    if (isset($item->committee->id)) {
      $item->parent = $item->committee->id;
    }
    $item->committee_name = $item->name;
    unset($item->name);
    unset($item->jurisdiction_link);
    unset($item->committee);
    unset($item->committee_type_label);
  }
  elseif ($type == "committee_member") {
    $item->person = $item->person->id;
    unset($item->committee_type);
    $item->committee_role = $item->role;
    unset($item->role);
    $item->committee = $item->committee->committee;
    unset($item->role_label);
  }
  elseif ($type == "term") {
    $vocab = taxonomy_vocabulary_machine_name_load('government');
    if (!empty($item)) {
      $terms = $item->terms;
      if (!empty($terms)) {
        foreach ($terms as $term) {
          $result = db_query("SELECT t.vid, t.tid, t.name FROM {taxonomy_term_data} t WHERE t.name = :name AND t.vid = :vid", array(':name' => $term->name, ":vid" => $vocab->vid));
          $result_obj = $result->fetchObject();
          if (empty($result_obj)) {

            $term_save = (object) array(
                  "name" => $term->name,
                  "vocabulary_machine_name" => "government",
                  'vid' => $vocab->vid,
            );
            taxonomy_term_save($term_save);
          }
          else {
            $term_save = $result_obj;
          }

          $duplicate = db_query("SELECT f.entity_id, f.gov_data_bill_terms_tid FROM {field_data_gov_data_bill_terms} AS f ORDER BY delta DESC LIMIT 1")->fetchObject();

          if (!isset($duplicate->entity_id)) {
            $duplicate->entity_id = '';
          }
          if (!isset($duplicate->gov_databill_terms_tid)) {
            $duplicate->gov_data_bill_terms_tid = '';
          }
          
          $gid = db_query("SELECT gid FROM gov_data WHERE bid = :bid", array("bid" => $item->bid))->fetchObject();

          if ($gid->gid != $duplicate->entity_id && $term_save->tid != $duplicate->gov_data_bill_terms_tid) {

            $delta = db_query("SELECT f.delta FROM {field_data_gov_data_bill_terms} f WHERE f.entity_id = :entity_id ORDER BY delta DESC LIMIT 1", array(':entity_id' => $gid->gid))->fetchObject();
            if (!isset($delta->delta)) {
              $delta->delta = 0;
            }
            db_insert("field_data_gov_data_bill_terms")
                ->fields(array(
                  "entity_type" => "gov_data",
                  "bundle" => "bill",
                  "deleted" => 0,
                  "entity_id" => $gid->gid,
                  "revision_id" => NULL,
                  "language" => "und",
                  "delta" => $delta->delta + 1,
                  "gov_data_bill_terms_tid" => $term_save->tid,
                ))->execute();
          }
        }
      }
    }
  }

  foreach ($item as $key => $value) {
    if (empty($value)) {
    watchdog("value is empty what?", "<pre>" . print_r($value, true) . "</pre>");
      $value = 0;
      watchdog("unset key", "<pre>" . print_r($key, true) . "</pre>");
      //unset($key);
      continue;
    }
    elseif ($value == "true") {
      $value = 1;
    }
    elseif ($key == "bid") {
      continue;
    }
    $gov_data_key = "gov_data_" . $key;
    if (isset($fields[$gov_data_key])) {
      if ($fields[$gov_data_key]['type'] == 'entityreference') {
        $val_type = "target_id";
      }
      else {
        $val_type = "value";
      }
    }
    else {
      $val_type = "value";
    }

    $entity->{$gov_data_key}['und'][0][$val_type][0] = $value;
    $entity->bid = $item->bid;
  }
  $item = $entity;
  watchdog("last bill", "<pre>" . print_r($item, true) . "</pre>");
}

function gov_data_filter_by_congress($type) {
  if ($type == "bill") {
    $append = "&order_by=-current_status_date";
  }
  elseif ($type == "vote") {
    $append = '';
  }

  $congresses = variable_get("gov_data_" . $type, array('113'));

  foreach ($congresses as $congress) {
    $url = "https://www.govtrack.us/api/v2/" . $type . "?congress=" . $congress . $append;
    $results = drupal_http_request($url);
    if (_gov_data_request_failure($results))
      return FALSE;
    gov_data_save($results, $type);
  }
}

function gov_data_limit($type, $max_limit) {
  $offset = 0;
  $limit = 6000;
  do {
    $url = "https://www.govtrack.us/api/v2/" . $type . "?limit=" . $limit . "&offset=" . $offset;
    watchdog("url", "<pre>" . print_r($url, true) . "</pre>");
    $results = drupal_http_request($url);
    $offset = $offset + $limit;
    gov_data_save($results, $type);
  } while ($offset < $max_limit); // puts upper limit on offset
}

function gov_data_pull($type) {
  switch ($type) {
    case "bill":
    case "vote":
      gov_data_filter_by_congress($type);
      break;
    case "person":
      $person_picker = variable_get("gov_data_person", array('get_role_person'));
      if (is_array($person_picker)) {
        $person_picker = array_shift(array_values($person_picker));
      }
      if ($person_picker == 'get_role_person') {
        $bundle = "role";
        $column = "person";
        gov_data_database($type, $bundle, $column);
      }
      elseif ($person_picker == "all") {
        $max_limit = 18000;
        gov_data_limit($type, $max_limit);
      }
      break;
    case "committee":
      $max_limit = 1000;
      gov_data_limit($type, $max_limit);
      break;
    case "role":
      $role_picker = variable_get("gov_data_role", array("current"));
      if ($role_picker == 'current') {
        $url = 'https://www.govtrack.us/api/v2/role?current=true';
        $results = drupal_http_request($url);
        if (_gov_data_request_failure($results))
          return FALSE;
        gov_data_save($results, $type);
      }
      elseif ($role_picker == "all") {
        $max_limit = 10000;
        gov_data_limit($type, $max_limit);
      }
      break;
    case "voter":
      $voter_picker = variable_get("gov_data_voter", "person");
      if (is_array($voter_picker)) {
        $voter_picker = array_shift(array_values($voter_picker));
      }
      if ($voter_picker == "person") {
        $bundle = "person";
        $column = "bid";
        $filter = "person";
        gov_data_database($type, $bundle, $column, $filter);
      }
      elseif ($voter_picker == "vote") {
        $bundle = "voter";
        $column = "bid";
        $filter = "vote";
        gov_data_database($type, $bundle, $column, $filter);
      }
      break;
    case "cosponsor":
      watchdog("cosponsor", "<pre>" . print_r("cosponsor", true) . "</pre>");
      $cosponsor_picker = variable_get("gov_data_cosponsor", "bill");
      if (is_array($cosponsor_picker)) {
        $cosponsor_picker = array_shift(array_values($cosponsor_picker));
      }/*
      if ($cosponsor_picker == "person") {
        $bundle = "person";
        $column = "bid";
        $filter = "person";
        gov_data_database($type, $bundle, $column, $filter);
      }*/
      if ($cosponsor_picker == "bill") {
        $bundle = "bill";
        $column = "bid";
        $filter = "bill";
        gov_data_database($type, $bundle, $column, $filter);
      }
      break;
    case "committee_member":
      $committee_picker = variable_get("gov_data_committee_member", "person");
      if (is_array($committee_picker)) {
        $committee_picker = array_shift(array_values($committee_picker));
      }
      if ($committee_picker == "person") {
        $bundle = "person";
        $column = "bid";
        $filter = "person";
        gov_data_database($type, $bundle, $column, $filter);
      }
      elseif ($committee_picker == "committee") {
        $bundle = "committee";
        $column = "bid";
        $filter = "committee";
        gov_data_database($type, $bundle, $column, $filter);
      }
      break;
    case "term":
      $bundle = "bill";
      $column = "bid";
      $filter = "bill";
      gov_data_database($type, $bundle, $column, $filter);
      break;
  }
}

function gov_data_generate_url($single, $type, $op, $key, $filter = NULL) {
  $appended = "";
  $prepended = "";
  watchdog("single no key", "<pre>" . print_r($single, true) . "</pre>");
  watchdog("key", "<pre>" . print_r($key, true) . "</pre>");
  if ($op == 1) {
    $url = "https://www.govtrack.us/api/v2/" . $type . "/" . $single->bid;
    watchdog("url", "<pre>" . print_r($url, true) . "</pre>");
  }
  elseif ($op == 0) {
    if ($type == "voter") {
      $prepended = "vote_";
    }
    elseif ($type == "cosponsor") {
      $appended = "ship";
    }
    $url = "https://www.govtrack.us/api/v2/" . $prepended . $type . $appended . "?" . $filter . "=" . $single->bid;
    watchdog("url", "<pre>" . print_r($url, true) . "</pre>");
  }
  elseif ($op == 2) {
    $url = "https://www.govtrack.us/api/v2/bill/" . $single->bid;
    watchdog("url", "<pre>" . print_r($url, true) . "</pre>");
  }
  return $url;
}

function gov_data_multiple_process($multiples, $type, $op, $key = NULL, $filter = NULL) {
  foreach ($multiples as $single) {
    watchdog("single", "<pre>" . print_r($single, true) . "</pre>");
    $url = gov_data_generate_url($single, $type, $op, $key, $filter);
    $results = drupal_http_request($url);
    if (_gov_data_request_failure($results))
      return FALSE;

    gov_data_save($results, $type);
  }
}

function gov_data_item_save($item, $type) {

  drupal_alter('gov_data_mapping', $item, $type);
  
  watchdog("before save", "<pre>" . print_r($item, true) . "</pre>");

  // Check to make sure the saved data isn't a duplicate
  $result = db_select("gov_data", "g")
          ->fields("g", array("bid"))
          ->condition("bid", $item->bid, "=")
          ->condition("type", $item->type, "=")
          ->execute()->fetchCol();

  watchdog("result", "<pre>" . print_r($result, true) . "</pre>");

  if (!empty($result) || $item->type == "term") {
    
  }
  else {

    entity_save('gov_data', $item);
  }
}

function gov_data_save($results, $type) {
  
  watchdog("role stuff", "<pre>" . print_r($results, true) . "</pre>");

  if ($type == "term") {
    $item = json_decode($results->data);
    gov_data_item_save($item, $type);
  }
  else {

    $items = json_decode($results->data)->objects;

    foreach ($items as $item) {
      watchdog("committee items", "<pre>" . print_r($item, true) . "</pre>");
      gov_data_item_save($item, $type);
    }
  }
}

/**
 * Internal helper function to deal cleanly with various HTTP response codes.
 */
function _gov_data_request_failure($results) {
  switch ($results->code) {
    case '200': // Success!
    case '304': // Not modified, nothing to do.
      return FALSE;
    default:
      watchdog('gov_data', 'Failed to retrieve government data with error: %error', array('%error' => $results->error));
      return TRUE;
  }
  return FALSE;
}
