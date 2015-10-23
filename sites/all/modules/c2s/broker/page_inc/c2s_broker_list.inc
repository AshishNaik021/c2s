<link href="<?php echo base_path()."/".drupal_get_path('module', 'general') . '/css/global-c2s.css'; ?>" rel="stylesheet" />
<?php

    $count = 0;



    $header = array(
       array('data' => 'Broker Name', 'field' => '', 'style'=>'width: 15%;'),
       array('data' => 'NRDS #', 'field' => '', 'style'=>'width: 12%;'),
       array('data' => 'EIN #', 'field' => '', 'style'=>'width: 12%;'),
       array('data' => 'Address', 'field' => '', 'style'=>'width: 25%;'),
        array('data' => 'Email Id', 'field' => '', 'style'=>'width: 15%;'),
        array('data' => 'Phone', 'field' => '', 'style'=>'width: 9%;'),
        array('data' => 'Action', 'field' => '', 'style'=>'width: 12%;'),
     );
  
	$data = array(); 
	
	try{
                $query = db_select('c2s_broker_master', 'tbl')
                ->extend('PagerDefault')
                ->extend('TableSort');

                $query->condition('status','A')
                ->condition('type','B')
                         ->fields('tbl', array('broker_agent_id', 'first_name','last_name','home_address', 'home_city','home_state','home_zip','personal_email','personal_phone','nrds_number','ein_number','brokerage_id'))
                         ->limit(20)
                         ->orderByHeader($header)
                         ->orderBy('broker_agent_id', 'DESC');
                

                $results = $query->execute();	

                foreach ($results as $row) {

                                        $id 	  = $row->broker_agent_id; 
                                        $fullname 	  = $row->first_name." ".$row->last_name;
                                        $address 	  = $row->home_address.", ".$row->home_city.", ".$row->home_state."-".$row->home_zip;
                                        $email   	  = $row->personal_email;
                                        $phone   	  = $row->personal_phone;
                                        $nrds    	  = $row->nrds_number;
                                        $ein     	  = $row->ein_number;
                                        $view	  = "<a href='view/".$row->brokerage_id."' id='edit_link' title=' View Broker Details'>
                                                        <img src='".base_path().drupal_get_path('module', 'general')."/images/edit.png' style='width: 15px;margin-left: 10px;float:left'></a>";
                                        $delete		  = "<a href='deactivate/".$id."/".$row->brokerage_id."' id='view_link'  title='Deactivate Broker'>
                                                        <img src='".base_path().drupal_get_path('module', 'general')."/images/delete.png' style='width: 15px;margin-left: 10px;float:left'></a>";



                          $data[] = array(  	   
                                        $fullname, 	  
                                        $nrds    ,
                                        $ein     ,
                                        $address ,	
                                        $email   ,
                                        $phone   ,
  
                                        $view.$delete,
                                );
                          
                          $count++;
                  }
	  
	  }catch(Exception $e){ drupal_set_message("Error: ".$e); }
	  
        if($count==0){
            $msgdata = "No records found!";
        }else{
            $msgdata = '';
        }  
          
	$data = '<div id="main-view-wrapper">'.theme('table', 
                            array(
                                'header' => $header,
                                'rows' => $data,
                            )
			)."</div>";
        
	$data .= theme('pager');

        
//$data .= '<div id="main-view-wrapper">'.$data.'</div>';
          
 
 
//            $form['employee_table'] = array(
//              '#type' => 'tableselect',
//              '#header' => $header,
//              '#options' => $data,
//              '#empty' => t('There are no date formats found in the db'),       
//            );
//
//           $form['pager'] = array('#markup' => theme('pager')); 