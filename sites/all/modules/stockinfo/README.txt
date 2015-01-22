
Description:
------------
        
This is a stock quote info module that is meant to allow users to build complex applications on top of it. Based on the Stock API module originally created by Matt Westgate

Features:
---------

This module provides several features and options:

* When a stock is first queried, the request goes over the internet to
  Yahoo Finance. The data retrieved is then stored in a database
  table for later fetches by modules.

* The stock data in the table are periodically refreshed from Yahoo,
  at an admin specified interval.

Database:
---------

This module requires that the database table 'stockinfo' be created.

Installation:
-------------

- Cron must be configured correctly and running on your site
- Copy the stockinfo module directory to the modules directory
- Enable the module in Administer > Modules
- You can change the update frequency in Administer > Settings > stockinfo

API Instructions
----------------
Retrieve Apple's stock quote from Yahoo! 
  
  $stock = stockinfo_fetch(array('AAPL'));

Retrieve multiple stocks from Yahoo!

  $symbols = array('AAPL', 'GOOG', 'MSFT', 'SBUX');
  $stocks = stockinfo_fetch($symbols);

Caching the stock information locally:

  foreach ($stocks as $key => $stock) {
    stockinfo_save(_stockinfo_to_object($stock));
  }

Loading a stock from cache

  $stock = stockinfo_load('AAPL');

Loading multiple stocks from the cache

  $symbols = array('AAPL', 'GOOG', 'MSFT', 'SBUX');
  $stocks = stockinfo_multiload($symbols);

Bugs/Features/Patches:
----------------------

If you want to report bugs, feature requests, or submit a patch, please do so
at the project page on the Drupal web site.
http://drupal.org/project/stockinfo

Author
------

Original module developed by Matt Westgate http://www.lullabot.com/

Fork module developed by Andrew Alexander http://andrewjalexander.com
