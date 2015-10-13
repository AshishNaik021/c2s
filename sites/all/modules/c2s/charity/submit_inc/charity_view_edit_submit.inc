<?php

// ==================================================================================================
//                   Charity Organization Information Update
// ==================================================================================================
	$charity_organization_id				=   $form_state['values']['charity_organization_id'];
	//drupal_set_message('In Submit --- charity_organization_id = '.$charity_organization_id);
	$charity_organization_name				=   $form_state['values']['charity_organization_name'];
	//drupal_set_message('In Submit --- charity_organization_name = '.$charity_organization_name);
	$number_501_c_3			      		 	=   $form_state['values']['number_501_c_3'];
	//drupal_set_message('In Submit --- number_501_c_3	 = '.$number_501_c_3);
	$street_address							=   $form_state['values']['street_address'];
	$city									=   $form_state['values']['city'];
	//drupal_set_message('In Submit --- city	 = '.$city);
	$state_id								=   $form_state['values']['state_id'];
	//drupal_set_message('In Submit --- state_id	 = '.$state_id);
	$zip_code								=   $form_state['values']['zip_code'];
	//drupal_set_message('In Submit --- zip_code	 = '.$zip_code);
	$contact_number							=   $form_state['values']['contact_number'];
	$personal_email_id						=   $form_state['values']['personal_email_id'];
	$website_url							=   $form_state['values']['website_url'];

// ----- ETF Bank Account Details --- //

	$account_number							=   $form_state['values']['account_number'];
	$name_on_account						=   $form_state['values']['name_on_account'];
	$financial_institution_name 			=   $form_state['values']['financial_institution_name'];
	$financial_institution_phone			=   $form_state['values']['financial_institution_phone'];
	$account_type							=   $form_state['values']['account_type'];
	$aba_routing_number 					=   $form_state['values']['aba_routing_number'];
// -----///


	try{
	    
	    db_update('c2s_charity_org_master')->fields(array(
			'charity_org_name'       		  =>    $charity_organization_name	,
			'number_501_c_3'				  =>    $number_501_c_3,
			'charity_org_address'	   		  =>    $street_address,
			'charity_org_city'	  		      =>	$city,
			'charity_org_state'	   			  =>	$state_id,
			'charity_org_zip'	   			  =>	$zip_code,
			'phone_number'	   			      =>	$contact_number	,
			'email_id'	   			     	  =>	$personal_email_id,
			'website_url'	   			      =>	$website_url,
			'bank_account_number'	   		  =>	$account_number,
			'bank_account_name'	   			  =>	$name_on_account,
			'bank_name'	   			 	      =>	$financial_institution_name,
			'bank_phone'	   			      =>	$financial_institution_phone,
			'bank_account_type'	   			  =>	$account_type,
			'bank_aba_routing_number'	   	  =>	$aba_routing_number,
			'last_update_timestamp'           =>   REQUEST_TIME,
	    ))
		->condition('charity_organization_id', $charity_organization_id, '=')
		->execute();

		drupal_set_message("Charity Organization Details for <b>".$charity_organization_name."</b> Updated Successfully!");
	}
	catch(Exception $e)
	{
		drupal_set_message("Charity Organization Details could not be Updated <br>" . $e, 'error');				
	}

	
	 $form_state['redirect'] = array(
		'c2s/charity/view/'.$charity_organization_id,
	   array(
		'query' => array(
	   ),
	  ),
	 );	

				
// --------------------------------------------------------------------------------------------------

