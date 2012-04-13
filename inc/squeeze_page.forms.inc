<?php

function squeeze_page_advanced_signup($form, &$form_state) {   
  $params = $form_state['build_info']['args'][0]; 
  $form = array();
  
  $form['node_id'] = array (
      '#value' => $params['node_id']
  );   
  
  if (isset($params['invalid']) && $params['invalid']) {
    $form['#theme'] = 'squeeze_page_advanced_invalid_signup';   
    return $form;
  }
  else {
    $form['#theme'] = 'squeeze_page_advanced_'.$params['orient'].'_signup';     
  }
  
  $form['emailVarName'] = array (
    '#value' => $params['emailVarName']
  );
  
  $form[$params['emailVarName']] = array(
    '#type' => 'textfield',
    '#default_value' => t('Enter Your Email Address Here'),
    '#attributes' => array(
      'onclick' => "this.value='';",
    )
  );  
  
  if ($params['orient'] == 'horizontal') {
    $formCss = '.form-item-'.$params['emailVarName'].' {margin:0px;padding:0px}';
    
    $form['#attached']['css'][$formCss] = array('type' => 'inline');
    
    $form['#prefix'] = '<div style="background:#ffffcc;border:2px solid #808000;padding:15px;0px">';
    $form['#suffix'] = '</div>';    
    
    $form[$params['emailVarName']]['#attributes']['style'] = 'border:1px solid #7F9DB9;width: 90%; height: 40px;text-align:center';
  }
  elseif ($params['orient'] == 'vertical') {
    $form['#prefix'] = '<div style="background:#ffffcc;border:2px solid #808000;padding:7px 0px;width:280px;margin:auto">';
    $form['#suffix'] = '</div>';   

    $form[$params['emailVarName']]['#attributes']['style'] = 'border:1px solid #7F9DB9;width: 90%; height: 40px;text-align:center';
  }
  
  if (isset($params['method']) && $params['method']) {
    $form['#method'] = $params['method'];
  }
  
  if (isset($params['hiddenvars']) && $params['hiddenvars']) { 
    foreach ($params['hiddenvars'] as $k => $v) {
      $form[$k] = array(
        '#type' => 'hidden',
        '#value' => $v
      );
    }
  }
  
  $gtt = ASSETS_DIR . '/gtt.gif';
  $form['submit'] = array(
    '#type' => 'image_button',
    '#src' => $gtt
  );
  
  if ($params['provider'] == PROVIDER_INFINITE) { 
    $form['#action'] = url($params['action'], array('external' => true)); 
  }
  elseif ($params['provider'] == PROVIDER_MAILCHIMP) { 
    $form['submit']['#submit'] = array('squeeze_page_subscribe_mailchimp');
  }
  
  return $form;
}

function squeeze_page_advanced_signup_validate($form, &$form_state) {
  $formValues = $form_state['values'];
  $emailVarName = $form_state['complete form']['emailVarName']['#value']; 
  if (!valid_email_address($formValues[$emailVarName])) {
    form_set_error('', t('Please enter a valid email address.'));
  }
}

function squeeze_page_subscribe_mailchimp($form, &$form_state) {
  $formValues = $form_state['values']; 
  $mcapi = mailchimp_get_api_object();
  $res = $mcapi->listSubscribe($formValues['list'], $formValues['email']);
  if ($res) {
    drupal_set_message(t('Congratulations! You have subscribed successfully. Please confirm your subscription now by checking your email.'));
  }
  else {
    drupal_set_message(t('Sorry, something has gone wrong when you subscribe!'), 'error');
  }   
   
  if (isset($formValues['redurl']) && $formValues['redurl']) {
    drupal_goto($formValues['redurl']);
    exit;
  }
}

function squeeze_page_basic_signup($form, &$form_state) {   
  $params = $form_state['build_info']['args'][0]; 
  $form = array();
  
  $form['node_id'] = array (
      '#value' => $params['node_id']
  );   
  
  if (isset($params['invalid']) && $params['invalid']) {
    $form['#theme'] = 'squeeze_page_basic_invalid_signup';   
    return $form;
  }
  else {
    $form['#theme'] = 'squeeze_page_basic_signup';     
  }
  
  $form['emailVarName'] = array (
    '#value' => $params['emailVarName']
  );
  
  $form[$params['emailVarName']] = array(
    '#type' => 'textfield',
    '#default_value' => t('Enter Your Email Address Here'),
    '#attributes' => array(
      'onclick' => "this.value='';",
    )
  );  
  
  $formCss = '.form-item-'.$params['emailVarName'].' {margin:0px;padding:0px}';
  
  $form['#attached']['css'][$formCss] = array('type' => 'inline');
  
  $form['#prefix'] = '<div style="padding:15px;0px">';
  $form['#suffix'] = '</div>';    
  
  $form[$params['emailVarName']]['#attributes']['style'] = 'border:1px solid #7F9DB9;width: 90%; height: 40px;text-align:center';

  if (isset($params['method']) && $params['method']) {
    $form['#method'] = $params['method'];
  }
  
  if (isset($params['hiddenvars']) && $params['hiddenvars']) { 
    foreach ($params['hiddenvars'] as $k => $v) {
      $form[$k] = array(
        '#type' => 'hidden',
        '#value' => $v
      );
    }
  }
  
  $gtt = ASSETS_DIR . '/gtt.gif';
  $form['submit'] = array(
    '#type' => 'image_button',
    '#src' => $gtt
  );
  
  if ($params['provider'] == PROVIDER_INFINITE) { 
    $form['#action'] = url($params['action'], array('external' => true)); 
  }
  elseif ($params['provider'] == PROVIDER_MAILCHIMP) { 
    $form['submit']['#submit'] = array('squeeze_page_subscribe_mailchimp');
  }
  
  return $form;
}

