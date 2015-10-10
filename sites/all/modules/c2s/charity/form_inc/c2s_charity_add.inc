<?php
	$city_options = array();
	$state_options = array();

	$state_options = getStates();

	
	$form['#attached']['js'] = array(
		drupal_get_path('module', 'agent') . '/js/validate.js',
	);
	$form['#attached']['css'] = array(
		drupal_get_path('module', 'broker') . '/css/global-c2s.css',
	);

// ==========  Form Starts  ================ //

	$form['form_start'] = array(
	   '#type' => 'item',
	   '#suffix' => '<div id="main-form-wrapper"> ',
	);
	$form['charity_organizations_name'] = array(
	    '#title'          => 'Charity Organizations Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Charity Organizations Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	
	
    
		
	$form['number_501_c_3'] = array(
	    '#title'          => '501 (c)(3) Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 10,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
		    'placeholder'=> t('Unique Number for Your Charity Organization'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
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
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);

//--------------  Ajax CallBack for Cities and ZipCodes  ---------------------

	if (isset($form_state['values']['state_id'])) {
		$selected_state_id = isset($form_state['values']['state_id']) ? $form_state['values']['state_id'] : key($state_options);
	}else{
		$selected_state_id = '';
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
	    '#prefix' 		=> '<span class="wrapper-w16">',
	    '#suffix' 		=> '</span>',
	);

	$city_options = getCities($selected_state_id);
	if (isset($form_state['values']['city'])) {
		$selected_city = isset($form_state['values']['city']) ? $form_state['values']['city'] : key($city_options);
	}else{
		$selected_city = '';
	}

	$form['city'] = array(
	    '#type'				=>	'select',
	    '#title' 			=> 	t('City'),
	    '#required'			=>	'true',
		'#default_value' 	=> 	'',
	    '#options' 			=>	$city_options,
	    '#attributes' 	=> array(
	        'placeholder' 	=>	t(''),
	        'class' 		=>	array('select-xlarge', 'uniform'),
	    ),
		'#ajax' 		=> array(
			'callback' 	=> 'find_zip_callback',
			'wrapper' 	=> 'zip-wrapper',
		),
	    '#prefix' 		=> '<div id="cities-wrapper"> <span class="wrapper-w16">',
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
	    '#prefix' => '<div id="zip-wrapper"><span class="wrapper-w16">',
	    '#suffix' => '</span></div>',
	);
	
// ========================================================================

	$form['contact_number'] = array(
	    '#title'          => 'Contact Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('123-456-7890'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return phoneNumber(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
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
	        'onKeyPress' => array('return isMailId(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	
	
	$form['website_url'] = array(
	    '#title'          => 'Website URL',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Website URL'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	// --------------------Personal Bank Account Details Start------------------- //

	$form['etf_bank_details_subsection_start'] = array(
	   '#type' => 'item',
	   '#prefix' => '<div id="form_sections" class="form_sections"> ',
	   '#suffix' => '<div class="form_section_title" data-item = "form_section_1"> ETF Bank Account Details
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="form_section_1_arrow" class="inner_section_arrow icon_rotate" > </div>
	    <div id = "form_section_1">'
	);
	
	$form['account_number'] = array(
	    '#title'          => 'Account Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 20,
	    '#required'		  => 'true',
	    '#default_value'  => '',
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
	    '#default_value'  => '',
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
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Financial Institution Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
    $form['financial_institution_phone'] = array(
	    '#title'          => 'Financial Institution Phone Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 12,
	    '#required'		  => 'true',
	    '#default_value'  => '',
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
	    '#type'		      => 'radios',
	    '#required'		  => 'true',
	    '#default_value'  => 'checking',
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
	    '#default_value'  => '',
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
	