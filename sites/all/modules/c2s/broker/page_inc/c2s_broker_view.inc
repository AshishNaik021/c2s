<?php

$brokerage_id = arg(3);
$result = db_query("SELECT * FROM c2s_brokerage_details WHERE brokerage_id = ".$brokerage_id);
foreach($result as $value){
    $brokerage_name 		  = $value->brokerage_name;
    $brokerage_start_date 	  = $value->brokerage_start_date;
    $number_of_owners         = $value->number_of_owners;
    $franchise_fee_cap		  = $value->franchise_fee_cap;
    $reap_amount_cap	      = $value->reap_amount_cap;
    $created 		          = $value->created;
    $changed 		          = $value->changed;
}

$result = db_query("SELECT * FROM c2s_broker_master WHERE brokerage_id = ".$brokerage_id." and status = 'A'");
$broker_details = array();

$city = array('0'=>'City','1'=>'City1');
$state = array('0'=>'State','1'=>'State1');
$n = 0;
foreach($result as $value){
    $n++;
    $broker_details[$n]['id']	      = $value->broker_agent_id;    
    $broker_details[$n]['fname']	  = $value->first_name;
    $broker_details[$n]['mname']	  = $value->middle_name;
    $broker_details[$n]['lname']	  = $value->last_name;
    $broker_details[$n]['dob']  	  = $value->dob;
    $broker_details[$n]['pers_email'] = $value->personal_email;
    $broker_details[$n]['pers_phon']  = $value->personal_phone;
    $broker_details[$n]['home_addr']  = $value->home_address;
    $broker_details[$n]['city']       = $city[$value->home_city];
    $broker_details[$n]['state']      = $state[$value->home_state];
    $broker_details[$n]['home_zip']   = $value->home_zip;
    
}
$total_brokers = $n;

$number_to_words = array(1=>"One", 2=> "Two", 3=> "Three", 4=>"Four", 5=>"Five", 6=>"Six");


    $form['form_start'] = array(
        '#type' => 'item',
        '#suffix' => '<div id="main-form-wrapper"> adasds',
    );
    
    $form['brokerage_tab'] = array(
        '#type' => 'item',
        '#suffix' => '<div class="form_section_tab selected" data-item="form_tab_0" > Brokerage Details </div>',
    );
    
	for($i=1; $i<=$total_brokers; $i++){
	 
	 $form['broker_tab_'.$i] = array(
	     '#type' => 'item',
	     '#suffix' => '<div class="form_section_tab" data-item="form_tab_'.$i.'" > Brokerage '.$number_to_words[$i].' </div>',
	 );
	 
	}
	
	$form['brokerage_details_start'] = array(
	    '#type' => 'item',
	    '#suffix' => '<div id="form_tab_0" class="form_sections" style="display:block">',
	);
	
	$form['brokerage_details_end'] = array(
	    '#type' => 'item',
	    '#suffix' => '</div>',
	);
  

    
    $form['form_end'] = array(
        '#type' => 'item',
        '#suffix' => '</div> ',
    );

