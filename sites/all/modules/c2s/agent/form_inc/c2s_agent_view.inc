<?php

$form['#attached']['js'] = array(
    drupal_get_path('module', 'agent') . '/js/validate.js',
);
$form['#attached']['js'] = array(
    drupal_get_path('module', 'agent') . '/js/agent.js',
);

$form['#attached']['css'] = array(
    drupal_get_path('module', 'broker') . '/css/global-c2s.css',
);


$broker_id = arg(3);
$result = db_query("SELECT * FROM broker_master WHERE (broker_agent_id = ".$broker_id." or related_agent_id = ".$broker_id.") and deactivate = 0");
$broker_details = array();

$city = array('0'=>'City','1'=>'City1');
$state = array('0'=>'State','1'=>'State1');
$n = 0;
foreach($result as $value){
    $n++;
    $broker_details[$n]['id']	      = $value->broker_agent_id;
    $broker_details[$n]['agent_start_date']   = $value->agent_start_date;
    $broker_details[$n]['agent_relationship']   = $value->agent_relationship;
    $broker_details[$n]['fname']	  = $value->first_name;
    $broker_details[$n]['mname']	  = $value->middle_name;
    $broker_details[$n]['lname']	  = $value->last_name;
    $broker_details[$n]['dob']  	  = $value->dob;
    $broker_details[$n]['pers_email'] = $value->personal_email;
    $broker_details[$n]['pers_phon']  = $value->personal_phone;
    $broker_details[$n]['home_addr']  = $value->home_address;
    $broker_details[$n]['city']       = $value->home_city;
    $broker_details[$n]['state']      = $value->home_state;
    $broker_details[$n]['home_zip']   = $value->home_zip;

    $broker_details[$n]['business_addr']  = $value->business_address;
    $broker_details[$n]['business_city']       = $value->business_city;
    $broker_details[$n]['business_state']      = $value->business_state;
    $broker_details[$n]['business_zip']   = $value->business_zip;
    $broker_details[$n]['state_id_number']  = $value->state_id_number;
    $broker_details[$n]['ein_number']       = $value-> ein_number;
    $broker_details[$n]['mls_username']      = $value-> mls_username;
    $broker_details[$n]['mls_password']   = $value-> mls_password;

    $broker_details[$n]['nrds_number']  = $value->nrds_number;
    $broker_details[$n]['c2s_email_id']       = $value->c2s_email_id;
    $broker_details[$n]['office_phone']      = $value->office_phone;
    $broker_details[$n]['office_extension']   = $value->office_extension;

    $broker_details[$n]['pers_comm_accno']      = $value-> pers_comm_accno;
    $broker_details[$n]['office_extension']   = $value->office_extension;
    $broker_details[$n]['pers_comm_accname']  = $value-> pers_comm_accname;
    $broker_details[$n]['pers_comm_bankname']       = $value-> pers_comm_bankname;
    $broker_details[$n]['pers_comm_bankphone']      = $value-> pers_comm_bankphone;
    $broker_details[$n]['pers_comm_acctype']   = $value-> pers_comm_acctype;

    $broker_details[$n]['pers_comm_aba_routing']  = $value-> pers_comm_aba_routing;
    $broker_details[$n]['choice_charity_orgid']       = $value-> choice_charity_orgid;

    $broker_details[$n]['beneficiary_first_name']  = $value-> beneficiary_first_name;
    $broker_details[$n]['beneficiary_middle_name']       = $value-> beneficiary_middle_name;
    $broker_details[$n]['beneficiary_last_name']      = $value-> beneficiary_last_name;
    $broker_details[$n]['beneficiary_relationship']   = $value-> beneficiary_relationship;
    $broker_details[$n]['beneficiary_email_id']  = $value-> beneficiary_email_id;
    $broker_details[$n]['beneficiary_contact_number']       = $value-> beneficiary_contact_number;
    $broker_details[$n]['beneficiary_address']      = $value-> beneficiary_address;
    $broker_details[$n]['beneficiary_city_id']   = $value-> beneficiary_city_id;

    $broker_details[$n]['beneficiary_state_id']  = $value-> beneficiary_state_id;
    $broker_details[$n]['beneficiary_zip_code']       = $value-> beneficiary_zip_code;


}

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




