<?php

/**
 * Add body classes if certain regions have content.
 */
function ipca_portal_preprocess_html(&$variables) {
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


function ipca_portal_preprocess_page(&$variables) {
    if (user_is_logged_in() == FALSE && $_GET['q'] != 'user/login') {
        return drupal_goto('user/login');
    }
}

/**
 * Implements hook_preprocess_maintenance_page().
 */
//function ipca_portal_preprocess_maintenance_page(&$variables) {
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
function ipca_portal_preprocess_node(&$variables) {
    if ($variables['view_mode'] == 'full' && node_is_page($variables['node'])) {
        $variables['classes_array'][] = 'node-full';
    }
}

/**
 * Override or insert variables into the block template.
 */
function ipca_portal_preprocess_block(&$variables) {
    // In the header region visually hide block titles.
    if ($variables['block']->region == 'header') {
        $variables['title_attributes_array']['class'][] = 'element-invisible';
    }
}



function ipca_portal_form_alter(&$form, $form_state, $form_id) {
    switch ($form_id) {
        case 'user_login_block':
        case 'user_login':
            unset($form['links']);
            $form['name']['#description'] = t('');
            $form['pass']['#description'] = t('');
            $form['captcha'] = array(
                                     '#type' => 'captcha',
                                     '#captcha_type' => 'recaptcha/reCAPTCHA',
                                     );
            break;
    }
}

function ipca_portal_user_login(&$edit, $account) {
  //$edit['redirect'] = '<front>';
  $GLOBALS['destination'] = '<front>';
}

function ipca_portal_css_alter(&$css) {

    unset($css[drupal_get_path('module', 'support') . '/css/main.css']);
    unset($css[drupal_get_path('module', 'pms_dashboard') . '/css/pms_dashboard.css']);
    unset($css[drupal_get_path('module', 'attendance') . '/css/attendance.css']);
    unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
    unset($css[drupal_get_path('module', 'system') . '/system.theme.css']);
    unset($css[drupal_get_path('module', 'lightbox2') . '/css/lightbox.css']);
}

function ipca_portal_js_alter(&$js) {

    unset($js[drupal_get_path('module', 'candidate') . '/js/candidate.js']);
    unset($js[drupal_get_path('module', 'employee_deputation') . '/js/employee_deputation.js']);
    unset($js[drupal_get_path('module', 'employee_induction') . '/js/pms.js']);
    unset($js[drupal_get_path('module', 'employee_transfer') . '/js/employee_transfer.js']);
    unset($js[drupal_get_path('module', 'manpower_requisition') . '/js/organogram.js']);
    unset($js[drupal_get_path('module', 'salary_structure') . '/js/salary_structure.js']);
    unset($js[drupal_get_path('module', 'support') . '/js/field_validations.js']);
    unset($js[drupal_get_path('module', 'support') . '/js/candidate.js']);
    unset($js[drupal_get_path('module', 'support') . '/js/main_menu.js']);
    unset($js[drupal_get_path('module', 'visitor_management') . '/js/visitor_management.js']);
    unset($js[drupal_get_path('module', 'lightbox2') . '/js/lightbox.js']);
    unset($js[drupal_get_path('module', 'colorbox') . '/js/jquery.colorbox-min.js']);
    unset($js[drupal_get_path('module', 'colorbox') . '/js/colorbox.js']);
    unset($js[drupal_get_path('module', 'colorbox') . '/js/colorbox_load.js']);
   
    
    
}

function ipca_portal_theme() {
  $items = array();
  // create custom user-login.tpl.php
  $items['user_login'] = array(
  'render element' => 'form',
  'path' => drupal_get_path('theme', 'ipca_portal') . '/templates',
  'template' => 'user-login',
  
 );
return $items;
}
