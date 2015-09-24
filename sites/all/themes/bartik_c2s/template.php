<?php

/**
 * Add body classes if certain regions have content.
 */



function bartik_c2s_preprocess_html(&$variables) {
   //drupal_flush_all_caches();
    if (!empty($variables['page']['featured'])) {
        $variables['classes_array'][] = 'featured';
    }

    if (!empty($variables['page']['triptych_first']) || !empty($variables['page']['triptych_middle']) || !empty($variables['page']['triptych_last'])) {
        $variables['classes_array'][] = 'triptych';
    }

    if (!empty($variables['page']['footer_firstcolumn']) || !empty($variables['page']['footer_secondcolumn']) || !empty($variables['page']['footer_thirdcolumn']) || !empty($variables['page']['footer_fourthcolumn'])) {
        $variables['classes_array'][] = 'footer-columns';
    }

    // Add conditional stylesheets for IE
    drupal_add_css(path_to_theme() . '/css/ie.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
    drupal_add_css(path_to_theme() . '/css/ie6.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'IE 6', '!IE' => FALSE), 'preprocess' => FALSE));
}

/**
 * Override or insert variables into the page template for HTML output.
 */


function bartik_c2s_preprocess_page(&$variables) {
    if (user_is_logged_in() == FALSE && $_GET['q'] != 'user/login') {
        return drupal_goto('user/login');
    }
}

/**
 * Implements hook_preprocess_maintenance_page().
 */
//function bartik_c2s_preprocess_maintenance_page(&$variables) {
//    // By default, site_name is set to Drupal if no db connection is available
//    // or during site installation. Setting site_name to an empty string makes
//    // the site and update pages look cleaner.
//    // @see template_preprocess_maintenance_page
//    if (!$variables['db_is_active']) {
//        $variables['site_name'] = '';
//    }
//    drupal_add_css(drupal_get_path('theme', 'ipca_portal') . '/css/maintenance-page.css');
//}

/**
 * Override or insert variables into the node template.
 */
function bartik_c2s_preprocess_node(&$variables) {
    if ($variables['view_mode'] == 'full' && node_is_page($variables['node'])) {
        $variables['classes_array'][] = 'node-full';
    }
}

/**
 * Override or insert variables into the block template.
 */
function bartik_c2s_preprocess_block(&$variables) {
    // In the header region visually hide block titles.
    if ($variables['block']->region == 'header') {
        $variables['title_attributes_array']['class'][] = 'element-invisible';
    }
}



function bartik_c2s_form_alter(&$form, $form_state, $form_id) {
    switch ($form_id) {
        case 'user_login_block':
        case 'user_login':
            unset($form['links']);
            $form['#attached']['css'] = array(
                drupal_get_path('module', 'broker') . '/css/global-c2s.css',
            );
//            $form['name']['#description'] = t('');
            $form['name'] = array(
                '#title'           => '',
                '#type'		       => 'textfield',
                '#maxlength'	   => 100,
                '#default_value'   =>'',
                '#attributes'       => array(
                    'class'=> array('username_login'),
                    'placeholder'=> 'Email/ Username',
                    //'readonly'=>'readonly',
                ),
                '#prefix' => '<div style="width: 10%;margin-left: 20%;">
                <img style="width: 190px;position: absolute;margin-top: -65px;" src="'. base_path() . path_to_theme().'/images/skyline.png" />
                <img style="width: 190px;margin-top: 11px;" src="'. base_path() . path_to_theme().'/images/logo.png" /></div><p> LOGIN </p>',
                '#suffix' => '',
            );
            
            $form['pass'] = array(
                '#title'           => '',
                '#type'		       => 'password',
                '#maxlength'	   => 100,
                '#default_value'   =>'',
                '#attributes'       => array(
                    'class'=> array('password_login'),
                    'placeholder'=> 'Password',
                    //'readonly'=>'readonly',
                ),
             //   '#prefix' => '<div style="width: 10%;margin-left: 20%;">
             //   <img style="width: 190px;position: absolute;margin-top: -65px;" src="'. base_path() . path_to_theme().'/images/skyline.png" />
             //   <img style="width: 190px;margin-top: 11px;" src="'. base_path() . path_to_theme().'/images/logo.png" /></div><p> LOGIN </p>',
            //    '#suffix' => '',
            );
           // $form['pass']['#description'] = t('');            
            break;
    }
}

function bartik_c2s_user_login(&$edit, $account) {
  //$edit['redirect'] = '<front>';
  $GLOBALS['destination'] = '<front>';
}

function bartik_c2s_css_alter(&$css) {


}

function bartik_c2s_js_alter(&$js) {


   
    
    
}
function bartik_c2s_theme() {
    $items = array();
    // create custom user-login.tpl.php
    $items['user_login'] = array(
        'render element' => 'form',
        'path' => drupal_get_path('theme', 'bartik_c2s') . '/templates',
        'template' => 'use-login',

    );
    return $items;
}


