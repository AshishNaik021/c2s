<?php

// ==================================================================================================
//                   New Broker and Brokerage Information Submit
// ==================================================================================================

	$total_broker_owners			=   $form_state['values']['broker_owners'];
	$brokerage_start_date			=   $form_state['values']['names_fieldset']['brokerage_start_date'];
	$brokerage_name					=   $form_state['values']['names_fieldset']['brokerage_name'];
	$franchise_fee_cap				=   substr($form_state['values']['names_fieldset']['franchise_fee_cap'],1);
	$reap_amount_cap				=   substr($form_state['values']['names_fieldset']['reap_amount_cap'],1);
	$transaction_management_fee		=   substr($form_state['values']['names_fieldset']['transaction_management_fee'],1);

	try{
		//--------------------------------------------------------------------------//
		// 				Add single record of Brokerage company.
		//--------------------------------------------------------------------------//
        $values_brokerage = array(
			'brokerage_name'       			=>  $brokerage_name,
			'brokerage_start_date' 			=> 	$brokerage_start_date,
			'franchise_fee_cap'	   			=>	$franchise_fee_cap,
			'reap_amount_cap'	   			=>	$reap_amount_cap,
			'transaction_management_fees'	=>	$transaction_management_fee,
			'number_of_owners'				=>	$total_broker_owners,
			'created'         	   			=>  REQUEST_TIME,
	    );
        
	    db_insert('c2s_brokerage_details')
			->fields($values_brokerage)
			->execute();
			drupal_set_message("New Brokerage Company Details Successfully Inserted! ");				
	}
	catch(Exception $e)
	{
		drupal_set_message("New Brokerage Company Details could not be Inserted <br><br>" . $e, 'error');				
	}
//=========================================================================================================================

	try{
		//--------------------------------------------------------------------------//
		// 	Add multiple records of Required Paperwork for each Brokerage company.
		//--------------------------------------------------------------------------//
		
		$result = db_query("SELECT max(brokerage_id) as max_brokerage_id FROM c2s_brokerage_details ORDER BY 1");
		foreach($result as $value){
			$brokerage_id	=	$value->max_brokerage_id;
		}

		$selected_paperwork = $form_state['values']['names_fieldset']['brokerage_paperwork'];
		foreach($selected_paperwork as $key => $pw_value){
			if($pw_value > 0){ 
				// 0 Value means that element was not selected. 
				// If the element is selected, it's value is actually the Key value of Checkboxes array. 
				$values_paperwork = array(
					'brokerage_id'       			=>  $brokerage_id,
					'paperwork_id' 					=> 	$pw_value,
					'created'         	   			=>  REQUEST_TIME,
				);
				db_insert('c2s_brokerage_paperwork')
				->fields($values_paperwork)
				->execute();
			}
		}
		drupal_set_message("Required Paperwork for this Brokerage Company is Successfully Inserted!");
	}
	catch(Exception $e)
	{
		drupal_set_message("Paperwork for this Brokerage Company could not be Inserted. <br><br>" . $e, 'error');				
	}

	


