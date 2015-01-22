<?php

/**
 * @file
 * A wrapper API for the retreiving stock quotes from Yahoo! Finance.
 */
/*
 * Historical stock fetch - grabs historical data for stocks
 */
function stockinfo_historical_fetch($symbol) {
  $date = variable_get("stockinfo_historical_from_date", variable_get("stockinfo_historical_from_date_default"));
  $date['month'] = $date['month'] - 1;
  $url = "http://ichart.yahoo.com/table.csv?s=" . $symbol . "&a=" . $date['month'] . "&b=" . $date['day'] . "&c=" . $date['year'] . "&d=" . date("m") . "&e=" . date("d") . "&f=" . date("Y") . "&g=w&ignore=.csv";
  $results = drupal_http_request($url);
  if (_stockinfo_request_failure($results))
    return FALSE;

  // Symbols are returned in CSV format.
  return _stockinfo_historical_parse_csv($results->data);
}

/*
 * Function that deals with stock items that occasionally have problematic values
 */

function stockinfo_trouble($fields, $s) {
  $symbols = explode("+", $s);
  $all_data = array();
  foreach ($fields as $label => $field) {
    $url = "http://download.finance.yahoo.com/d/quotes.csvr?s=$s&f=$field&e=.csv";
    $results = drupal_http_request($url);
    if (_stockinfo_request_failure($results))
      return FALSE;
    $data = str_replace("\n\r", "\n", $results->data);
    $data = explode("\n", $data);
    // Removes empty array item at the end of the array
    array_pop($data);
    $data = array_combine($symbols, $data);
    foreach ($data as $key_datum => $datum) {
      $all_data[$key_datum][$label] = $datum;
    }
  }
  return $all_data;
}

/**
 * Implement a HTTP request to Yahoo Finance to retrieve stock quotes.
 *
 * @param $symbols array
 *   An array of ticker symbols to send to Yahoo!. There is not limit on the
 *   number of symbols. Yahoo! limits 200 symbols per request, so we queue up
 *   the request into batches.
 *
 * @return
 *   An array of stocks with stock information fromm Yahoo!. False on failure.
 */
function stockinfo_fetch($symbols) {

  // Step 1: Yahoo! limits stock updates to 200 or less per request. Split up larger arrays.
  $l = 199;
  if (count($symbols) <= $l) {
    $s = array_map('urlencode', $symbols);
    $s = implode('+', $s);
    $fields = stockinfo_get_quotetype();
    $quotetype = $fields['quotetype'];
    $url = "http://download.finance.yahoo.com/d/quotes.csvr?s=$s&f=s0n0$quotetype&e=.csv";
    $results = drupal_http_request($url);
    if (_stockinfo_request_failure($results))
      return FALSE;

    $trouble = stockinfo_trouble($fields['trouble_properties'], $s);
    $result = _stockinfo_parse_csv($results->data);
    $trouble_array = array();
    foreach ($result as &$result_value) {
      if (!is_array($result_value)) {
        continue;
      }
      $trouble_array = $trouble[$result_value['symbol']];
      if (!is_array($trouble_array)) {
        $trouble_array = array();
      }
      $result_value = array_merge($trouble_array, $result_value);
    }
    return $result;
  }
  else {
    $batches = array_chunk($symbols, $l);
    $stocks = array();
    foreach ($batches as $key => $batch) {
      $stocks = array_merge(stockinfo_fetch($batch), $stocks);
    }
    return $stocks;
  }
}

function stockinfo_property_page() {
  $form = array();
  $form['stockinfo_property'] = array(
    '#type' => 'checkboxes',
    '#options' => variable_get("stockinfo_field_label"),
    '#title' => t('Stock Properties to Collect'),
    '#default_value' => variable_get('stockinfo_property', array()),
  );
  return system_settings_form($form);
}

/**
 * Return the field parameter string to pull the correct columns from Yahoo!
 */
