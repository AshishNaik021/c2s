<?php
$city_options = array();
$state_options = array();
$state_options = getStates();

$number_to_words = array(1=>"One", 2=> "Two", 3=> "Three", 4=>"Four", 5=>"Five", 6=>"Six");

	$form['form_start'] = array(
		'#type' => 'item',
		'#suffix' => '<div id="main-view-wrapper">',
	);




	$form['agent_start_date'] = array(
		'#title'		   =>	t('Start Date'),
		'#type'		      => 'date_popup',
		'#date_label_position' => 'Within',
		
		'#date_format'	  => 'm/d/Y',
		'#date_year_range'  => '-3:+3',
		'#attributes'       => array(
			'placeholder'=> t('mm/dd/YYYY'),
			'class'=> array('date-input-medium form_text'),
			'onKeyPress' => array('return false;'),
		),
		'#prefix' => '<span class="wrapper-w50"><span class="wrapper-w60">',
		'#suffix' => '</span></span>',
	);

	$form['parent_id'] = array(
		 '#title'		   =>	t('Select Parent Agent'),
		'#type'		      => 'textfield',
        '#autocomplete_path' => 'parent/autocomplete',
		'#maxlength'	  => 50,
		'#attributes'     => array(
			'placeholder'=> t('Type Min. 3 Characters of Agent Name'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return onlyAlphabets(event, this);',),
			//'readonly'=>'readonly',
		),
		'#prefix' => '<span class="wrapper-w50">',
		'#suffix' => '</span></span></span>',
	);


	for($i=1; $i<=2; $i++){
		$class="";
		if($i==1){
			$class="selected";
		}
		$form['agent_tab_'.$i] = array(
			'#type' => 'item',
			'#suffix' => '<div class="form_section_tab '.$class.'" id="tab_'.$i.'" data-item="form_tab_'.$i.'" onclick="click_tabs_add(\'tab_'.$i.'\')" > Agent '.$number_to_words[$i].' </div>',
		);

	}



	for($i=1; $i<=2; $i++){
		$display="none";
		$true_false = FALSE;
		if($i==1){
			$display="block";
			$true_false = TRUE;
			//drupal_Set_message("true_false = ".$true_false);
		}else{
			$true_false = FALSE;
			//drupal_Set_message("true_false = ".$true_false);
		}

		
	$form['agent_'.$i.'_details_start'] = array(
		'#type' => 'item',
		'#theme_wrappers'  => array(),
		'#suffix' => '<div id="form_tab_'.$i.'" class="form_sections" style="display:'.$display.'">',
	);

	if($i == 2){
		$form['agent_relationship'] = array(
			'#type'=>'select',
			
			'#options' =>array('0'=>'-- Select --','Sibling'=>'Sibling','Spouse'=>'Spouse','Parent'=>'Parent','OffSpring'=>'OffSpring'),
			'#theme_wrappers'  => array(),
			'#attributes' => array(
				'placeholder' => t(''),
				'class' => array('form_text'),
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
		 '#title'		=>	t('First Name'),
		'#type'		    => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	=> 25,
		'#attributes'   => array(
			'placeholder'=> t('First Name'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return onlyAlphabets(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['agent_'.$i.'_middle_name'] = array(
		 '#title'		   =>	t('Middle Name'),
	   '#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 25,
		'#attributes'     => array(
			'placeholder'=> t('Middle Name'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return onlyAlphabets(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['agent_'.$i.'_last_name'] = array(
		 '#title'		   =>	t('Last Name'),
	   '#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 25,
		'#attributes'     => array(
			'placeholder'=> t('Last Name'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return onlyAlphabets(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);


	$form['date_of_birth_'.$i] = array(
		 '#title'		   =>	t('Date of Birth'),
		'#type'		      => 'date_popup',
		'#required'		=>	$true_false,
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


	$form['personl_email_id_'.$i] = array(
		'#title'		   =>	t('Email Id'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 100,
		'#attributes'     => array(
			'placeholder'=> t('Personal Email ID'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return MailId(event, this);',),
			'onblur' 		=> array('validateEmail(this.value, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['contact_number_'.$i] = array(
		  '#title'		   =>	t('Contact'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 15,
		'#attributes'     => array(
			'placeholder'=> t('123-456-789'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return IsNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['street_address_'.$i] = array(
		 '#title'		   =>	t('Street Address'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 50,
		'#attributes'     => array(
			'placeholder'=> t('Street Address'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return isAlphaNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w100">',
		'#suffix' => '</span></span>',
	);

	if (isset($form_state['values']['state_id_'.$i])) {
			$selected_state_id  = isset($form_state['values']['state_id_'.$i]) ? $form_state['values']['state_id_'.$i] : key($state_options);
		}else{
			$selected_state_id = '';
		}
		$form['state_id_'.$i] = array(
				 '#title'	=>	t('State'),
				'#type'=>'select',
				'#required'		=>	$true_false,
				'#options'	=>	$state_options,
				'#default_value' 	=>	$selected_state_id ,
				'#attributes' 	=> array(
					'class' 	=> array('select-xlarge', 'uniform'),
				),
				'#ajax' 		=> array(
					'callback' 	=> 'find_cities_callback_agent'.$i,
					'wrapper' 	=> 'cities-wrapper_'.$i,
				),
				
				'#prefix' => '<span class="wrapper-w33">',
				'#suffix' => '</span></span>',
			);
			$city_options = getCitiesBroker();
			if (isset($form_state['values']['city_id'.$i])) {
			$selected_city = isset($form_state['values']['city_id'.$i]) ? $form_state['values']['city_id'.$i] : key($city_options);
		}else{
			$selected_city = '';
		}
		$form['city_id_'.$i] = array(
			 '#title'=>	t('City'),
			'#type'=>'select',
			'#required'		=>	$true_false,
			'#default_value' 	=> 	'',
			'#options' 		=>	$city_options,
			'#attributes' 	=> array(
			'placeholder' 	=>	t(''),
			   'class' 		=>	array('select-xlarge', 'uniform'),
			),
			'#ajax' 		=> array(
				'callback' 	=> 'find_zip_callback10',
				'wrapper' 	=> 'zip-wrapper',
			),
		'#prefix' => '<div id="cities-wrapper_'.$i.'"> <span class="wrapper-w33">',
		'#suffix' => '</span></span></div>',
		);

				$zip = getZip($selected_city, $selected_state_id);

			$form['zip_code_'.$i] = array(
				 '#title'		   =>	t('Zip Code'),
				'#type'		      => 'textfield',
				'#maxlength'	  => 25,
				'#required'		  => 'true',
				'#value'  => $zip,
				'#attributes'     => array(
					'placeholder'=> t('Zip Code'),
					 'class'=> array('input-mini'),
				//'readonly'=>'readonly',
					//	        'onKeyPress' => array('return IsNumeric(event, this);',),
					//'readonly'=>'readonly',
				),
				'#prefix' => '<span class="wrapper-w33">',
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
		'#title'		   =>	t('State ID#'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 25,
		'#attributes'     => array(
			'placeholder'=> t('Broker State Id #'),
			'class'=> array('form_text'),
						'onKeyPress' => array('return IsNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['mls_username_'.$i] = array(
		 '#title'		   =>	t('MLS User Id'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 25,
		'#attributes'     => array(
			'placeholder'=> t('MLS User Id'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return isAlphaNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['mls_password_'.$i] = array(
		 '#title'		   =>	t('MLS Password'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 25,
		'#attributes'     => array(
			'placeholder'=> t('MLS Password'),
			'class'=> array('form_text'),
						'onKeyPress' => array('return isAlphaNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

    $form['agent_nrds_'.$i] = array(
		 '#title'		   =>	t('NRDS#'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 25,
		'#attributes'     => array(
			'placeholder'=> t('Broker NRDS#'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return IsNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);


	$form['office_phone_'.$i] = array(
		 '#title'		   =>	t('Office Phone'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 15,
		'#attributes'     => array(
			'placeholder'=> t('123-456-789'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return IsNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['extension_'.$i] = array(
		 '#title'		   =>	t('Extension'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 25,
		'#attributes'     => array(
			'placeholder'=> t('Extension'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return IsNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);
	$form['create_email_'.$i] = array(
		'#title'		   =>	t('Create My C2S Email As'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 25,
		'#attributes'     => array(
			'placeholder'=> t('example@c2semail.com'),
			'class'=> array('form_text'),
						'onKeyPress' => array('return isMailId(event, this);',),
						'onblur' 		=> array('validateEmail(this.value, this);',),
		),
		'#prefix' => '<span class="wrapper-w100">',
		'#suffix' => '</span></span>',
	);
	$form['choice_of_charity_org_'.$i] = array(
		'#title'		   =>	t('Choose The Charity Organization Of Your Choice'),
	   '#type'		      => 'textfield',
       '#autocomplete_path' => 'charity/autocomplete',
		'#required'		=>	$true_false,
		'#maxlength'	  => 250,
		'#attributes'     => array(
			'placeholder'=> t('Type Min 3 Chars'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return isAlphaNumeric(event, this);',),
			//'readonly'=>'readonly',
		),
		'#prefix' => '<span class="wrapper-w100">',
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
		'#title'		   =>	t('Account Number'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 50,
		'#attributes'     => array(
			'placeholder'=> t('Account Number'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return IsNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w50">',
		'#suffix' => '</span></span>',
	);
	$form['name_on_personal_account_'.$i] = array(
		'#title'		   =>	t('Name On Account'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 50,
		'#attributes'     => array(
			'placeholder'=> t('Name On Account'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return onlyAlphabets(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w50">',
		'#suffix' => '</span></span>',
	);
	$form['personal_financial_institution_name_'.$i] = array(
		'#title'		   =>	t('Bank Name'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 50,
		'#attributes'     => array(
			'placeholder'=> t('Financial Institution Name'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return onlyAlphabets(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w100">',
		'#suffix' => '</span></span>',
	);
	$form['personal_financial_institution_phone_'.$i] = array(
		'#title'		   =>	t('Bank Phone'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 15,
		'#attributes'     => array(
			'placeholder'=> t('Financial Institution Phone Number'),
			'class'=> array('form_text'),
						'onKeyPress' => array('return IsNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);



	$form['personal_account_type_'.$i] = array(
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
	$form['personal_aba_routing_number_'.$i] = array(
		'#title'		   =>	t('ABA Routing#'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 50,
		'#attributes'     => array(
			'placeholder'=> t('ABA Routing Number'),
			'class'=> array('form_text'),
						'onKeyPress' => array('return IsNumeric(event, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
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
		 '#title'		   =>	t('First Name'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 25,
		'#attributes'     => array(
			'placeholder'=> t('First Name'),
			'class'=> array('form_text'),
						'onKeyPress' => array('return onlyAlphabets(event, this)',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['beneficiary_middle_name_'.$i] = array(
		 '#title'		   =>	t('Middle Name'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 25,
		'#attributes'     => array(
			'placeholder'=> t('Middle Name'),
			'class'=> array('form_text'),
						'onKeyPress' => array('return onlyAlphabets(event, this)',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['beneficiary_last_name_'.$i] = array(
		 '#title'		   =>	t('Last Name'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 25,
		'#attributes'     => array(
			'placeholder'=> t('Last Name'),
			'class'=> array('form_text'),
						'onKeyPress' => array('return onlyAlphabets(event, this)',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);
	$form['beneficiary_relarionship_'.$i] = array(
		   '#title'		   =>	t('Relationship'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 50,
		'#attributes'     => array(
			'placeholder'=> t('Relationship'),
			'class'=> array('form_text'),
						'onKeyPress' => array('return onlyAlphabets(event, this)',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['beneficiary_email_id_'.$i] = array(
		  '#title'		   =>	t('Email Id'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 50,
		'#attributes'     => array(
			'placeholder'=> t('Email ID'),
			'class'=> array('form_text'),
			'onKeyPress' => array('return MailId(event, this)',),
			'onblur' 		=> array('validateEmail(this.value, this);',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);

	$form['beneficiary_contact_number_'.$i] = array(
		 '#title'		   =>	t('Contact'),
	   '#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 15,
		'#attributes'     => array(
			'placeholder'=> t('123-456-789'),
			'class'=> array('form_text'),
						'onKeyPress' => array('return IsNumeric(event, this)',),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);
	$form['beneficiary_address_'.$i] = array(
		 '#title'		   =>	t('Street Address'),
		'#type'		      => 'textfield',
		'#required'		=>	$true_false,
		'#maxlength'	  => 50,
		'#attributes'     => array(
			'placeholder'=> t('Beneficiary Address'),
			'class'=> array('form_text'),
						'onKeyPress' => array('return isAlphaNumeric(event, this)',),
		),
		'#prefix' => '<span class="wrapper-w100">',
		'#suffix' => '</span></span>',
	);

	if (isset($form_state['values']['beneficiary_state_id_'.$i])) {
			$selected_state_id  = isset($form_state['values']['beneficiary_state_id_'.$i]) ? $form_state['values']['beneficiary_state_id_'.$i] : key($state_options);
		   }else{
			$selected_state_id = '';
			}
			$form['beneficiary_state_id_'.$i] = array(
				  '#title'		   =>	t('State'),
				'#type'=>'select',
				'#required'		=>	$true_false,
				 '#options'	=>	$state_options,
				'#default_value' 	=>	$selected_state_id ,
			'#attributes' 	=> array(
				'class' 	=> array('select-xlarge', 'uniform'),
			),
			'#ajax' 		=> array(
				'callback' 	=> 'find_cities_callback_1',
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
			$form['beneficiary_city_id_'.$i] = array(
				 '#title'		   =>	t('City'),
				'#type'=>'select',
				'#required'		=>	$true_false,
				'#default_value' 	=> 	'',
			'#options' 		=>	$city_options,
			'#attributes' 	=> array(
			'placeholder' 	=>	t(''),
			   'class' 		=>	array('select-xlarge', 'uniform'),
			),
			'#ajax' 		=> array(
				'callback' 	=> 'find_zip_callback12',
				'wrapper' 	=> 'zip-wrapper',
			),
				'#prefix' => '<span class="wrapper-w33">',
				'#suffix' => '</span></span>',
			);

			
			 $zip = getZip($selected_city, $selected_state_id);
			$form['beneficiary_zip_code_'.$i] = array(
				 '#title'		   =>	t('Zip Code'),
				'#type'		      => 'textfield',
				'#maxlength'	  => 25,
				'#required'		=>	$true_false,
				'#attributes'     => array(
					'placeholder'=> t('Zip Code'),
					'class'=> array('form_text'),
					//	        'onKeyPress' => array('return IsNumeric(event, this);',),
					//'readonly'=>'readonly',
				),
				'#prefix' => '<span class="wrapper-w33">',
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