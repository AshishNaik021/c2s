<link href="<?php echo base_path()."/".drupal_get_path('module', 'broker') . '/css/global-c2s.css'; ?>" rel="stylesheet" />
<?php

    $count = 0;



    $header = array(
       array('data' => 'Employee Name', 'field' => '', 'style'=>'width: 15%;'),
       array('data' => 'NRDS #', 'field' => '', 'style'=>'width: 12%;'),
       array('data' => 'EIN #', 'field' => '', 'style'=>'width: 12%;'),
       array('data' => 'Address', 'field' => '', 'style'=>'width: 25%;'),
        array('data' => 'Email Id', 'field' => '', 'style'=>'width: 15%;'),
        array('data' => 'Phone', 'field' => '', 'style'=>'width: 9%;'),
        array('data' => 'Action', 'field' => '', 'style'=>'width: 12%;'),
     );
  
	$data = array(); 
	
	try{
                $query = db_select('broker_master', 'tbl')
                ->extend('PagerDefault')
                ->extend('TableSort');

                $query->condition('deactivate','0')
                         ->fields('tbl', array('broker_agent_id', 'first_name','last_name','home_address', 'home_city','home_state','home_zip','personal_email','personal_phone','nrds_number','ein_number'))
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
                                        $alloclink	  = "<a href='pms_employee_allocation?erid=".$id."&edt=2' id='edit_link' title=' Edit Employee Allocation'>
                                                        <img src='".base_path()."/".drupal_get_path('module', 'broker')."/images/edit.png' style='width: 15px;margin-left: 10px;float:left'></a>";
                                        $view		  = "<a href='pms_employee_view?erid=".$id."' id='view_link'  title='View Employee Profile'>
                                                        <img src='".base_path()."/".drupal_get_path('module', 'broker')."/images/delete.png' style='width: 15px;margin-left: 10px;float:left'></a>";



                          $data[] = array(  	   
                                        $fullname, 	  
                                        $nrds    ,
                                        $ein     ,
                                        $address ,	
                                        $email   ,
                                        $phone   ,
  
                                        $alloclink.$view,
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