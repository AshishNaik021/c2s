<?php

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
	   '#prefix' => '<h2 class="main_form_title"> Broker Enrollment Form </h2>',
	   '#suffix' => '<div id="main-form-wrapper"> ',
	);
        

	$form['brokerage_start_date'] = array(
	    '#title'	      => 'Brokerage Start Date',
	    '#label'          => '',
	    '#type'		      => 'date_popup',
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#date_format'	  => 'd/m/Y',
	    '#date_year_range'  => '-3:+3',
	    '#attributes'       => array(
	        'placeholder'=> t('dd/mm/YYYY'),
	        'class'=> array('date-input-medium'),
	    ),
	    '#prefix' => '<span class="wrapper-w100">',
	    '#suffix' => '</span>',
	);
	
	$form['brokerage_name'] = array(
	    '#title'           => 'Name of Brokerage',
	    '#type'		       => 'textfield',
	    '#maxlength'	   => 3,
	    '#required'		   =>'true',
	    '#default_value'   =>'',
	    '#attributes'       => array(
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);
		
	$form['number_of_owners'] = array(
	    '#title'          => 'How many Broker Owners are there?',
	    '#type'		      => 'textfield',
	    '#maxlength'	  => 3,
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#attributes'     => array(
	        'class'=> array('input-mini'),
	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w50">',
	    '#suffix' => '</span>',
	);	
	
	$form['section_one_start'] = array(
	    '#type' => 'item',
	    '#prefix' => '<h3 class="main_form_title"> Broker One </h3><div id="inner_section">',
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
//	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
	    '#suffix' => '</span>',
	);	

	$form['broker_middle_name'] = array(
	    '#title'          => 'Middle Name',
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
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
	    '#suffix' => '</span>',
	);

	$form['broker_last_name'] = array(
	    '#title'          => 'Last Name',
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
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
	    '#suffix' => '</span>',
	);
	
	
	$form['date_of_birth'] = array(
	    '#title'	      => 'Date of Birth',
	    '#label'          => '',
	    '#type'		      => 'date_popup',
	    '#required'		  => 'true',
	    '#default_value'  => '',
	    '#date_format'	  => 'd/m/Y',
	    '#date_year_range'  => '-3:+3',
	    '#attributes'       => array(
	        'placeholder'=> t('dd/mm/YYYY'),
	        'class'=> array('date-input-medium'),
	    ),
	    '#prefix' => '<span class="">',
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
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
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
	        	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
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
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
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
	    '#prefix' => '<div id="section_left"><span class="wrapper-w33">',
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
	    '#prefix' => '<span class="wrapper-w33">',
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
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="wrapper-w33">',
	    '#suffix' => '</span></div>',
	);

	$form['section_serprator'] = array(
	    '#type' => 'item',
	    '#suffix' => '<div> Professional Details </div> ',
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
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
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
	    '#prefix' => '<span id="rep-loc-replace"><span class="mini-form-item-with-lable-top">',
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
	    '#prefix' => '<span id="rep-loc-replace"><span class="mini-form-item-with-lable-top">',
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
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
	    '#suffix' => '</span>',
	);	

	$form['broker_state_id'] = array(
	    '#title'          => 'Broker State Id #',
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
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
	    '#suffix' => '</span>',
	);
	
	$form['broker_ein'] = array(
	    '#title'          => 'Broker EIN',
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
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
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
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
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
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
	    '#suffix' => '</span>',
	);
	
	$form['broker_nrds_link'] = array(
	    '#type' => 'item',
	    '#prefix' => '<div><span class="label"> Broker NRDS Search Link </span>',
	    '#suffix' => '<a href="#">link..</a></div>',
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
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
	    '#suffix' => '</span> <p style="float:left;">@city2shore.com</p>',
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
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
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
	        //	        'onKeyPress' => array('return numbersonly(this, event)',),
	        //'readonly'=>'readonly',
	    ),
	    '#prefix' => '<span class="large-form-item-with-lable-top">',
	    '#suffix' => '</span>',
	);
	
	$form['section_one_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div> ',
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
	 'onKeyPress' => array('return numbersonly(this, event)',),
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
	 'onKeyPress' => array('return numbersonly(this, event)',),
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
	
	
	
	
	$form['form_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div> ',
	);
	