//=========================================================================================================================
	

	for($i=1; $i<=$total_broker_owners; $i++){

		try{

				//---------------  Personal Details  --------------//
				$first_name				=   $form_state['values']['names_fieldset']['broker_'.$i.'_first_name'];
				$middle_name			=   $form_state['values']['names_fieldset']['broker_'.$i.'_middle_name'];
				$last_name			    =   $form_state['values']['names_fieldset']['broker_'.$i.'_last_name'];
				$dob				    =   $form_state['values']['names_fieldset']['date_of_birth_'.$i];
				$personal_email			=   $form_state['values']['names_fieldset']['personl_email_id_'.$i];
				$personal_phone			=   $form_state['values']['names_fieldset']['contact_number_'.$i];
				$home_address			=   $form_state['values']['names_fieldset']['street_address_'.$i];
				$home_city				=   $form_state['values']['names_fieldset']['city_'.$i];
				$home_state				=   $form_state['values']['names_fieldset']['state_id_'.$i];
				$home_zip			    =   $form_state['values']['names_fieldset']['zip_code_'.$i];
				$business_address		=   $form_state['values']['names_fieldset']['busines_street_address_'.$i];
				$business_city			=   $form_state['values']['names_fieldset']['business_city_id_'.$i];
				$business_state			=   $form_state['values']['names_fieldset']['business_state_id_'.$i];
				$business_zip			=   $form_state['values']['names_fieldset']['business_zip_code_'.$i];
				$state_id_number		=   $form_state['values']['names_fieldset']['broker_state_id_number_'.$i];
				$ein_number				=   $form_state['values']['names_fieldset']['broker_ein_'.$i];
				$mls_username			=   $form_state['values']['names_fieldset']['mls_username_'.$i];
				$mls_password			=   $form_state['values']['names_fieldset']['mls_password_'.$i];
				$nrds_number			=   $form_state['values']['names_fieldset']['broker_nrds_'.$i];
				$c2s_email_id			=   $form_state['values']['names_fieldset']['create_email_'.$i];
				$office_phone			=   $form_state['values']['names_fieldset']['office_phone_'.$i];
				$office_extension		=   $form_state['values']['names_fieldset']['extension_'.$i];
				//---------------  Banking Details  --------------//
				$comm_reap_accno		=   $form_state['values']['names_fieldset']['comm_account_number_'.$i];
				$comm_reap_accname		=   $form_state['values']['names_fieldset']['name_on_comm_account_'.$i];
				$comm_reap_bankphone	=   $form_state['values']['names_fieldset']['comm_financial_institution_phone_'.$i];
				$comm_reap_bankname		=   $form_state['values']['names_fieldset']['comm_financial_institution_name_'.$i];
				$comm_reap_acctype		=   $form_state['values']['names_fieldset']['comm_account_type_'.$i];
				$comm_reap_aba_routing	=   $form_state['values']['names_fieldset']['comm_aba_routing_number_'.$i];
				$pers_comm_accno		=   $form_state['values']['names_fieldset']['personal_account_number_'.$i];
				$pers_comm_accname		=   $form_state['values']['names_fieldset']['name_on_personal_account_'.$i];
				$pers_comm_bankname		=   $form_state['values']['names_fieldset']['personal_financial_institution_name_'.$i];
				$pers_comm_bankphone	=   $form_state['values']['names_fieldset']['personal_financial_institution_phone_'.$i];
				$pers_comm_acctype		=   $form_state['values']['names_fieldset']['personal_account_type_'.$i];
				$pers_comm_aba_routing	=   $form_state['values']['names_fieldset']['personal_aba_routing_number_'.$i];
				$choice_charity_orgid	=   $form_state['values']['names_fieldset']['choice_of_charity_org_'.$i];
				//---------------  Beneficiary Details  --------------//
				$beneficiary_first_name	=   $form_state['values']['names_fieldset']['beneficiary_first_name_'.$i];
				$beneficiary_middle_name=   $form_state['values']['names_fieldset']['beneficiary_middle_name_'.$i];
				$beneficiary_last_name  =   $form_state['values']['names_fieldset']['beneficiary_last_name_'.$i];
				$beneficiary_relation   =   $form_state['values']['names_fieldset']['beneficiary_relarionship_'.$i];
				$beneficiary_email      =   $form_state['values']['names_fieldset']['beneficiary_email_id_'.$i];
				$beneficiary_contact	=   $form_state['values']['names_fieldset']['beneficiary_contact_number_'.$i];
				$beneficiary_address	=   $form_state['values']['names_fieldset']['beneficiary_address_'.$i];
				$beneficiary_city		=   $form_state['values']['names_fieldset']['beneficiary_city_id_'.$i];
				$beneficiary_state		=   $form_state['values']['names_fieldset']['beneficiary_state_id_'.$i];
				$beneficiary_zip		=   $form_state['values']['names_fieldset']['beneficiary_zip_code_'.$i];

	
		//--------------------------------------------------------------------------//
		// 				Add Multiple records of Broker Owners.
		// 		First add records in User Table and then in Broker Table. 
		//--------------------------------------------------------------------------//
				
			// =========   Save in USER Table ================
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


			//================  Save in Broker Table  ==========================
			
			db_insert('c2s_broker_master')
			->fields(array(
					'user_id'             		=>  $account->uid,
					'type'                		=>  'B',
                    'brokerage_id'              =>  $brokerage_id,
					'first_name'      	  		=>  $first_name,
					'middle_name'		  		=>	$middle_name,
					'last_name'			  		=>	$last_name,
					'dob'				  		=>	$dob,
					'personal_email'	  		=>	$personal_email,
					'personal_phone'	  		=>	$personal_phone,
					'home_address'		  		=>	$home_address,
					'home_city'			  		=>	$home_city,
					'home_state'      	  		=>  $home_state,
					'home_zip'			  		=>	$home_zip,
					'business_address'	  		=>	$business_address,
					'business_city'		  		=>	$business_city,
					'business_state'	  		=>	$business_state,
					'business_zip'		  		=>	$business_zip,
					'state_id_number'	  		=>	$state_id_number,
					'ein_number'		  		=>	$ein_number,
					'mls_username'		  		=>	$mls_username,
					'mls_password'		  		=>	$mls_password,
					'nrds_number'      	  		=>  $nrds_number,
					'c2s_email_id'		  		=>	$c2s_email_id,
					'office_phone'		  		=>	$office_phone,
					'office_extension'	  		=>	$office_extension,
					'comm_reap_accno'	  		=>	$comm_reap_accno,
					'comm_reap_accname'	  		=>	$comm_reap_accname,
					'comm_reap_bankname'  		=>	$comm_reap_bankname,
					'comm_reap_bankphone' 		=>	$comm_reap_bankphone,
					'comm_reap_acctype'	  		=>	$comm_reap_acctype,
					'comm_reap_aba_routing'		=>	$comm_reap_aba_routing,
					'pers_comm_accno'	  		=>	$pers_comm_accno,
					'pers_comm_accname'	  		=>	$pers_comm_accname,
					'pers_comm_bankname'  		=>	$pers_comm_bankname,
					'pers_comm_bankphone' 		=>	$pers_comm_bankphone,
					'pers_comm_acctype'	  		=>	$pers_comm_acctype,
					'pers_comm_aba_routing'		=>	$pers_comm_aba_routing,
					'choice_charity_orgid'		=>	$choice_charity_orgid,
					'beneficiary_first_name'    =>  $beneficiary_first_name,
					'beneficiary_middle_name'   =>  $beneficiary_middle_name,
					'beneficiary_last_name'     =>  $beneficiary_last_name,
					'beneficiary_relationship'  =>  $beneficiary_relation,
					'beneficiary_email_id'      =>  $beneficiary_email,
					'beneficiary_contact_number'=>  $beneficiary_contact,
					'beneficiary_address'       =>  $beneficiary_address,
					'beneficiary_city'       	=>  $beneficiary_city,
					'beneficiary_state'      	=>  $beneficiary_state,
					'beneficiary_zip'      		=>  $beneficiary_zip,	 
					'status'					=> 'A',
					'created'         	  		=>  REQUEST_TIME,
				))
				->execute();
				drupal_set_message("New Broker Details for <b>".$first_name." ".$last_name."</b> Submitted Successfully");
			}
			catch(Exception $e)
			{
				drupal_set_message("New Broker Details for <b>".$first_name." ".$last_name."</b> could not be Inserted <br><br>" . $e, 'error');				
			}
	} // End of For Loop
	

	 $form_state['redirect'] = array(
	  'c2s/broker/view/'.$brokerage_id,
	   array(
		'query' => array(
	   ),
	  ),
	 );	

				
// --------------------------------------------------------------------------------------------------