$form['agent_start_date'] = array(
    '#label'          => 'invisible',
    '#type'		      => 'date_popup',
    '#theme_wrappers'  => array(),
    '#date_label_position' => 'Within',
    '#default_value' => $broker_details[1]['agent_start_date'],
    '#disabled'     => true,
    '#date_format'	  => 'm/d/Y',
    '#date_year_range'  => '-3:+3',
    '#attributes'       => array(
        'placeholder'=> t('mm/dd/YYYY'),
        'class'=> array('date-input-medium input_disabled'),
        'onKeyPress' => array('return false;'),
    ),
    '#prefix' => '<span class="wrapper-w100"><span class="wrapper-w33"><label class="label_left"> Start Date </label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['parent_id'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
      '#default_value' => $broker_details[1]['id'],
    '#disabled'     => true, 
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
    $form['agent_tab_'.$i] = array(
        '#type' => 'item',
        '#suffix' => '<div class="form_section_tab '.$class.'" id="tab_'.$i.'" data-item="form_tab_'.$i.'" onclick="click_tabs_agent('.$i.')" > Agent '.$number_to_words[$i].' </div>',
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
 
$form['#submit'][] = 'c2s_agent_view_submit';    
$form['agent_'.$i.'_details_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#suffix' => '<input type="button" value="Edit Broker" style="float: right; margin:5px;" onclick="convert_edit('.$broker_details[$i]['id'].')">
	     <input type="button" value="Deactivate Broker" style="float: right; margin:5px;" onclick="window.location=\''.base_path().'c2s/agent/deactivate/'.$broker_details[$i]['id'].'\'">',
    '#prefix' => '<div id="form_tab_'.$i.'" class="form_sections" style="display:'.$display.'">',
);

if($i == 2){
    $form['agent_relationship'] = array(
        '#type'=>'select',
        '#default_value' => $broker_details[$i]['agent_relationship'],
        '#disabled'     => true,
        '#options' =>array('0'=>'-- Select --','Sibling'=>'Sibling','Spouse'=>'Spouse','Parent'=>'Parent','OffSpring'=>'OffSpring'),
        '#theme_wrappers'  => array(),
        '#attributes' => array(
            'placeholder' => t(''),
            'class' => array('input_disabled'),
        ),
        '#prefix' => '<span class="wrapper-w33"><label class="label_left">Select Relation With Agent One</label><span class="value_left">',
        '#suffix' => '</span></span>',
    );
}


$form['agent_'.$i.'_details_seperator'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#suffix' => '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
);

$form['agent_'.$i.'_personal_info_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_full"><div class="section_left"> <div class="form_subsection_title" data-item="inner_section_1"> Personal Information</div>',
);

$form['agent_'.$i.'_first_name'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#default_value' => $broker_details[$i]['fname'],
    '#disabled'     => true,
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

$form['agent_'.$i.'_id'] = array(
    '#type'		      => 'hidden',
    '#default_value' => $broker_details[$i]['id'],
);

$form['agent_'.$i.'_middle_name'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#default_value' => $broker_details[$i]['mname'],
    '#disabled'     => true,
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

$form['agent_'.$i.'_last_name'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#default_value' => $broker_details[$i]['lname'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['dob'],
    '#disabled'     => true,
    '#theme_wrappers'  => array(),
    '#date_format'	  => 'm/d/Y',
    '#date_year_range'  => '-3:+3',
    '#attributes'       => array(
        'placeholder'=> t('mm/dd/YYYY'),
        'class'=> array('date-input-medium input_disabled'),
        'onKeyPress' => array('return false;'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Date of Birth</label><span class="value_left">',
    '#suffix' => '</span></span>',
);


$form['personl_email_id_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#default_value' => $broker_details[$i]['pers_email'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['pers_phon'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['home_addr'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['city'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['state'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['home_zip'],
    '#disabled'     => true,
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

$form['agent_'.$i.'_personal_info_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div>',
);


$form['agent_'.$i.'_professional_info_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_left"> <div class="form_subsection_title" data-item="inner_section_1"> Professional Information</div>',
);



$form['agent_state_id_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#default_value' => $broker_details[$i]['state_id_number'],
    '#disabled'     => true,
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


$form['agent_nrds_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 25,
    '#default_value' => $broker_details[$i]['nrds_number'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['mls_username'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['mls_password'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['office_phone'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['office_extension'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['c2s_email_id'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['choice_charity_orgid'],
    '#disabled'     => true,
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


$form['agent_'.$i.'_professional_info_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div><div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div></div>',
);


// --------- //
//---------- //

$form['agent_'.$i.'_bank_info_right_start_'.$i] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_full"><div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Bank Details</div>',
);

$form['personal_account_number_'.$i] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#default_value' => $broker_details[$i]['pers_comm_accno'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['pers_comm_accname'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['pers_comm_bankname'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['pers_comm_bankphone'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['pers_comm_acctype'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['pers_comm_aba_routing'],
    '#disabled'     => true,
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


$form['agent_'.$i.'_bank_info_right_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div>',
);

$form['agent_'.$i.'_beneficiary_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Beneficiary Details</div>',
);

$form['beneficiary_first_name_'.$i] = array(

    '#type'		      => 'textfield',
    '#maxlength'	  => 50,
    '#default_value' => $broker_details[$i]['beneficiary_first_name'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['beneficiary_middle_name'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['beneficiary_last_name'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['beneficiary_relationship'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['beneficiary_email_id'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['beneficiary_contact_number'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['beneficiary_address'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['beneficiary_city_id'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['beneficiary_state_id'],
    '#disabled'     => true,
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
    '#default_value' => $broker_details[$i]['beneficiary_zip_code'],
    '#disabled'     => true,
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

$form['agent_'.$i.'_beneficiary_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div></div>',
);

//-----------//


$form['agent_'.$i.'_details_end'] = array(
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