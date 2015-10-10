<?php
/*
* -------------------------------------------------------------------------
*	For Edit, Take the 3rd Argument and fetch all values from database. 
* -------------------------------------------------------------------------
*/
$arg = arg();
$city_options = array();
$state_options = array();
$state_options = getStates();

if (isset($arg[3])){
	$charity_organization_id = arg(3);
	$result = db_query("SELECT * FROM c2s_charity_org_master WHERE charity_organization_id = ".$charity_organization_id);
	foreach($result as $value){
		$charity_org_id 				= $value->charity_organization_id;	
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
	}
	$input_class  = 'input_disabled';
	$select_class = 'input_disabled';	
	$required_disabled = '#disabled';
	$radio = 'textfield';
}else{
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
		$bank_account_type 		        = 'Checking';
		$bank_aba_routing_number 		= '';

		$input_class = 'input-mini';
		$select_class = "'select-xlarge', 'uniform'";
		$required_disabled = '#required';
		$radio = 'radios';

}
	
$form['#attached']['js'] = array(
    drupal_get_path('module', 'agent') . '/js/validate.js',
);
$form['#attached']['css'] = array(
    drupal_get_path('module', 'broker') . '/css/global-c2s.css',
);

// ==========  Form Starts  ================ //
	$form['Charity Edit Buttons'] = array(
	    '#type' => 'item',
	    '#prefix' => '<input type="button" value="Edit Charity Organization" style="float: right; margin:5px;" onclick="convert_edit('.$form_state['form_id'].')">
	     <input type="button" value="Deactivate Charity Organization" style="float: right; margin:5px;" onclick="window.location=\''.base_path().'c2s/broker/deactivate/'.$charity_org_id.'/'.$charity_org_id.'\'">',
	    '#suffix' => '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
	);

	$form['form_start'] = array(
	   '#type' => 'item',
	   '#suffix' => '<div id="main-form-wrapper"> ',
	);
	$form['charity_organizations_name'] = array(
	    '#title'          => 'Charity Organizations Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    $required_disabled => 'true',
	    '#default_value'  => $charity_org_name,
	    '#attributes'     => array(
	        'placeholder'=> t('Charity Organizations Name'),
	        'class'=> array($input_class),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	
	
    
		
	$form['number_501_c_3'] = array(
	    '#title'          => '501 (c)(3) Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 3,
	    $required_disabled		  => 'true',
	    '#default_value'  => $number_501_c_3,
	    '#attributes'     => array(
		     'placeholder'=> t('Type Min 3 Chars'),
	        'class'=> array($input_class),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	
	$form['street_address'] = array(
	    '#title'          => 'Street Address',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    $required_disabled		  => 'true',
	    '#default_value'  => $charity_org_address,
	    '#attributes'     => array(
	        'placeholder'=> t('Street Address'),
	        'class'=> array($input_class),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
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
	    $required_disabled=>'true',
	    '#attributes' 	=> array(
	        'class'=> array($select_class),
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
	    $required_disabled=>'true',
		'#default_value' 	=> 	'',
	    '#options' 			=>	$city_options,
	    '#attributes' 	=> array(
	        'placeholder' 	=>	t(''),
	        'class'=> array($select_class),
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
	    $required_disabled=>'true',
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

/*
	$form['city'] = array(
	    '#title' => t('City'),
	    '#type'=>'select',
	    $required_disabled=>'true',
	    '#default_value'=>$charity_org_city,
	    '#options' => getCities($charity_org_state),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class'=> array($select_class),
//	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);

	$form['state'] = array(
	    '#title' => t('State'),
	    '#type'=>'select',
	    $required_disabled=>'true',
	    '#default_value'=>$charity_org_state,
	    '#options' => getStates(),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class'=> array($input_class),
//	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);
	$form['zip_code'] = array(
	    '#title'          => 'Zip Code',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    $required_disabled		  => 'true',
	    '#value'  => $charity_org_zip,
	    '#attributes'     => array(
	        'placeholder'=> t('Zip Code'),
	        'class'=> array($input_class),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);
*/
	$form['contact_number'] = array(
	    '#title'          => 'Contact Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    $required_disabled		  => 'true',
	    '#default_value'  => $phone_number,
	    '#attributes'     => array(
	        'placeholder'=> t('Contact Number'),
	        'class'=> array($input_class),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);

	$form['personal_email_id'] = array(
	    '#title'          => 'Personal Email ID',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    $required_disabled		  => 'true',
	    '#default_value'  => $email_id,
	    '#attributes'     => array(
	        'placeholder'=> t('Personal Email ID'),
	        'class'=> array($input_class),
	        'onKeyPress' => array('return MailId(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	
	
	$form['website_url'] = array(
	    '#title'          => 'Website URL',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    $required_disabled		  => 'true',
	    '#default_value'  => $website_url,
	    '#attributes'     => array(
	        'placeholder'=> t('Website URL'),
	        'class'=> array($input_class),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['etf_bank_details_subsection_start'] = array(
	   '#type' => 'item',
	   '#prefix' => '<div id="form_sections" class="form_sections"> ',
	   '#suffix' => '<div class="form_section_title" data-item = "form_section_1"> ETF Bank Account Details
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="form_section_1_arrow" class="inner_section_arrow icon_rotate" > </div>
	    <div id = "form_section_1">'
	);

	
	
	// --------------------Personal Bank Account Details Start------------------- //
	
	
	$form['account_number'] = array(
	    '#title'          => 'Account Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    $required_disabled		  => 'true',
	    '#default_value'  => $bank_account_number,
	    '#attributes'     => array(
	        'placeholder'=> t('Account Number'),
	        'class'=> array($input_class),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	$form['name_on_account'] = array(
	    '#title'          => 'Name On Account',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    $required_disabled		  => 'true',
	    '#default_value'  => $bank_account_name,
	    '#attributes'     => array(
	        'placeholder'=> t('Name On Account'),
	        'class'=> array($input_class),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
    $form['financial_institution_name'] = array(
	    '#title'          => 'Financial Institution Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    $required_disabled		  => 'true',
	    '#default_value'  => $bank_name,
	    '#attributes'     => array(
	        'placeholder'=> t('Financial Institution Name'),
	        'class'=> array($input_class),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
    $form['financial_institution_phone'] = array(
	    '#title'          => 'Financial Institution Phone Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    $required_disabled		  => 'true',
	    '#default_value'  => $bank_phone,
	    '#attributes'     => array(
	        'placeholder'=> t('Financial Institution Phone Number'),
	        'class'=> array($input_class),
//	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
    
    
    
	 $form['account_type'] = array(
	    '#title'          => 'Account Type',
	    '#type'		      => $radio,
	    '#maxlength'	  => 50,
	    $required_disabled => 'true',
	    '#default_value'  => $bank_account_type,
	    '#attributes'     => array(
	        'class'=> array($input_class),
	        ),
	     '#options'        => array(	
			'Checking'=> t('Checking'),
			'Saving'=> t('Saving')
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	 
	$form['aba_routing_number'] = array(
	    '#title'          => 'ABA Routing Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    $required_disabled		  => 'true',
	    '#default_value'  => $bank_aba_routing_number,
	    '#attributes'     => array(
	        'placeholder'=> t('ABA Routing Number'),
	        'class'=> array($input_class),
//	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
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
