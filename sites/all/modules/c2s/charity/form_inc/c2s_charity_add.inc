<?php
	$city_options = array();
	$state_options = array();
	$state_options = getStates();
	$arg = arg();
// ===============  When in Edit mode, 3rd Arg will be set to Charity Org ID =======================
if(isset($arg[3])){
	$charity_organization_id = arg(3);
	$query = "SELECT * FROM c2s_charity_org_master WHERE charity_organization_id = ".$charity_organization_id ;
	$result = db_query($query);
	foreach($result as $value){
		$charity_org_name 				= $value->charity_org_name;
		$number_501_c_3 	  			= $value->number_501_c_3;
		$charity_org_address         	= $value->charity_org_address;
		$charity_org_city		  		= $value->charity_org_city;
		$charity_org_state	      		= $value->charity_org_state;
		$charity_org_zip 		        = $value->charity_org_zip;
		$phone_number 		          	= $value->phone_number;
		$email_id 		          		= $value->email_id;
		$website_url 		          	= $value->website_url;
		$bank_account_number 		    = $value->bank_account_number;
		$bank_account_name 		        = $value->bank_account_name;
		$bank_name 		          		= $value->bank_name;
		$bank_phone 		          	= $value->bank_phone;
		$bank_account_type 		        = $value->bank_account_type;
		$bank_aba_routing_number 		= $value->bank_aba_routing_number;

		$value_of_submit_button = 'Update Charity!';
	}
}else {
// ======== Insert Mode - ADD New Values ==================
		$charity_org_name 				= '';
		$number_501_c_3 	  			= '';
		$charity_org_address         	= '';
		$charity_org_city		  		= '';
		$charity_org_state	      		= '';
		$charity_org_zip 		        = '';
		$phone_number 		          	= '';
		$email_id 		          		= '';
		$website_url 		          	= '';
		$bank_account_number 		    = '';
		$bank_account_name 		        = '';
		$bank_name 		          		= '';
		$bank_phone 		          	= '';
		$bank_account_type 		        = 'checking';
		$bank_aba_routing_number 		= '';

		$charity_organization_id = '';
		$value_of_submit_button = 'Submit';
}


// ======================================================================================================

