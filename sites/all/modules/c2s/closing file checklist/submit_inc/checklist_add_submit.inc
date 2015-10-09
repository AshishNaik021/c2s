<?php

// ==================================================================================================
//                   New Checklist Information Submit
// ==================================================================================================

			$types_of_transaction							=   $form_state['values']['types_of_transaction'];
			$title_company									=   $form_state['values']['title_company'];
			$processor_name									=   $form_state['values']['processor_name'];
			$processor_email								=   $form_state['values']['processor_email'];
			$property_address								=   $form_state['values']['property_address'];
			$city_id										=   $form_state['values']['city_id'];
			$state_id			   		 					=   $form_state['values']['state_id'];
			$zip_code				    					=   $form_state['values']['zip_code'];
			$parcel_number									=   $form_state['values']['parcel_number'];
			$mls											=   $form_state['values']['mls'];
			$price											=   $form_state['values']['price'];
			$loan											=   $form_state['values']['loan'];
			$transaction_date								=   $form_state['values']['transaction_date'];
			$closing_date			    					=   $form_state['values']['closing_date'];
			$terms											=   $form_state['values']['terms'];
			$association_name								=   $form_state['values']['association_name'];
			$contact_person									=   $form_state['values']['contact_person'];
			$phone_number									=   $form_state['values']['phone_number'];
			$email											=   $form_state['values']['email'];
			$property_type									=   $form_state['values']['property_type'];
			$earnest_money									=   $form_state['values']['earnest_money'];
			$transaction_management_fee						=   $form_state['values']['transaction_management_fee'];
			$listing_name									=   $form_state['values']['listing_name'];
			$listing_company								=   $form_state['values']['listing_company'];
			$listing_phone									=   $form_state['values']['listing_phone'];
			$listing_fax									=   $form_state['values']['listing_fax'];
			$listing_email									=   $form_state['values']['listing_email'];
			$listing_commission_value						=   $form_state['values']['listing_commission_value'];
			$listing_commission_amount						=   $form_state['values']['listing_commission_amount'];
			$buyers_name									=   $form_state['values']['buyers_name'];
			$buyers_company									=   $form_state['values']['buyers_company'];
			$buyers_phone									=   $form_state['values']['buyers_phone'];
			$buyers_fax										=   $form_state['values']['buyers_fax'];
			$buyers_email									=   $form_state['values']['buyers_email'];
			$buyers_commission_value						=   $form_state['values']['buyers_commission_value'];
			$buyers_commission_amount						=   $form_state['values']['buyers_commission_amount'];
			$sellers_first_name								=   $form_state['values']['sellers_first_name'];
			$sellers_middle_name							=   $form_state['values']['sellers_middle_name'];
			$sellers_last_name								=   $form_state['values']['sellers_last_name'];
			$sellers_phone  								=   $form_state['values']['sellers_phone'];
			$sellers_marital_status   						=   $form_state['values']['sellers_marital_status'];
			$buyers_first_name      						=   $form_state['values']['buyers_first_name'];
			$buyers_middle_name								=   $form_state['values']['buyers_middle_name'];
			$buyers_last_name								=   $form_state['values']['buyers_last_name'];
			$buyers_phone_1									=   $form_state['values']['buyers_phone_1'];
			$buyers_marital_status							=   $form_state['values']['buyers_marital_status'];
			$buyers_address									=   $form_state['values']['buyers_address'];
			$buyers_city_id									=   $form_state['values']['buyers_city_id'];
			$buyers_state_id								=   $form_state['values']['buyers_state_id'];
			$buyers_zip_code								=   $form_state['values']['buyers_zip_code'];
			$buyers_cost									=   $form_state['values']['buyers_cost'];
			$buyers_cost_how_much							=   $form_state['values']['buyers_cost_how_much'];
			$lender											=   $form_state['values']['lender'];
			$loan_officer									=   $form_state['values']['loan_officer'];
			$phone_number									=   $form_state['values']['phone_number'];
			$lender_fax										=   $form_state['values']['lender_fax'];
			$lender_email									=   $form_state['values']['lender_email'];
			$home_inspection_provider						=   $form_state['values']['home_inspection_provider'];
			$termite_provider								=   $form_state['values']['termite_provider'];
			$appraiser										=   $form_state['values']['appraiser'];
			$basic											=   $form_state['values']['basic'];
			$termite										=   $form_state['values']['termite'];
			$randon											=   $form_state['values']['randon'];
			$septic_inspection								=   $form_state['values']['septic_inspection'];
			$septic_inspection_provided						=   $form_state['values']['septic_inspection_provided'];
			$marketing_data_1								=   $form_state['values']['marketing_data_1'];
			$race											=   $form_state['values']['race'];
			$marital_status_1								=   $form_state['values']['marital_status_1'];
			$age											=   $form_state['values']['age'];
			$add_notes										=   $form_state['values']['add_notes'];




	try{
	    
	    $result_checklist = db_query("SELECT max(closing_file_checklist_id) as maxid_checklist FROM checklist_details ");
	    foreach($result_checklist as $value){
	        $id_checklist = $value->maxid_checklist;
	    }
	    $newid_checklist  =   $id_checklist + 1;
		
	
		$values_checklist = array(
							'closing_file_checklist_id'           	=>    $newid,
		                    'transaction_type'        				=>    $types_of_transaction,
		                    'title_company_name'             		=>    $title_company,
							'processor_name'      	  				=>    $processor_name,
							'processor_phone'		  				=>	  $processor_phone,
							'processor_email'			  			=>	  $personal_email,
							'property_address'				  		=>	  $property_address,
							'property_city'	  						=>	  $city_id,
							'property_state'	  					=>	  $state_id,
							'property_zip'		  					=>	  $zip_code,
							'parcle_number'			  				=>	  $parcle_number,
		                    'mls_user_name'      	  				=>    $mls,
		                    'price'			  						=>	  $price,
		                    'loan_amount'	  						=>	  $loan,
		                    'transaction_date'		  				=>	  $transaction_date,
		                    'closing_date'	  						=>	  $closing_date,
		                    'terms'		  							=>	  $terms,
		                    'association_name'	  					=>	  $association_name,
		                    'association_contact_person'		    =>	  $contact_person,
		                    'association_phone_number'		  		=>	  $phone_number,
		                    'association_email'		  				=>	  $email,
		                    'property_type'      	  				=>    $property_type,
		                    'earnest_money'		  					=>	  $earnest_money,
		                    'transaction_management_fee'		    =>	  $transaction_management_fee,
		                    'listing_agent_name'	  				=>	  $listing_name,
		                    'listing_agent_company_name'	  		=>	  $listing_company_name,
		                    'listing_agent_phone'	  				=>	  $listing_phone,
		                    'listing_agent_fax'  					=>	  $listing_fax,
		                    'listing_agent_email' 					=>	  $listing_email,
		                    'listing_agent_commission_percent'	  	=>	  $listing_commission_value,
		                    'listing_agent_commission_amount'		=>	  $listing_commission_amount,
		                    'buyers_agent_name'	  					=>	  $buyers_name,
		                    'buyers_agent_company_name'	  			=>	  $buyers_company,
		                    'buyers_agent_phone'  					=>	  $buyers_phone,
		                    'buyers_agent_fax' 						=>	  $buyers_fax,
		                    'buyers_agent_email'	  				=>	  $buyers_email,
		                    'buyers_agent_commission_percent'		=>	  $buyers_commission_value,
		                    'buyers_agent_commission_amount'		=>	  $buyers_commission_amount,
                            'sellers_first_name'      				=>    $sellers_first_name,
                            'sellers_middle_name'           		=>    $sellers_middle_name,
                            'sellers_last_name'             		=>    $sellers_last_name,
                            'sellers_phone_number'          		=>    $sellers_phone,
                            'sellers_marital_status'                =>    $sellers_marital_status,
                            'buyers_first_name'        				=>    $buyers_first_name,
                            'buyers_middle_name'           			=>    $buyers_middle_name,
                            'buyers_last_name'            			=>    $buyers_last_name,
                            'buyers_phone_number'            		=>    $buyers_phone_1,
                            'buyers_marital_status'           	    =>    $buyers_marital_status,
                            'buyers_current_address'        		=>    $buyers_address,
                            'buyers_city'        					=>    $buyers_city_id,
                            'buyers_state'        					=>    $buyers_state_id,
                            'buyers_zip'        					=>    $buyers_zip_code,							
							'buyers_cost_paid_by_seller'            =>    $buyers_cost,
							'buyers_cost_paid '        				=>    $buyers_cost_how_much,
							'lender_name'        					=>    $lender,
							'lender_loan_officer'        			=>    $lender_officer,
							'lender_phone_number'        			=>    $phone_number,
							'lender_fax'        					=>    $lender_fax,
							'lender_email'        					=>    $lender_email,    	
							'home_inspection_provider'        		=>    $home_inspection_provider,
							'termite_provider'        				=>    $termite_provider,
							'basic'        							=>    $basic,
							'termite'        						=>    $termite,
							'appraiser'        						=>    $appraiser,
							'randon'        						=>    $randon,
							'well_septic_inspection'        		=>    $septic_inspection,
							'well_septic_inspection_provided'       =>    $septic_inspection_provided,
							'lead_source'        					=>    $marketing_data_1,
							'race'        						    =>    $race,
							'marital_status'        				=>    $marital_status_1,
							'age'        							=>    $age,
							'notes'        							=>    $add_notes,
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

