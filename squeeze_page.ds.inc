<?php
/**
 * @file
 * squeeze_page.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function squeeze_page_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|advanced_squeeze_page|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'advanced_squeeze_page';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|advanced_squeeze_page|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function squeeze_page_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|advanced_squeeze_page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'advanced_squeeze_page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'flexible:advanced_squeeze_page';
  $ds_layout->settings = array(
    'css_id' => '',
    'class' => '',
    'sticky' => 0,
    'layout' => 'flexible:advanced_squeeze_page',
    'hide_sidebars' => 0,
    'pipeline' => 'standard',
    'hide_empty_regions' => '',
    'ds_panels' => 1,
    'did' => 1,
    'theme' => 'panels_flexible',
  );
  $export['node|advanced_squeeze_page|default'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|advanced_squeeze_page|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'advanced_squeeze_page';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'panels-twocol_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'classes' => array(),
  );
  $export['node|advanced_squeeze_page|full'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|basic_squeeze_page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'basic_squeeze_page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'flexible:basic_squeeze_page';
  $ds_layout->settings = array(
    'css_id' => '',
    'class' => '',
    'sticky' => 0,
    'layout' => 'flexible:basic_squeeze_page',
    'hide_sidebars' => 0,
    'pipeline' => 'standard',
    'hide_empty_regions' => FALSE,
    'ds_panels' => TRUE,
    'did' => '2',
    'theme' => 'panels_flexible',
  );
  $export['node|basic_squeeze_page|default'] = $ds_layout;

  return $export;
}
