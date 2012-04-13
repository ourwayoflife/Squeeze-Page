<?php
/**
 * @file
 * squeeze_page.stylizer.inc
 */

/**
 * Implements hook_default_stylizer().
 */
function squeeze_page_default_stylizer() {
  $export = array();

  $style = new stdClass;
  $style->disabled = FALSE; /* Edit this to true to make a default style disabled initially */
  $style->api_version = 1;
  $style->name = 'lead_magnets_styles';
  $style->admin_title = 'Lead Magnets Styles';
  $style->admin_description = 'Style for lead magnet pane';
  $style->settings = array(
    'name' => 'lead_magnets_styles',
    'style_base' => 'pane_plain_box',
    'font' => array(
      'font' => '',
      'size' => '',
      'letter_spacing' => '',
      'word_spacing' => '',
      'decoration' => 'underline',
      'weight' => 'bold',
      'style' => 'normal',
      'variant' => '',
      'case' => '',
      'alignment' => 'center',
    ),
    'header_font' => array(
      'font' => '',
      'size' => '',
      'letter_spacing' => '',
      'word_spacing' => '',
      'decoration' => '',
      'weight' => '',
      'style' => '',
      'variant' => '',
      'case' => '',
      'alignment' => '',
    ),
    'border' => array(
      'thickness' => '',
      'style' => '',
    ),
    'header_border' => array(
      'thickness' => '',
      'style' => '',
    ),
    'padding' => array(
      'top' => '',
      'right' => '',
      'bottom' => '',
      'left' => '',
    ),
    'palette' => array(
      'background' => '#ffffff',
      'text' => '#0678BE',
      'border' => '#000000',
      'header-background' => '#FFFFFF',
      'header-text' => '#000000',
      'header-border' => '#000000',
    ),
  );
  $export['lead_magnets_styles'] = $style;

  return $export;
}
