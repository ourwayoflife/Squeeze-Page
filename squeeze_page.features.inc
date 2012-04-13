<?php
/**
 * @file
 * squeeze_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function squeeze_page_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "stylizer" && $api == "stylizer") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function squeeze_page_node_info() {
  $items = array(
    'advanced_squeeze_page' => array(
      'name' => t('Advanced Squeeze Page'),
      'base' => 'node_content',
      'description' => t('Use this content type to create advanced squeeze page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'basic_squeeze_page' => array(
      'name' => t('Basic Squeeze Page'),
      'base' => 'node_content',
      'description' => t('Use this content type to create basic squeeze page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_themekey_features_rule_chain_import().
 */
function squeeze_page_themekey_features_rule_chain_import() {
  if (!defined('THEMEKEY_PAGECACHE_UNSUPPORTED')) {
    define('THEMEKEY_PAGECACHE_UNSUPPORTED', 0);
	define('THEMEKEY_PAGECACHE_SUPPORTED', 1);
	define('THEMEKEY_PAGECACHE_TIMEBASED', 2);
  }
  $rules = array(
    0 => array(
	  'rule' => array(
	  'property' => 'node:type',
	  'operator' => '=',
	  'value' => 'basic_squeeze_page',
	  'theme' => 'omega',
	  'enabled' => '1',
	  'wildcards' => array(),
	),
	'string' => '"node:type = basic_squeeze_page >>> omega"',
	  'childs' => array(),
	),
	1 => array(
	  'rule' => array(
	    'property' => 'node:type',
	    'operator' => '=',
	    'value' => 'advanced_squeeze_page',
	    'theme' => 'omega',
	    'enabled' => '1',
	    'wildcards' => array(),
	  ),
	  'string' => '"node:type = advanced_squeeze_page >>> omega"',
	  'childs' => array(),
	),
  );
	
  return $rules;
}