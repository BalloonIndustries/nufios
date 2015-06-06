<?php
/**
 * @file
 * A wrapper API for the retrieving historical stock quotes from Yahoo Finance.
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