/*
     $data  =  "";
	 $data .=  '<div id="main-view-wrapper"> '; // Wrapper Start

	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Name of Brokerage </label>'.
	           '<span class="value_left"> '.$brokerage_name .' </value>'. '</span></span>';

	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Brokerage Start Date </label>'.
	     '<span class="value_left"> '. $brokerage_start_date .' </value>'. '</span></span>';	 

	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Number of Owners </label>'.
	     '<span class="value_left"> '. $number_of_owners .' </value>'. '</span></span>';	 
	 
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 
	for($i=1; $i<=$total_brokers; $i++){
	 
	    $class = "selected";
	    if($i>1){
	        $class = "";
	    }
	    
	 $data .=  '<div class="form_section_tab '.$class.'" data-item="form_tab_'.$i.'" > Broker '.$number_to_words[$i].' </div>';
	 
	}
	 
	for($i=1; $i<=$total_brokers; $i++){

	    
	 $display = "block";
	 if($i>1){
	     $display = "none";
	 }
	    
	 $data .=  '<div id="form_tab_'.$i.'" class="form_sections" style="display:'.$display.'">'; // Form Start	 
	 
	 $data .=  '<div style="margin: 1%;float: right;width: 100%;">
	      <input type="button" value="Edit Broker" style="float: right; margin:5px;">
	     <input type="button" value="Deactivate Broker" style="float: right; margin:5px;" onclick="window.location=\''.base_path().'c2s/broker/deactivate/'.$broker_details[$i]['id'].'/'.$brokerage_id.'\'"></div>'; // Disable Button
	 
	 
	 // -- Personal Information -- //
	 
	 $data .=  '<div class="section_left">'; // section  left start
	 $data .=  '<div class="form_subsection_title" data-item="inner_section_1"> Personal Information</div>';
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> First Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Middle Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';	 
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Last Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';

	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //

	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Date Of Birth </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Personal Email </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Contact Number </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_phon'] .' </value>'. '</span></span>';	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Street Address </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['home_addr'] .' </value>'. '</span></span>';
	 

	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> City </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['city'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> State </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['state'] .' </value>'. '</span></span>';	
	 
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> Zip Code </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['home_zip'] .' </value>'. '</span></span>';
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 
	 // -- Professional Information -- //
	 $data .=  '<div class="section_left">'; // section  left start
	 $data .=  '<div class="form_subsection_title" data-item="inner_section_1"> Professional Information</div>';
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Business Address </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';

	 
 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 

	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> City </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> State </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Zip Code </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 

	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Broker State Id # </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Broker EIN </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Broker NRDS# </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> MLS Username </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> MLS Password </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> C2S Email Id </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Office Phone </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Extension </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Charity Organization Of Your Choice </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 
	 
	 
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
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Name on Account </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 
	 
	 $data .=  '<span class="wrapper-w60">'. '<label class="label_left"> Financial Institution Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 

	 
	 
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Contact Number </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Account Type </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> ABA Routing # </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
 
	 
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 // -- sub section -- //
	 
	 $data .=  '<div class="subsection_left">'; // section  left start
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start

	 $data .=  '<div class="form_subsection_title2">Personal Commissions & Reap</div>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Account Number </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Name on Account </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 
	 
	 $data .=  '<span class="wrapper-w60">'. '<label class="label_left"> Financial Institution Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 

	 
	 
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Contact Number </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Account Type </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> ABA Routing # </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 $data .=  '</div>'; // section  full end	 
	 
	 
	 // -- Beneficiary Information -- //
	 
	 $data .=  '<div class="section_left">'; // section  left start
	 $data .=  '<div class="form_subsection_title" data-item="inner_section_1"> Beneficiary Details</div>';
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> First Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Middle Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Last Name </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Relationship </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['dob'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Email id </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_email'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Contact Number </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['pers_phon'] .' </value>'. '</span></span>';
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w100">'. '<label class="label_left"> Street Address </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['home_addr'] .' </value>'. '</span></span>';
	 
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> City </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['city'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> State </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['state'] .' </value>'. '</span></span>';
	 
	 
	 $data .=  '<span class="wrapper-w16">'. '<label class="label_left"> Zip Code </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['home_zip'] .' </value>'. '</span></span>';
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 
	 // -------------- //
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // -------------- //
	 
	 // -- Broker Details Information -- //
	 $data .=  '<div class="section_full">'; // section  full start
	 
	 $data .=  '<div class="form_subsection_title" data-item="inner_section_1"> Broker Details</div>';
	 $data .=  '<div class="subsection_left">'; // section  left start
	 
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<div class="form_subsection_title2">Cap Amount Section</div>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Franchise Cap </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w33">'. '<label class="label_left"> Transaction Management </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['mname'] .' </value>'. '</span></span>';
	 
	 $data .=  '<span class="wrapper-w25">'. '<label class="label_left"> Reap Amount Cap </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['lname'] .' </value>'. '</span></span>';
	 
	 // ---------------//
	 $data .=  '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>'; // seperator
	 // ------------- //
	 
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 // -- sub section -- //
	 
	 $data .=  '<div class="subsection_left">'; // section  left start
	 
	 $data .=  '<div id="inner_section" class="inner_section_1 inner_subsection">'; // inner section start
	 
	 $data .=  '<div class="form_subsection_title2">Paper Work Required</div>';
	 
	 for($j=0; $j<=10; $j++){
	 
	       $data .=  '<span class="wrapper-w33">'. '<label class="label_left">  </label>'.
	     '<span class="value_left"> '.  $broker_details[$i]['fname'] .' </value>'. '</span></span>';
	 }
	 	 
	 
	 
	 $data .=  '</div> '; // Inner Section End
	 
	 $data .=  '</div>'; // section  left end
	 
	 $data .=  '</div>'; // section  full end
	  
	 $data .=  '</div> '; // Form End
	 
	} // loop end
	 
	 $data .=  '</div> '; // Wrapper End */
	