<?php
$city_options = array();
$state_options = array();
$state_options = getStates();

$number_to_words = array(1=>"One", 2=> "Two", 3=> "Three", 4=>"Four", 5=>"Five", 6=>"Six");
$total_brokers = 1;


$form['form_start'] = array(
    '#type' => 'item',
    '#suffix' => '<div id="main-view-wrapper">',
);

if (isset($form_state['values']['broker_owners'])) {
    $total_brokers = isset($form_state['values']['broker_owners']) ? $form_state['values']['broker_owners'] : '1';
}
$form['broker_owners'] = array(
	'#title'	=>	t('Total Broker Owners'),
    '#type' => 'select',
    '#options' => array(1=>'1', 2=>'2',3=>'3',4=>'4',5=>'5'),
    '#default_value' => 1,
    '#attributes' => array(
        'class' => array('form_text'),
    ),
    '#ajax' => array(
        'wrapper' => 'names-fieldset-wrapper',
        'callback' => 'spower_add_more_callback',
    ),
    '#prefix' => '<div class="wrapper-w100"><span class="wrapper-w25"><span class="value_left">',
    '#suffix' => '</span></span></div>',
);


$form['#tree'] = TRUE;
$form['names_fieldset'] = array(
    '#type' => 'fieldset',
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="names-fieldset-wrapper">',
    '#suffix' => '</div>',
);

$form['names_fieldset']['brokerage_tab'] = array(
    '#type' => 'item',
    '#suffix' => '<div class="form_section_tab selected" id="tab_0" data-item="form_tab_0" onclick="click_tabs_add(\'tab_0\')" > Brokerage Details </div>',
);

for($i=1; $i<=$total_brokers; $i++){
    $form['names_fieldset']['broker_tab_'.$i] = array(
        '#type' => 'item',
        '#suffix' => '<div class="form_section_tab" id="tab_'.$i.'" data-item="form_tab_'.$i.'" onclick="click_tabs_add(\'tab_'.$i.'\')" > Broker '.$number_to_words[$i].' </div>',
    );

}

$form['names_fieldset']['brokerage_details_start'] = array(
    '#type' => 'item',
    '#suffix' => '<div id="form_tab_0" class="form_sections" style="display:block">',
);

$form['names_fieldset']['brokerage_details_separator'] = array(
    '#type' => 'item',
    '#suffix' => '<div class="separator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
);

$form['names_fieldset']['brokerage_section_left_start'] = array(
    '#type' => 'item',
    '#suffix' => '<div class="section_left"> <div class="form_subsection_title" data-item="inner_section_1" >Company Information</div>',
);



