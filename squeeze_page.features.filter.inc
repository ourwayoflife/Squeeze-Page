<?php
/**
 * @file
 * squeeze_page.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function squeeze_page_filter_default_formats() {
  $formats = array();

  // Exported format: Display Suite code
  $formats['ds_code'] = array(
    'format' => 'ds_code',
    'name' => 'Display Suite code',
    'cache' => '0',
    'status' => '1',
    'weight' => '12',
    'filters' => array(
      'ds_code' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