// ==========  Form Starts  ================ //

	$form['form_start'] = array(
	   '#type' => 'item',
	   '#suffix' => '<div id="main-view-wrapper"> ',
	);
	
	$form['charity_organizations_id'] = array(
	    '#type'		      	=> 'hidden',
	    '#default_value' 	=> $charity_organization_id,
		'#suffix' 			=> '<div class="section_left">',
	);	
	
	$form['charity_organizations_name'] = array(
	    '#title'          => 'Charity Organizations Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => $charity_org_name,
	    '#attributes'     => array(
	        'placeholder'	=> t('Charity Organizations Name'),
	        'class'			=> array('input-mini'),
	        'onKeyPress'	=> array('return isAlphaNumeric(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);	
	
	$form['street_address'] = array(
	    '#title'          => 'Street Address',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#required'		  => 'true',
	    '#default_value'  => $charity_org_address,
	    '#attributes'     => array(
	        'placeholder'=> t('Street Address'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);

//--------------  Ajax CallBack for Cities and ZipCodes  ---------------------

	if (isset($form_state['values']['state_id'])) {
		$selected_state_id = isset($form_state['values']['state_id']) ? $form_state['values']['state_id'] : key($state_options);
	}else{
		$selected_state_id = $charity_org_state;
	}
	
	$form['state_id'] = array(
	    '#type'				=>	'select',
	    '#title' 			=> 	t('State'),
	    '#options'			=>	$state_options,
		'#default_value' 	=>	$selected_state_id,
	    '#required'			=>	'true',
	    '#attributes' 	=> array(
	        'class' 	=> array('select-xlarge', 'uniform'),
	    ),
		'#ajax' 		=> array(
			'callback' 	=> 'find_cities_callback',
			'wrapper' 	=> 'cities-wrapper',
		),
	    '#prefix' 		=> '<span class="wrapper-w33">',
	    '#suffix' 		=> '</span>',
	);

	$city_options = getCities($selected_state_id);
	if (isset($form_state['values']['city'])) {
		$selected_city = isset($form_state['values']['city']) ? $form_state['values']['city'] : key($city_options);
	}else{
		$selected_city = $charity_org_city;
	}

	$form['city'] = array(
	    '#type'				=>	'select',
	    '#title' 			=> 	t('City'),
	    '#required'			=>	'true',
		'#default_value' 	=> 	$selected_city,
	    '#options' 			=>	$city_options,
	    '#attributes' 	=> array(
	        'placeholder' 	=>	t(''),
	        'class' 		=>	array('select-xlarge', 'uniform'),
	    ),
		'#ajax' 		=> array(
			'callback' 	=> 'find_zip_callback',
			'wrapper' 	=> 'zip-wrapper',
		),
	    '#prefix' 		=> '<div id="cities-wrapper"> <span class="wrapper-w33">',
	    '#suffix' 		=> '</span></div>',
	);

	$zip = getZip($selected_city, $selected_state_id);
	$form['zip_code'] = array(
	    '#title'          => 'Zip Code',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#value'  => $zip,
	    '#attributes'     => array(
	        'placeholder'=> t('Zip Code'),
	        'class'=> array('input-mini'),
	        'readonly'=>'readonly',
	    ),
	    '#prefix' => '<div id="zip-wrapper"><span class="wrapper-w33">',
	    '#suffix' => '</span></div></div>',
	);
	
// ========================================================================
	$form['number_501_c_3'] = array(
	    '#title'          => '501 (c)(3) Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 10,
	    '#required'		  => 'true',
	    '#default_value'  => $number_501_c_3,
	    '#attributes'     => array(
		    'placeholder'=> t('Unique Number for Your Charity Organization'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	    ),
	    '#prefix' => '<div class="section_left"><span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);	
	


	$form['contact_number'] = array(
	    '#title'          => 'Contact Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => $phone_number,
	    '#attributes'     => array(
	        'placeholder'=> t('123-456-7890'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return phoneNumber(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);

	$form['personal_email_id'] = array(
	    '#title'          => 'Personal Email ID',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#required'		  => 'true',
	    '#default_value'  => $email_id,
	    '#attributes'     => array(
	        'placeholder'=> t('Personal Email ID'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isMailId(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	
	$form['website_url'] = array(
	    '#title'          => 'Website URL',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => $website_url,
	    '#attributes'     => array(
	        'placeholder'=> t('Website URL'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span></div>',
	);
	
	// --------------------Personal Bank Account Details Start------------------- //

	$form['etf_bank_details_subsection_start'] = array(
	   '#type' => 'item',
	   '#prefix' => '<div class="section_full">',
	   '#suffix' => '<div class="form_subsection_title" data-item="inner_section_1" >ETF Bank Account Details</div>',
	);
	
	$form['account_number'] = array(
	    '#title'          => 'Account Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 20,
	    '#required'		  => 'true',
	    '#default_value'  => $bank_account_number,
	    '#attributes'     => array(
	        'placeholder'=> t('Account Number (Without Spaces)'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	$form['name_on_account'] = array(
	    '#title'          => 'Name On Account',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => $bank_account_name,
	    '#attributes'     => array(
	        'placeholder'=> t('Name On Account'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
    $form['financial_institution_name'] = array(
	    '#title'          => 'Financial Institution Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => $bank_name,
	    '#attributes'     => array(
	        'placeholder'=> t('Financial Institution Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
    $form['financial_institution_phone'] = array(
	    '#title'          => 'Financial Institution Phone Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 12,
	    '#required'		  => 'true',
	    '#default_value'  => $bank_phone,
	    '#attributes'     => array(
	        'placeholder'=> t('Financial Institution Phone Number'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return phoneNumber(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
    
    

	 $form['account_type'] = array(
	    '#title'          => 'Account Type',
	    '#type'		      => 'select',
	    '#required'		  => 'true',
	    '#default_value'  => $bank_account_type,
	    '#attributes'     => array(
	        'class'=> array('input-mini'),
	        ),
	     '#options'        => array(	
			'checking'=> t('Checking'),'saving'=> t('Saving')
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	 

	$form['aba_routing_number'] = array(
	    '#title'          => 'ABA Routing Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => $bank_aba_routing_number,
	    '#attributes'     => array(
	        'placeholder'=> t('ABA Routing Number'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	
// --------------------Personal Bank Account Details End------------------- //

	$form['section_one_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div>',
	);


	
	$form['submit'] = array('#type'=>'submit',
	    '#value'=> $value_of_submit_button,
	    '#attributes' => array(
	        'class' => array('submit-blue-button-float-right'),
	    ),
	    '#suffix'=>'</div>',
	);
	
	
	$form['form_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div></div>  ',
	);
	