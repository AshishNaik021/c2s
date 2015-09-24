<?php

$form['#attached']['js'] = array(
    drupal_get_path('module', 'agent') . '/js/validate.js',
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

	$form['form_start'] = array(
	   '#type' => 'item',
	   '#suffix' => '<div id="main-form-wrapper"> ',
	);
        
	$form['brokerage_name'] = array(
	    '#title'           => 'Name of Brokerage',
	    '#type'		       => 'textfield',
	    '#maxlength'	   => 100,
	    '#required'		   =>'true',
	    '#default_value'   =>'',
	    '#attributes'       => array(
	        'class'=> array('input-mini'),
	        'placeholder'=> 'City2Shore',
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        'onChange'   => array('addPrefix(this, "City2Shore ")'),
	        'onClick'    => array('removePrefix(this)')
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
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
	        'onKeyPress' => array('return false;'),
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	

		
	$form['number_of_owners'] = array(
	    '#title'          => 'Total Broker Owners',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 5,
	    '#required'		  => 'true',
	    '#default_value'  => '1',
	    '#attributes'     => array(
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);	
	
	
	$form['broker_owner_1'] = array(
	   '#type' => 'item',
	   '#prefix' => '<div id="form_sections" class="form_sections"> ',
	   '#suffix' => '<div class="form_section_title" data-item = "form_section_1"> Broker One 
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="form_section_1_arrow" class="inner_section_arrow icon_rotate" > </div>
	    <div id = "form_section_1">'
	);
    	$form['personal_info_subsection_start'] = array(
    	   '#type' => 'item',
    	   '#prefix' => '<div class="form_subsection_title" data-item="inner_section_1"> Personal Information 
    	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="inner_section_1_arrow" class="inner_section_arrow" >
    	    </div>',
    	   '#suffix' => '<div id="inner_section" class="inner_section_1 inner_subsection" style="display: none;">',
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
	        'onKeyPress' => array('return false;'),
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
	        'onKeyPress' => array('return MailId(event, this);',),
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
	    '#options' =>array(1=>'City'),
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
	    '#options' =>array(1=>'State'),
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
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="inner_section_2_arrow" class="inner_section_arrow" >
	    </div>',
	   '#suffix' => '<div id="inner_section" class="inner_section_2 inner_subsection" style="display: none;">',
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
	    '#options' =>array(1=>'City'),
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
	    '#options' =>array(1=>'State'),
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
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	
	$form['broker_nrds_link'] = array(
	     '#title'          => 'Link to look up NRDS#',
	    '#type' => 'item',
	    '#prefix' => '<span class="wrapper-w25"><a class="url" href="url">http://reg.realtor.org/</a>' ,
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
	    '#suffix' => '</span> <p class="c2s"style="float:left;width: 105px;padding-left: 0px;margin-left: 0px;">@city2shore.com</p>',
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
	
	$form['choice_of_charity_org'] = array(
	    '#title'          => 'Charity Organization Of Choice',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 250,
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
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="inner_section_3_arrow" class="inner_section_arrow" >
	    </div>',
	   '#suffix' => '<div id="inner_section" class="inner_section_3 " style="display: none;">',
	);
	
	// --------------------Commission Bank Account Details Start------------------- //
	
	$form['bank_account1_start'] = array(
	    '#type' => 'item',
	    '#prefix' => '<div class="form_subsection_title2" data-item="inner_section2_1">
	    Bank Account Number For Payout Commissions & Reap To Agent
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="inner_section2_1_arrow" class="inner_section_arrow inner_subsection_arrow" >
	    </div>',
		'#suffix' =>  '<div id="inner_section" class="inner_section2_1 inner_subsection" style="display: none;">',
	);
	
	$form['comm_account_number'] = array(
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
	$form['name_on_comm_account'] = array(
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
    $form['comm_financial_institution_phone'] = array(
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
    $form['comm_financial_institution_name'] = array(
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
    
	 $form['comm_account_type'] = array(
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
	
	$form['comm_aba_routing_number'] = array(
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
	
	// --------------------Commission Bank Account Details End------------------- //

	// --------------------Personal Bank Account Details Start------------------- //
	
	$form['bank_account2_start'] = array(
	    '#type' 	=> 'item',
	    '#prefix' 	=> '<div class="form_subsection_title2" data-item="inner_section2_2">
	    Bank Account Number For Personal Commissions & Reap
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="inner_section2_2_arrow" class="inner_section_arrow inner_subsection_arrow" >
	    </div>',
		'#suffix' 	=> '<div id="inner_section" class="inner_section2_2 inner_subsection" style="display: none;">',
	);
	
	$form['personal_account_number'] = array(
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
	$form['name_on_personal_account'] = array(
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
    $form['personal_financial_institution_name'] = array(
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
    $form['personal_financial_institution_phone'] = array(
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
    
    
    
	 $form['personal_account_type'] = array(
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
	$form['personal_aba_routing_number'] = array(
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
	
// --------------------Personal Bank Account Details End------------------- //
	
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
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="inner_section_4_arrow" class="inner_section_arrow" >
	    </div>',
	    '#suffix' => '<div id="inner_section" class="inner_section_4 inner_subsection" style="display: none;">',
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
            'onKeyPress' => array('return MailId(event, this)',),
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
	    '#options' =>array(1=>'City'),
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
	    '#options' =>array(1=>'State'),
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
        '#suffix' => '</div><hr>',
    );


    // -------------------------------- BROKER DETAIL SECTION ------------------------------------------- //
    
    $form['broker_detail_section_start'] = array(
        '#type' => 'item',
        '#prefix' => '<div class="form_subsection_title" data-item="inner_section_5"> Broker Detail Section
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="inner_section_5_arrow" class="inner_section_arrow" >
	    </div>',
        	    '#suffix' => '<div id="inner_section" class="inner_section_5 " style="display: none;">',
    );
    
//    '#prefix' => '<h3 class="main_form_title"> Broker Details Section </h3><div id="inner_section"><h3> Cap Amounts </h3>',

	$form['cap_amount_section_start'] = array(
	    '#type' => 'item',
	    '#prefix' => '<div class="form_subsection_title2" data-item="inner_section2_3">
	       Cap Amounts Section
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="inner_section2_3_arrow" class="inner_section_arrow inner_subsection_arrow" >
	    </div>',
		'#suffix' =>  '<div id="inner_section" class="inner_section2_3 inner_subsection" style="display: none;">',
	);
    
   
    $form['franchise_fee_cap'] = array(
        '#title'          => 'Franchise Fee Cap',
        '#type'		      => 'textfield',
        '#maxlength'	  => 100,
        '#required'		  => 'true',
        '#default_value'  => 'asdas',
        '#attributes'     => array(
            'placeholder'=> t('$3000'),
            'class'=> array('input-mini'),
            //	        'onKeyPress' => array('return numbersonly(this, event)',),
            //'readonly'=>'readonly',
        ),
        '#prefix' => '<span class="wrapper-w33">',
        '#suffix' => '</span>',
    );
    $form['transaction_management_fee'] = array(
        '#title'          => 'Transaction Management Fee',
        '#type'		      => 'textfield',
        '#maxlength'	  => 100,
        '#required'		  => 'true',
        '#default_value'  => 'asdas',
        '#attributes'     => array(
            'placeholder'=> t('$2.96'),
            'class'=> array('input-mini'),
            //	        'onKeyPress' => array('return numbersonly(this, event)',),
            //'readonly'=>'readonly',
        ),
        '#prefix' => '<span class="wrapper-w33">',
        '#suffix' => '</span>',
    );
    
    $form['reap_amount_cap'] = array(
        '#title'          => 'Reap Amount Cap',
        '#type'		      => 'textfield',
        '#maxlength'	  => 100,
        '#required'		  => 'true',
        '#default_value'  => 'asdas',
        '#attributes'     => array(
            'placeholder'=> t('$18,000'),
            'class'=> array('input-mini'),
            //	        'onKeyPress' => array('return numbersonly(this, event)',),
            //'readonly'=>'readonly',
        ),
        '#prefix' => '<span class="wrapper-w33">',
        '#suffix' => '</span>',
    );
    
    $form['cap_amount_section_end'] = array(
        '#type' => 'item',
        '#suffix' =>  '</div>',
    );
    
    $form['paper_work_section_start'] = array(
        '#type' => 'item',
        '#prefix' => '<div class="form_subsection_title2" data-item="inner_section2_4">
	      Paper Work Required
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="inner_section2_4_arrow" class="inner_section_arrow inner_subsection_arrow" >
	    </div>',
        '#suffix' =>  '<div id="inner_section" class="inner_section2_4 inner_subsection" style="display: none;">',
    );
    
    
    $option_types = array('1' => t('Option 1'), '2' => t('Option 2'), '3'=> t('Option 3'), '4'=> t('Option 4'), '5'=> t('Option 5'), '6'=> t('Option 6'));
    
    $form['paperwork_required'] = array(
        '#type' => 'checkboxes',
        '#title' => '',
        //'#default_value' => isset($node->option_types) ? $node->option_types : 1,
        '#options' => $option_types,
        '#prefix' => '<span class="large-form-item-with-lable-top">',
        '#suffix' => '</span>',
    );
    
    $form['add_new_document_name'] = array(
        '#title'          => 'Add New Document Name',
        '#type'		      => 'textfield',
        '#maxlength'	  => 100,
        '#default_value'  => 'asdas',
        '#attributes'     => array(
            'placeholder'=> t('Add New Document Name'),
            'class'=> array('input-mini'),
            //	        'onKeyPress' => array('return numbersonly(this, event)',),
            //'readonly'=>'readonly',
        ),
        '#prefix' => '<span class="wrapper-w100">',
        '#suffix' => '</span>',
    );
    
    $form['add_document_button'] = array(
        '#type' => 'button',
        '#value' => t('Add Document'),
    );
    
    $form['paper_work_section_end'] = array(
        '#type' => 'item',
        '#suffix' => '</div> ',
    );
    
    $form['broker_detail_section_end'] = array(
        '#type' => 'item',
        '#suffix' => '</div> ',
    );
	
	$form['section_one_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div></div> ',
	);


	
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
	