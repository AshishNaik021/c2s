<?php
/*
* -------------------------------------------------------------------------
*	For Edit, Take the 3rd Argument and fetch all values from database. 
* -------------------------------------------------------------------------
*/
$city_options = array();
$state_options = array();
$state_options = getStates();

$charity_organization_id = arg(3);
$query = "SELECT * FROM c2s_charity_org_master WHERE charity_organization_id = ".$charity_organization_id ;
$result = db_query($query);
foreach($result as $value){
	$charity_org_name 				= $value->charity_org_name;
	$number_501_c_3 	  			= $value->number_501_c_3;
	$charity_org_address         	= $value->charity_org_address;
	$charity_org_city		  		= $value->charity_org_city;
	$charity_org_state	      		= $value->charity_org_state;
	$charity_org_zip 		        = $value->charity_org_zip;
	$phone_number 		          	= $value->phone_number;
	$email_id 		          		= $value->email_id;
	$website_url 		          	= $value->website_url;
	$bank_account_number 		    = $value->bank_account_number;
	$bank_account_name 		        = $value->bank_account_name;
	$bank_name 		          		= $value->bank_name;
	$bank_phone 		          	= $value->bank_phone;
	$bank_account_type 		        = $value->bank_account_type;
	$bank_aba_routing_number 		= $value->bank_aba_routing_number;
	$charity_org_status 			= $value->Charity_Org_Status;

	$approver_user_id		 		= $value->approver_user_id;
	$approval_status	          	= $value->approval_status;
	$approver_remark 		        = $value->approver_remark;
	$approval_timestamp		 		= $value->approval_timestamp;

	$input_class  = 'input_disabled';
	$select_class = 'input_disabled';	
	$required_disabled = '#disabled';
	$radio = 'textfield';

}
		$output = '';
		
		if($charity_org_status == 'A'){
			$output .= '<div id="page-outer-wrapper"> <div id="page-inner-wrapper">';
			$deact = 'De-Activate';
		}else{
			$output .= '<div id="page-outer-wrapper"> <div id="page-inner-wrapper" style="background:#ffefef;">';
			$output .= '<h2 style="color:red; text-align:center;"> De-Activated </h2>';
			$deact = 'Re-Activate';
		}
					
		$output .= '<div id="view-page-title"> Charity Organization Information 
						<div id="icon-block">
							<div id="edit-icon" style="float:left">   <a href="../add/'.$charity_organization_id .'"> Edit </a>  &nbsp; | &nbsp; </div>
							<div id="delete-icon" style="float:left"> <a href="../deactivate/'.$charity_organization_id .'/'.$deact.'"> '.$deact.' </a> </div>
						</div>
					</div>';
					
		$output .= '<div id="view-page-block">';
			$output .= '<div id="view-page-small-block">';
				$output .= '<div id="view-page-block-label"> Charity Organization Details </div>';
				
				$output .= '<div id="view-page-small-block2-50p">';
				$output .= '<div id="view-page-block-label"> Charity Organization Name </div>';
				$output .= '<div id="view-page-block-value"> '. $charity_org_name .' </div>';
				$output .= '</div>'; //end of small-block2
				$output .= '<div id="view-page-small-block2-50p">';
				$output .= '<div id="view-page-block-label"> Organization\'s Unique ID </div>';
				$output .= '<div id="view-page-block-value"> '. $number_501_c_3 .' </div>';
				$output .= '</div>'; //end of small-block2
				
				$output .= '<div id="view-page-small-block2-50p">';
				$output .= '<div id="view-page-block-label"> Office Address </div>';
				$output .= '<div id="view-page-block-value"> '. $charity_org_address.', '.$charity_org_city.', '.$charity_org_state.' - '.$charity_org_zip.' </div>';
				$output .= '</div>'; //end of small-block2
			$output .= '</div>'; //end of small-block

		$output .= '<div id="view-page-small-block">';
		$output .= '<div id="view-page-block-label"> Contact Details </div>';
			$output .= '<div id="view-page-small-block2-30p">';
			$output .= '<div id="view-page-block-label"> Phone Number </div>';
			$output .= '<div id="view-page-block-value"> '. $phone_number .' </div>';
			$output .= '</div>'; //end of small-block2
			
			$output .= '<div id="view-page-small-block2-30p">';
			$output .= '<div id="view-page-block-label"> Email ID </div>';
			$output .= '<div id="view-page-block-value"> '. $email_id .' </div>';
			$output .= '</div>'; //end of small-block2
			
			$output .= '<div id="view-page-small-block2-30p">';
			$output .= '<div id="view-page-block-label"> Website URL </div>';
			$output .= '<div id="view-page-block-value"> '. $website_url .' </div>';
			$output .= '</div>'; //end of small-block2
		$output .= '</div>'; //end of small-block
		$output .= '</div>'; //end of block

		$output .= '<div id="view-page-block">';
			$output .= '<div id="view-page-small-block">';
				$output .= '<div id="view-page-block-label"> Bank Account Details </div>';
				$output .= '<div id="view-page-small-block2-50p">';
				$output .= '<div id="view-page-block-label"> Bank Account Number </div>';
				$output .= '<div id="view-page-block-value"> '. $bank_account_number .' </div>';
				$output .= '</div>'; //end of small-block2
				
				$output .= '<div id="view-page-small-block2-50p">';
				$output .= '<div id="view-page-block-label"> Name on Bank Account</div>';
				$output .= '<div id="view-page-block-value"> '. $bank_account_name .' </div>';
				$output .= '</div>'; //end of small-block2
			$output .= '</div>'; //end of small-block
			$output .= '<div id="view-page-small-block">';
				$output .= '<div id="view-page-small-block2-50p">';
				$output .= '<div id="view-page-block-label"> Bank Name </div>';
				$output .= '<div id="view-page-block-value"> '. $bank_name .' </div>';
				$output .= '</div>'; //end of small-block2
				
				$output .= '<div id="view-page-small-block2-50p">';
				$output .= '<div id="view-page-block-label"> Bank Contact Number</div>';
				$output .= '<div id="view-page-block-value"> '. $bank_phone .' </div>';
				$output .= '</div>'; //end of small-block2
			$output .= '</div>'; //end of small-block
			$output .= '<div id="view-page-small-block">';
				$output .= '<div id="view-page-small-block2-50p">';
				$output .= '<div id="view-page-block-label"> Bank Account Type </div>';
				$output .= '<div id="view-page-block-value"> '. $bank_account_type .' </div>';
				$output .= '</div>'; //end of small-block2
				
				$output .= '<div id="view-page-small-block2-50p">';
				$output .= '<div id="view-page-block-label"> ABA Routing Number</div>';
				$output .= '<div id="view-page-block-value"> '. $bank_aba_routing_number .' </div>';
				$output .= '</div>'; //end of small-block2
			$output .= '</div>'; //end of small-block
		
		$output .= '</div>'; //end of block

		$output .= '<div id="view-page-fullwidth-block">';
				$output .= '<div id="view-page-small-block2-30p">';
					$output .= '<div id="view-page-block-label"> Approval Status </div>';
					if($approval_status=='P'){
						$output .= '<div id="view-page-block-value" style="padding-left:20px;"> 
									<img src="/C2S_Drupal2/sites/all/modules/c2s/general/images/pending-stamp.jpg" width="75px" height="75px" />
									</div>';
					}elseif($approval_status=='A'){
						$output .= '<div id="view-page-block-value" style="padding-left:20px;"> 
									<img src="/C2S_Drupal2/sites/all/modules/c2s/general/images/approved-stamp.jpg" width="75px" height="75px" />
									</div>';
					}else{
						$output .= '<div id="view-page-block-value" style="padding-left:20px;"> 
									<img src="/C2S_Drupal2/sites/all/modules/c2s/general/images/rejected-stamp.jpg" width="75px" height="75px" />
									</div>';
					}
					
				$output .= '</div>'; //end of small-block2
				$output .= '<div id="view-page-small-block2-30p">';
					$output .= '<div id="view-page-block-label"> Approved By </div>';
					if(!is_null($approver_user_id)){
						$output .= '<div id="view-page-block-value"> '. $approver_user_id .' </div>';
					}
					else{
						$output .= '<div id="view-page-block-value" style="color:red;padding:7% 0 0 8%;"> -- NA -- </div>';
					}
				$output .= '</div>'; //end of small-block2
				$output .= '<div id="view-page-small-block2-30p">';
					$output .= '<div id="view-page-block-label"> Approval Date </div>';
					if(!is_null($approver_user_id)){
						$output .= '<div id="view-page-block-value"> '. $approval_timestamp .' </div>';
					}else{
						$output .= '<div id="view-page-block-value" style="color:red;padding:7% 0 0 8%;"> -- NA -- </div>';
					}
				$output .= '</div>'; //end of small-block2
		$output .= '</div>'; //end of small-block

		if($approval_status=='R'){
			$output .= '<div id="view-page-fullwidth-block">';
					$output .= '<div id="view-page-block-label"> Remark By Approver </div>';
					$output .= '<div id="view-page-block-value"> '. $approver_remark .' </div>';
			$output .= '</div>'; //end of small-block
		}
		$output .= '</div></div>';



