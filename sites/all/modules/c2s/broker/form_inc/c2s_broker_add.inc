<?php

$form['#attached']['js'] = array(
    drupal_get_path('module', 'broker') . '/js/validate.js',
);

$form['#attached']['css'] = array(
    drupal_get_path('module', 'broker') . '/css/global-c2s.css',
);

/*
	//drupal_add_css(drupal_get_path('module', 'overtime') . '/css/overtime.css');
$form['#attached']['css'] = array(
		drupal_get_path('module', 'overtime') . '/css/overtime.css',
);
	$ot_rate_id			= 0;
	
	$location_code 		= '';
	$category 			= '';
	$grade		 		= '';
	$employee_type 		= '';
	$effective_date 	= '';
	$rate_multiple 		= '';
	$created 			= '';
	$changed 			= '';

	if(isset($_GET['ot_rate_id'])){
		$ot_rate_id = $_GET['ot_rate_id'];
	}

		
	$result = db_query("SELECT * 
                              FROM pms_setting_overtime 
                              WHERE ot_rate_id = ".$ot_rate_id);
	foreach($result as $value){
		$company_code 		= $value->company_id;
		$location_code 		= $value->location_id;
		$category 		= $value->category_id;
		$grade		 	= $value->grade_id;
		$employee_type 		= $value->employee_type;
		$effective_date 	= $value->effective_date;
		$rate_multiple 		= $value->rate_multiple;
		$created 		= $value->created;
		$changed 		= $value->changed;
	}
        if(empty($company_code )){$company_code = 1;}
*/
$result_paperwork = db_query("select document_name from required_paperwork") ;


$number_to_words = array(1=>"One", 2=> "Two", 3=> "Three", 4=>"Four", 5=>"Five", 6=>"Six");
$total_brokers = 1;

if (isset($form_state['values']['broker_owners'])) {
    $total_brokers = isset($form_state['values']['broker_owners']) ? $form_state['values']['broker_owners'] : '1';
   
}
$form['broker_owners'] = array(
    '#type' => 'select',
    '#options' => array(1=>'1', 2=>'2',3=>'3',4=>'4',5=>'5'),
    '#default_value' => 1,
    '#theme_wrappers'  => array(),
    '#attributes' => array(
        'class' => array('form_text'),
    ),
    '#ajax' => array(
        'wrapper' => 'names-fieldset-wrapper',
        'callback' => 'spower_add_more_callback',
    ),
    '#prefix' => '<div class="wrapper-w100"><span class="wrapper-w16"><label class="label_left"> Total Owner </label><span class="value_left">',
    '#suffix' => '</span></span></div>',
);


$form['form_start'] = array(
    '#type' => 'item',
    '#suffix' => '<div id="main-view-wrapper">',
);



$form['#tree'] = TRUE;
$form['names_fieldset'] = array(
    '#type' => 'fieldset',
    '#theme_wrappers'  => array(),
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="names-fieldset-wrapper">',
    '#suffix' => '</div>',
);

$form['names_fieldset']['brokerage_tab'] = array(
    '#type' => 'item',
    '#suffix' => '<div class="form_section_tab selected" id="tab_0" data-item="form_tab_0" onclick="click_tabs(\'tab_0\')" > Brokerage Details </div>',
);

for($i=1; $i<=$total_brokers; $i++){
    $form['names_fieldset']['broker_tab_'.$i] = array(
        '#type' => 'item',
        '#suffix' => '<div class="form_section_tab" id="tab_'.$i.'" data-item="form_tab_'.$i.'" onclick="click_tabs(\'tab_'.$i.'\')" > Brokerage '.$number_to_words[$i].' </div>',
    );

}

$form['names_fieldset']['brokerage_details_start'] = array(
    '#type' => 'item',
    '#suffix' => '<div id="form_tab_0" class="form_sections" style="display:block">',
);

$form['names_fieldset']['brokerage_details_seperator'] = array(
    '#type' => 'item',
    '#suffix' => '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
);

