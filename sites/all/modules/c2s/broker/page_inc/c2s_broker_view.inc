<?php

drupal_add_css( drupal_get_path('module', 'broker') . '/css/global-c2s.css');

/*
	//drupal_add_css(drupal_get_path('module', 'overtime') . '/css/overtime.css');
$form['#attached']['css'] = array(
		drupal_get_path('module', 'overtime') . '/css/overtime.css',
);
	$ot_rate_id			= 0;
	
	$location_code 		= '';
	$category 			= '';
	$grade		 		= '';
	$employee_type 		= '';
	$effective_date 	= '';
	$rate_multiple 		= '';
	$created 			= '';
	$changed 			= '';

	if(isset($_GET['ot_rate_id'])){
		$ot_rate_id = $_GET['ot_rate_id'];
	}

		
	$result = db_query("SELECT * 
                              FROM pms_setting_overtime 
                              WHERE ot_rate_id = ".$ot_rate_id);
	foreach($result as $value){
		$company_code 		= $value->company_id;
		$location_code 		= $value->location_id;
		$category 		= $value->category_id;
		$grade		 	= $value->grade_id;
		$employee_type 		= $value->employee_type;
		$effective_date 	= $value->effective_date;
		$rate_multiple 		= $value->rate_multiple;
		$created 		= $value->created;
		$changed 		= $value->changed;
	}
        if(empty($company_code )){$company_code = 1;}
*/
$result = db_query("SELECT * FROM brokerage_details WHERE brokerage_id = 2");
foreach($result as $value){
    $brokerage_name 		  = $value->brokerage_name;
    $brokerage_start_date 	  = $value->brokerage_start_date;
    $number_of_owners         = $value->number_of_owners;
    $franchise_fee_cap		  = $value->franchise_fee_cap;
    $reap_amount_cap	      = $value->reap_amount_cap;
    $created 		          = $value->created;
    $changed 		          = $value->changed;
}

$result = db_query("SELECT * FROM broker_master WHERE brokerage_id = 2");
$broker_details = array();

$city = array('0'=>'City','1'=>'City1');
$state = array('0'=>'State','1'=>'State1');

