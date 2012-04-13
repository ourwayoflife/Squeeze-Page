<?php

  function _squeeze_page_store_layout_settings() {
    $layoutSettings = serialize(array (
      'css_id' => '', 
      'class' =>  '',
      'sticky' => 0,
      'layout' => 'flexible:advanced_squeeze_page',
      'hide_sidebars' => 0,
      'pipeline' => 'standard',
      'hide_empty_regions' => '', 
      'ds_panels' => 1,
      'did' => 1,
      'theme' => 'panels_flexible'
    ));

    db_insert('ds_layout_settings')
      ->fields(array(
      'id' => 'node|advanced_squeeze_page|default', 
      'entity_type' => 'node', 
      'bundle' => 'advanced_squeeze_page', 
      'view_mode' => 'default', 
      'layout' => 'flexible:advanced_squeeze_page', 
      'settings' => $layoutSettings,
    ))
    ->execute();     

    //store setting for exclude_node_title
    $entSettings = array(
      'advanced_squeeze_page' => 'advanced_squeeze_page',
      'basic_squeeze_page' => 'basic_squeeze_page'
    );  

    variable_set('exclude_node_title_content_type_values', $entSettings);
  }  
  
  function _squeeze_page_store_panels_display() {
    $panelSettings = serialize(array(
      'style_settings' => array(
        'default' => '',
        'heading' => '',
        'horizontal_opt_in' => '', 
        'main_short_copy' => '',
        'lead_magnets' => '', 
      ))
    );
    
    db_insert('panels_display')
      ->fields(array(
      'did' => 1, 
      'layout' => 'flexible:advanced_squeeze_page', 
      'layout_settings' => serialize(array()), 
      'panel_settings' => $panelSettings, 
      'cache' => serialize(array()), 
      'title' => '',
      'hide_title' => 0,
      'title_pane' => 0
    ))
    ->execute();     
    
    $panelSettings = serialize(array(
      'style_settings' => array(
        'default' => '',
        'header' => array(
          'style' => '$',
          'settings' => array(
            'name' => '_temporary',
            'style_base' => 'region_plain_box',
            'palette' => array(
              'background' => '#FFFFFF',
              'text' => '#000000',
              'border' => '#000000',
            ),
            'font' => array(
              'font' => '',
              'size' => '',
              'letter_spacing' => '', 
              'word_spacing' => '',
              'decoration' => '',
              'weight' => '',
              'style' => '',
              'variant' => '',
              'case' => '',
              'alignment' => 'center',
            ),
            'border' => array(
              'thickness' => '',
              'style' => ''
            ),
            'padding' => array(
              'top' => '',
              'right' => '',
              'bottom' => '',
              'left' => '',
            ),
          ),
        ),
        'squeeze_copy' => '',
        'opt_in_box' => '',
      ),
      'header' => array(
        'style' => 'stylizer',
      ))
    );
    
    db_insert('panels_display')
      ->fields(array(
      'did' => 2, 
      'layout' => 'flexible:basic_squeeze_page', 
      'layout_settings' => serialize(array()), 
      'panel_settings' => $panelSettings, 
      'cache' => serialize(array()), 
      'title' => '',
      'hide_title' => 0,
      'title_pane' => 0
    ))
    ->execute();      
  }
  
  function _squeeze_page_store_panels_pane() {
    $configuration = serialize(array(
      'label' => 'hidden',
      'formatter' => 'image',
      'formatter_settings' => array(
        'image_style' => '',
        'image_link' => ''
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '' 
    ));
    
    db_insert('panels_pane')
      ->fields(array(
      'pid' => 1, 
      'did' => 1,
      'panel' => 'heading', 
      'type' => 'entity_field', 
      'subtype' => 'node:field_headline', 
      'shown' => 1,
      'access' => serialize(array()),
      'configuration' => $configuration,
      'cache' => serialize(array()),
      'style' => serialize(array('settings' => '')),
      'css' => serialize(array()),
      'extras' => serialize(array()),
      'position' => 0
      
    ))
    ->execute();      
    
    $configuration = serialize(array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => ''));
    
    db_insert('panels_pane')
      ->fields(array(
      'pid' => 2, 
      'did' => 1,
      'panel' => 'main_short_copy', 
      'type' => 'entity_field', 
      'subtype' => 'node:body', 
      'shown' => 1,
      'access' => serialize(array()),
      'configuration' => $configuration,
      'cache' => serialize(array()),
      'style' => serialize(array('settings' => '')),
      'css' => serialize(array()),
      'extras' => serialize(array()),
      'position' => 0
      
    ))
    ->execute();     

    $configuration = serialize(array(
      'label' => 'hidden',
      'formatter' => 'field_collection_view',
      'formatter_settings' => array(
        'edit' => 'Edit',
        'delete' => 'Delete',
        'add' => 'Add',
        'description' => 1
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => ''
    ));
    
    db_insert('panels_pane')
      ->fields(array(
      'pid' => 3, 
      'did' => 1,
      'panel' => 'lead_magnets', 
      'type' => 'entity_field', 
      'subtype' => 'node:field_leadmagnets', 
      'shown' => 1,
      'access' => serialize(array()),
      'configuration' => $configuration,
      'cache' => serialize(array()),
      'style' => serialize(array('settings' => '', 'style' => 'stylizer:lead_magnets_styles')),
      'css' => serialize(array()),
      'extras' => serialize(array()),
      'position' => 0
      
    ))
    ->execute(); 

    $configuration = serialize(array(
      'title' => '',
      'body' => "<?php\n\necho squeeze_page_render_advanced_form(\$entity, 'horizontal');\n\n?>",
      'format' => 'ds_code',
      'context' => array(),
      'override_title' => '',
      'override_title_text' => ''
    ));
    
    db_insert('panels_pane')
      ->fields(array(
      'pid' => 4, 
      'did' => 1,
      'panel' => 'horizontal_opt_in', 
      'type' => 'dsc', 
      'subtype' => 'dsc', 
      'shown' => 1,
      'access' => serialize(array()),
      'configuration' => $configuration,
      'cache' => serialize(array()),
      'style' => serialize(array('settings' => '')),
      'css' => serialize(array()),
      'extras' => serialize(array()),
      'position' => 0
      
    ))
    ->execute(); 

    $configuration = serialize(array(
      'title' => '',
      'body' => "<?php\n\necho squeeze_page_render_advanced_form(\$entity, 'vertical');\n\n?>",
      'format' => 'ds_code',
      'context' => array(),
      'override_title' => '',
      'override_title_text' => ''
    ));
    
    db_insert('panels_pane')
      ->fields(array(
      'pid' => 5, 
      'did' => 1,
      'panel' => 'lead_magnets', 
      'type' => 'dsc', 
      'subtype' => 'dsc', 
      'shown' => 1,
      'access' => serialize(array()),
      'configuration' => $configuration,
      'cache' => serialize(array()),
      'style' => serialize(array('settings' => '')),
      'css' => serialize(array()),
      'extras' => serialize(array()),
      'position' => 1
      
    ))
    ->execute();  

    $configuration = serialize(array(
      'override_title' => 1,
      'override_title_text' => '', 
    ));
    
    db_insert('panels_pane')
      ->fields(array(
      'pid' => 6, 
      'did' => 1,
      'panel' => 'heading', 
      'type' => 'block', 
      'subtype' => 'delta_blocks-messages', 
      'shown' => 1,
      'access' => serialize(array()),
      'configuration' => $configuration,
      'cache' => serialize(array()),
      'style' => serialize(array('settings' => '')),
      'css' => serialize(array()),
      'extras' => serialize(array()),
      'position' => 1
      
    ))
    ->execute();    

    
    
    
    
    
    
    
    //header
    $configuration = serialize(array(
      'label' => 'hidden',
      'formatter' => 'image',
      'formatter_settings' => array(
        'image_style' => '',
        'image_link' => ''
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '' 
    ));
    
    db_insert('panels_pane')
      ->fields(array(
      'pid' => 7, 
      'did' => 2,
      'panel' => 'header', 
      'type' => 'entity_field', 
      'subtype' => 'node:field_header', 
      'shown' => 1,
      'access' => serialize(array()),
      'configuration' => $configuration,
      'cache' => serialize(array()),
      'style' => serialize(array('settings' => '')),
      'css' => serialize(array()),
      'extras' => serialize(array()),
      'position' => 0
      
    ))
    ->execute();   

    //header (messages)
    $configuration = serialize(array(
      'override_title' => 1,
      'override_title_text' => '', 
    ));
    
    db_insert('panels_pane')
      ->fields(array(
      'pid' => 8, 
      'did' => 2,
      'panel' => 'header', 
      'type' => 'block', 
      'subtype' => 'delta_blocks-messages', 
      'shown' => 1,
      'access' => serialize(array()),
      'configuration' => $configuration,
      'cache' => serialize(array()),
      'style' => serialize(array('settings' => '')),
      'css' => serialize(array()),
      'extras' => serialize(array()),
      'position' => 1
      
    ))
    ->execute();   

    //squeeze copy
    $configuration = serialize(array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => ''));
    
    db_insert('panels_pane')
      ->fields(array(
      'pid' => 9, 
      'did' => 2,
      'panel' => 'squeeze_copy', 
      'type' => 'entity_field', 
      'subtype' => 'node:field_squeeze_copy', 
      'shown' => 1,
      'access' => serialize(array()),
      'configuration' => $configuration,
      'cache' => serialize(array()),
      'style' => serialize(array('settings' => '')),
      'css' => serialize(array()),
      'extras' => serialize(array()),
      'position' => 0
      
    ))
    ->execute();  

    //opt in box
    $configuration = serialize(array(
      'title' => '',
      'body' => "<?php\n\necho squeeze_page_render_basic_form(\$entity);\n\n?>",
      'format' => 'ds_code',
      'context' => array(),
      'override_title' => '',
      'override_title_text' => ''
    ));
    
    db_insert('panels_pane')
      ->fields(array(
      'pid' => 10, 
      'did' => 2,
      'panel' => 'opt_in_box', 
      'type' => 'dsc', 
      'subtype' => 'dsc', 
      'shown' => 1,
      'access' => serialize(array()),
      'configuration' => $configuration,
      'cache' => serialize(array()),
      'style' => serialize(array('settings' => '')),
      'css' => serialize(array()),
      'extras' => serialize(array()),
      'position' => 0
      
    ))
    ->execute();      
  }
  
  /*function _squeeze_page_configure_themekey() {
    db_insert('themekey_properties')
      ->fields(array(
      'property' => 10, 
      'operator' => 2,
      'value' => 'opt_in_box', 
      'weight' => 'dsc', 
      'theme' => 'dsc', 
      'enabled' => 1,
      'wildcards' => serialize(array()),      
    ))
    ->execute();    	
  }*/