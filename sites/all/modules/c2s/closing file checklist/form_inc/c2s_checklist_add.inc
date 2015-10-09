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
	
	$form['agent_name'] = array(
	    '#title'          => 'Agent Name',
	    '#type'		      => 'item',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => 'MS. Laura Carr',
	    '#attributes'     => array(
	        'placeholder'=> t('MS. Laura Carr'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['types_of_transaction'] = array(
	    '#title' => t('Types Of Transaction'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(1=>'Buyer'),
	    '#attributes' => array(
	        'placeholder' => t('Buyer'),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['title_company'] = array(
	    '#title'          => 'Title Company',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Title Company'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);
	$form['processor_name'] = array(
	    '#title'          => 'Processor Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Processor Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['processor_email'] = array(
	    '#title'          => 'Processor Email',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Processor Email'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['property_address'] = array(
	    '#title'          => 'Property Address',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Property Address'),
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
	$form['parcel_number'] = array(
	    '#title'          => 'Parcel Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Parcel Number'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	
	$form['mls'] = array(
	    '#title'          => 'MLS',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Write MLS Number'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	$form['price'] = array(
	    '#title'          => 'Price',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Price'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	$form['loan'] = array(
	    '#title'          => 'Loan',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Loan'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	$form['transaction_date'] = array(
	    '#title'	      => 'Transaction Date',
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
	$form['closing_date'] = array(
	    '#title'	      => 'Closing Date',
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
	$form['terms'] = array(
	    '#title' => t('Terms'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(1=>'Cash','Conv','FHA','VA','RHS','RD','Other'),
	    '#attributes' => array(
	        'placeholder' => t('Buyer'),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	 $form['association_information'] = array(
	    '#title'          => 'Association Information',
	    '#type'		      => 'radios',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'class'=> array('input-mini'),
	        ),
	     '#options'        => array(	'YES'=> t('YES'),'NO'=> t('NO')
//	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
    $form['amount'] = array(
	    '#title' => t('Amount'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(1=>'Cash','Conv','FHA','VA','RHS','RD','Other'),
	    '#attributes' => array(
	        'placeholder' => t('Buyer'),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	$form['association_name'] = array(
	    '#title'          => 'Association Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Association Name'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['contact_person'] = array(
	    '#title'          => 'Contact Person',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Contact Person'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['phone_number'] = array(
	    '#title'          => 'Phone Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Phone Number'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	$form['email'] = array(
	    '#title'          => 'Email',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Email'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	$form['property_type'] = array(
	    '#title'          => 'Property Type',
	    '#type'		      => 'radios',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'class'=> array('input-mini'),
	        ),
	     '#options'        => array(	'Residential'=> t('Residential'),'Lot/Vacant'=> t('Lot/Vacant'),'Condo'=> t('Condo')
		 ,'FSBO'=> t('FSBO'),'Lease'=> t('Lease'),'New Construction'=> t('New Construction'),'Commercial'=> t('Commercial')
//	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);
	$form['earnest_money'] = array(
	    '#title'          => 'Earnest Money',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Earnest Money'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	$form['transaction_management_fee'] = array(
	    '#title'          => 'Transaction Management Fee',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Transaction Management Fee'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	$form['listing_agent'] = array(
	    '#type' => 'item',
	   '#prefix' => '<div class="form_subsection_title" data-item="inner_section_1"> Listing Agent
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="inner_section_1_arrow" class="inner_section_arrow" >
	    </div>',
	   '#suffix' => '<div id="inner_section" class="inner_section_1 inner_subsection" style="display: none;">',
	);
	
	
	$form['listing_name'] = array(
	    '#title'          => 'Listing Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Listing Name'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);
	$form['listing_company'] = array(
	    '#title'          => 'Listing Company',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Listing Company'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);
	
	$form['listing_phone'] = array(
	    '#title'          => 'Listing Phone',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Listing Phone'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['listing_fax'] = array(
	    '#title'          => 'Listing FAX',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Listing FAX'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['listing_email'] = array(
	    '#title'          => 'Listing Email',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Listing Email'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);
	
	$form['listing_commission_value'] = array(
	    '#title'          => 'Commission',
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
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['listing_commission_amount'] = array(
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
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	
	$form['listing_agent_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div>',
	);
	$form['buyers_agent'] = array(
	    '#type' => 'item',
	   '#prefix' => '<div class="form_subsection_title" data-item="inner_section_2"> Buyers Agent
	    <img src="'.base_path().'/'.drupal_get_path('module', 'agent').'/images/arrow_toggle.png" id="inner_section_2_arrow" class="inner_section_arrow" >
	    </div>',
	   '#suffix' => '<div id="inner_section" class="inner_section_2 inner_subsection" style="display: none;">',
	);
	
	
	$form['buyers_name'] = array(
	    '#title'          => 'Buyers Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Buyers Name'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);
	$form['buyers_company'] = array(
	    '#title'          => 'Buyers Company',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Buyers Company'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);
	
	$form['buyers_phone'] = array(
	    '#title'          => 'Buyers Phone',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Buyers Phone'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['buyers_fax'] = array(
	    '#title'          => 'Buyers FAX',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Buyers FAX'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['buyers_email'] = array(
	    '#title'          => 'Buyers Email',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Buyers Email'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);
	
	$form['buyers_commission_value'] = array(
	    '#title'          => 'Commission',
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
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['buyers_commission_amount'] = array(
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
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	
	$form['buyers_agent_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div>',
	);
	$form['sellers_first_name'] = array(
	    '#title'          => 'First Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Sellers Name'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);	

	$form['sellers_middle_name'] = array(
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

	$form['sellers_last_name'] = array(
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
	$form['sellers_phone'] = array(
	    '#title'          => 'Sellers Phone',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Sellers Phone'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['sellers_marital_status'] = array(
	    '#title' => t('Marital Status'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(1=>'State'),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['buyers_first_name'] = array(
	    '#title'          => 'First Name',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Sellers Name'),
	        'class'=> array('input-mini'),
//	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);	

	$form['buyers_middle_name'] = array(
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

	$form['buyers_last_name'] = array(
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
	$form['buyers_phone_1'] = array(
	    '#title'          => 'Buyers Phone',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Sellers Phone'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['buyers_marital_status'] = array(
	    '#title' => t('Marital Status'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(1=>'State'),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	 $form['buyers_address'] = array(
	    '#title'          => 'Buyers Address',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 100,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Buyers Address'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	
	$form['buyers_city_id'] = array(
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
	
	$form['buyers_state_id'] = array(
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
	
    $form['buyers_zip_code'] = array(
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
	$form['buyers_cost'] = array(
	    '#title'          => 'Buyers Cost Paid By Seller',
	    '#type'		      => 'radios',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'class'=> array('input-mini'),
	        ),
	     '#options'        => array(	'YES'=> t('YES'),'NO'=> t('NO')
//	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['buyers_cost_how_much'] = array(
	    '#title'          => 'If Yes How Much',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t(''),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['lender'] = array(
	    '#title'          => 'Lender',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Lender'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['loan_officer'] = array(
	    '#title'          => 'Loan Officer',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Loan Officer'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	$form['phone_number'] = array(
	    '#title'          => 'Phone Number',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Phone Number'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	$form['lender_fax'] = array(
	    '#title'          => 'Lender FAX',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Lender FAX'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	$form['lender_email'] = array(
	    '#title'          => 'Lender Email',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Lender Email'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w25">',
	    '#suffix' => '</span>',
	);
	$form['home_inspection_provider'] = array(
	    '#title'          => 'Home Inspection Provider',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Home Inspection Provider'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);
	$form['termite_provider'] = array(
	    '#title'          => 'Termite Provider',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Termite Provider'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);
	$form['appraiser'] = array(
	    '#title'          => 'Appraiser',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Appraiser'),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span>',
	);
	$form['basic'] = array(
	    '#title'          => 'Basic',
	    '#type'		      => 'checkbox',
	    '#maxlength'	  => 25,
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t(''),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);
	$form['termite'] = array(
	    '#title'          => 'Termite',
	    '#type'		      => 'checkbox',
	    '#maxlength'	  => 25,
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t(''),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);
	$form['randon'] = array(
	    '#title'          => 'Randon',
	    '#type'		      => 'checkbox',
	    '#maxlength'	  => 25,
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t(''),
	        'class'=> array('input-mini'),
	        //	        'onKeyPress' => array('return IsNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);
	$form['septic_inspection'] = array(
	    '#title'          => 'Well Septic Inspection',
	    '#type'		      => 'radios',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'class'=> array('input-mini'),
	        ),
	     '#options'        => array(	'YES'=> t('YES'),'NO'=> t('NO')
//	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['septic_inspection_provided'] = array(
	    '#title'          => 'If Yes Provided By',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 25,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t(''),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
	$form['marketing_data_1'] = array(
	    '#title' => t('Marketing Data'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(1=>'--Select--'),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span id="rep-loc-replace"><span class="wrapper-w25">',
	    '#suffix' => '</span></span>',
	);
	$form['race'] = array(
	    '#title' => t('Race'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(1=>'--Select--'),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span id="rep-loc-replace"><span class="wrapper-w25">',
	    '#suffix' => '</span></span>',
	);
	$form['marital_status_1'] = array(
	    '#title' => t('Marital Status'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(1=>'--Select--'),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span id="rep-loc-replace"><span class="wrapper-w25">',
	    '#suffix' => '</span></span>',
	);
	$form['age'] = array(
	    '#title' => t('Age'),
	    '#type'=>'select',
	    '#required'=>'true',
	    '#default_value'=>'',
	    '#options' =>array(1=>'--Select--'),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<span id="rep-loc-replace"><span class="wrapper-w25">',
	    '#suffix' => '</span></span>',
	);
	$form['add_notes'] = array(
	    '#title'          => 'Add Notes',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 50,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'placeholder'=> t('Add Notes'),
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return onlyAlphabets(event, this);',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
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
	