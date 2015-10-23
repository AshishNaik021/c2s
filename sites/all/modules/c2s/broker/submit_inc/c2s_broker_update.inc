<?php

// ==================================================================================================
//                   Deactivate Broker 
// ==================================================================================================
$broker_id = $form_state['input']['broker_id'];

$first_name				=   $form_state['input']['broker_'.$broker_id.'_first_name'];
$middle_name			=   $form_state['input']['broker_'.$broker_id.'_middle_name'];
$last_name			    =   $form_state['input']['broker_'.$broker_id.'_last_name'];
$dob				    =   date('Y-m-d',strtotime($form_state['input']['date_of_birth_'.$broker_id]['date']));
$personal_email			=   $form_state['input']['personl_email_id_'.$broker_id];
$personal_phone			=   $form_state['input']['contact_number_'.$broker_id];
$home_address			=   $form_state['input']['street_address_'.$broker_id];
$home_city				=   $form_state['input']['city_id_'.$broker_id];
$home_state				=   $form_state['input']['state_id_'.$broker_id];
$home_zip			    =   $form_state['input']['zip_code_'.$broker_id];
$business_address		=   $form_state['input']['busines_street_address_'.$broker_id];
$business_city			=   $form_state['input']['business_city_id_'.$broker_id];
$business_state			=   $form_state['input']['business_state_id_'.$broker_id];
$business_zip			=   $form_state['input']['business_zip_code_'.$broker_id];
$state_id_number		=   $form_state['input']['broker_state_id_number_'.$broker_id];
$ein_number				=   $form_state['input']['broker_ein_'.$broker_id];
$mls_username			=   $form_state['input']['mls_username_'.$broker_id];
$mls_password			=   $form_state['input']['mls_password_'.$broker_id];
$nrds_number			=   $form_state['input']['broker_nrds_'.$broker_id];
$c2s_email_id			=   $form_state['input']['create_email_'.$broker_id];
$office_phone			=   $form_state['input']['office_phone_'.$broker_id];
$office_extension		=   $form_state['input']['extension_'.$broker_id];
// -----///
$comm_reap_accno		=   $form_state['input']['comm_account_number_'.$broker_id];
$comm_reap_accname		=   $form_state['input']['name_on_comm_account_'.$broker_id];
$comm_reap_bankphone	=   $form_state['input']['comm_financial_institution_phone_'.$broker_id];
$comm_reap_bankname		=   $form_state['input']['comm_financial_institution_name_'.$broker_id];
$comm_reap_acctype		=   $form_state['input']['comm_account_type_'.$broker_id];
$comm_reap_aba_routing	=   $form_state['input']['comm_aba_routing_number_'.$broker_id];
$pers_comm_accno		=   $form_state['input']['personal_account_number_'.$broker_id];
$pers_comm_accname		=   $form_state['input']['name_on_personal_account_'.$broker_id];
$pers_comm_bankname		=   $form_state['input']['personal_financial_institution_name_'.$broker_id];
$pers_comm_bankphone	=   $form_state['input']['personal_financial_institution_phone_'.$broker_id];
$pers_comm_acctype		=   $form_state['input']['personal_account_type_'.$broker_id];
$pers_comm_aba_routing	=   $form_state['input']['personal_aba_routing_number_'.$broker_id];
$choice_charity_orgid	=   $form_state['input']['choice_of_charity_org_'.$broker_id];
// ----- beneficiary --- //
$beneficiary_first_name	=   $form_state['input']['beneficiary_first_name_'.$broker_id];
$beneficiary_middle_name=   $form_state['input']['beneficiary_middle_name_'.$broker_id];
$beneficiary_last_name  =   $form_state['input']['beneficiary_last_name_'.$broker_id];
$beneficiary_relation   =   $form_state['input']['beneficiary_relarionship_'.$broker_id];
$beneficiary_email      =   $form_state['input']['beneficiary_email_id_'.$broker_id];
$beneficiary_contact	=   $form_state['input']['beneficiary_contact_number_'.$broker_id];
$beneficiary_address	=   $form_state['input']['beneficiary_address_'.$broker_id];
$beneficiary_city		=   $form_state['input']['beneficiary_city_id_'.$broker_id];
$beneficiary_state		=   $form_state['input']['beneficiary_state_id_'.$broker_id];
$beneficiary_zip		=   $form_state['input']['beneficiary_zip_code_'.$broker_id];

try{
    $id = arg(3);

   
    db_update('c2s_broker_master')
    ->fields(array(

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
		                    'business_address'	  =>	$business_address,
		                    'business_city'		  =>	$business_city,
		                    'business_state'	  =>	$business_state,
		                    'business_zip'		  =>	$business_zip,
		                    'state_id_number'	  =>	$state_id_number,
		                    'ein_number'		  =>	$ein_number,
		                    'mls_username'		  =>	$mls_username,
		                    'mls_password'		  =>	$mls_password,
		                    'nrds_number'      	  =>    $nrds_number,
		                    'c2s_email_id'		  =>	$c2s_email_id,
		                    'office_phone'		  =>	$office_phone,
		                    'office_extension'	  =>	$office_extension,
		                    'comm_reap_accno'	  =>	$comm_reap_accno,
		                    'comm_reap_accname'	  =>	$comm_reap_accname,
		                    'comm_reap_bankname'  =>	$comm_reap_bankname,
		                    'comm_reap_bankphone' =>	$comm_reap_bankphone,
		                    'comm_reap_acctype'	  =>	$comm_reap_acctype,
		                    'comm_reap_aba_routing'				=>	$comm_reap_aba_routing,
		                    'pers_comm_accno'	  =>	$pers_comm_accno,
		                    'pers_comm_accname'	  =>	$pers_comm_accname,
		                    'pers_comm_bankname'  =>	$pers_comm_bankname,
		                    'pers_comm_bankphone' =>	$pers_comm_bankphone,
		                    'pers_comm_acctype'	  =>	$pers_comm_acctype,
		                    'pers_comm_aba_routing'				=>	$pers_comm_aba_routing,
		                    'choice_charity_orgid'				=>	$choice_charity_orgid,
                            'beneficiary_first_name'      		=>  $beneficiary_first_name,
                            'beneficiary_middle_name'           =>  $beneficiary_middle_name,
                            'beneficiary_last_name'             =>  $beneficiary_last_name,
                            'beneficiary_relationship'          =>  $beneficiary_relation,
                            'beneficiary_email_id'              =>  $beneficiary_email,
                            'beneficiary_contact_number'        =>  $beneficiary_contact,
                            'beneficiary_address'           	=>  $beneficiary_address,
                            'beneficiary_city'            	=>  $beneficiary_city,
                            'beneficiary_state'            	=>  $beneficiary_state,
                            'beneficiary_zip'           	=>  $beneficiary_zip,	
    ))
    ->condition('broker_agent_id', $broker_id, '=')
    ->execute();
    
    drupal_set_message("Broker Successfully Updated"); 
    drupal_goto('c2s/broker/view/'.arg(3)); 
}
catch(Exception $e)
{
    drupal_set_message("Broker Could Not Be Successfully Updated <br>" . $e, 'error');
}

				
// --------------------------------------------------------------------------------------------------

