<?php

// ==================================================================================================
//                   New Charity Organization Information Submit
// ==================================================================================================
$charity_organizations_name				=   $form_state['values']['charity_organizations_name'];
$501_c_3_#			      		 		=   $form_state['values']['501_c_3_#'];
$street_address							=   $form_state['values']['street_address'];
$city_id								=   $form_state['values']['city_id'];
$state_id								=   $form_state['values']['state_id'];
$zip_code								=   $form_state['values']['zip_code'];
$contact_number							=   $form_state['values']['contact_number'];
$personl_email_id						=   $form_state['values']['personl_email_id'];
$website_url							=   $form_state['values']['website_url'];

// ----- ETF Bank Account Details --- //

$account_number							=   $form_state['values']['account_number'];
$name_on_account						=   $form_state['values']['name_on_personal_account'];
$financial_institution_name 			=   $form_state['values']['financial_institution_name'];
$financial_institution_phone			=   $form_state['values']['financial_institution_phone'];
$account_type							=   $form_state['values']['account_type'];
$aba_routing_number 					=   $form_state['values']['aba_routing_number'];
// -----///


	try{
	    
	    $result_charity = db_query("SELECT max(charity_organization_id) as maxid_charity FROM Charity_Master ");
	    foreach($result_charity as $value){
	        $id_charity = $value->maxid_charity;
	    }
	    $newid_charity  =   $id_charity + 1;
	    
        $values_charity = array(
	    'charity_organization_id'         =>    $newid_charity,
	    'charity_org_name'       		  =>    $charity_organizations_name	,
        '501_c_3_number'				  =>    $501_c_3_#,
	    'charity_org_address'	   		  =>    $street_address,
	    'charity_org_city'	  		      =>	$city_id,
	    'charity_org_state'	   			  =>	$state_id,
		'charity_org_zip'	   			  =>	$zip_code,
		'phone_number'	   			      =>	$contact_number	,
		'email_id'	   			     	  =>	$personl_email_id,
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
        
	    db_insert('Charity_Master')
	    ->fields($values_charity)
	    ->execute();

		drupal_set_message("New Charity Organization Details Submitted Successfully");
	}
	catch(Exception $e)
	{
		drupal_set_message("New Charity Organization Details could not be Inserted <br>" . $e, 'error');				
	}


	 $form_state['redirect'] = array(
		'c2s/charity/add',
	   array(
		'query' => array(
	   ),
	  ),
	 );	

				
// --------------------------------------------------------------------------------------------------

