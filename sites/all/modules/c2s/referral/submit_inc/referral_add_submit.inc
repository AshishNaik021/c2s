<?php

// ==================================================================================================
//                   New Referral Information Submit
// ==================================================================================================
			$referral_type								=   $form_state['values']['referral_type'];
			// ----- Receiving Office Details --- //
			$receiving_agent_name			      		=   $form_state['values']['receiving_agent_name'];
			$receiving_firm_name						=   $form_state['values']['receiving_firm_name'];
			$receiving_address							=   $form_state['values']['receiving_address'];
			$receiving_city_id							=   $form_state['values']['receiving_city_id'];
			$receiving_state_id							=   $form_state['values']['receiving_state_id'];
			$receiving_zip_code							=   $form_state['values']['receiving_zip_code'];
			$receiving_agent_email						=   $form_state['values']['receiving_agent_email'];
			$receiving_business_phone					=   $form_state['values']['receiving_business_phone'];
			$receiving_fax								=   $form_state['values']['receiving_fax'];
			
			// -----///
			
			// ----- Referring Office Details --- //
			$referring_agent_name			      		=   $form_state['values']['referring_agent_name'];
			$referring_firm_name						=   $form_state['values']['referring_firm_name'];
			$referring_address							=   $form_state['values']['referring_address'];
			$referring_city_id							=   $form_state['values']['referring_city_id'];
			$recferring_state_id						=   $form_state['values']['referring_state_id'];
			$referring_zip_code							=   $form_state['values']['referring_zip_code'];
			$referring_agent_email						=   $form_state['values']['referring_agent_email'];
			$referring_business_phone					=   $form_state['values']['referring_business_phone'];
			$referring_fax								=   $form_state['values']['referring_fax'];
			
			// -----///

			// ----- Client Information Details --- //

			$client_name								=   $form_state['values']['client_name'];
			$client_email								=   $form_state['values']['client_email'];
			$client_address 							=   $form_state['values']['client_address'];
			$client_city_id								=   $form_state['values']['client_city_id'];
			$client_state_id							=   $form_state['values']['client_state_id'];
			$client_zip_code 							=   $form_state['values']['client_zip_code'];
			$client_mobile 								=   $form_state['values']['client_mobile'];
			$client_home_phone 							=   $form_state['values']['client_phone'];
			$client_office_phone 						=   $form_state['values']['client_office_phone'];
			$client_best_time_to_contact 				=   $form_state['values']['client_best_time_to_contact'];
			$client_fax 								=   $form_state['values']['client_fax'];
			$client_terms_value 						=   $form_state['values']['client_terms_value'];
			$client_terms_amount 						=   $form_state['values']['client_terms_amount'];
			$client_receiving_agent 					=   $form_state['values']['client_receiving_agent'];
			$client_referring_agent 					=   $form_state['values']['client_referring_agent'];
			$client_receiving_date 						=   $form_state['values']['client_receiving_date'];
			$client_referring_date 						=   $form_state['values']['client_referring_date'];
			// -----///


	try{
	    
	    $result_referral = db_query("SELECT max(referral_id) as maxid_charity FROM Referral_Master ");
	    foreach($result_referral as $value){
	        $id_referral = $value->maxid_referral;
	    }
	    $newid_referral  =   $id_referral + 1;
	    
        $values_referral = array(
	    'referral_id'         							=>    $newid_referral,
	    'referral_type'       		  					=>    $referral_type	,
        'receiving_office_agent_name'				  	=>    $receiving_agent_name,
	    'receiving_office_firm_name'	  		      	=>	  $receiving_firm_name,
	    'receiving_office_address'	   			  		=>	  $receiving_address,
		'receiving_office_city'	   			  			=>	  $receiving_city_id,
		'receiving_office_state'	   			      	=>	  $receiving_state_id	,
		'receiving_office_zip'	   			     	  	=>	  $receiving_zip_code,
		'receiving_office_email_id'	   			      	=>	  $receiving_agent_email,
		'reveiving_office_business_phone'	   		  	=>	  $receiving_business_phone,
		'receiving_office_fax'	   			 		 	=>	  $receiving_fax,
		'referring_office_agent_name'	   			    =>	  $referring_agent_name,
		'referring_office_firm_name'	   			    =>	  $referring_firm_name,
		'referring_office_address'	   			  		=>	  $referring_address,
		'referring_office_city'	   	  					=>	  $referring_city_id,
		'referring_office_state'	   	  				=>    $referring_state_id
		'referring_office_zip'	   	  					=>	  $referring_zip_code,
		'referring_office_email_id'	   	  				=>	  $referring_agent_email,
		'referring_office_business_phone'	   	  		=>	  $referring_business_phone,
		'referring_office_fax'	   	  					=>	  $referring_fax,
		'client_name'	   	  							=>	  $client_name,
		'client_email'	   	  							=>	  $client_email,
		'client_address'	   	  						=>	  $client_address,
		'client_city'	   	  							=>	  $client_city_id,
		'client_state'	   	  							=>	  $client_state_id,
		'client_zip'	   	  							=>	  $client_zip_code,
		'client_business_phone'	   	 		 			=>	  $client_mobile,
		'client_fax'	   	  							=>	  $client_fax,
		'best_time_to_contact'	   	  					=>	  $client_best_time_to_contact,
		'client_terms_percent_value'	   	  			=>	  $client_terms_value,
		'client_terms_dollar_amount'	   	  			=>	  $client_terms_amount,
		'client_receiving_agent'	   	  				=>	  $client_receiving_agent,
		'client_referring_agent'	   	  				=>	  $client_referring_agent,
		'client_receiving_agent_sign_date'	   	  		=>	  $client_receiving_date,
		'client_referring_agent_sign_date'	   	  		=>	  $client_referring_date,
	    'created_timestamp'								=>    REQUEST_TIME,
	    'last_update_timestamp'           				=>    REQUEST_TIME,
	    );
        
	    db_insert('referral_Master')
	    ->fields($values_referral)
	    ->execute();

		drupal_set_message("New Referral Form Details Submitted Successfully");
	}
	catch(Exception $e)
	{
		drupal_set_message("New Referral Form Details could not be Inserted <br>" . $e, 'error');				
	}


	 $form_state['redirect'] = array(
		'c2s/referral/add',
	   array(
		'query' => array(
	   ),
	  ),
	 );	

				
// --------------------------------------------------------------------------------------------------

