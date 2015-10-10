<?php

// ==================================================================================================
//                   New Charity Organization Information Submit
// ==================================================================================================
	$charity_organizations_name				=   $form_state['values']['charity_organizations_name'];
	$number_501_c_3			      		 	=   $form_state['values']['number_501_c_3'];
	$street_address							=   $form_state['values']['street_address'];
	$city									=   $form_state['values']['city'];
	$state_id								=   $form_state['values']['state_id'];
	$zip_code								=   $form_state['values']['zip_code'];
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
	    
	    
        $values_charity = array(
			'charity_org_name'       		  =>    $charity_organizations_name	,
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
			'created_timestamp'         	  =>   REQUEST_TIME,
			'last_update_timestamp'           =>   REQUEST_TIME,
	    );
        
	    db_insert('c2s_charity_org_master')
	    ->fields($values_charity)
	    ->execute();

		drupal_set_message("New Charity Organization Details Submitted Successfully");
	}
	catch(Exception $e)
	{
		drupal_set_message("New Charity Organization Details could not be Inserted <br>" . $e, 'error');				
	}


	
	$result_charity = db_query("SELECT max(charity_organization_id) as maxid_charity FROM c2s_charity_org_master ");
	foreach($result_charity as $value){
		$maxid_charity = $value->maxid_charity;
	}
	
	 $form_state['redirect'] = array(
		'c2s/charity/view/'.$maxid_charity,
	   array(
		'query' => array(
	   ),
	  ),
	 );	

				
// --------------------------------------------------------------------------------------------------

