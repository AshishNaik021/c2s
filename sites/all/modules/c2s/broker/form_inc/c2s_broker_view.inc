<?php

drupal_add_css( drupal_get_path('module', 'broker') . '/css/global-c2s.css');

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

$brokerage_id = arg(3);
$result = db_query("SELECT * FROM brokerage_details WHERE brokerage_id = ".$brokerage_id);
foreach($result as $value){
    $brokerage_name 		  = $value->brokerage_name;
    $brokerage_start_date 	  = $value->brokerage_start_date;
    $number_of_owners         = $value->number_of_owners;
    $franchise_fee_cap		  = $value->franchise_fee_cap;
    $reap_amount_cap	      = $value->reap_amount_cap;
    $created 		          = $value->created;
    $changed 		          = $value->changed;
}

$result = db_query("SELECT * FROM broker_master WHERE brokerage_id = ".$brokerage_id." and deactivate = 0");
$broker_details = array();

$city = array('0'=>'City','1'=>'City1');
$state = array('0'=>'State','1'=>'State1');
$n = 0;
foreach($result as $value){
    $n++;
    $broker_details[$n]['id']	      = $value->broker_agent_id;    
    $broker_details[$n]['fname']	  = $value->first_name;
    $broker_details[$n]['mname']	  = $value->middle_name;
    $broker_details[$n]['lname']	  = $value->last_name;
    $broker_details[$n]['dob']  	  = $value->dob;
    $broker_details[$n]['pers_email'] = $value->personal_email;
    $broker_details[$n]['pers_phon']  = $value->personal_phone;
    $broker_details[$n]['home_addr']  = $value->home_address;
    $broker_details[$n]['city']       = $city[$value->home_city];
    $broker_details[$n]['state']      = $state[$value->home_state];
    $broker_details[$n]['home_zip']   = $value->home_zip;

    $broker_details[$n]['business_addr']  = $value->business_address;
    $broker_details[$n]['business_city']       = $city[$value->business_city];
    $broker_details[$n]['business_state']      = $state[$value->business_state];
    $broker_details[$n]['business_zip']   = $value->business_zip;
    $broker_details[$n]['state_id_number']  = $value->state_id_number;
    $broker_details[$n]['ein_number']       = $value-> ein_number;
    $broker_details[$n]['mls_username']      = $value-> mls_username;
    $broker_details[$n]['mls_password']   = $value-> mls_password;
    
    $broker_details[$n]['nrds_number']  = $value->nrds_number;
    $broker_details[$n]['c2s_email_id']       = $value->c2s_email_id;
    $broker_details[$n]['office_phone']      = $value->office_phone;
    $broker_details[$n]['office_extension']   = $value->office_extension;
    $broker_details[$n]['comm_reap_accno']  = $value-> comm_reap_accno;
    $broker_details[$n]['comm_reap_accname']       = $value-> comm_reap_accname;
    $broker_details[$n]['comm_reap_bankname']      = $value-> comm_reap_bankname;
    $broker_details[$n]['comm_reap_bankphone']   = $value-> comm_reap_bankphone;
    
    $broker_details[$n]['comm_reap_acctype']  = $value-> comm_reap_acctype;
    $broker_details[$n]['comm_reap_aba_routing']       = $value-> comm_reap_aba_routing;
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
$total_brokers = $n;

$result_paperwork = db_query("select document_name from required_paperwork where `paperwork_id` in 
    (SELECT `paperwork_id` FROM `brokerage_paperwork` where `brokerage_id` = ".$brokerage_id.")") ;
    



$number_to_words = array(1=>"One", 2=> "Two", 3=> "Three", 4=>"Four", 5=>"Five", 6=>"Six");


    $form['form_start'] = array(
        '#type' => 'item',
        '#suffix' => '<div id="main-view-wrapper">',
    );
    
    $form['brokerage_tab'] = array(
        '#type' => 'item',
        '#suffix' => '<div class="form_section_tab selected" data-item="form_tab_0" > Brokerage Details </div>',
    );
    
	for($i=1; $i<=$total_brokers; $i++){
	 
	 $form['broker_tab_'.$i] = array(
	     '#type' => 'item',
	     '#suffix' => '<div class="form_section_tab" data-item="form_tab_'.$i.'" > Brokerage '.$number_to_words[$i].' </div>',
	 );
	 
	}
	
	$form['brokerage_details_start'] = array(
	    '#type' => 'item',
	    '#suffix' => '<div id="form_tab_0" class="form_sections" style="display:block">',
	);
	
	$form['brokerage_details_seperator'] = array(
	    '#type' => 'item',
	    '#suffix' => '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
	);
	
	$form['brokerage_section_left_start'] = array(
	    '#type' => 'item',
	    '#theme_wrappers'  => array(),
	    '#prefix' => '<div class="section_left">',
	);
	
	
	
	$form['brokerage_name'] = array(
	    '#type'		       => 'textfield',
	    '#maxlength'	   => 100,
	    '#theme_wrappers'  => array(),
	    '#default_value'   => $brokerage_name,
	    '#disabled'        =>'true',
	    '#attributes'       => array(
	        'class'=> array('input_disabled'),
	        'placeholder'=> 'City2Shore',
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        'onChange'   => array('addPrefix(this, "City2Shore ")'),
	        'onClick'    => array('removePrefix(this)')
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100"><label class="label_left"> Name of Brokerage </label><span class="value_left">',
	    '#suffix' => '</span></span> <div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
	);
	

	$form['brokerage_start_date'] = array(
	    '#label'          => 'invisible',
	    '#type'		      => 'date_popup',
	    '#theme_wrappers'  => array(),
	    '#date_label_position' => 'Within',
	    '#disabled'       => 'true',
	    '#default_value'  => $brokerage_start_date,
	    '#date_format'	  => 'm/d/Y',
	    '#date_year_range'  => '-3:+3',
	    '#attributes'       => array(
	        'placeholder'=> t('mm/dd/YYYY'),
	        'class'=> array('date-input-medium input_disabled'),
	        'onKeyPress' => array('return false;'),
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left"> Start Date </label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	
	
	$form['number_of_owners'] = array(
	    '#title'          => 'Total Owners',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 5,
	    '#disabled'       => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $number_of_owners,
	    '#attributes'     => array(
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left"> Total Owner </label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['franchise_fee_cap'] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $franchise_fee_cap,
	    '#attributes'     => array(
	        'placeholder'=> t('$3000'),
	        'class'=> array('input_disabled'),
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Franchise Cap</label><span class="value_left">',
	    '#suffix' => '</span></span><div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
	);
	$form['transaction_management_fee'] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => '10',
	    '#attributes'     => array(
	        'placeholder'=> t('$2.96'),
	        'class'=> array('input_disabled'),
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Transaction Fee</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['reap_amount_cap'] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $reap_amount_cap,
	    '#attributes'     => array(
	        'placeholder'=> t('$18,000'),
	        'class'=> array('input_disabled'),
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Reap Cap</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['brokerage_section_left_end'] = array(
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
	
	$form['brokerage_section_right_start'] = array(
	    '#type' => 'item',
	    '#theme_wrappers'  => array(),
	    '#prefix' => '<div class="section_left">',
	    '#suffix' => $paperwork_list, 
	);	
	
	
	
	$form['brokerage_section_right_end'] = array(
	    '#type' => 'item',
	    '#theme_wrappers'  => array(),
	    '#prefix' => '</div>',
	);
	
	$form['brokerage_details_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div>',
	);
  
	
	/* Broker Loop */
	
	for($i=1; $i<=$total_brokers; $i++){
	$form['broker_'.$i.'_details_start'] = array(
	    '#type' => 'item',
	    '#suffix' => '<div id="form_tab_'.$i.'" class="form_sections" style="display:none">',
	);
	
	
	$form['broker_'.$i.'_details_seperator'] = array(
	    '#type' => 'item',
	    '#suffix' => '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
	);
	
	$form['broker_'.$i.'_personal_info_start'] = array(
	    '#type' => 'item',
	    '#theme_wrappers'  => array(),
	    '#prefix' => '<div class="section_left"> <div class="form_subsection_title" data-item="inner_section_1"> Personal Information</div>',
	);
	
	$form['broker_'.$i.'_first_name'] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['fname'],
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
	    '#disabled'		  => 'true',
	    '#default_value'  => $broker_details[$i]['mname'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['lname'],
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
	    '#disabled'		  => 'true',
	    '#default_value'  => $broker_details[$i]['dob'],
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
	    '#disabled'		  => 'true',
	    '#default_value'  => $broker_details[$i]['pers_email'],
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
	    '#disabled'		  => 'true',
	    '#default_value'  =>  $broker_details[$i]['pers_phon'],
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
	    '#disabled'		  => 'true',
	    '#default_value'  => $broker_details[$i]['home_addr'],
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
	    '#disabled'=>'true',
	    '#default_value'=>$broker_details[$i]['city'],
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
	    '#disabled'=>'true',
	    '#default_value'=>$broker_details[$i]['state'],
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
	    '#disabled'		  => 'true',
	    '#default_value'  => $broker_details[$i]['home_zip'],
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
	
	$form['busines_street_address_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['business_addr'],
	    '#attributes'     => array(
	        'placeholder'=> t('Street Address'),
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100"><label class="label_left">Business Address</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['business_city_id_'.$i] = array(
	    '#type'=>'select',
	    '#disabled'=>'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'=>$broker_details[$i]['business_city'],
	    '#options' =>array(1=>'City'),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('input_disabled'),
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left">City</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['business_state_id_'.$i] = array(
	    '#type'=>'select',
	    '#disabled'=>'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'=>$broker_details[$i]['business_state'],
	    '#options' =>array(1=>'State'),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('input_disabled'),
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left">State</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['business_zip_code_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['business_zip'],
	    '#attributes'     => array(
	        'placeholder'=> t('Zip Code'),
	        'class'=> array('input_disabled'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25"><label class="label_left">Zip Code</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['broker_state_id_number_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['state_id_number'],
	    '#attributes'     => array(
	        'placeholder'=> t('Broker State Id #'),
	        'class'=> array('input_disabled'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left">State ID#</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['broker_ein_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['ein_number'],
	    '#attributes'     => array(
	        'placeholder'=> t('Broker EIN'),
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Broker EIN#</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['mls_username_'.$i] = array(

	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['mls_username'],
	    '#attributes'     => array(
	        'placeholder'=> t('MLS Username'),
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25"><label class="label_left">MLS Username</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['mls_password_'.$i] = array(

	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['mls_password'],
	    '#attributes'     => array(
	        'placeholder'=> t('MLS Password'),
	        'class'=> array('input_disabled'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left">MLS Password</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['broker_nrds_'.$i] = array(

	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['nrds_number'],
	    '#attributes'     => array(
	        'placeholder'=> t('Broker NRDS#'),
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left">NRDS#</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['create_email_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['c2s_email_id'],
	    '#attributes'     => array(
	        'placeholder'=> t('Create Email'),
	        'class'=> array('input_disabled'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25"><label class="label_left">C2S Email</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['office_phone_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['office_phone'],
	    '#attributes'     => array(
	        'placeholder'=> t('Office Phone'),
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Office Phone</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);

	$form['extension_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['office_extension'],
	    '#attributes'     => array(
	        'placeholder'=> t('Extension'),
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Extension</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['choice_of_charity_org_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 250,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['choice_charity_orgid'],
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
	    '#prefix' => '</div><div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
	);
	
	$form['broker_'.$i.'_bank_info_start'] = array(
	    '#type' => 'item',
	    '#theme_wrappers'  => array(),
	    '#prefix' => '<div class="section_full"> <div class="form_subsection_title" data-item="inner_section_1"> Bank Details</div>',
	);
	
	//-------------- //
	
	$form['broker_'.$i.'_bank_info_left_start'] = array(
	    '#type' => 'item',
	    '#theme_wrappers'  => array(),
	    '#prefix' => '<div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Payout Commissions &amp; Reap To Agent</div>',
	);

	
	$form['comm_account_number_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['comm_reap_accno'],
	    '#attributes'     => array(
	        'placeholder'=> t('Account Number'),
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Account Number</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	$form['name_on_comm_account_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['comm_reap_accname'],
	    '#attributes'     => array(
	        'placeholder'=> t('Name On Account'),
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w60"><label class="label_left">Name on Account</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	$form['comm_financial_institution_name_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['comm_reap_bankname'],
	    '#attributes'     => array(
	        'placeholder'=> t('Financial Institution Name'),
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100"><label class="label_left">Bank Name</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	$form['comm_financial_institution_phone_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['comm_reap_bankphone'],
	    '#attributes'     => array(
	        'placeholder'=> t('Financial Institution Phone Number'),
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Bank Contact</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['comm_account_type_'.$i] = array(
	    '#type'		      => 'select',
	    '#maxlength'	  => 50,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['comm_reap_acctype'],
	    '#attributes'     => array(
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	    ),
	    //	        'onKeyPress' => array('return numbersonly(this, event)',),
	    //'readonly'=>'readonly',
	    '#options'        => array('checking' => t('Checking'),'saving'=> t('Saving')),
	    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Account Type</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	
	
	$form['comm_aba_routing_number_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['comm_reap_aba_routing'],
	    '#attributes'     => array(
	        'placeholder'=> t('ABA Routing Number'),
	        'class'=> array('input_disabled'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25"><label class="label_left">ABA Routing#</label><span class="value_left">',
	    '#suffix' => '</span></span>',
	);
	
	$form['broker_'.$i.'_bank_info_left_end'] = array(
	    '#type' => 'item',
	    '#theme_wrappers'  => array(),
	    '#prefix' => '</div>',
	);
	
	//---------- //
	
	$form['broker_'.$i.'_bank_info_right_start_'.$i] = array(
	    '#type' => 'item',
	    '#theme_wrappers'  => array(),
	    '#prefix' => '<div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Personal Commissions & Reap</div>',
	);
	
	$form['personal_account_number_'.$i] = array(
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['pers_comm_accno'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['pers_comm_accname'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['pers_comm_bankname'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['pers_comm_bankphone'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['pers_comm_acctype'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['pers_comm_aba_routing'],
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
	
	//-------------//
	
	
	$form['broker_'.$i.'_bank_info_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div>',
	);
	
	// --------- //
	
	$form['broker_'.$i.'_beneficiary_start'] = array(
	    '#type' => 'item',
	    '#theme_wrappers'  => array(),
	    '#prefix' => '<div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Beneficiary Details</div>',
	);
	
	$form['beneficiary_first_name_'.$i] = array(

	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#disabled'		  => 'true',
	    '#default_value'  => $broker_details[$i]['beneficiary_first_name'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['beneficiary_middle_name'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['beneficiary_last_name'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['beneficiary_relationship'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['beneficiary_email_id'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['beneficiary_contact_number'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['beneficiary_address'],
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
	    '#disabled'=>'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'=>$broker_details[$i]['beneficiary_city_id'],
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
	    '#disabled'=>'true',
	    '#default_value'=>$broker_details[$i]['beneficiary_state_id'],
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
	    '#disabled'		  => 'true',
	    '#theme_wrappers'  => array(),
	    '#default_value'  => $broker_details[$i]['beneficiary_zip_code'],
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
	    '#prefix' => '</div>',
	);
	
	//-----------//

	$form['broker_'.$i.'_details_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div>',
	);
	
	}

    
    $form['form_end'] = array(
        '#type' => 'item',
        '#suffix' => '</div> ',
    );

/*
     $data  =  "";
	 $data .=  '<div id="main-view-wrapper"> '; // Wrapper Start

	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Name of Brokerage </label>'.
	           '<span class="value_left"> '.$brokerage_name .' </value>'. '</span></span>';

	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Brokerage Start Date </label>'.
	     '<span class="value_left"> '. $brokerage_start_date .' </value>'. '</span></span>';	 

	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Number of Owners </label>'.
	     '<span class="value_left"> '. $number_of_owners .' </value>'. '</span></span>';	 
	 
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 
	for($i=1; $i<=$total_brokers; $i++){
	 
	    $class = "selected";
	    if($i>1){
	        $class = "";
	    }
	    
	 $data .=  '<div class="form_section_tab '.$class.'" data-item="form_tab_'.$i.'" > Broker '.$number_to_words[$i].' </div>';
	 
	}
	 
	for($i=1; $i<=$total_brokers; $i++){

	    
	 $display = "block";
	 if($i>1){
	     $display = "none";
	 }
	    
	 $data .=  '<div id="form_tab_'.$i.'" class="form_sections" style="display:'.$display.'">'; // Form Start	 
	 
	 $data .=  '<div style="margin: 1%;float: right;width: 100%;">
	      <input type="button" value="Edit Broker" style="float: right; margin:5px;">
	     <input type="button" value="Deactivate Broker" style="float: right; margin:5px;" onclick="window.location=\''.base_path().'c2s/broker/deactivate/'.$broker_details[$i]['id'].'/'.$brokerage_id.'\'"></div>'; // Disable Button
	 
	 
	 // -- Personal Information -- //
	 
	 $data .=  '<div class="section_left">'; // section  left start
	 $data .=  '<div class="form_subsection_title" data-item="inner_section_1"> Personal Information</div>';
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> First Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Middle Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';	 
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Last Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';

	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //

	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Date Of Birth </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Personal Email </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Contact Number </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_phon'] .' </value>'. '</span></span>';	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Street Address </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['home_addr'] .' </value>'. '</span></span>';
	 

	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> City </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['city'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> State </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['state'] .' </value>'. '</span></span>';	
	 
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> Zip Code </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['home_zip'] .' </value>'. '</span></span>';
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 
	 // -- Professional Information -- //
	 $data .=  '<div class="section_left">'; // section  left start
	 $data .=  '<div class="form_subsection_title" data-item="inner_section_1"> Professional Information</div>';
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Business Address </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';

	 
 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 

	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> City </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> State </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Zip Code </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 

	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Broker State Id # </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Broker EIN </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Broker NRDS# </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> MLS Username </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> MLS Password </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> C2S Email Id </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Office Phone </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Extension </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Charity Organization Of Your Choice </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 
	 
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 // -- Bank Details Information -- //
	 $data .=  '<div class="section_full">'; // section  full start
	 
	 $data .=  '<div class="form_subsection_title" data-item="inner_section_1"> Bank Details</div>';
	 $data .=  '<div class="subsection_left">'; // section  left start

	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<div class="form_subsection_title2">Payout Commissions &amp; Reap To Agent</div>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Account Number </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Name on Account </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 
	 
	 $data .=  '<span class="wrapper-w60">'. '<label class="label_left"> Financial Institution Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 

	 
	 
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Contact Number </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Account Type </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> ABA Routing # </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
 
	 
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 // -- sub section -- //
	 
	 $data .=  '<div class="subsection_left">'; // section  left start
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start

	 $data .=  '<div class="form_subsection_title2">Personal Commissions & Reap</div>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Account Number </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Name on Account </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 
	 
	 $data .=  '<span class="wrapper-w60">'. '<label class="label_left"> Financial Institution Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 

	 
	 
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Contact Number </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Account Type </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> ABA Routing # </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 $data .=  '</div>'; // section  full end	 
	 
	 
	 // -- Beneficiary Information -- //
	 
	 $data .=  '<div class="section_left">'; // section  left start
	 $data .=  '<div class="form_subsection_title" data-item="inner_section_1"> Beneficiary Details</div>';
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> First Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Middle Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Last Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Relationship </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Email id </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Contact Number </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_phon'] .' </value>'. '</span></span>';
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Street Address </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['home_addr'] .' </value>'. '</span></span>';
	 
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> City </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['city'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> State </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['state'] .' </value>'. '</span></span>';
	 
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> Zip Code </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['home_zip'] .' </value>'. '</span></span>';
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 // -- Broker Details Information -- //
	 $data .=  '<div class="section_full">'; // section  full start
	 
	 $data .=  '<div class="form_subsection_title" data-item="inner_section_1"> Broker Details</div>';
	 $data .=  '<div class="subsection_left">'; // section  left start
	 
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<div class="form_subsection_title2">Cap Amount Section</div>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Franchise Cap </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Transaction Management </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Reap Amount Cap </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 // -- sub section -- //
	 
	 $data .=  '<div class="subsection_left">'; // section  left start
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<div class="form_subsection_title2">Paper Work Required</div>';
	 
	 for($j=0; $j<=10; $j++){
	 
	       $data .=  '<span class="wrapper-w33">'. '<label class="label_left">  </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';
	 }
	 	 
	 
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 $data .=  '</div>'; // section  full end
	  
	 $data .=  '</div> '; // Form End
	 
	} // loop end
	 
	 $data .=  '</div> '; // Wrapper End */
	