function stockinfo_get_quotetype() {
  $properties = variable_get("stockinfo_property");
  $machine_properties = variable_get("stockinfo_field_machine_name");
  $mapped_properties = array("symbol", "name");
  // properties that cause problems due to not being properly contained from Yahoo
  $trouble = array("k3", "b6", "a5", "f6", "j1");
  $trouble_properties = array();
  $quotetype = '';
  foreach ($properties as $key => $value) {
    if (empty($value)) {
      
    }
    elseif (in_array($value, $trouble)) {
      $trouble_properties[$machine_properties[$value]] = $value;
    }
    else {
      $quotetype .= $value;
      $mapped_properties[] = $machine_properties[$value];
    }
  }
  return array("quotetype" => $quotetype, "mapped_properties" => $mapped_properties, "trouble_properties" => $trouble_properties);
}

/**
 * Helper function to convert a historical feed from Yahoo! to an array.
 */
function _stockinfo_historical_parse_csv($data) {
  $csv = _stockinfo_str_getcsv($data);
  foreach ($csv[0] as &$map) {
    $map = strtolower($map);
    $map = str_replace(" ", "_", $map);
    if ($map == "high" || $map == "low" || $map == "close" || $map == "adj_close") {
      $map = "stockinfo_historical_" . $map;
    }
    elseif ($map == "date") {
      
    }
    else {
      $map = "stockinfo_" . $map;
    }
  }
  foreach ($csv as $row => $value) {
    if ($row != 0) {
      $csv[$row] = array_combine($csv[0], $value);
    }
  }
  unset($csv[0]);
  return $csv;
}

/**
 * Helper function to convert a feed from Yahoo! to an array.
 */
function _stockinfo_parse_csv($data) {
  $stocks = array();
  $lines = array();
  $pre_lines = _stockinfo_str_getcsv($data);
  // Clean up the data.
  $quotetype = stockinfo_get_quotetype();
  $mapped_properties = $quotetype['mapped_properties'];
  $quote_length = ((drupal_strlen($quotetype['quotetype']) + 4) / 2);
  foreach ($pre_lines as $key => $stock) {
    // Checks whether the number of keys in the quote type matches the result, otherwise passes a warning
    if (count($stock) == $quote_length) {
      $combine = array_combine($mapped_properties, $stock);
      $lines[] = $combine;
    }
    else {
      watchdog("Stock Info", "Error parsing stock: " . $stock[0]);
    }
  }

  foreach ($lines as $key => $stock) {
    foreach ($stock as $key => $value) {
      // Clean up and normalize the data
      $value = trim($value, '"');
      if ($value == '0.00')
        $value = 0;
      elseif ($value == '0.00%')
        $value = 0;
      $stock[$key] = $value;
    }
    $stocks[] = $stock;
  }
  return $stocks;
}

/**
 * Internal helper function to deal cleanly with various HTTP response codes.
 */
function _stockinfo_request_failure($results) {
  switch ($results->code) {
    case '200': // Success!
    case '304': // Not modified, nothing to do.
      return FALSE;
    default:
      watchdog('stockinfo', 'Failed to retrieve stock quotes with error: %error', array('%error' => $results->error));
      return TRUE;
  }
  return FALSE;
}

/**
 * Internal helper function to change text values returned for float
 * fields to '0'.
 */
function _stockinfo_fix_floats($stock) {
  $stock = (array) $stock;
  $schema = drupal_get_schema('stockinfo');

  foreach ($schema['fields'] as $name => $field) {
    if ($field['type'] == 'float' && isset($stock[$name]) && !is_numeric($stock[$name])) {
      $stock[$name] = 0;
    }
  }

  return (object) $stock;
}

/*
 * Helper function to convert CSV string to array for all PHP versions.
 */

function _stockinfo_str_getcsv($input, $delimiter = ',', $enclosure = '"', $escape = NULL, $eol = NULL) {
  $array = array();
  $input = trim($input);
  if (function_exists('str_getcsv')) {
    $array = array_map('str_getcsv', preg_split('/\r\n?|\n/', $input));
  }
  else {
    $temp = fopen("php://memory", "rw");
    fwrite($temp, $input);
    fseek($temp, 0);
    while (($data = fgetcsv($temp, 4096, $delimiter, $enclosure)) !== FALSE) {
      $array[] = $data;
    }
    fclose($temp);
  }
  return $array;
}
