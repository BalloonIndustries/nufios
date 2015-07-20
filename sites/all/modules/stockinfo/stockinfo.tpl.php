<div class="stockinfo-content">
  <p><span class="stockinfo-header">Name: </span>
    <span><?php print render($element->name); ?></span></p>
  <p><span class="stockinfo-header">Symbol: </span>
    <span><?php print render($element->symbol); ?></span></p>
  <p><span class="stockinfo-header">Exchange: </span>
    <span><?php print render($element->stock_exchange); ?></span></p>
  <p><span class="stockinfo-header">Price: </span>
    <span><?php print render($element->last_trade_price_only); ?></span></p>
  <p><span class="stockinfo-header">Volume: </span>
    <span><?php print render($element->volume); ?></span></p>
  <p><span class="stockinfo-header">Market Cap: </span>
    <span><?php print render($element->market_capitalization); ?></span></p>
  <p><span class="stockinfo-header">Average Daily Volume: </span>
    <span><?php print render($element->average_daily_volume); ?></span></p>
  <p><span class="stockinfo-header">Change in Price: </span>
    <span><?php print render($element->change_); ?></span></p>
  <p><span class="stockinfo-header">Change in Percentage: </span>
    <span><?php print render($element->changein_percent); ?></span></p>
  <p><span class="stockinfo-header">Last Trade: </span>
    <span><?php print render($element->last_trade_date); ?></span></p>
  <p><span class="stockinfo-header">Bid: </span>
    <span><?php print render($element->bid); ?></span></p>
  <p><span class="stockinfo-header">Ask: </span>
    <span><?php print render($element->ask); ?></span></p>
  <p><span class="stockinfo-header">Previous Close: </span>
    <span><?php print render($element->previous_close); ?></span></p>
  <p><span class="stockinfo-header">Open: </span>
    <span><?php print render($element->open); ?></span></p>
  <p><span class="stockinfo-header">Day's Range: </span>
    <span><?php print render($element->days_range); ?></span></p>
  <p><span class="stockinfo-header">Year's Range: </span>
    <span><?php print render($element->years_range); ?></span></p>
  <p><span class="stockinfo-header">Change from Year Low: </span>
    <span><?php print render($element->change_from_year_low); ?></span></p>
  <p><span class="stockinfo-header">Percent Change from Year Low: </span>
    <span><?php print render($element->percent_change_from_year_low); ?></span></p>
  <p><span class="stockinfo-header">Change from Year High: </span>
    <span><?php print render($element->change_from_year_high); ?></span></p>
  <p><span class="stockinfo-header">Percent Change from Year High: </span>
    <span><?php print render($element->percebt_change_from_year_high); ?></span></p>
  <p><span class="stockinfo-header">Change from Year Low: </span>
    <span><?php print render($element->change_from_year_low); ?></span></p>
  <p><span class="stockinfo-header">EPS: </span>
    <span><?php print render($element->earnings_share); ?></span></p>
  <p><span class="stockinfo-header">EPS Estimate for the Current Year: </span>
    <span><?php print render($element->e_p_s_estimate_current_year); ?></span></p>
  <p><span class="stockinfo-header">EPS Estimate for the Next Year: </span>
    <span><?php print render($element->e_p_s_estimate_next_year); ?></span></p>
  <p><span class="stockinfo-header">EPS Estimate for the Next Quarter: </span>
    <span><?php print render($element->e_p_s_estimate_next_quarter); ?></span></p>
  <!-- Add price_e_p_s_estimate_current_year and next_year here -->
  <p><span class="stockinfo-header">Price/Earnings Ratio: </span>
    <span><?php print render($element->p_e_ratio); ?></span></p>
  <p><span class="stockinfo-header">Short Ratio: </span>
    <span><?php print render($element->short_ratio); ?></span></p>
  <p><span class="stockinfo-header">Dividend Pay Date: </span>
    <span><?php print render($element->dividend_pay_date); ?></span></p>
  <p><span class="stockinfo-header">Ex-Dividend Pay Date: </span>
    <span><?php print render($element->ex_dividend_date); ?></span></p>
  <p><span class="stockinfo-header">Dividend Yield: </span>
    <span><?php print render($element->dividend_yield); ?></span></p>
  <p><span class="stockinfo-header">One Year Target Price: </span>
    <span><?php print render($element->oneyr_target_price); ?></span></p>
  <p><span class="stockinfo-header">PEG Ratio: </span>
    <span><?php print render($element->p_e_g_ratio); ?></span></p>
  <p><span class="stockinfo-header">Book Value: </span>
    <span><?php print render($element->book_value); ?></span></p>
  <p><span class="stockinfo-header">Price to Book: </span>
    <span><?php print render($element->price_book); ?></span></p>
  <p><span class="stockinfo-header">Price to Sales: </span>
    <span><?php print render($element->price_sales); ?></span></p>
  <p><span class="stockinfo-header">EBITDA: </span>
    <span><?php print render($element->e_b_i_t_d_a); ?></span></p>
  <p><span class="stockinfo-header">Fifty Day Moving Average: </span>
    <span><?php print render($element->fiftyday_moving_average); ?></span></p>
  <p><span class="stockinfo-header">Change from Fifty Day Moving Average: </span>
    <span><?php print render($element->change_from_fiftyday_moving_average); ?></span></p>
  <p><span class="stockinfo-header">Percent Change from Fifty Day Moving Average: </span>
    <span><?php print render($element->percent_change_from_fiftyday_moving_average); ?></span></p>
  <p><span class="stockinfo-header">Two Hundred Day Moving Average: </span>
    <span><?php print render($element->two_hundredday_moving_average); ?></span></p>
  <p><span class="stockinfo-header">Change from Two Hundred Day Moving Average: </span>
    <span><?php print render($element->change_from_two_hundredday_moving_average); ?></span></p>
  <p><span class="stockinfo-header">Percent Change from Two Hundred Day Moving Average: </span>
    <span><?php print render($element->percent_change_from_two_hundredday_moving_average); ?></span></p>
  <p><span class="stockinfo-header">Day's Value Change: </span>
    <span><?php print render($element->days_value_change); ?></span></p>
  <p><span class="stockinfo-header">Last Updated: </span>
    <span><?php print render($element->changed); ?></span></p>
</div>