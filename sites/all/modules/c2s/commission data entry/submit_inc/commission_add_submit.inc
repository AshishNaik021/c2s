<?php

// ==================================================================================================
//                   New Commission Data Entry Information Submit
// ==================================================================================================
			$commission_transaction_date					=   $form_state['values']['commission_transaction_date'];
			$commission_price			      		 		=   $form_state['values']['commission_price'];
			$transaction_commission_value					=   $form_state['values']['transaction_commission_value'];
			$transaction_commission_amount					=   $form_state['values']['transaction_commission_amount'];
			$transaction_management_fees					=   $form_state['values']['transaction_management_fees'];
			$transaction_cheque_number						=   $form_state['values']['transaction_cheque_number'];
			$transaction_cheque_date						=   $form_state['values']['transaction_cheque_date'];
			$transaction_scanned_copy						=   $form_state['values']['transaction_scanned_copy'];
			$transaction_scanned_copy_1						=   $form_state['values']['transaction_scanned_copy_1'];
// -----///


	try{
	    
	    $result_charity = db_query("SELECT max(transaction_id) as maxid_charity FROM Commission_Master ");
	    foreach($result_commission as $value){
	        $id_commission = $value->maxid_commission;
	    }
	    $newid_transaction  =   $id_tranasaction + 1;
	    
        $values_commission = array(
	    'transaction_id'         			=>    $newid_transaction,
	    'closing_file_checklist_id'       	=>    $closing_file_checklist_id	,
        'transaction_date'				  	=>    $commission_transaction_date#,
	    'property_price'	   		  =>    $commission_price,
	    'commission_percent_value'	  		      =>	$transaction_commission_value,
	    'commission_amount'	   			  =>	$transaction_commission_amount,
		'transaction_management_fees'	   			  =>	$transaction_management_fees,
		'cheque_1_number'	   			      =>	$transaction_cheque_number	,
		'date_on_cheque_1'	   			     	  =>	$transaction_cheque_date,
		'scanned_cheque_1_id'	   			      =>	$transaction_scanned_copy,
		'cheque_2_number'	   		  =>	$transaction_scanned_copy_1,
		'date_on_cheque_2'	   			  =>	$name_on_account,
		'scanned_cheque_2_id'	   			 	      =>	$financial_institution_name,
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

