<?php

// ==================================================================================================
//                   New Broker and Brokerage Information Submit
// ==================================================================================================
$agent_start_date	=   $form_state['values']['agent_start_date'];
$parent_id			    =   '2';
$broker = array();
$broker['relation_with_agent']  =   $form_state['values']['agent_relationship'];
$total_agents = 1;
if($broker['relation_with_agent'] != 0 || $broker['relation_with_agent'] != ""){
    $total_agents = 2;
}
for($i=1;$i<=$total_agents;$i++){
$broker[$i]['first_name']			=   $form_state['values']['agent_'.$i.'_first_name'];
$broker[$i]['middle_name']			=   $form_state['values']['agent_'.$i.'_middle_name'];
$broker[$i]['last_name']		    =   $form_state['values']['agent_'.$i.'_last_name'];

$broker[$i]['dob']				    =   $form_state['values']['date_of_birth_'.$i];
$broker[$i]['personal_email']		=   $form_state['values']['personl_email_id_'.$i];
$broker[$i]['personal_phone']		=   $form_state['values']['contact_number_'.$i];
$broker[$i]['home_address']			=   $form_state['values']['street_address_'.$i];
$broker[$i]['home_city']			=   $form_state['values']['city_id_'.$i];
$broker[$i]['home_state']			=   $form_state['values']['state_id_'.$i];
$broker[$i]['home_zip']			    =   $form_state['values']['zip_code_'.$i];
$broker[$i]['state_id_number']		=   $form_state['values']['agent_state_id_number_'.$i];
$broker[$i]['mls_username']			=   $form_state['values']['mls_username_'.$i];
$broker[$i]['mls_password']			=   $form_state['values']['mls_password_'.$i];
$broker[$i]['nrds_number']			=   $form_state['values']['agent_nrds_'.$i];
$broker[$i]['c2s_email_id']			=   $form_state['values']['create_email_'.$i];
$broker[$i]['office_phone']			=   $form_state['values']['office_phone_'.$i];
$broker[$i]['office_extension']		=   $form_state['values']['extension_'.$i];
$broker[$i]['choice_charity_orgid']	=   $form_state['values']['choice_of_charity_org_'.$i];
// -----///
$broker[$i]['pers_comm_accno']		=   $form_state['values']['personal_account_number_'.$i];
$broker[$i]['pers_comm_accname']	=   $form_state['values']['name_on_personal_account_'.$i];
$broker[$i]['pers_comm_bankname']	=   $form_state['values']['personal_financial_institution_name_'.$i];
$broker[$i]['pers_comm_bankphone']	=   $form_state['values']['personal_financial_institution_phone_'.$i];
$broker[$i]['pers_comm_acctype']	=   $form_state['values']['personal_account_type_'.$i];
$broker[$i]['pers_comm_aba_routing']=   $form_state['values']['personal_aba_routing_number_'.$i];
// --------- ///
$broker[$i]['beneficiary_first_name']	=   $form_state['values']['beneficiary_first_name_'.$i];
$broker[$i]['beneficiary_middle_name']  =   $form_state['values']['beneficiary_middle_name_'.$i];
$broker[$i]['beneficiary_last_name'] =   $form_state['values']['beneficiary_last_name_'.$i];
$broker[$i]['beneficiary_relation']  =   $form_state['values']['beneficiary_relarionship_'.$i];
$broker[$i]['beneficiary_email']     =   $form_state['values']['beneficiary_email_id_'.$i];
$broker[$i]['beneficiary_contact']	 =   $form_state['values']['beneficiary_contact_number_'.$i];
$broker[$i]['beneficiary_address']	 =   $form_state['values']['beneficiary_address_'.$i];
$broker[$i]['beneficiary_city']		 =   $form_state['values']['beneficiary_city_id_'.$i];
$broker[$i]['beneficiary_state']	 =   $form_state['values']['beneficiary_state_id_'.$i];
$broker[$i]['beneficiary_zip']		 =   $form_state['values']['beneficiary_zip_code_'.$i];
}



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
            for($i=1;$i<=$total_agents;$i++){
            $fields = array(
              'name' => $broker[$i]['c2s_email_id'],
              'mail' => $broker[$i]['c2s_email_id'].'@city2shore.com',
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
        for($i=1;$i<=$total_agents;$i++){

		$db_last_insert_id = db_insert('broker_master')
		   ->fields([       
		                    'parent_id'           =>    $parent_id,
		                    'user_id'             =>    $account->uid,
		                    'type'                =>    'A',
		                    'agent_relationship'  =>    $relation,
		                    'related_agent_id'    =>    $relation_agent_id,
		                    'agent_start_date'    =>    $agent_start_date, 
							'first_name'      	  =>    $broker[$i]['first_name'],
							'middle_name'		  =>	$broker[$i]['middle_name'],
							'last_name'			  =>	$broker[$i]['last_name'],
							'dob'				  =>	$broker[$i]['dob'],
							'personal_email'	  =>	$broker[$i]['personal_email'],
							'personal_phone'	  =>	$broker[$i]['personal_phone'],
							'home_address'		  =>	$broker[$i]['home_address'],
							'home_city'			  =>	$broker[$i]['home_city'],
		                    'home_state'      	  =>    $broker[$i]['home_state'],
		                    'home_zip'			  =>	$broker[$i]['home_zip'],
		                    'state_id_number'	  =>	$broker[$i]['state_id_number'],
		                    'mls_username'		  =>	$broker[$i]['mls_username'],
		                    'mls_password'		  =>	$broker[$i]['mls_password'],
		                    'nrds_number'      	  =>    $broker[$i]['nrds_number'],
		                    'ein_number'      	  =>    $broker[$i]['nrds_number'],
		                    'c2s_email_id'		  =>	$broker[$i]['c2s_email_id'],
		                    'office_phone'		  =>	$broker[$i]['office_phone'],
		                    'office_extension'	  =>	$broker[$i]['office_extension'],
		                    'pers_comm_accno'	  =>	$broker[$i]['pers_comm_accno'],
		                    'pers_comm_accname'	  =>	$broker[$i]['pers_comm_accname'],
		                    'pers_comm_bankname'  =>	$broker[$i]['pers_comm_bankname'],
		                    'pers_comm_bankphone' =>	$broker[$i]['pers_comm_bankphone'],
		                    'pers_comm_acctype'	  =>	$broker[$i]['pers_comm_acctype'],
		                    'pers_comm_aba_routing'				=>	$broker[$i]['pers_comm_aba_routing'],
		                    'choice_charity_orgid'				=>	$broker[$i]['choice_charity_orgid'], 
		       'beneficiary_first_name'      		=>  $broker[$i]['beneficiary_first_name'],
		       'beneficiary_middle_name'           =>  $broker[$i]['beneficiary_middle_name'],
		       'beneficiary_last_name'             =>  $broker[$i]['beneficiary_last_name'],
		       'beneficiary_relationship'          =>  $broker[$i]['beneficiary_relation'],
		       'beneficiary_email_id'              =>  $broker[$i]['beneficiary_email'],
		       'beneficiary_contact_number'        =>  $broker[$i]['beneficiary_contact'],
		       'beneficiary_address'           	=>  $broker[$i]['beneficiary_address'],
		       'beneficiary_city_id'            	=>  $broker[$i]['beneficiary_city'],
		       'beneficiary_state_id'            	=>  $broker[$i]['beneficiary_state'],
		       'beneficiary_zip_code'           	=>  $broker[$i]['beneficiary_zip'],
							'created'         	  =>    REQUEST_TIME,
							'changed'         	  =>    REQUEST_TIME,
                                                        ])
			  ->execute();
		      if($total_agents == 2 && $i == 1){
		          $relation = $broker['relation_with_agent'];
		          $relation_agent_id = $db_last_insert_id;
		      }
            }
				drupal_set_message("New Agent Details Submitted Successfully");
	}
	catch(Exception $e)
	{
		drupal_set_message("New Agent Details could not be Inserted <br>" . $e, 'error');				
	}


	 $form_state['redirect'] = array(
	  'c2s/agent/view/'.$relation_agent_id,
	   array(
		'query' => array(
	   ),
	  ),
	 );	

				
// --------------------------------------------------------------------------------------------------

