<?php

$form['#attached']['js'] = array(
    drupal_get_path('module', 'c2s') . '/js/validate.js',
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

	$form['form_start'] = array(
	   '#type' => 'item',
	   '#suffix' => '<div id="main-form-wrapper"> ',
	);
        

	$form['brokerage_start_date'] = array(
	    '#title'	      => 'Brokerage Start Date',
	    '#label'          => '',
	    '#type'		      => 'date_popup',
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#date_format'	  => 'm/d/Y',
	    '#date_year_range'  => '-3:+3',
	    '#attributes'       => array(
	        'placeholder'=> t('mm/dd/YYYY'),
	        'class'=> array('date-input-medium'),
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);
	
	$form['brokerage_name'] = array(
	    '#title'           => 'Name of Brokerage',
	    '#type'		       => 'textfield',
	    '#maxlength'	   => 100,
	    '#required'		   =>'true',
	    '#default_value'   =>'',
	    '#attributes'       => array(
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<p class="C2S"style="float:left;">city2shore</p><span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
		
	$form['number_of_owners'] = array(
	    '#title'          => 'How many Broker Owners are there?',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 5,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	
	
	$form['broker_owner_1'] = array(
	   '#type' => 'item',
	   '#prefix' => '<div id="form_sections" class="form_sections"> ',
	   '#suffix' => '<div class="form_section_title" data-item = "form_section_1"> Broker One 
	    <img src="'.base_path().'/'.drupal_get_path('module', 'c2s').'/images/arrow_toggle.png" id="form_section_1_arrow" style="width:16px;" > </div>
	    <div id = "form_section_1">'
	);
    	$form['personal_info_subsection_start'] = array(
    	   '#type' => 'item',
    	   '#prefix' => '<div class="form_subsection_title" data-item="inner_section_1"> Personal Information 
    	    <img src="'.base_path().'/'.drupal_get_path('module', 'c2s').'/images/arrow_toggle.png" id="inner_section_1_arrow" style="width:16px;" >
    	    </div>',
    	   '#suffix' => '<div id="inner_section" class="inner_section_1">',
    	);
	$form['broker_first_name'] = array(
	    '#title'          => 'First Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('First Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);	

	$form['broker_middle_name'] = array(
	    '#title'          => 'Middle Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Middle Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);

	$form['broker_last_name'] = array(
	    '#title'          => 'Last Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Last Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);
	
	
	$form['date_of_birth'] = array(
	    '#title'	      => 'Date of Birth',
	    '#label'          => '',
	    '#type'		      => 'date_popup',
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#date_format'	  => 'm/d/Y',
	    '#date_year_range'  => '-3:+3',
	    '#attributes'       => array(
	        'placeholder'=> t('mm/dd/YYYY'),
	        'class'=> array('date-input-medium'),
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);
	
	
	$form['personl_email_id'] = array(
	    '#title'          => 'Personal Email ID',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Personal Email ID'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);
	
	$form['contact_number'] = array(
	    '#title'          => 'Contact Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Contact Number'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);

	$form['street_address'] = array(
	    '#title'          => 'Street Address',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Street Address'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);

	$form['city_id'] = array(
	    '#title' => t('City'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);

	$form['state_id'] = array(
	    '#title' => t('State'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);
	$form['zip_code'] = array(
	    '#title'          => 'Zip Code',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Zip Code'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);
	
	$form['personal_info_subsection_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div><hr>',
	);

	

	$form['professional_info_subsection_start'] = array(
	    '#type' => 'item',
	   '#prefix' => '<div class="form_subsection_title" data-item="inner_section_2"> Professional Information 
	    <img src="'.base_path().'/'.drupal_get_path('module', 'c2s').'/images/arrow_toggle.png" id="inner_section_2_arrow" style="width:16px;" >
	    </div>',
	   '#suffix' => '<div id="inner_section" class="inner_section_2">',
	);
	
	$form['busines_street_address'] = array(
	    '#title'          => 'Business Address',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Street Address'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['business_city_id'] = array(
	    '#title' => t('City'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span id="rep-loc-replace"><span class="wrapper-w16">',
	    '#suffix' => '</span></span>',
	);
	
	$form['business_state_id'] = array(
	    '#title' => t('State'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span id="rep-loc-replace"><span class="wrapper-w16">',
	    '#suffix' => '</span></span>',
	);
	
    $form['business_zip_code'] = array(
	    '#title'          => 'Zip Code',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Zip Code'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);
    
	$form['broker_state_id'] = array(
	    '#title'          => 'Broker State Id #',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Broker State Id #'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	
	$form['broker_ein'] = array(
	    '#title'          => 'Broker EIN',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Broker EIN'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	
	$form['mls_username'] = array(
	    '#title'          => 'MLS Username',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('MLS Username'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	
	$form['mls_password'] = array(
	    '#title'          => 'MLS Password',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('MLS Password'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	
	$form['broker_nrds'] = array(
	    '#title'          => 'Broker NRDS#',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Broker NRDS#'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['broker_nrds_link'] = array(
	     '#title'          => 'Link to look up NRDS#',
	    '#type' => 'item',
	    '#prefix' => '<span class="wrapper-w50"><a class="url" href="url">http://reg.realtor.org/</a>' ,
	    '#suffix' => '</span>',
	);
	
	$form['create_email'] = array(
	    '#title'          => 'Create Email',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Create Email'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span> <p class="c2s"style="float:left;">@city2shore.com</p>',
	);
	
	$form['office_phone'] = array(
	    '#title'          => 'Office Phone',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Office Phone'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	
	$form['extension'] = array(
	    '#title'          => 'Extension',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Extension'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	
	$form['charity organization of choice'] = array(
	    '#title'          => 'Charity Organization Of Choice',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Type Min 3 Chars'),
	        'class'=> array('input-mini'),
	         'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['professional_info_subsection_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div><hr>',
	);
	
	$form['bank_details_subsection_start'] = array(
	    '#type' => 'item',
	   '#prefix' => '<div class="form_subsection_title" data-item="inner_section_3"> Bank Details
	    <img src="'.base_path().'/'.drupal_get_path('module', 'c2s').'/images/arrow_toggle.png" id="inner_section_3_arrow" style="width:16px;" >
	    </div>',
	   '#suffix' => '<div id="inner_section" class="inner_section_3">',
	);
	
	$form['bank_account1_start'] = array(
	    '#type' => 'item',
	    '#prefix' => '<div class="form_subsection_title2" data-item="inner_section2_1">
	    Bank Account Number For Payout Commissions & Reap To Agent
	    <img src="'.base_path().'/'.drupal_get_path('module', 'c2s').'/images/arrow_toggle.png" id="inner_section2_1_arrow" style="width:16px;" >
	    </div>',
		'#suffix' =>  '<div id="inner_section" class="inner_section2_1">',
	);
	
	$form['account_number_1'] = array(
	    '#title'          => 'Account Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Account Number'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	$form['name_on_account_1'] = array(
	    '#title'          => 'Name On Account',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Name On Account'),
	        'class'=> array('input-mini'),
	         'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
    $form['financial_institution_name_1'] = array(
	    '#title'          => 'Financial Institution Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Financial Institution Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
    $form['financial_institution_phone_number_1'] = array(
	    '#title'          => 'Financial Institution Phone Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Financial Institution Phone Number'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
    
	 $form['account_type_1'] = array(
	    '#title'          => 'Account Type',
	    '#type'		      => 'radios',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	       'class'=> array('input-mini'),
	       'onKeyPress' => array('return IsNumeric(event, this);',),
	       ),             
//	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    '#options'        => array('checking' => t('Checking'),'saving'=> t('Saving')),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	
	$form['aba_routing_number_1'] = array(
	    '#title'          => 'ABA Routing Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('ABA Routing Number'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	
	$form['bank_account1_end'] = array(
	    '#type' => 'item',
	    '#suffix' =>  '</div>',
	);	

	$form['bank_account2_start'] = array(
	    '#type' 	=> 'item',
	    '#prefix' 	=> '<div class="form_subsection_title2" data-item="inner_section2_2">
	    Bank Account Number For Personal Commissions & Reap
	    <img src="'.base_path().'/'.drupal_get_path('module', 'c2s').'/images/arrow_toggle.png" id="inner_section2_2_arrow" style="width:16px;" >
	    </div>',
		'#suffix' 	=> '<div id="inner_section" class="inner_section2_2">',
	);
	
	$form['account_number_2'] = array(
	    '#title'          => 'Account Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Account Number'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	$form['name_on_account_2'] = array(
	    '#title'          => 'Name On Account',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Name On Account'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
    $form['financial_institution_name_2'] = array(
	    '#title'          => 'Financial Institution Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Financial Institution Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
    $form['financial_institution_phone_number_2'] = array(
	    '#title'          => 'Financial Institution Phone Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Financial Institution Phone Number'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
    
    
    
	 $form['account_type_2'] = array(
	    '#title'          => 'Account Type',
	    '#type'		      => 'radios',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'class'=> array('input-mini'),
	        ),
	     '#options'        => array(	'checking'=> t('Checking'),'saving'=> t('Saving')
//	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	 
	$form['aba_routing_number_2'] = array(
	    '#title'          => 'ABA Routing Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('ABA Routing Number'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	
	$form['bank_account2_end'] = array(
	    '#type' 	=> 'item',
	    '#suffix' 	=> '</div>',
	);
	
	$form['bank_details_subsection_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div><hr>',
	);

	
	$form['beneficiary_details_subsection_start'] = array(
	    '#type' => 'item',
	    '#prefix' => '<div class="form_subsection_title" data-item="inner_section_4"> Beneficiary Details
	    <img src="'.base_path().'/'.drupal_get_path('module', 'c2s').'/images/arrow_toggle.png" id="inner_section_4_arrow" style="width:16px;" >
	    </div>',
	    '#suffix' => '<div id="inner_section" class="inner_section_4">',
	);
	
	$form['beneficiary_first_name'] = array(
	    '#title'          => 'First Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('First Name'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);	

	$form['beneficiary_middle_name'] = array(
	    '#title'          => 'Middle Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Middle Name'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);

	$form['beneficiary_last_name'] = array(
	    '#title'          => 'Last Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Last Name'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);
	$form['beneficiary_relarionship'] = array(
	    '#title'          => 'Relationship',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Relationship'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);	

	$form['beneficiary_email_id'] = array(
	    '#title'          => 'Beneficiary Email ID',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Email ID'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);

	$form['beneficiary_contact_number'] = array(
	    '#title'          => 'Beneficiary Contact Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Contact Number'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);
    $form['beneficiary_address'] = array(
	    '#title'          => 'Beneficiary Address',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Beneficiary Address'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['beneficiary_city_id'] = array(
	    '#title' => t('City'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span id="rep-loc-replace"><span class="wrapper-w16">',
	    '#suffix' => '</span></span>',
	);
	
	$form['beneficiary_state_id'] = array(
	    '#title' => t('State'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span id="rep-loc-replace"><span class="wrapper-w16">',
	    '#suffix' => '</span></span>',
	);
	
    $form['beneficiary_zip_code'] = array(
	    '#title'          => 'Zip Code',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Zip Code'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);
      	
    $form['beneficiary_details_subsection_end'] = array(
        '#type' => 'item',
        '#suffix' => '</div>',
    );

	
	
	$form['section_one_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div></div> ',
	);

	/*
	    

	 
	 $loc_options = '';  $selected_rep_loc ='';
	
	 $company_options = emp_company_dd();
	
	 if(isset($form_state['values']['company_id'])){
	 $selected_rep_loc = isset($form_state['values']['company_id']) ? $form_state['values']['company_id']: key($company_options);
	 }else{
	 $selected_rep_loc = $company_code;
	 }
	
	
	 $form['ot_rate_id'] = array(
	 '#type'=>'hidden',
	 '#default_value'=>$ot_rate_id,
	 );
	
	 $form['company_id'] = array(
	 '#title' => t('Company'),
	 '#type'=>'select',
	 '#required'=>'true',
	 '#default_value'=>$company_code,
	 '#options' => $company_options,
	 '#attributes' => array(
	 'placeholder' => t(''),
	 'class' => array('select-xlarge', 'uniform'),
	 ),
	 '#prefix' => '<span class="mini-form-item-with-lable-top">',
	 '#suffix' => '</span>',
	 '#ajax' => array(
	 'callback' => 'emp_rep_loc_callback',
	 'wrapper' =>  'rep-loc-replace',
	 //'progress' => 'none',
	 ),
	 );
	
	 $loc_options = emp_rep_location_dd($selected_rep_loc);
	
	 $form['location_id'] = array(
	 '#title' => t('Location'),
	 '#type'=>'select',
	 '#required'=>'true',
	 '#default_value'=>$location_code,
	 '#options' =>$loc_options,
	 '#attributes' => array(
	 'placeholder' => t(''),
	 'class' => array('select-xlarge', 'uniform'),
	 ),
	 '#prefix' => '<span id="rep-loc-replace"><span class="mini-form-item-with-lable-top">',
	 '#suffix' => '</span></span>',
	 );
	
	
	
	
	 $form['emp_type'] = array(
	 '#title' 			=> t('Employee Type'),
	 '#type'			=>'select',
	 '#default_value'	=>$employee_type,
	 '#options' 		=>array('Yes'=>'Unionized','No'=>'Non-unionized'),
	 '#attributes' => array(
	 'placeholder' => t(''),
	 'class' => array('select-xlarge', 'uniform'),
	 ),
	 '#prefix' => '<span class="mini-form-item-with-lable-top">',
	 '#suffix' => '</span>',
	 );
	
	
	 $cat_options = emp_category_dd();
	
	 $form['category'] = array(
	 '#title' => t('Employee Category'),
	 '#type'=>'select',
	 '#required'=>'true',
	 '#default_value'=>$category,
	 '#options' =>$cat_options,
	 '#attributes' => array(
	 'placeholder' => t(''),
	 'class' => array('select-xlarge', 'uniform'),
	 ),
	 '#prefix' => '<span class="mini-form-item-with-lable-top">',
	 '#suffix' => '</span>',
	 );
	
	
	 $grade_options = emp_grade_dd_ot();
	
	 $form['grade'] = array(
	 '#title' => t('Employee Grade'),
	 '#type'=>'select',
	 '#required'=>'true',
	 '#default_value'=>$grade,
	 '#options' =>$grade_options,
	 '#attributes' => array(
	 'placeholder' => t(''),
	 'class' => array('select-xlarge', 'uniform'),
	 ),
	 '#prefix' => '<span class="mini-form-item-with-lable-top">',
	 '#suffix' => '</span>',
	 );
	
	
	 $form['rates'] = array(
	 '#title'                => 'Rate Multiple of Basic Salary / Hour',
	 '#type'		 => 'textfield',
	 '#maxlength'		 => 3,
	 '#required'		 =>'true',
	 '#default_value'	 =>$rate_multiple,
	 '#description' 		 => 'Rate Multiple is used for OT Rate calculation <br> e.g. OT Amount = Monthly Basic/30/8 * Rate Multiple * Num of OT Hours',
	 '#attributes'       => array(
	 'class'=> array('input-mini'),
	 'onKeyPress' => array('return IsNumeric(event, this);',),
	 //'readonly'=>'readonly',
	 ),
	 '#prefix' => '<span class="large-form-item-with-lable-top">',
	 '#suffix' => '</span>',
	 );
	
	
	
	 $form['submit'] = array('#type'=>'submit',
	 '#value'=>t(' Submit '),
	 '#attributes' => array(
	 'class' => array('submit-blue-button-float-right'),
	 ),
	 '#submit' => array('overtime_setting_submit'),
	 '#suffix'=>'</div>',
	 );
	
	 $ot_setting_display  =  ot_setting_display();
	
	 $form['setting_report'] = array(
	 '#type'=>'hidden',
	 '#prefix' =>'<div id="#">'.$ot_setting_display.'</div>',
	 );
	
	
	
	 */
	
	


	/*
	 $loc_options = '';  $selected_rep_loc ='';
	
	 $company_options = emp_company_dd();
	
	 if(isset($form_state['values']['company_id'])){
	 $selected_rep_loc = isset($form_state['values']['company_id']) ? $form_state['values']['company_id']: key($company_options);
	 }else{
	 $selected_rep_loc = $company_code;
	 }
	
	
	 $form['ot_rate_id'] = array(
	 '#type'=>'hidden',
	 '#default_value'=>$ot_rate_id,
	 );
	
	 $form['company_id'] = array(
	 '#title' => t('Company'),
	 '#type'=>'select',
	 '#required'=>'true',
	 '#default_value'=>$company_code,
	 '#options' => $company_options,
	 '#attributes' => array(
	 'placeholder' => t(''),
	 'class' => array('select-xlarge', 'uniform'),
	 ),
	 '#prefix' => '<span class="mini-form-item-with-lable-top">',
	 '#suffix' => '</span>',
	 '#ajax' => array(
	 'callback' => 'emp_rep_loc_callback',
	 'wrapper' =>  'rep-loc-replace',
	 //'progress' => 'none',
	 ),
	 );
	
	 $loc_options = emp_rep_location_dd($selected_rep_loc);
	
	 $form['location_id'] = array(
	 '#title' => t('Location'),
	 '#type'=>'select',
	 '#required'=>'true',
	 '#default_value'=>$location_code,
	 '#options' =>$loc_options,
	 '#attributes' => array(
	 'placeholder' => t(''),
	 'class' => array('select-xlarge', 'uniform'),
	 ),
	 '#prefix' => '<span id="rep-loc-replace"><span class="mini-form-item-with-lable-top">',
	 '#suffix' => '</span></span>',
	 );
	
	
	 $form['effective_date'] = array(
	 '#title'			 => 'Effective From',
	 '#type'			 => 'date_popup',
	 '#required'		 =>'true',
	 '#default_value'	 =>$effective_date,
	 '#date_format'		 => 'd/m/Y',
	 '#date_year_range'  => '2:2',
	 '#attributes'       => array(
	 'placeholder'=> t('dd/mm/YY'),
	 'class'=> array('date-input-medium'),
	 ),
	 '#prefix' => '<span class="mini-form-item-with-lable-top">',
	 '#suffix' => '</span>',
	 );
	
	
	
	 $form['emp_type'] = array(
	 '#title' 			=> t('Employee Type'),
	 '#type'			=>'select',
	 '#default_value'	=>$employee_type,
	 '#options' 		=>array('Yes'=>'Unionized','No'=>'Non-unionized'),
	 '#attributes' => array(
	 'placeholder' => t(''),
	 'class' => array('select-xlarge', 'uniform'),
	 ),
	 '#prefix' => '<span class="mini-form-item-with-lable-top">',
	 '#suffix' => '</span>',
	 );
	
	
	 $cat_options = emp_category_dd();
	
	 $form['category'] = array(
	 '#title' => t('Employee Category'),
	 '#type'=>'select',
	 '#required'=>'true',
	 '#default_value'=>$category,
	 '#options' =>$cat_options,
	 '#attributes' => array(
	 'placeholder' => t(''),
	 'class' => array('select-xlarge', 'uniform'),
	 ),
	 '#prefix' => '<span class="mini-form-item-with-lable-top">',
	 '#suffix' => '</span>',
	 );
	
	
	 $grade_options = emp_grade_dd_ot();
	
	 $form['grade'] = array(
	 '#title' => t('Employee Grade'),
	 '#type'=>'select',
	 '#required'=>'true',
	 '#default_value'=>$grade,
	 '#options' =>$grade_options,
	 '#attributes' => array(
	 'placeholder' => t(''),
	 'class' => array('select-xlarge', 'uniform'),
	 ),
	 '#prefix' => '<span class="mini-form-item-with-lable-top">',
	 '#suffix' => '</span>',
	 );
	
	
	 $form['rates'] = array(
	 '#title'                => 'Rate Multiple of Basic Salary / Hour',
	 '#type'		 => 'textfield',
	 '#maxlength'		 => 3,
	 '#required'		 =>'true',
	 '#default_value'	 =>$rate_multiple,
	 '#description' 		 => 'Rate Multiple is used for OT Rate calculation <br> e.g. OT Amount = Monthly Basic/30/8 * Rate Multiple * Num of OT Hours',
	 '#attributes'       => array(
	 'class'=> array('input-mini'),
	 'onKeyPress' => array('return IsNumeric(event, this);',),
	 //'readonly'=>'readonly',
	 ),
	 '#prefix' => '<span class="large-form-item-with-lable-top">',
	 '#suffix' => '</span>',
	 );
	
	
	
	 $form['submit'] = array('#type'=>'submit',
	 '#value'=>t(' Submit '),
	 '#attributes' => array(
	 'class' => array('submit-blue-button-float-right'),
	 ),
	 '#submit' => array('overtime_setting_submit'),
	 '#suffix'=>'</div>',
	 );
	
	 $ot_setting_display  =  ot_setting_display();
	
	 $form['setting_report'] = array(
	 '#type'=>'hidden',
	 '#prefix' =>'<div id="#">'.$ot_setting_display.'</div>',
	 );
	
	
	
	 */
	
	$form['submit'] = array('#type'=>'submit',
	    '#value'=>t(' Submit '),
	    '#attributes' => array(
	        'class' => array('submit-blue-button-float-right'),
	    ),
	    '#suffix'=>'</div>',
	);
	
	
	$form['form_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div> ',
	);
	