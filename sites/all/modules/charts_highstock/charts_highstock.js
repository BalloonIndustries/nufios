/**
 * @file
 * JavaScript integration between Highstock and Drupal.
 */
(function ($) {

Drupal.behaviors.chartsHighstock = {};
Drupal.behaviors.chartsHighstock.attach = function(context, settings) {
  $('.charts-highchart').once('charts-highchart', function() {
    if ($(this).attr('data-chart')) {
      var config = $.parseJSON($(this).attr('data-chart'));
      $(this).highstock(config);
    }
  });
};

})(jQuery);