function squeeze_page_basic_signup_validate($form, &$form_state) {
  $formValues = $form_state['values'];
  $emailVarName = $form_state['complete form']['emailVarName']['#value']; 
  if (!valid_email_address($formValues[$emailVarName])) {
    form_set_error('', t('Please enter a valid email address.'));
  }
}

function squeeze_page_theme() {
  return array(
    'squeeze_page_advanced_horizontal_signup' => array
      (
        'render element' => 'form'
      ),
    'squeeze_page_advanced_vertical_signup' => array
      (
        'render element' => 'form'
      ), 
    'squeeze_page_basic_signup' => array
      (
        'render element' => 'form'
      ),            
    'squeeze_page_basic_invalid_signup' => array
      (
        'render element' => 'form'
      ), 
    'squeeze_page_advanced_invalid_signup' => array
      (
        'render element' => 'form'
      ),       
  );
}

function theme_squeeze_page_basic_signup($variables) {  
  $arr = ASSETS_DIR . '/arrowright1.jpg';
  $form = $variables['form']; 
  $output = '<table style="margin:auto;border:none;width:auto" cellpadding="0" cellspacing="15" align="center">'. 
    '<tbody style="border:none"><tr valign="middle"><td><img alt="as" src="'.$arr.'" width="150"></td>'. 
    '<td style="width: 270px;">'.drupal_render($form[$form['emailVarName']['#value']]).'</td></tr>'. 
    '<tr><td colspan="2" style="text-align:center" align="center">'.drupal_render($form['submit']).'</td></tr></tbody></table>';

  $output .= drupal_render_children($form);
  return $output;  
}

function theme_squeeze_page_advanced_horizontal_signup($variables) {  
  $as2 = ASSETS_DIR . '/as2.png';
  $form = $variables['form']; 
  $output = '<table style="margin:auto;border:none;width:auto" cellpadding="0" cellspacing="15" align="center">'. 
    '<tbody><tr valign="middle"><td style="width: 220px;"><img alt="as" src="'.$as2.'" height="38" width="250"></td>'. 
    '<td style="width: 270px;">'.drupal_render($form[$form['emailVarName']['#value']]).'</td>'. 
    '<td>'.drupal_render($form['submit']).'</td></tr></tbody></table>';

  $output .= drupal_render_children($form);
  return $output;  
}

function theme_squeeze_page_advanced_vertical_signup($variables) {
  $xx2 = ASSETS_DIR . '/xx2.png';
  $form = $variables['form'];
  $output = '<table cellspacing="0" cellpadding="10" style="border:none;margin:auto"><tbody><tr><td align="center">'.
    '<img width="250" height="45" src="'.$xx2.'">'.
    '<table style="border:none"><tbody><tr><td align="center">'.drupal_render($form[$form['emailVarName']['#value']]).
    '</td></tr></tbody></table>'.drupal_render($form['submit']).
    '</td></tr></tbody></table>';

  $output .= drupal_render_children($form);
  return $output;  
}

function theme_squeeze_page_advanced_invalid_signup($variables) {
  $form = $variables['form'];
  $output = '<div style="color:#000;background:#FFFF00;border:1px solid #FF0000;padding:5px;">Cannot display signup form. '.
            'You might have submitted an invalid one or you have not properly configured mailing list in the node '.
            l(t('edit'), 'node/'.$form['node_id']['#value'].'/edit').' form.</div>';
  return $output;
}

function theme_squeeze_page_basic_invalid_signup($variables) {
  $form = $variables['form'];
  $output = '<div style="color:#000;background:#FFFF00;border:1px solid #FF0000;padding:5px;">Cannot display signup form. '.
            'You might have submitted an invalid one or you have not properly configured mailing list in the node '.
            l(t('edit'), 'node/'.$form['node_id']['#value'].'/edit').' form.</div>';
  return $output;
}