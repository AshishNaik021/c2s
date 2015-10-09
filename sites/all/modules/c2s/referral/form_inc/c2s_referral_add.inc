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
	$form['referral_type'] = array(
	    '#title'          => 'Referral Type',
	    '#type'		      => 'radios',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'class'=> array('input-mini'),
	        ),
	     '#options'        => array(	'Listing'=> t('Listing'),'Buyer'=> t('Buyer'),'Both'=> t('Both')
//	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);

	$form['receiving_office_subsection_start'] = array(
	   '#type' => 'item',
	   '#prefix' => '<div id="form_sections" class="form_sections"> ',
	   '#suffix' => '<div class="form_section_title" data-item = "form_section_1"> Receiving Office
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="form_section_1_arrow" class="inner_section_arrow icon_rotate" > </div>
	    <div id = "form_section_1">'
	);

	
	
	// --------------------Receiving Office Details Start------------------- //
	
	
	$form['receiving_agent_name'] = array(
	    '#title'          => 'Agent Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Agent Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	$form['receiving_firm_name'] = array(
	    '#title'          => 'Firm Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Firm Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['receiving_address'] = array(
	    '#title'          => 'Address',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Address'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);

	$form['receiving_city_id'] = array(
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

	$form['receiving_state_id'] = array(
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
	$form['receiving_zip_code'] = array(
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
	
    $form['receiving_agent_email'] = array(
	    '#title'          => 'Agent Email',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Agent Email'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
    
	$form['receiving_business_phone'] = array(
	    '#title'          => 'Business Phone',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Business Phone'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);	
	$form['receiving_fax'] = array(
	    '#title'          => 'Fax',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Fax'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);	
	
// --------------------Receiving Office Details End------------------- //

	$form['section_one_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div></div> ',
	);
	$form['referring_office_subsection_start'] = array(
	   '#type' => 'item',
	   '#prefix' => '<div id="form_sections" class="form_sections"> ',
	   '#suffix' => '<div class="form_section_title" data-item = "form_section_2"> Referring Office
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="form_section_2_arrow" class="inner_section_arrow icon_rotate" > </div>
	    <div id = "form_section_2">'
	);

	
	
	// --------------------Referring Office Details Start------------------- //
	
	
	$form['referring_agent_name'] = array(
	    '#title'          => 'Agent Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Agent Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	$form['referring_firm_name'] = array(
	    '#title'          => 'Firm Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Firm Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['referring_address'] = array(
	    '#title'          => 'Address',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Address'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);

	$form['reffering_city_id'] = array(
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

	$form['referring_state_id'] = array(
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
	$form['referring_zip_code'] = array(
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
	
    $form['referring_agent_email'] = array(
	    '#title'          => 'Agent Email',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Agent Email'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
    
	$form['referring_business_phone'] = array(
	    '#title'          => 'Business Phone',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Business Phone'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);	
	$form['referring_fax'] = array(
	    '#title'          => 'Fax',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Fax'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);	
	
// --------------------Referring Office Details End------------------- //

	$form['section_two_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div></div> ',
	);
	
	$form['client_information_subsection_start'] = array(
	   '#type' => 'item',
	   '#prefix' => '<div id="form_sections" class="form_sections"> ',
	   '#suffix' => '<div class="form_section_title" data-item = "form_section_3"> Client Information
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="form_section_3_arrow" class="inner_section_arrow icon_rotate" > </div>
	    <div id = "form_section_3">'
	);

	
	
	// --------------------Client Information Details Start------------------- //
	
	
	$form['client_name'] = array(
	    '#title'          => 'Client Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Client Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	$form['client_email'] = array(
	    '#title'          => 'Email',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Email'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['client_address'] = array(
	    '#title'          => 'Address',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Address'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);

	$form['client_city_id'] = array(
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

	$form['client_state_id'] = array(
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
	$form['client_zip_code'] = array(
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
	
    $form['client_mobile'] = array(
	    '#title'          => 'Mobile',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Mobile'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);	
	$form['client_home_phone'] = array(
	    '#title'          => 'Home Phone',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Home Phone'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);	
	$form['client_office_phone'] = array(
	    '#title'          => 'Office Phone',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Office Phone'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);	
	$form['client_best_time_to_contact'] = array(
	    '#title'          => 'Best Time to Contact',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Best Time to Contact'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);	
	$form['client_fax'] = array(
	    '#title'          => 'Fax',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Fax'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);	
    $form['client_terms_value'] = array(
	    '#title'          => 'Terms',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('% Value'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	
	$form['client_terms_amount'] = array(
	    '#title'          => 'Commission',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('% Amount'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	$form['client_information'] = array(
	    '#title'          => '',
	    '#type'		      => 'item',
	    '#maxlength'	  => 25,
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => 'Referral Fee Upon Completion Of Sale.</span>',
	);
	
	$form['client_receiving_agent'] = array(
	    '#title'          => 'Receiving Agent',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Receiving Agent'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	$form['client_referring_agent'] = array(
	    '#title'          => 'Referring Agent',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Referring Agent'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	$form['client_receiving_date'] = array(
	    '#title'	      => 'Receiving Date',
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
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['client_referring_date'] = array(
	    '#title'	      => 'Referring Date',
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
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);

	
// --------------------Client Information Details End------------------- //

	$form['section_three_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div></div> ',
	);
	
	$form['client_information_1'] = array(
	    '#title'          => '',
	    '#type'		      => 'item',
	    '#maxlength'	  => 25,
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => 'Referral Fee PAID Upon Closing Of Sale.By signing and accepting this document,the receiving agent is hereby bound legally in contact with referring agent to pay, excat and full amount stated in terms of these agreement, along with poof of purchase price, within ten(10)bdays of transaction close date.</span>',
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
	