$form['names_fieldset']['brokerage_name'] = array(
	'#title'		   =>	t('Name of Brokerage Company'),
    '#type'		       => 'textfield',
    '#maxlength'	   => 60,
    '#required'        =>'true',
    '#attributes'       => array(
        'class'=> array('form_text'),
        'placeholder'=> 'City2Shore',
        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
        'onChange'   => array('addPrefix(this, "City2Shore ")'),
        'onClick'    => array('removePrefix(this)')
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w60">',
    '#suffix' => '</span> ',
);


$form['names_fieldset']['brokerage_start_date'] = array(
    '#title'		   	=>	t('Start Date '),
    '#type'		      	=> 'date_popup',
    '#date_label_position' => 'Within',
    '#required'       	=> 'true',
    '#date_format'	  	=> 'm/d/Y',
    '#date_year_range'  => '-3:+3',
    '#attributes'       => array(
        'placeholder'	=> t('mm/dd/YYYY'),
        'class'			=> array('date-input-medium form_text'),
        'onKeyPress' 	=> array('return false;'),
    ),
    '#prefix' => '<span class="wrapper-w33">',
    '#suffix' => '</span></span> <div class="separator" style="height: 10px;width: 100%;float: left; clear: both;"></div>',
);


$form['names_fieldset']['franchise_fee_cap'] = array(
    '#title'		   =>	t('Franchise Cap'),
	'#type'		      => 'textfield',
    '#maxlength'	  => 10,
    '#required'		  => 'true',
    '#attributes'     => array(
        'placeholder'=> t('$3000'),
        'class'=> array('form_text'),
		'onKeyPress' => array('return IsNumeric( event, this)',),
        'onChange'   => array('addPrefix(this, "$")'),
    ),
    '#prefix' => '<span class="wrapper-w33">',
    '#suffix' => '</span></span>',
);


$form['names_fieldset']['reap_amount_cap'] = array(
    '#title'		  => t('REAP Cap'),
	'#type'		      => 'textfield',
    '#maxlength'	  => 10,
    '#required'		  => 'true',
    '#attributes'     => array(
        'placeholder'=> t('$18,000'),
        'class'=> array('form_text'),
        'onKeyPress' => array('return IsNumeric(event, this)',),
        'onChange'   => array('addPrefix(this, "$")'),
    ),
    '#prefix' => '<span class="wrapper-w33">',
    '#suffix' => '</span></span>',
);

$form['names_fieldset']['transaction_management_fee'] = array(
    '#title'		   =>	t('Transaction Fee'),
    '#type'		      => 'textfield',
    '#maxlength'	  => 10,
    '#required'		  => 'true',
    '#attributes'     => array(
        'placeholder'=> t('$295'),
        'class'=> array('form_text'),
		'onKeyPress' => array('return IsNumeric( event, this)',),
        'onChange'   => array('addPrefix(this, "$")'),
    ),
    '#prefix' => '<span class="wrapper-w33">',
    '#suffix' => '</span></span>',
);


$form['names_fieldset']['brokerage_section_left_end'] = array(
    '#type' => 'item',
    '#prefix' => '</div>',
);

$paperwork_options = getPaperworkRequired();
$form['names_fieldset']['brokerage_paperwork'] = array(
	'#title' => t('Required Paperwork'),
    '#type' => 'checkboxes',
    '#required' => 'true',
	'#options' => $paperwork_options,
    '#prefix' => '<div class="section_left"> <div class="form_subsection_title" data-item="inner_section_1" >Statutory Requirements</div>',
    '#suffix' => '</div>',
);



$form['names_fieldset']['brokerage_details_end'] = array(
    '#type' => 'item',
    '#suffix' => '</div>',
);

/* Broker Loop */

for($i=1; $i<=$total_brokers; $i++){
	$form['names_fieldset']['broker_'.$i.'_details_start'] = array(
		'#type' => 'item',
		'#suffix' => '<div id="form_tab_'.$i.'" class="form_sections" style="display:none">',
	);


	$form['names_fieldset']['broker_'.$i.'_details_separator'] = array(
		'#type' => 'item',
		'#suffix' => '<div class="separator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
	);

	$form['names_fieldset']['broker_'.$i.'_personal_info_start'] = array(
		'#type' => 'item',
		'#title' => '',
		'#prefix' => '',
		'#suffix' => '<div class="section_right"> <div class="form_subsection_title" data-item="inner_section_1" >Personal Information</div>',
	);

	$form['names_fieldset']['broker_'.$i.'_first_name'] = array(
		'#title'		   =>	t('First Name'),
		'#type'		      => 'textfield',
		'#maxlength'	  => 25,
		'#required'		  => 'true',
		'#attributes'     => array(
			'placeholder'=> t('First Name'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return onlyAlphabets(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['names_fieldset']['broker_'.$i.'_middle_name'] = array(
		'#title'		   =>	t('Middle Name'),
		'#type'		      => 'textfield',
		'#maxlength'	  => 25,
		'#required'		  => 'true',
		'#attributes'     => array(
			'placeholder'=> t('Middle Name'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return onlyAlphabets(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['names_fieldset']['broker_'.$i.'_last_name'] = array(
		'#title'		   =>	t('Last Name'),
		'#type'		      => 'textfield',
		'#maxlength'	  => 25,
		'#required'		  => 'true',
		'#attributes'     => array(
			'placeholder'=> t('Last Name'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return onlyAlphabets(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);


	$form['names_fieldset']['date_of_birth_'.$i] = array(
		'#title'		   =>	t('Date of Birth'),
		'#type'		      => 'date_popup',
		'#required'		  => 'true',
		'#date_format'	  => 'm/d/Y',
		'#date_year_range'  => '-100:-18',
		'#attributes'       => array(
			'placeholder'=> t('mm/dd/YYYY'),
			'class'=> array('date-input-medium form_text'),
			'onKeyPress' => array('return false;'),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);


	$form['names_fieldset']['personl_email_id_'.$i] = array(
		'#title'		   =>	t('Email Id'),
		'#type'		      => 'textfield',
		'#maxlength'	  => 50,
		'#required'		  => 'true',
		'#attributes'     => array(
			'placeholder'=> t('Personal Email ID'),
			'class'=> array('form_text'),
			'onKeyPress' 	=> array('return MailId(event, this);',),
			'onblur' 		=> array('validateEmail(this.value, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['names_fieldset']['contact_number_'.$i] = array(
		'#title'		   =>	t('Phone Number'),
		'#type'		      => 'textfield',
		'#maxlength'	  => 12,
		'#required'		  => 'true',
		'#attributes'     => array(
			'placeholder'=> t('123-456-7890'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return IsNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['names_fieldset']['street_address_'.$i] = array(
		'#title'		   =>	t('Street Address'),
		'#type'		      => 'textfield',
		'#maxlength'	  => 100,
		'#required'		  => 'true',
		'#attributes'     => array(
			'placeholder'=> t('Street Address'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return isAlphaNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w100">',
		'#suffix' => '</span></span>',
	);


	$form['names_fieldset']['broker_number_'.$i] = array(
			'#type'		=>	'hidden',
			'#value'	=>	$i,
	);

	
    if (isset($form_state['values']['state_id_'.$i])) {
		$selected_state_id  = isset($form_state['values']['state_id_'.$i]) ? $form_state['values']['state_id_'.$i] : key($state_options);
	}else{
		$selected_state_id = '';
	}
	
	$form['names_fieldset']['state_id_'.$i] = array(
			'#title'		   =>	t('State'),
			'#type'=>'select',
			'#required'=>'true',
			'#options'	=>	$state_options,
			'#default_value' 	=>	$selected_state_id ,
	    '#attributes' 	=> array(
	        'class' 	=> array('select-xlarge', 'uniform'),
	    ),
		'#ajax' 		=> array(
			'callback' 	=> 'find_cities_callback_'.$i,
			'wrapper' 	=> 'cities-wrapper_'.$i,
		),
			
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);
		$city_options = getCitiesBroker();
		if (isset($form_state['values']['city_'.$i])) {
		$selected_city = isset($form_state['values']['city_'.$i]) ? $form_state['values']['city_'.$i] : key($city_options);
	}else{
		$selected_city = '';
	}
	$form['names_fieldset']['city_'.$i] = array(
		'#title'		   =>	t('City'),
		'#type'=>'select',
		'#required'=>'true',
		'#default_value' 	=> 	'',
	    '#options' 		=>	$city_options,
	    '#attributes' 	=> array(
	    'placeholder' 	=>	t(''),
		   'class' 		=>	array('select-xlarge', 'uniform'),
	    ),
		'#ajax' 		=> array(
			'callback' 	=> 'find_zip_callback11',
			'wrapper' 	=> 'zip-wrapper',
		),
    '#prefix' => '<div id="cities-wrapper_'.$i.'"> <span class="wrapper-w33">',
    '#suffix' => '</span></span></div>',
    );

		$zip = getZip($selected_city, $selected_state_id);

		$form['names_fieldset']['zip_code_'.$i] = array(
			'#title'		   =>	t('Zip Code'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 10,
			'#required'		  => 'true',
			'#value'  => $zip,
			'#attributes'     => array(
				'placeholder'=> t('Zip Code'),
				 'class'=> array('input-mini'),
				//	'readonly'=>'readonly',
				//	'onKeyPress' => array('return IsNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
			 
		);
		$form['names_fieldset']['create_email_'.$i] = array(
			'#title'		   =>	t('Create My C2S Email As'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 50,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('example@c2semail.com'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return isMailId(event, this);',),
				'onblur' 		=> array('validateEmail(this.value, this);',),
			),
			'#prefix' => '<span class="wrapper-w100">',
			'#suffix' => '</span></span>',
		);
		$form['names_fieldset']['broker_'.$i.'_personal_info_end'] = array(
			'#type' => 'item',
			'#prefix' => '</div>',
		);


		$form['names_fieldset']['broker_'.$i.'_professional_info_start'] = array(
			'#type' => 'item',
			'#prefix' => '<div class="section_left"> <div class="form_subsection_title" data-item="inner_section_1"> Professional Information</div>',
		);

		$form['names_fieldset']['broker_state_id_number_'.$i] = array(
			'#title'		   =>	t('State ID#'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 10,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Broker State Id #'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return IsNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['broker_ein_'.$i] = array(
			'#title'		   =>	t('Broker EIN#'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 10,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Broker EIN'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return IsNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['broker_nrds_'.$i] = array(
             '#title'		   =>	t('NRDS#'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 10,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Broker NRDS#'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return IsNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['mls_username_'.$i] = array(
            '#title'		   =>	t('MLS User Id'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 25,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('MLS User Id'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return isAlphaNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['mls_password_'.$i] = array(
            '#title'		   =>	t('MLS Password'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 25,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('MLS Password'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return isAlphaNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);



		$form['names_fieldset']['busines_street_address_'.$i] = array(
			'#title'		   =>	t('Business Address'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 100,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Street Address'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return isAlphaNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w100">',
			'#suffix' => '</span></span>',
		);
		 if (isset($form_state['values']['business_state_id_'.$i])) {
		$selected_state_id  = isset($form_state['values']['business_state_id_'.$i]) ? $form_state['values']['business_state_id_'.$i] : key($state_options);
	   }else{
		$selected_state_id = '';
	    }
        $form['names_fieldset']['business_state_id_'.$i] = array(
			'#title'		   =>	t('State'),
			'#type'=>'select',
			'#required'=>'true',
             '#options'	=>	$state_options,
			'#default_value' 	=>	$selected_state_id ,
	    '#attributes' 	=> array(
	        'class' 	=> array('select-xlarge', 'uniform'),
	    ),
		'#ajax' 		=> array(
			'callback' 	=> 'find_cities_callback_22',
			'wrapper' 	=> 'cities-wrapper_'.$i,
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);
		$city_options = getCitiesBroker();
		if (isset($form_state['values']['business_city_id_'.$i])) {
			$selected_city = isset($form_state['values']['business_city_id_'.$i]) ? $form_state['values']['business_city_id_'.$i] : key($city_options);
		}else{
			$selected_city = '';
		}
		$form['names_fieldset']['business_city_id_'.$i] = array(
			'#title'		   =>	t('City'),
			'#type'=>'select',
			'#required'=>'true',
			'#default_value' 	=> 	'',
			'#options' 		=>	$city_options,
			'#attributes' 	=> array(
			'placeholder' 	=>	t(''),
			'class' 		=>	array('select-xlarge', 'uniform'),
	    ),
		'#ajax' 		=> array(
			'callback' 	=> 'find_zip_callback22',
			'wrapper' 	=> 'zip-wrapper',
		),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		
        $zip = getZip($selected_city, $selected_state_id);
		$form['names_fieldset']['business_zip_code_'.$i] = array(
			'#title'		   =>	t('Zip Code'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 10,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Zip Code'),
				'class'=> array('form_text'),
				//	        'onKeyPress' => array('return IsNumeric(event, this);',),
				//'readonly'=>'readonly',
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['office_phone_'.$i] = array(
			 '#title'		   =>	t('Office Phone'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 12,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('123-456-7890'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return IsNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['extension_'.$i] = array(
			'#title'		  => t('Extension'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 5,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'	=> t('Extension'),
				'class'			=> array('form_text'),
				'onKeyPress' 	=> array('return IsNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['broker_'.$i.'_professional_info_end'] = array(
			'#type' 	=> 'item',
			'#prefix' 	=> '</div><div class="separator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
		);
		
		$form['names_fieldset']['broker_'.$i.'charity_org'] = array(
		'#type' => 'item',
		'#prefix' => '<div class="section_center"> <div class="form_subsection_title" data-item="inner_section_1"> Choose The Charity Organization of Your Choice</div>',
	); 

		$form['names_fieldset']['choice_of_charity_org_'.$i] = array(
			'#title'		  =>	t('Charity Organization Chosen'),
			'#type'		      => 'textfield',
            '#autocomplete_path' => 'charity/autocomplete',
			'#maxlength'	  => 3,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'	=> t('Type Min 3 Chars'),
				'class'			=> array('form_text'),
				'onKeyPress' 	=> array('return isNumeric(event, this);',),
				//'readonly'=>'readonly',
			),

			'#prefix' => '<span class="wrapper-w100">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['broker_'.$i.'_charity_org_end'] = array(
			'#type' 	=> 'item',
			'#prefix' 	=> '</div><div class="separator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
		);


		$form['names_fieldset']['broker_'.$i.'_bank_info_start'] = array(
			'#type' 	=> 'item',
			'#prefix' 	=> '<div class="section_full"> <div class="form_subsection_title" data-item="inner_section_1"> Bank Details</div>',
		);

		//-------------- //

		$form['names_fieldset']['broker_'.$i.'_bank_info_left_start'] = array(
			'#type' 	=> 'item',
			'#prefix' 	=> '<div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Payout Commissions &amp; Reap To Agent</div>',
		);


		$form['names_fieldset']['comm_account_number_'.$i] = array(
			'#title'		  => t('Account Number'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 16,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder' 	=> t('Account Number'),
				'class'			=> array('form_text'),
				'onKeyPress' 	=> array('return IsNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w50">',
			'#suffix' => '</span></span>',
		);
		$form['names_fieldset']['name_on_comm_account_'.$i] = array(
			'#title'		   =>	t('Name on Account'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 50,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Name On Account'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return onlyAlphabets(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w50">',
			'#suffix' => '</span></span>',
		);
		$form['names_fieldset']['comm_financial_institution_name_'.$i] = array(
			'#title'		   =>	t('Bank Name'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 50,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Financial Institution Name'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return onlyAlphabets(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w100">',
			'#suffix' => '</span></span>',
		);
		$form['names_fieldset']['comm_financial_institution_phone_'.$i] = array(
			'#title'		   =>	t('Bank Contact'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 12,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Financial Institution Phone Number'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return IsNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['comm_account_type_'.$i] = array(
			'#title'		   =>	t('Account Type'),
			'#type'		      => 'select',
			'#required'		  => 'true',
			 '#default_value'  => 'checking',
			'#attributes'     => array(
				'class'=> array('input-mini'),
	        ),
			'#options'        => array('checking' => t('Checking'),'saving'=> t('Saving')),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);



		$form['names_fieldset']['comm_aba_routing_number_'.$i] = array(
			'#title'		   =>	t('ABA Routing#'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 16,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('ABA Routing Number'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return isAlphaNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['broker_'.$i.'_bank_info_left_end'] = array(
			'#type' => 'item',
			'#prefix' => '</div>',
		);

		//---------- //

		$form['names_fieldset']['broker_'.$i.'_bank_info_right_start_'.$i] = array(
			'#type' => 'item',
			'#prefix' => '<div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Personal Commissions & Reap</div>',
		);

		$form['names_fieldset']['personal_account_number_'.$i] = array(
			'#title'		   =>	t('Account Number'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 16,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Account Number'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return IsNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w50">',
			'#suffix' => '</span></span>',
		);
		$form['names_fieldset']['name_on_personal_account_'.$i] = array(
			'#title'		   =>	t('Name On Account'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 50,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Name On Account'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return onlyAlphabets(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w50">',
			'#suffix' => '</span></span>',
		);
		$form['names_fieldset']['personal_financial_institution_name_'.$i] = array(
			'#title'		   =>	t('Bank Name'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 50,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Financial Institution Name'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return onlyAlphabets(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w100">',
			'#suffix' => '</span></span>',
		);
		$form['names_fieldset']['personal_financial_institution_phone_'.$i] = array(
			'#title'		   =>	t('Bank Phone'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 15,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Financial Institution Phone Number'),
				'class'=> array('form_text'),
							'onKeyPress' => array('return IsNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);



		$form['names_fieldset']['personal_account_type_'.$i] = array(
			'#title'		   =>	t('Account Type'),
			'#type'		      => 'select',
			'#required'		  => 'true',
			 '#default_value'  => 'checking',
			'#attributes'     => array(
				'class'=> array('input-mini'),
	        ),
			'#options'        => array(	'checking'=> t('Checking'),'saving'=> t('Saving')
				//	        'onKeyPress' => array('return numbersonly(this, event)',),
				//'readonly'=>'readonly',
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);
		$form['names_fieldset']['personal_aba_routing_number_'.$i] = array(
			'#title'		   =>	t('ABA Routing#'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 15,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('ABA Routing Number'),
				'class'=> array('form_text'),
							'onKeyPress' => array('return isAlphaNumeric(event, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);


		$form['names_fieldset']['broker_'.$i.'_bank_info_right_end'] = array(
			'#type' => 'item',
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
			'#prefix' => '<div class="section_full"><div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Beneficiary Details</div>',
		);

		$form['names_fieldset']['beneficiary_first_name_'.$i] = array(
            '#title'		   =>	t('First Name'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 25,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('First Name'),
				'class'=> array('form_text'),
							'onKeyPress' => array('return onlyAlphabets(event, this)',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['beneficiary_middle_name_'.$i] = array(
             '#title'		   =>	t('Middle Name'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 25,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Middle Name'),
				'class'=> array('form_text'),
						'onKeyPress' => array('return onlyAlphabets(event, this)',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['beneficiary_last_name_'.$i] = array(
              '#title'		   =>	t('Last Name'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 25,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Last Name'),
				'class'=> array('form_text'),
							'onKeyPress' => array('return onlyAlphabets(event, this)',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);
		$form['names_fieldset']['beneficiary_relarionship_'.$i] = array(
              '#title'		   =>	t('Relationship'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 50,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Relationship'),
				'class'=> array('form_text'),
							'onKeyPress' => array('return onlyAlphabets(event, this)',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		$form['names_fieldset']['beneficiary_email_id_'.$i] = array(
            '#title'		   =>	t('Email Id'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 50,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Email ID'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return MailId(event, this)',),
				'onblur' 		=> array('validateEmail(this.value, this);',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
			
		);

		$form['names_fieldset']['beneficiary_contact_number_'.$i] = array(
			 '#title'		  => t('Phone Number'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 15,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Contact Number'),
				'class'=> array('form_text'),
				'onKeyPress' => array('return IsNumeric(event, this)',),
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);
		$form['names_fieldset']['beneficiary_address_'.$i] = array(
             '#title'		   =>	t('Street Address'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 50,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Beneficiary Address'),
				'class'=> array('form_text'),
							'onKeyPress' => array('return isAlphaNumeric(event, this)',),
			),
			'#prefix' => '</div><div class="section_left"><div class="form_subsection_title" data-item="inner_section_1">Beneficiary Address</div> <span class="wrapper-w100">',
			'#suffix' => '</span></span>',
		);
         if (isset($form_state['values']['beneficiary_state_id_'.$i])) {
		$selected_state_id  = isset($form_state['values']['beneficiary_state_id_'.$i]) ? $form_state['values']['beneficiary_state_id_'.$i] : key($state_options);
	   }else{
		$selected_state_id = '';
	    }
        $form['names_fieldset']['beneficiary_state_id_'.$i] = array(
			'#title'		   =>	t('State'),
			'#type'=>'select',
			'#required'=>'true',
            '#options'	=>	$state_options,
			'#default_value' 	=>	$selected_state_id ,
			'#attributes' 	=> array(
				'class' 	=> array('select-xlarge', 'uniform'),
			),
			'#ajax' 		=> array(
				'callback' 	=> 'find_cities_callback_33',
				'wrapper' 	=> 'cities-wrapper_'.$i,
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);
		$city_options = getCitiesBroker();
		if (isset($form_state['values']['beneficiary_city_id_'.$i])) {
		$selected_city = isset($form_state['values']['beneficiary_city_id_'.$i]) ? $form_state['values']['beneficiary_city_id_'.$i] : key($city_options);
	}else{
		$selected_city = '';
	}
		$form['names_fieldset']['beneficiary_city_id_'.$i] = array(
			'#title'		   =>	t('City'),
			'#type'=>'select',
			'#required'=>'true',
			'#default_value' 	=> 	'',
	    '#options' 		=>	$city_options,
	    '#attributes' 	=> array(
	    'placeholder' 	=>	t(''),
		   'class' 		=>	array('select-xlarge', 'uniform'),
	    ),
		'#ajax' 		=> array(
			'callback' 	=> 'find_zip_callback44',
			'wrapper' 	=> 'zip-wrapper',
		),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		
         $zip = getZip($selected_city, $selected_state_id);
		$form['names_fieldset']['beneficiary_zip_code_'.$i] = array(
			'#title'		   =>	t('Zip Code'),
			'#type'		      => 'textfield',
			'#maxlength'	  => 10,
			'#required'		  => 'true',
			'#attributes'     => array(
				'placeholder'=> t('Zip Code'),
				'class'=> array('form_text'),
				//	        'onKeyPress' => array('return IsNumeric(event, this);',),
				//'readonly'=>'readonly',
			),
			'#prefix' => '<span class="wrapper-w33">',
			'#suffix' => '</span></span>',
		);

		

		$form['names_fieldset']['broker_'.$i.'_beneficiary_end'] = array(
			'#type' => 'item',
			'#prefix' => '</div></div>',
		);

		//-----------//

	if($i == ($total_brokers)){
	  $form['names_fieldset']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Submit'),
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