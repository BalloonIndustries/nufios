<?php

/**
 * Implements hook_views_data().
 */
function sentiment_stat_views_data()
{

    $data = array();

    $data['sentiment_stat']['table']['group'] = t('Sentiment Statistics');

    $data['sentiment_stat']['table']['base'] = array(
        'title' => t('Sentiment Statistics'),
    );
    
    $data['sentiment_stat']['sid'] = array(
    'title' => t('SID'),
    'help' => t('The statistic ID.'),
    'field' => array(
        'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
            'relationship' => array(
        'base' => 'sentiment_stat',
        'field' => 'sid',
        'handler' => 'views_handler_relationship',
        'label' => t('Statistics'),
    ),
);
    
        $data['sentiment_stat']['variance'] = array(
    'title' => t('Variance'),
    'help' => t('The variance.'),
    'field' => array(
        'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
);
        
            $data['sentiment_stat']['mean'] = array(
    'title' => t('Mean'),
    'help' => t('The mean.'),
    'field' => array(
        'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
);
            
                $data['sentiment_stat']['std'] = array(
    'title' => t('Standard Deviation'),
    'help' => t('The standard deviation.'),
    'field' => array(
        'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
);
                
                    $data['sentiment_stat']['zscore'] = array(
    'title' => t('Z-Score'),
    'help' => t('The Z-Score.'),
    'field' => array(
        'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_numeric',
    ),
);
    
    $data['sentiment_stat']['type'] = array(
    'title' => t('Type'),
    'help' => t('The type of record.'),
    'field' => array(
        'handler' => 'views_handler_field',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
);
    
    $data['sentiment_stat']['category'] = array(
    'title' => t('Category'),
    'help' => t('The category of record.'),
    'field' => array(
        'handler' => 'views_handler_field',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
);
    $data['sentiment_stat']['date'] = array(
    'title' => t('Date'),
    'help' => t('The record date.'),
    'field' => array(
        'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_date',
    ),
    );
    
    $data['sentiment_stat']['table']['join'] = array(
    'sentiment_stat' => array(
        'left_field' => 'sid',
        'field' => 'sid',
    ),
);

    return $data;

}