foreach($result as $value){
    $broker_details['fname']	  = $value->first_name;
    $broker_details['mname']	  = $value->middle_name;
    $broker_details['lname']	  = $value->last_name;
    $broker_details['dob']  	  = $value->dob;
    $broker_details['pers_email'] = $value->personal_email;
    $broker_details['pers_phon']  = $value->personal_phone;
    $broker_details['home_addr']  = $value->home_address;
    $broker_details['city']       = $city[$value->home_city];
    $broker_details['state']      = $state[$value->home_state];
    $broker_details['home_zip']  = $value->home_zip;
}


     $data  =  "";
	 $data .=  '<div id="main-view-wrapper"> '; // Wrapper Start

	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Name of Brokerage </label>'.
	           '<span class="value_left"> '.$brokerage_name .' </value>'. '</span></span>';

	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Brokerage Start Date </label>'.
	     '<span class="value_left"> '. $brokerage_start_date .' </value>'. '</span></span>';	 

	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Number of Owners </label>'.
	     '<span class="value_left"> '. $number_of_owners .' </value>'. '</span></span>';	 
	 
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 
	 $data .=  '<div id="form_sections" class="form_sections">'; // Form Start	 

	 $data .=  '<div class="form_section_title" data-item="form_section_1" > Broker One </div>';	 
	 
	 // -- Personal Information -- //
	 
	 $data .=  '<div class="section_left">'; // section  left start
	 $data .=  '<div class="form_subsection_title" data-item="inner_section_1"> Personal Information</div>';
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> First Name </label>'.
	     '<span class="value_left"> '.  $broker_details['fname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Middle Name </label>'.
	     '<span class="value_left"> '.  $broker_details['mname'] .' </value>'. '</span></span>';	 
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Last Name </label>'.
	     '<span class="value_left"> '.  $broker_details['lname'] .' </value>'. '</span></span>';

	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //

	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Date Of Birth </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Personal Email </label>'.
	     '<span class="value_left"> '.  $broker_details['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Contact Number </label>'.
	     '<span class="value_left"> '.  $broker_details['pers_phon'] .' </value>'. '</span></span>';	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Street Address </label>'.
	     '<span class="value_left"> '.  $broker_details['home_addr'] .' </value>'. '</span></span>';
	 

	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> City </label>'.
	     '<span class="value_left"> '.  $broker_details['city'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> State </label>'.
	     '<span class="value_left"> '.  $broker_details['state'] .' </value>'. '</span></span>';	
	 
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> Zip Code </label>'.
	     '<span class="value_left"> '.  $broker_details['home_zip'] .' </value>'. '</span></span>';
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 
	 // -- Professional Information -- //
	 $data .=  '<div class="section_left">'; // section  left start
	 $data .=  '<div class="form_subsection_title" data-item="inner_section_1"> Professional Information</div>';
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Business Address </label>'.
	     '<span class="value_left"> '.  $broker_details['fname'] .' </value>'. '</span></span>';

	 
 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 

	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> City </label>'.
	     '<span class="value_left"> '.  $broker_details['mname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> State </label>'.
	     '<span class="value_left"> '.  $broker_details['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Zip Code </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 

	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Broker State Id # </label>'.
	     '<span class="value_left"> '.  $broker_details['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Broker EIN </label>'.
	     '<span class="value_left"> '.  $broker_details['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Broker NRDS# </label>'.
	     '<span class="value_left"> '.  $broker_details['lname'] .' </value>'. '</span></span>';
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> MLS Username </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> MLS Password </label>'.
	     '<span class="value_left"> '.  $broker_details['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> C2S Email Id </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Office Phone </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Extension </label>'.
	     '<span class="value_left"> '.  $broker_details['pers_email'] .' </value>'. '</span></span>';
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Charity Organization Of Your Choice </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 // -- Bank Details Information -- //
	 $data .=  '<div class="section_full">'; // section  full start
	 
	 $data .=  '<div class="form_subsection_title" data-item="inner_section_1"> Bank Details</div>';
	 $data .=  '<div class="subsection_left">'; // section  left start

	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<div class="form_subsection_title2">Payout Commissions &amp; Reap To Agent</div>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Account Number </label>'.
	     '<span class="value_left"> '.  $broker_details['fname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Name on Account </label>'.
	     '<span class="value_left"> '.  $broker_details['mname'] .' </value>'. '</span></span>';
	 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Institution Name </label>'.
	     '<span class="value_left"> '.  $broker_details['mname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Contact </label>'.
	     '<span class="value_left"> '.  $broker_details['lname'] .' </value>'. '</span></span>';
	 
	 
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Broker State Id # </label>'.
	     '<span class="value_left"> '.  $broker_details['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Broker EIN </label>'.
	     '<span class="value_left"> '.  $broker_details['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Broker NRDS# </label>'.
	     '<span class="value_left"> '.  $broker_details['lname'] .' </value>'. '</span></span>';
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> MLS Username </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> MLS Password </label>'.
	     '<span class="value_left"> '.  $broker_details['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> C2S Email Id </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Office Phone </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Extension </label>'.
	     '<span class="value_left"> '.  $broker_details['pers_email'] .' </value>'. '</span></span>';
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Charity Organization Of Your Choice </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 // -- sub section -- //
	 
	 $data .=  '<div class="subsection_left">'; // section  left start
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start

	 $data .=  '<div class="form_subsection_title2">Personal Commissions & Reap</div>';
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Business Address </label>'.
	     '<span class="value_left"> '.  $broker_details['fname'] .' </value>'. '</span></span>';
	 
	 
	 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> City </label>'.
	     '<span class="value_left"> '.  $broker_details['mname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> State </label>'.
	     '<span class="value_left"> '.  $broker_details['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Zip Code </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Broker State Id # </label>'.
	     '<span class="value_left"> '.  $broker_details['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Broker EIN </label>'.
	     '<span class="value_left"> '.  $broker_details['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Broker NRDS# </label>'.
	     '<span class="value_left"> '.  $broker_details['lname'] .' </value>'. '</span></span>';
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> MLS Username </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> MLS Password </label>'.
	     '<span class="value_left"> '.  $broker_details['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> C2S Email Id </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Office Phone </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Extension </label>'.
	     '<span class="value_left"> '.  $broker_details['pers_email'] .' </value>'. '</span></span>';
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Charity Organization Of Your Choice </label>'.
	     '<span class="value_left"> '.  $broker_details['dob'] .' </value>'. '</span></span>';
	 
	 
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 $data .=  '</div>'; // section  full end	 
	 
	 
	 $data .=  '</div> '; // Form End
	 
	 $data .=  '</div> '; // Wrapper End
	