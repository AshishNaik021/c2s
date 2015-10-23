<?php

// ==================================================================================================
//                   New Agent Information Submit
// ==================================================================================================
$agent_start_date	=   $form_state['values']['agent_start_date'];
$parent_id			=   $form_state['values']['parent_id'];
drupal_set_message("parent_id = ".$parent_id);

$agent = array();
$agent['relation_with_agent']  =   $form_state['values']['agent_relationship'];
$total_agents = 1;
if($agent['relation_with_agent'] != 0 || $agent['relation_with_agent'] != ""){
    $total_agents = 2;
}
for($i=1;$i<=$total_agents;$i++){
	$agent[$i]['first_name']			=   $form_state['values']['agent_'.$i.'_first_name'];
	$agent[$i]['middle_name']			=   $form_state['values']['agent_'.$i.'_middle_name'];
	$agent[$i]['last_name']		    	=   $form_state['values']['agent_'.$i.'_last_name'];

	$agent[$i]['dob']				    =   $form_state['values']['date_of_birth_'.$i];
	$agent[$i]['personal_email']		=   $form_state['values']['personl_email_id_'.$i];
	$agent[$i]['personal_phone']		=   $form_state['values']['contact_number_'.$i];
	$agent[$i]['home_address']			=   $form_state['values']['street_address_'.$i];
	$agent[$i]['home_city']				=   $form_state['values']['city_id_'.$i];
	$agent[$i]['home_state']			=   $form_state['values']['state_id_'.$i];
	$agent[$i]['home_zip']			    =   $form_state['values']['zip_code_'.$i];
	$agent[$i]['state_id_number']		=   $form_state['values']['agent_state_id_number_'.$i];
	$agent[$i]['mls_username']			=   $form_state['values']['mls_username_'.$i];
	$agent[$i]['mls_password']			=   $form_state['values']['mls_password_'.$i];
	$agent[$i]['nrds_number']			=   $form_state['values']['agent_nrds_'.$i];
	$agent[$i]['c2s_email_id']			=   $form_state['values']['create_email_'.$i];
	$agent[$i]['office_phone']			=   $form_state['values']['office_phone_'.$i];
	$agent[$i]['office_extension']		=   $form_state['values']['extension_'.$i];
	$agent[$i]['choice_charity_orgid']	=   $form_state['values']['choice_of_charity_org_'.$i];
	// -----///
	$agent[$i]['pers_comm_accno']		=   $form_state['values']['personal_account_number_'.$i];
	$agent[$i]['pers_comm_accname']		=   $form_state['values']['name_on_personal_account_'.$i];
	$agent[$i]['pers_comm_bankname']	=   $form_state['values']['personal_financial_institution_name_'.$i];
	$agent[$i]['pers_comm_bankphone']	=   $form_state['values']['personal_financial_institution_phone_'.$i];
	$agent[$i]['pers_comm_acctype']		=   $form_state['values']['personal_account_type_'.$i];
	$agent[$i]['pers_comm_aba_routing']	=   $form_state['values']['personal_aba_routing_number_'.$i];
	// --------- ///
	$agent[$i]['beneficiary_first_name']	=   $form_state['values']['beneficiary_first_name_'.$i];
	$agent[$i]['beneficiary_middle_name']  	=   $form_state['values']['beneficiary_middle_name_'.$i];
	$agent[$i]['beneficiary_last_name'] 	=   $form_state['values']['beneficiary_last_name_'.$i];
	$agent[$i]['beneficiary_relation']  	=   $form_state['values']['beneficiary_relarionship_'.$i];
	$agent[$i]['beneficiary_email']     	=   $form_state['values']['beneficiary_email_id_'.$i];
	$agent[$i]['beneficiary_contact']	 	=   $form_state['values']['beneficiary_contact_number_'.$i];
	$agent[$i]['beneficiary_address']	 	=   $form_state['values']['beneficiary_address_'.$i];
	$agent[$i]['beneficiary_city']		 	=   $form_state['values']['beneficiary_city_id_'.$i];
	$agent[$i]['beneficiary_state']	 		=   $form_state['values']['beneficiary_state_id_'.$i];
	$agent[$i]['beneficiary_zip']		 	=   $form_state['values']['beneficiary_zip_code_'.$i];
}



	try{
	      //This will generate a random password, you could set your own here
            $password = md5('city2shore@123');
            
            //set up the user fields
            for($i=1;$i<=$total_agents;$i++){
				$fields = array(
				  'name' => $agent[$i]['c2s_email_id'],
				  'mail' => $agent[$i]['c2s_email_id'].'@city2shore.com',
				  'pass' => $password,
				  'status' => 1,
				  'init' => 'email address',
				  'roles' => array(
					DRUPAL_AUTHENTICATED_RID => 'authenticated user',
					),
				);
 
				//the first parameter is left blank so a new user is created
				$account = user_save('', $fields);
            }
            // If you want to send the welcome email, use the following code
 
            // Manually set the password so it appears in the e-mail.
			//  $account->password = $fields['pass'];
               
	// Send the e-mail through the user module.
	//  drupal_mail('user', 'register_no_approval_required', $email, NULL, array('account' => $account), variable_get('site_mail', 'noreply@example..com'));
            
		$relation = "";
		$relation_agent_id = 0;            
		$max_broker_agent_id = 0;
        for($i=1;$i<=$total_agents;$i++){
			$agent_values = array(
				'parent_id'           =>    $parent_id,
				'user_id'             =>    $account->uid,
				'type'                =>    'A',
				'agent_relationship'  =>    $relation,
				'related_agent_id'    =>    $relation_agent_id,
				'agent_start_date'    =>    $agent_start_date, 
				'first_name'      	  =>    $agent[$i]['first_name'],
				'middle_name'		  =>	$agent[$i]['middle_name'],
				'last_name'			  =>	$agent[$i]['last_name'],
				'dob'				  =>	$agent[$i]['dob'],
				'personal_email'	  =>	$agent[$i]['personal_email'],
				'personal_phone'	  =>	$agent[$i]['personal_phone'],
				'home_address'		  =>	$agent[$i]['home_address'],
				'home_city'			  =>	$agent[$i]['home_city'],
				'home_state'      	  =>    $agent[$i]['home_state'],
				'home_zip'			  =>	$agent[$i]['home_zip'],
				'state_id_number'	  =>	$agent[$i]['state_id_number'],
				'mls_username'		  =>	$agent[$i]['mls_username'],
				'mls_password'		  =>	$agent[$i]['mls_password'],
				'nrds_number'      	  =>    $agent[$i]['nrds_number'],
				'ein_number'      	  =>    $agent[$i]['nrds_number'],
				'c2s_email_id'		  =>	$agent[$i]['c2s_email_id'],
				'office_phone'		  =>	$agent[$i]['office_phone'],
				'office_extension'	  =>	$agent[$i]['office_extension'],
				'pers_comm_accno'	  =>	$agent[$i]['pers_comm_accno'],
				'pers_comm_accname'	  =>	$agent[$i]['pers_comm_accname'],
				'pers_comm_bankname'  =>	$agent[$i]['pers_comm_bankname'],
				'pers_comm_bankphone' =>	$agent[$i]['pers_comm_bankphone'],
				'pers_comm_acctype'	  =>	$agent[$i]['pers_comm_acctype'],
				'pers_comm_aba_routing'			=>	$agent[$i]['pers_comm_aba_routing'],
				'choice_charity_orgid'			=>	$agent[$i]['choice_charity_orgid'], 
				'beneficiary_first_name'      	=>  $agent[$i]['beneficiary_first_name'],
				'beneficiary_middle_name'       =>  $agent[$i]['beneficiary_middle_name'],
				'beneficiary_last_name'         =>  $agent[$i]['beneficiary_last_name'],
				'beneficiary_relationship'      =>  $agent[$i]['beneficiary_relation'],
				'beneficiary_email_id'          =>  $agent[$i]['beneficiary_email'],
				'beneficiary_contact_number'    =>  $agent[$i]['beneficiary_contact'],
				'beneficiary_address'           =>  $agent[$i]['beneficiary_address'],
				'beneficiary_city'            	=>  $agent[$i]['beneficiary_city'],
				'beneficiary_state'            	=>  $agent[$i]['beneficiary_state'],
				'beneficiary_zip'           	=>  $agent[$i]['beneficiary_zip'],
				'created'         	  =>    REQUEST_TIME,
			);
			db_insert('c2s_agent_master')
				->fields($agent_values)
				->execute();
				
		    if($total_agents == 2 && $i == 1){
				$result  = db_query("SELECT max(broker_agent_id) as max_broker_agent_id FROM c2s_broker_master");
				foreach($result as $record){
					$max_broker_agent_id = $record->max_broker_agent_id;
				}
				$relation 			= $agent['relation_with_agent'];
				$relation_agent_id 	= $max_broker_agent_id;
		    }
			drupal_set_message("New Agent Details Submitted Successfully = ".$max_broker_agent_id);
            }
	}
	catch(Exception $e)
	{
		drupal_set_message("New Agent Details could not be Inserted <br>" . $e, 'error');				
	}

    if($relation_agent_id != 0){
		$redirect_id = $relation_agent_id;
	}else{
		$redirect_id = $max_broker_agent_id;
	}
	
	$form_state['redirect'] = array(
	  'c2s/agent/view/'.$redirect_id,
	   array(
		'query' => array(
	   ),
	  ),
	 );	

				
// --------------------------------------------------------------------------------------------------

