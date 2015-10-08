<?php

// ==================================================================================================
//                   New Checklist Information Submit
// ==================================================================================================
$closing_file_checklist_id					=   $form_state['values']['closing_file_checklist_id'];
$submitter_agent_id							=   $form_state['values']['submitter_agent_id'];
$transaction_type							=   $form_state['values']['transaction_type'];
$title_company_name							=   $form_state['values']['title_company_name'];
$processor_name								=   $form_state['values']['processor_name'];
$processor_phone							=   $form_state['values']['processor_phone'];
$personal_email								=   $form_state['values']['personal_email'];
$property_address			   		 		=   $form_state['values']['property_address'];
$property_city				    			=   $form_state['values']['property_city'];
$property_state								=   $form_state['values']['property_state'];
$property_zip								=   $form_state['values']['property_zip'];
$parcle_number								=   $form_state['values']['parcle_number'];
$mls_user_name								=   $form_state['values']['mls_user_name'];
$price										=   $form_state['values']['price'];
$loan_amount			    				=   $form_state['values']['loan_amount'];
$transaction_date							=   $form_state['values']['transaction_date'];
$closing_date								=   $form_state['values']['closing_date'];
$terms										=   $form_state['values']['terms'];
$association_name							=   $form_state['values']['association_name'];
$association_contact_person					=   $form_state['values']['association_contact_person'];
$association_phone_number					=   $form_state['values']['association_phone_number'];
$association_email							=   $form_state['values']['association_email'];
$property_type								=   $form_state['values']['property_type'];
$earnest_money								=   $form_state['values']['earnest_money'];
$transaction_management_fee					=   $form_state['values']['transaction_management_fee'];
$listing_agent_name							=   $form_state['values']['listing_agent_name'];
$listing_agent_company_name					=   $form_state['values']['listing_agent_company_name'];
$listing_agent_phone						=   $form_state['values']['listing_agent_phone'];
$listing_agent_fax							=   $form_state['values']['listing_agent_fax'];
$listing_agent_email						=   $form_state['values']['listing_agent_email'];
$listing_agent_commission_percent			=   $form_state['values']['listing_agent_commission_percent'];
$listing_agent_commission_amount			=   $form_state['values']['listing_agent_commission_amount'];
$buyers_agent_name							=   $form_state['values']['buyers_agent_name'];
$buyers_agent_company_name					=   $form_state['values']['buyers_agent_company_name'];
$buyers_agent_phone							=   $form_state['values']['buyers_agent_phone'];
$buyers_agent_fax							=   $form_state['values']['buyers_agent_fax'];
$buyers_agent_email							=   $form_state['values']['buyers_agent_email'];
$buyers_agent_commission_percent			=   $form_state['values']['buyers_agent_commission_percent'];
$buyers_agent_commission_amount				=   $form_state['values']['buyers_agent_commission_amount'];
$sellers_first_name							=   $form_state['values']['sellers_first_name'];
$sellers_middle_name						=   $form_state['values']['sellers_middle_name'];
$sellers_last_name							=   $form_state['values']['sellers_last_name'];
$sellers_phone_number  						=   $form_state['values']['sellers_phone_number'];
$sellers_marital_status   					=   $form_state['values']['sellers_marital_status'];
$buyers_first_name      					=   $form_state['values']['buyers_first_name'];
$buyers_middle_name							=   $form_state['values']['buyers_middle_name'];
$buyers_last_name							=   $form_state['values']['buyers_last_name'];
$buyers_phone_number						=   $form_state['values']['buyers_phone_number'];
$buyers_marital_status						=   $form_state['values']['buyers_marital_status'];
$buyers_current_address						=   $form_state['values']['buyers_current_address'];
$buyers_city								=   $form_state['values']['buyers_city'];
$buyers_state								=   $form_state['values']['buyers_state'];
$buyers_zip									=   $form_state['values']['buyers_zip'];
$buyers_cost_paid_by_seller					=   $form_state['values']['buyers_cost_paid_by_seller'];
$buyers_cost_paid							=   $form_state['values']['buyers_cost_paid'];
$lender_name								=   $form_state['values']['lender_name'];
$lender_loan_officer						=   $form_state['values']['lender_loan_officer'];
$lender_phone_number						=   $form_state['values']['lender_phone_number'];
$lender_fax									=   $form_state['values']['lender_fax'];
$lender_email									=   $form_state['values']['lender_email'];
$home_inspection_provider					=   $form_state['values']['home_inspection_provider'];
$termite_provider							=   $form_state['values']['termite_provider'];
$basic										=   $form_state['values']['basic'];
$termite									=   $form_state['values']['termite'];
$randon										=   $form_state['values']['randon'];
$appraiser									=   $form_state['values']['appraiser'];
$well_septic_inspection						=   $form_state['values']['well_septic_inspection'];
$well_septic_inspection_provided			=   $form_state['values']['well_septic_inspection_provided'];
$lead_source								=   $form_state['values']['lead_source'];
$race										=   $form_state['values']['race'];
$age										=   $form_state['values']['age'];
$notes										=   $form_state['values']['notes'];



	try{
	    
	    $result_checklist = db_query("SELECT max(closing_file_checklist_id) as maxid_checklist FROM checklist_details ");
	    foreach($result_checklist as $value){
	        $id_checklist = $value->maxid_checklist;
	    }
	    $newid_checklist  =   $id_checklist + 1;
		
	
		$values_checklist = array(
							'closing_file_checklist_id'           	=>    $newid,
		                    'transaction_type'        				=>    $transaction_type,
		                    'title_company_name'             		=>    $title_company_name,
							'processor_name'      	  				=>    $processor_name,
							'processor_phone'		  				=>	  $processor_phone,
							'processor_email'			  			=>	  $personal_email,
							'property_address'				  		=>	  $property_address,
							'property_city'	  						=>	  $property_city,
							'property_state'	  					=>	  $property_state,
							'property_zip'		  					=>	  $property_zip,
							'parcle_number'			  				=>	  $parcle_number,
		                    'mls_user_name'      	  				=>    $mls_user_name,
		                    'price'			  						=>	  $price,
		                    'loan_amount'	  						=>	  $loan_amount,
		                    'transaction_date'		  				=>	  $transaction_date,
		                    'closing_date'	  						=>	  $closing_date,
		                    'terms'		  							=>	  $terms,
		                    'association_name'	  					=>	  $association_name,
		                    'association_contact_person'		    =>	  $association_contact_person,
		                    'association_phone_number'		  		=>	  $association_phone_number,
		                    'association_email'		  				=>	  $association_email,
		                    'property_type'      	  				=>    $property_type,
		                    'earnest_money'		  					=>	  $earnest_money,
		                    'transaction_management_fee'		    =>	  $transaction_management_fee,
		                    'listing_agent_name'	  				=>	  $listing_agent_name,
		                    'listing_agent_company_name'	  		=>	  $listing_agent_company_name,
		                    'listing_agent_phone'	  				=>	  $listing_agent_phone,
		                    'listing_agent_fax'  					=>	  $listing_agent_fax,
		                    'listing_agent_email' 					=>	  $listing_agent_email,
		                    'listing_agent_commission_percent'	  	=>	  $listing_agent_commission_percent,
		                    'listing_agent_commission_amount'		=>	  $listing_agent_commission_amount,
		                    'buyers_agent_name'	  					=>	  $buyers_agent_name,
		                    'buyers_agent_company_name'	  			=>	  $buyers_agent_company_name,
		                    'buyers_agent_phone'  					=>	  $buyers_agent_phone,
		                    'buyers_agent_fax' 						=>	  $buyers_agent_fax,
		                    'buyers_agent_email'	  				=>	  $buyers_agent_email,
		                    'buyers_agent_commission_percent'		=>	  $buyers_agent_commission_percent,
		                    'buyers_agent_commission_amount'		=>	  $buyers_agent_commission_amount,
                            'sellers_first_name'      				=>    $sellers_first_name,
                            'sellers_middle_name'           		=>    $sellers_middle_name,
                            'sellers_last_name'             		=>    $sellers_last_name,
                            'sellers_phone_number'          		=>    $sellers_phone_number,
                            'sellers_marital_status'                =>    $sellers_marital_status,
                            'buyers_first_name'        				=>    $buyers_first_name,
                            'buyers_middle_name'           			=>    $buyers_middle_name,
                            'buyers_last_name'            			=>    $buyers_last_name,
                            'buyers_phone_number'            		=>    $buyers_phone_number,
                            'buyers_marital_status'           	    =>    $buyers_marital_status,
                            'buyers_current_address'        		=>    $buyers_current_address,
                            'buyers_city'        					=>    $buyers_city,
                            'buyers_state'        					=>    $buyers_state,
                            'buyers_zip'        					=>    $buyers_zip,							
							'buyers_cost_paid_by_seller'            =>    $buyers_cost_paid_by_seller,
							'buyers_cost_paid '        				=>    $buyers_cost_paid,
							'lender_name'        					=>    $lender_name,
							'lender_loan_officer'        			=>    $lender_loan_officer,
							'lender_phone_number'        			=>    $lender_phone_number,
							'lender_fax'        					=>    $lender_fax,
							'lender_email'        					=>    $lender_email,    	
							'home_inspection_provider'        		=>    $home_inspection_provider,
							'termite_provider'        				=>    $termite_provider,
							'basic'        							=>    $basic,
							'termite'        						=>    $termite,
							'randon'        						=>    $randon,
							'appraiser'        						=>    $appraiser,
							'well_septic_inspection'        		=>    $well_septic_inspection,
							'well_septic_inspection_provided'       =>    $well_septic_inspection_provided,
							'lead_source'        					=>    $lead_source,
							'race'        						    =>    $race,
							'marital_status'        				=>    $marital_status,
							'age'        							=>    $age,
							'notes'        							=>    $notes,
							'created_timestamp'         	  		=>    REQUEST_TIME,
							'last_update_timestamp'         	  	=>    REQUEST_TIME,
                                                        ])
			  ->execute();
				drupal_set_message("New Checklist Submitted Successfully");
	}
	catch(Exception $e)
	{
		drupal_set_message("New Checklist could not be Inserted <br>" . $e, 'error');				
	}


	 $form_state['redirect'] = array(
	  'c2s/checklist/add',
	   array(
		'query' => array(
	   ),
	  ),
	 );	

				
// --------------------------------------------------------------------------------------------------

