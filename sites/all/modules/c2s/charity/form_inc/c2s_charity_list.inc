<link href="<?php echo base_path()."/".drupal_get_path('module', 'broker') . '/css/global-c2s.css'; ?>" rel="stylesheet" />
<?php

    $count = 0;
    $header = array(
       array('data' 	=> 'Charity Org Name',	'field' => '', 'style'=>'width: 20%;'),
       array('data' 	=> '501(c)(3) Number',	'field' => '', 'style'=>'width: 10%;'),
       array('data' 	=> 'Phone Number', 		'field' => '', 'style'=>'width: 10%;'),
       array('data' 	=> 'Email ID', 			'field' => '', 'style'=>'width: 10%;'),
       array('data' 	=> 'Website', 			'field' => '', 'style'=>'width: 10%;'),
       array('data' 	=> 'Address', 			'field' => '', 'style'=>'width: 20%;'),
       array('data' 	=> 'Status', 			'field' => '', 'style'=>'width: 10%;'),
       array('data' 	=> 'Action', 			'field' => '', 'style'=>'width: 10%;'),
     );
  
	$data = array(); 
	
	try{
			$query = db_select('c2s_charity_org_master', 'tbl')
                ->extend('PagerDefault')
                ->extend('TableSort');

                $query->fields('tbl', array('charity_organization_id', 'charity_org_name', 'number_501_c_3', 'phone_number', 'email_id', 'website_url', 'charity_org_address', 'charity_org_city', 'charity_org_state', 'charity_org_zip', 'charity_org_status','approval_status'))
                      ->limit(20)
                      ->orderByHeader($header)
                      ->orderBy('charity_org_status', 'ASC', 'approval_status', 'DESC'); 
					  
                $results = $query->execute();	
                foreach ($results as $row) {
					$id 	  			= $row->charity_organization_id; 
					$charity_org_name 	= $row->charity_org_name;
					$number_501_c_3    	= $row->number_501_c_3;
					$phone   			= $row->phone_number;
					$email   			= $row->email_id;
					$website_url     	= $row->website_url;
					$address		 	= $row->charity_org_address .', '.$row->charity_org_city.', '.$row->charity_org_state.' - '.$row->charity_org_zip;
					$org_status		 	= $row->charity_org_status;	
					$approval_status	= $row->approval_status;	
					
					if($approval_status=='R'){
						$approval_image = "<img src='".base_path()."/".drupal_get_path('module', 'general')."/images/rejected-stamp.jpg' width='50px'>";
					}elseif($approval_status=='A'){
						$approval_image = "<img src='".base_path()."/".drupal_get_path('module', 'general')."/images/approved-stamp.jpg' width='50px'>";
					}else{
						$approval_image = "<img src='".base_path()."/".drupal_get_path('module', 'general')."/images/pending-stamp.jpg' width='50px'>";
					}
					
					$edit	= "<a href='add/".$id."' id='edit_link' title='Edit Charity Organization'>
							   <img src='".base_path()."/".drupal_get_path('module', 'general')."/images/edit.png' style='width: 15px;margin-left: 10px;float:left'></a>";
					$view	= "<a href='view/".$id."' id='view_link'  title='View Charity Organization'>
							   <img src='".base_path()."/".drupal_get_path('module', 'general')."/images/view.png' style='width: 15px;margin-left: 10px;float:left'></a>";

					$data[] = array(  	   
								$charity_org_name, 	  
								$number_501_c_3,
								$phone,
								$email,	
								$website_url,
								$address,
								$approval_image,
								$edit.$view,
							);
                    $count++;
                }
	  
	  }catch(Exception $e){ drupal_set_message("Error: ".$e); }
	  
        if($count==0){
            $msgdata = "No records found!";
        }else{
            $msgdata = '';
        }  
    $output = '';      
	$output .= '<div id="main-view-wrapper">'.
				 theme('table', 
					array(
						'header' => $header,
						'rows' => $data,
					)
				 )."</div>";
        
	$output .= theme('pager');

