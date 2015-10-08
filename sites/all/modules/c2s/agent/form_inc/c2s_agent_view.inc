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




$form['form_start'] = array(
    '#type' => 'item',
    '#suffix' => '<div id="main-view-wrapper">',
);




$form['brokerage_start_date'] = array(
    '#label'          => 'invisible',
    '#type'		      => 'date_popup',
    '#theme_wrappers'  => array(),
    '#date_label_position' => 'Within',
    '#required'       => 'true',
    '#date_format'	  => 'm/d/Y',
    '#date_year_range'  => '-3:+3',
    '#attributes'       => array(
        'placeholder'=> t('mm/dd/YYYY'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return false;'),
    ),
    '#prefix' => '<span class="wrapper-w100"><span class="wrapper-w33"><label class="label_left"> Start Date </label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['parent_id'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Type Min. 3 Characters of Agent Name'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return onlyAlphabets(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w60"><label class="label_left">Select Parent Agent</label><span class="value_left">',
    '#suffix' => '</span></span></span>',
);


for($i=1; $i<=2; $i++){
    $class="";
    if($i==1){
        $class="selected";
    }
    $form['broker_tab_'.$i] = array(
        '#type' => 'item',
        '#suffix' => '<div class="form_section_tab '.$class.'" id="tab_'.$i.'" data-item="form_tab_'.$i.'" onclick="click_tabs(\'tab_'.$i.'\')" > Agent '.$number_to_words[$i].' </div>',
    );

}









/* Broker Loop */
/*
$form['#tree'] = TRUE;
$form = array(
    '#type' => 'fieldset',
    '#theme_wrappers'  => array(),
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="names-fieldset-wrapper">',
    '#suffix' => '</div>',
); */

for($i=1; $i<=2; $i++){
    $display="none";
    if($i==1){
        $display="block";
    }
    
$form['broker_'.$i.'_details_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#suffix' => '<div id="form_tab_'.$i.'" class="form_sections" style="display:'.$display.'">',
);


$form['broker_'.$i.'_details_seperator'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#suffix' => '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
);

$form['broker_'.$i.'_personal_info_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_full"><div class="section_left"> <div class="form_subsection_title" data-item="inner_section_1"> Personal Information</div>',
);

$form['broker_'.$i.'_first_name'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('First Name'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return onlyAlphabets(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">First Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['broker_'.$i.'_middle_name'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Middle Name'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return onlyAlphabets(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Middle Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['broker_'.$i.'_last_name'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Last Name'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return onlyAlphabets(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Last Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);


$form['date_of_birth_'.$i] = array(
    '#label'          => '',
    '#type'		      => 'date_popup',
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#date_format'	  => 'm/d/Y',
    '#date_year_range'  => '-3:+3',
    '#attributes'       => array(
        'placeholder'=> t('mm/dd/YYYY'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return false;'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Date of Birth</label><span class="value_left">',
    '#suffix' => '</span></span>',
);


$form['personl_email_id_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Personal Email ID'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return MailId(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Email Id</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['contact_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Contact Number'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Contact</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['street_address_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Street Address'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w100"><label class="label_left">Street Address</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['city_id_'.$i] = array(
    '#type'=>'select',
    '#required'=>'true',
    '#options' =>array(1=>'City'),
    '#theme_wrappers'  => array(),
    '#attributes' => array(
        'placeholder' => t(''),
        'class' => array('input_disabled'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">City</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['state_id_'.$i] = array(
    '#type'=>'select',
    '#required'=>'true',
    '#options' =>array(1=>'State'),
    '#theme_wrappers'  => array(),
    '#attributes' => array(
        'placeholder' => t(''),
        'class' => array('input_disabled'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">State</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['zip_code_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Zip Code'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Zip Code</label><span class="value_left">',
    '#suffix' => '</span></span>',
     
);

$form['broker_'.$i.'_personal_info_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div>',
);


$form['broker_'.$i.'_professional_info_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_left"> <div class="form_subsection_title" data-item="inner_section_1"> Professional Information</div>',
);



$form['broker_state_id_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Broker State Id #'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">State ID#</label><span class="value_left">',
    '#suffix' => '</span></span>',
);


$form['broker_nrds_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Broker NRDS#'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">NRDS#</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['mls_username_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('MLS User Id'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">MLS User Id</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['mls_password_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('MLS Password'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">MLS Password</label><span class="value_left">',
    '#suffix' => '</span></span>',
);



$form['office_phone_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Office Phone'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Office Phone</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['extension_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Extension'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Extension</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['create_email_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('example@c2semail.com'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w60"><label class="label_left">C2S Email</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['choice_of_charity_org_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 250,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Type Min 3 Chars'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w100"><label class="label_left">Charity Organization Chosen</label><span class="value_left">',
    '#suffix' => '</span></span>',
);


$form['broker_'.$i.'_professional_info_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div><div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div></div>',
);


// --------- //
//---------- //

$form['broker_'.$i.'_bank_info_right_start_'.$i] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_full"><div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Bank Details</div>',
);

$form['personal_account_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Account Number'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Account Number</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['name_on_personal_account_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Name On Account'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w60"><label class="label_left">Name On Account</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['personal_financial_institution_name_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Financial Institution Name'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return onlyAlphabets(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w100"><label class="label_left">Bank Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['personal_financial_institution_phone_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Financial Institution Phone Number'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Bank Phone</label><span class="value_left">',
    '#suffix' => '</span></span>',
);



$form['personal_account_type_'.$i] = array(
    '#type'		      => 'select',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'class'=> array('input_disabled'),
    ),
    '#options'        => array(	'checking'=> t('Checking'),'saving'=> t('Saving')
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Account Type</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['personal_aba_routing_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('ABA Routing Number'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">ABA Routing#</label><span class="value_left">',
    '#suffix' => '</span></span>',
);


$form['broker_'.$i.'_bank_info_right_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div>',
);

$form['broker_'.$i.'_beneficiary_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Beneficiary Details</div>',
);

$form['beneficiary_first_name_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('First Name'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">First Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['beneficiary_middle_name_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Middle Name'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Middle Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['beneficiary_last_name_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Last Name'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Last Name</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['beneficiary_relarionship_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Relationship'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Relationship</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['beneficiary_email_id_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Email ID'),
        'class'=> array('input_disabled'),
        'onKeyPress' => array('return MailId(event, this)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Email Id</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['beneficiary_contact_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Contact Number'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Contact</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['beneficiary_address_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Beneficiary Address'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w100"><label class="label_left">Street Address</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['beneficiary_city_id_'.$i] = array(
    '#type'=>'select',
    '#required'=>'true',
    '#theme_wrappers'  => array(),
    '#options' =>array(1=>'City'),
    '#attributes' => array(
        'placeholder' => t(''),
        'class' => array('input_disabled'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">City</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['beneficiary_state_id_'.$i] = array(
    '#type'=>'select',
    '#required'=>'true',
    '#theme_wrappers'  => array(),
    '#options' =>array(1=>'State'),
    '#attributes' => array(
        'placeholder' => t(''),
        'class' => array('input_disabled'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">State</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['beneficiary_zip_code_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#required'		  => 'true',
    '#theme_wrappers'  => array(),
    '#attributes'     => array(
        'placeholder'=> t('Zip Code'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Zip Code</label><span class="value_left">',
    '#suffix' => '</span></span>',
     
);

$form['broker_'.$i.'_beneficiary_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div></div>',
);

//-----------//


$form['broker_'.$i.'_details_end'] = array(
    '#type' => 'item',
    '#suffix' => '</div>',
);


	}
	$form['submit'] = array(
	    '#type' => 'submit',
	    '#value' => t('Save'),
	);

 $form['form_end'] = array(
 '#type' => 'item',
 '#suffix' => '</div> ',
 );