$form['names_fieldset']['brokerage_section_left_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_left">',
);



$form['names_fieldset']['brokerage_name'] = array(
    '#type'		       => 'textfield',
    '#maxlength'	   => 100,
    '#theme_wrappers'  => array(),
    '#required'        =>'true',
    '#attributes'       => array(
        'class'=> array('form_text'),
        'placeholder'=> 'City2Shore',
        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
        'onChange'   => array('addPrefix(this, "City2Shore ")'),
        'onClick'    => array('removePrefix(this)')
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w100"><label class="label_left"> Name of Brokerage </label><span class="value_left">',
    '#suffix' => '</span></span> <div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
);


$form['names_fieldset']['brokerage_start_date'] = array(
    '#label'          => 'invisible',
    '#type'		      => 'date_popup',
    '#theme_wrappers'  => array(),
    '#date_label_position' => 'Within',
    '#required'       => 'true',
    '#date_format'	  => 'm/d/Y',
    '#date_year_range'  => '-3:+3',
    '#attributes'       => array(
        'placeholder'=> t('mm/dd/YYYY'),
        'class'=> array('date-input-medium form_text'),
        'onKeyPress' => array('return false;'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left"> Start Date </label><span class="value_left">',
    '#suffix' => '</span></span>',
);

/*

$form['names_fieldset']['number_of_owners'] = array(
    '#title'          => 'Total Owners',
    '#type'		      => 'textfield',
    '#maxlength'	  => 5,
    '#default_value'  => 1,
    '#required'       => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#ajax' => array(
        'wrapper' => 'names-fieldset-wrapper',
        'callback' => 'spower_add_more_callback',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left"> Total Owner </label><span class="value_left">',
    '#suffix' => '</span></span>',
); */



$form['names_fieldset']['franchise_fee_cap'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('$3000'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Franchise Cap</label><span class="value_left">',
    '#suffix' => '</span></span>',
);


$form['names_fieldset']['reap_amount_cap'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('$18,000'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Reap Cap</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['transaction_management_fee'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('$2.96'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Transaction Fee</label><span class="value_left">',
    '#suffix' => '</span></span>',
);


$form['names_fieldset']['brokerage_section_left_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div>',
);

$paperwork_list = "";
foreach($result_paperwork as $value_paperwork){
    $paperwork_list .='<span class="wrapper-w33">
	        <img src="'.base_path().'/'.drupal_get_path('module', 'broker').'/images/arrow_toggle.png" id="inner_section2_4_arrow" class="inner_section_arrow inner_subsection_arrow" >
	        '.$value_paperwork->document_name.'</span>';
     
}

$form['names_fieldset']['brokerage_section_right_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_left">',
    '#suffix' => $paperwork_list,
);



$form['names_fieldset']['brokerage_section_right_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div>',
);

$form['names_fieldset']['brokerage_details_end'] = array(
    '#type' => 'item',
    '#suffix' => '</div>',
);


/* Broker Loop */
/*
$form['#tree'] = TRUE;
$form['names_fieldset'] = array(
    '#type' => 'fieldset',
    '#theme_wrappers'  => array(),
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="names-fieldset-wrapper">',
    '#suffix' => '</div>',
); */

for($i=1; $i<=$total_brokers; $i++){
$form['names_fieldset']['broker_'.$i.'_details_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#suffix' => '<div id="form_tab_'.$i.'" class="form_sections" style="display:none">',
);


$form['names_fieldset']['broker_'.$i.'_details_seperator'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#suffix' => '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
);

$form['names_fieldset']['broker_'.$i.'_personal_info_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_left"> <div class="form_subsection_title" data-item="inner_section_1"> Personal Information</div>',
);

$form['names_fieldset']['broker_'.$i.'_first_name'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('First Name'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return onlyAlphabets(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">First Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['broker_'.$i.'_middle_name'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Middle Name'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return onlyAlphabets(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Middle Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['broker_'.$i.'_last_name'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Last Name'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return onlyAlphabets(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Last Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);


$form['names_fieldset']['date_of_birth_'.$i] = array(
    '#label'          => '',
    '#type'		      => 'date_popup',
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#date_format'	  => 'm/d/Y',
    '#date_year_range'  => '-3:+3',
    '#attributes'       => array(
        'placeholder'=> t('mm/dd/YYYY'),
        'class'=> array('date-input-medium form_text'),
        'onKeyPress' => array('return false;'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Date of Birth</label><span class="value_left">',
    '#suffix' => '</span></span>',
);


$form['names_fieldset']['personl_email_id_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Personal Email ID'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return MailId(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Email Id</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['contact_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Contact Number'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Contact</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['street_address_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Street Address'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w100"><label class="label_left">Street Address</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['city_id_'.$i] = array(
    '#type'=>'select',
    '#required'=>'true',
    '#options' =>array(1=>'City'),
    '#theme_wrappers'  => array(),
    '#attributes' => array(
        'placeholder' => t(''),
        'class' => array('form_text'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">City</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['state_id_'.$i] = array(
    '#type'=>'select',
    '#required'=>'true',
    '#options' =>array(1=>'State'),
    '#theme_wrappers'  => array(),
    '#attributes' => array(
        'placeholder' => t(''),
        'class' => array('form_text'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">State</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['zip_code_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Zip Code'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Zip Code</label><span class="value_left">',
    '#suffix' => '</span></span>',
     
);

$form['names_fieldset']['broker_'.$i.'_personal_info_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div>',
);


$form['names_fieldset']['broker_'.$i.'_professional_info_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_left"> <div class="form_subsection_title" data-item="inner_section_1"> Professional Information</div>',
);

$form['names_fieldset']['busines_street_address_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Street Address'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w100"><label class="label_left">Business Address</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['business_city_id_'.$i] = array(
    '#type'=>'select',
    '#required'=>'true',
    '#theme_wrappers'  => array(),
    '#options' =>array(1=>'City'),
    '#attributes' => array(
        'placeholder' => t(''),
        'class' => array('form_text'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">City</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['business_state_id_'.$i] = array(
    '#type'=>'select',
    '#required'=>'true',
    '#theme_wrappers'  => array(),
    '#options' =>array(1=>'State'),
    '#attributes' => array(
        'placeholder' => t(''),
        'class' => array('form_text'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">State</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['business_zip_code_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Zip Code'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Zip Code</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['broker_state_id_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Broker State Id #'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">State ID#</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['broker_ein_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Broker EIN'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Broker EIN#</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['broker_nrds_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Broker NRDS#'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">NRDS#</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['mls_username_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('MLS User Id'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">MLS User Id</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['mls_password_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('MLS Password'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">MLS Password</label><span class="value_left">',
    '#suffix' => '</span></span>',
);



$form['names_fieldset']['office_phone_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Office Phone'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Office Phone</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['extension_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Extension'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Extension</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['names_fieldset']['create_email_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('example@c2semail.com'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w60"><label class="label_left">C2S Email</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['names_fieldset']['choice_of_charity_org_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 250,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Type Min 3 Chars'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w100"><label class="label_left">Charity Organization Chosen</label><span class="value_left">',
    '#suffix' => '</span></span>',
);


$form['names_fieldset']['broker_'.$i.'_professional_info_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div><div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
);

$form['names_fieldset']['broker_'.$i.'_bank_info_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_full"> <div class="form_subsection_title" data-item="inner_section_1"> Bank Details</div>',
);

//-------------- //

$form['names_fieldset']['broker_'.$i.'_bank_info_left_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Payout Commissions &amp; Reap To Agent</div>',
);


$form['names_fieldset']['comm_account_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Account Number'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Account Number</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['names_fieldset']['name_on_comm_account_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Name On Account'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return onlyAlphabets(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w60"><label class="label_left">Name on Account</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['names_fieldset']['comm_financial_institution_name_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Financial Institution Name'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return onlyAlphabets(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w100"><label class="label_left">Bank Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['names_fieldset']['comm_financial_institution_phone_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Financial Institution Phone Number'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Bank Contact</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['comm_account_type_'.$i] = array(
    '#type'		      => 'select',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
    ),
    //	        'onKeyPress' => array('return numbersonly(this, event)',),
    //'readonly'=>'readonly',
    '#options'        => array('checking' => t('Checking'),'saving'=> t('Saving')),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Account Type</label><span class="value_left">',
    '#suffix' => '</span></span>',
);



$form['names_fieldset']['comm_aba_routing_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('ABA Routing Number'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">ABA Routing#</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['broker_'.$i.'_bank_info_left_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div>',
);

//---------- //

$form['names_fieldset']['broker_'.$i.'_bank_info_right_start_'.$i] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Personal Commissions & Reap</div>',
);

$form['names_fieldset']['personal_account_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Account Number'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Account Number</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['names_fieldset']['name_on_personal_account_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Name On Account'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w60"><label class="label_left">Name On Account</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['names_fieldset']['personal_financial_institution_name_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Financial Institution Name'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return onlyAlphabets(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w100"><label class="label_left">Bank Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['names_fieldset']['personal_financial_institution_phone_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Financial Institution Phone Number'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Bank Phone</label><span class="value_left">',
    '#suffix' => '</span></span>',
);



$form['names_fieldset']['personal_account_type_'.$i] = array(
    '#type'		      => 'select',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'class'=> array('form_text'),
    ),
    '#options'        => array(	'checking'=> t('Checking'),'saving'=> t('Saving')
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Account Type</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['names_fieldset']['personal_aba_routing_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('ABA Routing Number'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">ABA Routing#</label><span class="value_left">',
    '#suffix' => '</span></span>',
);


$form['names_fieldset']['broker_'.$i.'_bank_info_right_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div>',
);

//-------------//


$form['names_fieldset']['broker_'.$i.'_bank_info_end'] = array(
    '#type' => 'item',
    '#suffix' => '</div>',
);

// --------- //

$form['names_fieldset']['broker_'.$i.'_beneficiary_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_full"><div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Beneficiary Details</div>',
);

$form['names_fieldset']['beneficiary_first_name_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('First Name'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">First Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['beneficiary_middle_name_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Middle Name'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Middle Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['beneficiary_last_name_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Last Name'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Last Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['names_fieldset']['beneficiary_relarionship_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Relationship'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Relationship</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['beneficiary_email_id_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Email ID'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return MailId(event, this)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Email Id</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['beneficiary_contact_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Contact Number'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Contact</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['names_fieldset']['beneficiary_address_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Beneficiary Address'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w100"><label class="label_left">Street Address</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['beneficiary_city_id_'.$i] = array(
    '#type'=>'select',
    '#required'=>'true',
    '#theme_wrappers'  => array(),
    '#options' =>array(1=>'City'),
    '#attributes' => array(
        'placeholder' => t(''),
        'class' => array('form_text'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">City</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['beneficiary_state_id_'.$i] = array(
    '#type'=>'select',
    '#required'=>'true',
    '#theme_wrappers'  => array(),
    '#options' =>array(1=>'State'),
    '#attributes' => array(
        'placeholder' => t(''),
        'class' => array('form_text'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">State</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['beneficiary_zip_code_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Zip Code'),
        'class'=> array('form_text'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Zip Code</label><span class="value_left">',
    '#suffix' => '</span></span>',
     
);

$form['names_fieldset']['broker_'.$i.'_beneficiary_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div></div>',
);

//-----------//

if($i == ($total_brokers)){
  $form['names_fieldset']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
}

$form['names_fieldset']['broker_'.$i.'_details_end'] = array(
    '#type' => 'item',
    '#suffix' => '</div>',
);


	}


 $form['form_end'] = array(
 '#type' => 'item',
 '#suffix' => '</div> ',
 );