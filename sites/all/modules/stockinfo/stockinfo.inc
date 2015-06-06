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

function stockinfo_convert_to_timestamp($stock, $key, $value) {
  if ($key == 'last_trade_date') {
      $timestamp = strtotime($stock->last_trade_date . " " . $stock->last_trade_time);
      if(!isset($timestamp)) {
        $timestamp = NULL;
      }
      return $timestamp;
    }
    else if ($key == 'dividend_pay_date' || $key == "ex_dividend_date" || $key == "trade_date") {
      $timestamp = strtotime($stock->$key);
      if(!isset($timestamp)) {
        $timestamp = NULL;
      }
      return $timestamp;
    }
    else {
      return $value;
    }
}

/**
 * Adds quotes to both sides of stock symbol.
 */
function stockinfo_add_quote($s) {
  return('"' . $s . '"');
}

function stockinfo_make_numeric(&$value) {
        if (strpos($value, "M")) {
        $value = str_replace("M", "", $value);
        $value = $value * 1000000;
      }
      elseif (strpos($value, "B")) {
        $value = str_replace("B", "", $value);
        $value = $value * 1000000000;
      }
      elseif (strpos($value, "K")) {
        $value = str_replace("K", "", $value);
        $value = $value * 1000;
      }
      return $value;
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

  $l = 199;
  if (count($symbols) <= $l) {
  if(!is_array($symbols)) {
    return FALSE;
  }
    $s = array_map('urlencode', $symbols);
    $s = array_map('stockinfo_add_quote', $s);
    $s = implode(',', $s);
    $url = "http://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20yahoo.finance.quotes%20where%20symbol%20IN%20($s)&format=json&env=http://datatables.org/alltables.env";
    $nameurl = "http://download.finance.yahoo.com/d/quotes.csv?s=$s&f=sn&e=.csv";
    $name_results = drupal_http_request($nameurl);
    $name_array = _stockinfo_str_getcsv($name_results->data);
    $results = drupal_http_request($url);
    if (_stockinfo_request_failure($results))
      return FALSE;
    $data = drupal_json_decode($results->data);
    $result = $data['query']['results']['quote'];
    $result = array_map("stockinfo_add_name", $result, $name_array);
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

function stockinfo_add_name($result, $name_array) {
  if($name_array[0] == $result["symbol"]) {
    $result["Name"] = $name_array[1];
  }
  return $result;
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