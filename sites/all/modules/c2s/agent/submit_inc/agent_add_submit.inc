<?php

// ==================================================================================================
//                   New Broker and Brokerage Information Submit
// ==================================================================================================
$brokerage_start_date	=   $form_state['values']['agent_start_date'];
$parent_id			    =   '2';

$first_name				=   $form_state['values']['agent_first_name'];
$middle_name			=   $form_state['values']['agent_middle_name'];
$last_name			    =   $form_state['values']['agent_last_name'];
$dob				    =   $form_state['values']['date_of_birth'];
$personal_email			=   $form_state['values']['personl_email_id'];
$personal_phone			=   $form_state['values']['contact_number'];
$home_address			=   $form_state['values']['street_address'];
$home_city				=   $form_state['values']['city_id'];
$home_state				=   $form_state['values']['state_id'];
$home_zip			    =   $form_state['values']['zip_code'];
$state_id_number		=   $form_state['values']['agent_state_id'];
$mls_username			=   $form_state['values']['mls_username'];
$mls_password			=   $form_state['values']['mls_password'];
$nrds_number			=   $form_state['values']['agent_nrds'];
$c2s_email_id			=   $form_state['values']['create_email'];
$office_phone			=   $form_state['values']['office_phone'];
$office_extension		=   $form_state['values']['extension'];
$choice_charity_orgid	=   $form_state['values']['choice_of_charity_org'];
// -----///
$pers_comm_accno		=   $form_state['values']['personal_account_number'];
$pers_comm_accname		=   $form_state['values']['name_on_personal_account'];
$pers_comm_bankname		=   $form_state['values']['personal_financial_institution_name'];
$pers_comm_bankphone	=   $form_state['values']['personal_financial_institution_phone'];
$pers_comm_acctype		=   $form_state['values']['personal_account_type'];
$pers_comm_aba_routing	=   $form_state['values']['personal_aba_routing_number'];




	try{
	    /*
	    $result_brokerage = db_query("SELECT max(brokerage_id) as maxid_brokerage FROM brokerage_details ");
	    foreach($result_brokerage as $value){
	        $id_brokerage = $value->maxid_brokerage;
	    }
	    $newid_brokerage  =   $id_brokerage + 1;
	    
        $values_brokerage = array(
	    'brokerage_id'         =>   $newid_brokerage,
	    'brokerage_name'       =>   $brokerage_name,
        '$brokerage_start_date'=> $brokerage_start_date,
	    'number_of_owners'	   =>	$number_of_owners,
	    'franchise_fee_cap'	   =>	$franchise_fee_cap,
	    'reap_amount_cap'	   =>	$reap_amount_cap,
	    'created'         	   =>   REQUEST_TIME,
	    'changed'         	   =>   REQUEST_TIME,
	    );
        
	    db_insert('brokerage_details')
	    ->fields($values_brokerage)
	    ->execute();
        */
	      //This will generate a random password, you could set your own here
            $password = md5('city2shore@123');
 
            //set up the user fields
            $fields = array(
              'name' => $c2s_email_id,
              'mail' => $c2s_email_id.'@city2shore.com',
              'pass' => $password,
              'status' => 1,
              'init' => 'email address',
              'roles' => array(
                DRUPAL_AUTHENTICATED_RID => 'authenticated user',
              ),
            );
 
            //the first parameter is left blank so a new user is created
            $account = user_save('', $fields);
 
            // If you want to send the welcome email, use the following code
 
            // Manually set the password so it appears in the e-mail.
            $account->password = $fields['pass'];
               
  // Send the e-mail through the user module.
//  drupal_mail('user', 'register_no_approval_required', $email, NULL, array('account' => $account), variable_get('site_mail', 'noreply@example..com'));
            
            
	    $result = db_query("SELECT max(broker_id) as maxid FROM broker_master ");
		foreach($result as $value){
			$id = $value->maxid;
		}
		$newid  =   $id + 1;
	
		db_insert('broker_master')
		   ->fields([       'broker_id'           =>    $newid,
		                    'parent_id'           =>    $parent_id,
		                    'user_id'             =>    $account->uid,
		                    'type'                =>    'A',
							'first_name'      	  =>    $first_name,
							'middle_name'		  =>	$middle_name,
							'last_name'			  =>	$last_name,
							'dob'				  =>	$dob,
							'personal_email'	  =>	$personal_email,
							'personal_phone'	  =>	$personal_phone,
							'home_address'		  =>	$home_address,
							'home_city'			  =>	$home_city,
		                    'home_state'      	  =>    $home_state,
		                    'home_zip'			  =>	$home_zip,
		                    'state_id_number'	  =>	$state_id_number,
		                    'mls_username'		  =>	$mls_username,
		                    'mls_password'		  =>	$mls_password,
		                    'nrds_number'      	  =>    $nrds_number,
		                    'c2s_email_id'		  =>	$c2s_email_id,
		                    'office_phone'		  =>	$office_phone,
		                    'office_extension'	  =>	$office_extension,
		                    'pers_comm_accno'	  =>	$pers_comm_accno,
		                    'pers_comm_accname'	  =>	$pers_comm_accname,
		                    'pers_comm_bankname'  =>	$pers_comm_bankname,
		                    'pers_comm_bankphone' =>	$pers_comm_bankphone,
		                    'pers_comm_acctype'	  =>	$pers_comm_acctype,
		                    'pers_comm_aba_routing'				=>	$pers_comm_aba_routing,
		                    'choice_charity_orgid'				=>	$choice_charity_orgid,    
							'created'         	  =>    REQUEST_TIME,
							'changed'         	  =>    REQUEST_TIME,
                                                        ])
			  ->execute();
				drupal_set_message("New Agent Details Submitted Successfully");
	}
	catch(Exception $e)
	{
		drupal_set_message("New Agent Details could not be Inserted <br>" . $e, 'error');				
	}


	 $form_state['redirect'] = array(
	  'c2s/agent/view',
	   array(
		'query' => array(
	   ),
	  ),
	 );	

				
// --------------------------------------------------------------------------------------------------

