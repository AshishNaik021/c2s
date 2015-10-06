<?php
// ==================================================================================================
//                  Display Overtime Setting Table 
// ==================================================================================================
	
function ot_setting_display(){
$delete_img  	=  '<img src="../sites/all/modules/pms/support/images/delete.png" height="25px" width="25px">';	
$edit_image 	=  '<img src="../sites/all/modules/pms/support/images/edit.png" height="25px" width="25px"> ';

 $header = array(
    array('data' => 'Sr No',            'field' => 'ot_rate_id' , 'class' => (array ('sr_no')),             				  ),
    array('data' => 'Company Name',     'field' => 'company_id', 'sort' => 'ASC', 'class' => array('comp_id')),
    array('data' => 'Location Name', 	'field' => 'location_id', 'sort' => 'ASC', 'class' => array('loc_id')),
    array('data' => 'Category', 	    'field' => 'category', 'sort' => 'ASC', 'class' => array('category')),
    array('data' => 'Grade', 		    'field' => 'grade', 'sort' => 'ASC', 'class' => array('grade')),
    array('data' => 'Employee Type', 	'field' => 'employee_type', 'sort' => 'ASC', 'class' => array('emp_type')),
    array('data' => 'Rates', 		    'field' => 'rate_multiple', 'sort' => 'ASC', 'class' => array('rate_multiple')),
    array('data' => 'Action', 'class' => array('action')),
  );
  
  	$i=0;
	$data = array(); 
	
	$query = db_select('pms_setting_overtime ', 'tbl')
	
	->extend('PagerDefault')
        ->extend('TableSort');
 
	$query->condition('company_id', 1)
		 ->fields('tbl', array('ot_rate_id', 'company_id', 'location_id', 'category_id', 'grade_id', 'employee_type', 'rate_multiple'))
		 ->limit(5)
         ->orderByHeader($header)
		 ->orderBy('ot_rate_id', 'DESC');		
		 
	$results = $query->execute();	
		
	foreach ($results as $row) {
            $i++;
			$id           = $row->ot_rate_id; 
			$compay_id    = $row->company_id; 
			$location_id  = $row->location_id;
			$category_id  = $row->category_id;
			$grade_id     = $row->grade_id;
			$emp_type     = $row->employee_type;
			$rates        = $row->rate_multiple;
		
			$company_name   = get_comp_name_ot($compay_id);
			$location_name  = get_locn_name_ot($location_id);
			$category_name  = get_category_ot($category_id);
			$grade_name     = get_grade_ot($grade_id);
			
			if($emp_type == 'Yes'){$type = 'Unionized';}
			if($emp_type == 'No'){$type = 'Non-Unionized';}
			
		  $data[] = array( 
				 
                                'title1' => array(
                                'data' => $id,
                                'class' => array('sr_no')
                                ),
                      
                                'title2' => array(
                                'data' => $company_name,
                                'class' => array('comp_id')
                                ),
                      
                                'title3' => array(
                                'data' => $location_name,
                                'class' => array('loc_id')
                                ),
                      
                                'title4' => array(
                                'data' => $category_name,
                                'class' => array('category')
                                ),
                      
                                'title5' => array(
                                'data' => $grade_name,
                                'class' => array('grade')
                                ),
                      
                                'title6' => array(
                                'data' => $type,
                                'class' => array('emp_type')
                                ),
                      
                                'title7' => array(
                                'data' => $rates,
                                'class' => array('rate_multiple')
                                ),
                      
				
				'<a href="overtime_setting?ot_rate_id='.$id.'">'.$edit_image.' 		</a>
				<a href="delete_ot_setting?ot_rate_id='.$id.'">'.$delete_img.'   	</a>',
			);
	  }
          if ($i == 0) {
                $data[] = array('No Record Found');
            }
	$output = theme('table', 
					array(
						  'header' => $header, 
						  'rows' => $data,
					)
			);

	$output .= theme('pager');
			
	return $output;



}

function get_location_list(){
	$result	=	db_query("Select * from pms_master_entity ORDER BY city asc");	
	foreach($result as $record){
		$location[$record->code] 	= $record->city;
	}
	return $location;
}


// ==================================================================================================
//                 ALL GET FUNCTION FOR DISPLAY ADMIN SETTING MADULES
// ==================================================================================================

function get_comp_name_ot($comp_id){
	$result	=	db_query("Select name from pms_master_company where code = '".$comp_id."'");	
	foreach($result as $record){
		$name 	= $record->name;
	}
	return $name;
}

function get_locn_name_ot($lid){
	//drupal_set_message('Location  '.$lid);
	$city = '';
	$result	=	db_query("Select * from pms_master_entity where code = '".$lid."'");	
	foreach($result as $record){
		$city 	= $record->city;
	}
	return $city;
}
function get_category_ot($cat_id){
	$result	=	db_query("SELECT * 
							FROM pms_master_category 
					       WHERE category_id = '".$cat_id."'");	
	foreach($result as $record){
		$category 	= $record->description;
	}
	return $category;
}
function get_grade_ot($gid){
	$result	=	db_query("SELECT * 
							FROM pms_master_grade 
						   WHERE grade_id = '".$gid."'");	 
	foreach($result as $record){
		$grade_code 	= $record->grade_code;
	}
	return $grade_code;
}

function get_designation_ot($did){
	$designation_name ='';
	$result	=	db_query("SELECT * 
							FROM pms_master_designation
						   WHERE designation_id = ".$did
						   );	 
	foreach($result as $record){
		$designaion_name 	= $record->designation_name;
	}
	return $designation_name;
}


// ==================================================================================================
//                 DELETE ADMIN SETTIN ROWS
// ==================================================================================================
function get_user_id() {
  global $user;
  return $user->uid;
}


function delete_ot_setting(){
	$ot_rate_id = $_GET['ot_rate_id'];	
	$result	=	db_query("delete from pms_setting_overtime where ot_rate_id=".$ot_rate_id);	
	drupal_set_message('Over-Time Setting Deleted Successfully');
	header("location:../pms/overtime_setting");
}

function allocated_shift($empid, $ot_date){
	
	$allocated_shift ='';
	$result	=	db_query("SELECT * 
							FROM pms_shift_roster 
						   WHERE employee_id = '".$empid."' 
						     AND shift_date='".$ot_date."'
							 ");	
	foreach($result as $record){
		$allocated_shift 	= $record->allocated_shift;
	}
	return $allocated_shift;
}

function attendance_details($empid, $ot_date){
	$attendance_details['time_in']=0;  $attendance_details['time_out']=0; $attendance_details['total_hours']=0;
	$result	=	db_query("SELECT * 
							FROM pms_attendance_details 
						   WHERE employee_id = '".$empid."' 
						     AND attendance_date='".$ot_date."'
					");	
	foreach($result as $record){
		$attendance_details['time_in'] 		= $record->time_in;
		$attendance_details['time_out'] 	= $record->time_out;
		$attendance_details['total_hours'] 	= $record->total_hours;
	}
	
	return $attendance_details;
}




// ==================================================================================================
//                 OVERTIME VIEW CONFIRMATION RECIEPT
// ==================================================================================================
function overtime_details($ot_id){
	$result	=	db_query("SELECT * 
							FROM pms_ot_details 
						   WHERE ot_id = ".$ot_id
						   );	
	foreach($result as $record){
		$overtime_details['ot_id'] 				= $record->ot_id;
		$overtime_details['overtime_date'] 		= $record->overtime_date;
		$overtime_details['allocated_shift'] 	= $record->allocated_shift;
		$overtime_details['in_time'] 			= $record->in_time;
		$overtime_details['out_time'] 			= $record->out_time;
		$overtime_details['total_hours_worked'] = $record->total_hours_worked;
		$overtime_details['ot_start_time'] 		= $record->ot_start_time;
		$overtime_details['ot_end_time'] 		= $record->ot_end_time;
		$overtime_details['applied_ot_hours'] 	= $record->applied_ot_hours;
		$overtime_details['ot_reason'] 			= $record->ot_reason;
		$overtime_details['approved_ot_hours'] 	= $record->approved_ot_hours;
		$overtime_details['created'] 			= $record->created;
		$overtime_details['changed'] 			= $record->changed;
	}
	return $overtime_details;
}


// ==================================================================================================
//                 OVERTIME VIEW CONFIRMATION RECIEPT
// ==================================================================================================
function overtime_summary($application_id){
	$result	=	db_query("SELECT * 
							FROM pms_ot_summary
						   WHERE application_id = ". $application_id
						);	
	foreach($result as $record){
		$overtime_details['employee_id'] 		= $record->employee_id;
		$overtime_details['application_date'] 	= $record->application_date;
		$overtime_details['ot_status'] 			= $record->ot_status;
		$overtime_details['created'] 			= $record->created;
		$overtime_details['changed'] 			= $record->changed;
	}
	return $overtime_details;
}



function current_overtime_block($ot_id){
	$overtime_details 			= overtime_details($ot_id);
	$fromtime1 = substr($overtime_details['ot_start_time'],0,4);
	$fromtime2 = substr($overtime_details['ot_start_time'],4);
	$fromtime  = $fromtime1 .'&nbsp;'.$fromtime2;

	$totime1 = substr($overtime_details['ot_end_time'],0,4);
	$totime2 = substr($overtime_details['ot_end_time'],4);
	$totime	 = $totime1 .'&nbsp;'.$totime2;
	
	$detail = "<div id='view-leave-block'>
					<table id='report_table'>
						<tr> 
							<td> Over-Time Date:							</td>
							<td>From Time									</td>
							<td>To Time 									</td>
							<td>Applied O.T Hours			     			</td>
							<td>Approved O.T Hours			     			</td>
						</tr>
						<tr> 
							<td>". date('d/m/Y', strtotime($overtime_details['overtime_date'])) . "	</td>
							<td>". $fromtime . "	</td>
							<td>". $totime . "		</td>
							<td>". $overtime_details['applied_ot_hours'] . " Hrs</td>
							<td>". $overtime_details['approved_ot_hours'] . "</td>
						</tr>
						<tr> 
							<td colspan=8 > <span style='font-weight:bold;'> Reason for O.T / Remark: </span> &nbsp;	". $overtime_details['ot_reason'] . "	</td>
						</tr>
					</table>
				
				</div>";

	return $detail;
}


// ==================================================================================================
//                 EDIT CONFIRMATION RECIEPT 
// ==================================================================================================

function print_company_name_ot($company_name, $application_id, $month, $year){
	$pblock ='';
	if (isset($application_id)){ $pblock = get_print_block_ot($application_id, $month, $year); }
	$cn = "<div id='company-name'>". $company_name ."</div>";
	$var = $cn.$pblock;
	return $var;
}

function get_print_block_ot($application_id, $month, $year){
		global $user;
		$username = $user->name;	
               
		
		$overtime_summary			=	overtime_summary($application_id);
		$employee_id				=	$overtime_summary['employee_id'];
		$ot_status    				= 	$overtime_summary['ot_status'];
		
		if($username == $employee_id){
			$edit_status_count = get_edit_status_count($application_id, 'pms_ot_workflow', 'application_id');
			
			if($edit_status_count == 0){
                            
					$page_link = 'overtime_application_monthly?application_id='.$application_id.'&month='.$month.'&year='.$year.'';
					$edit =  "<td> <a class='edit-id'  title='Click To Edit The Application' href='$page_link'></a></td>";
                                       
			}else{
					$edit = '';
			}
		}		
		else
		{$edit='';}
                //drupal_set_message($employee_id.'- '.$username.'-- '.$edit);
        //<td> <a class='pnt-img'  title='Click To Print the Receipt' href='#' onclick='window.print()' ></a></td>
	//<td> <a class='pdf-img'  title='Click To Generate the PDF' href='#'></a></td>        
	$pblock = "<table id='print-blk-ot'><tr><td> <a class='pnt-img'  title='Click To Print the Receipt' href='#' onclick='window.print()' ></a></td>".$edit."</tr></table>";
	return $pblock;
}

// ==================================================================================================
//                 LIST OF APPLIED OVER TIME 
// ==================================================================================================
function list_ot_applied_monthly_block($empid, $module_name, $table_name,$selected_status){

//==========================================================
//		Preparation
//==========================================================
$emp_basic_details  = get_emp_basic_details(get_erid($empid));
$company_id             = $emp_basic_details['company_id'];
$location_id            = $emp_basic_details['location_id'];
$grade_id               = $emp_basic_details['grade_id'];
$login_grade_code       = get_description_detail('pms_master_grade', 'grade_code', 'grade_id', $grade_id);
$otedcode               = 206;
$ot_allowance_grade_arr = get_allowance_gradewise_arr($company_id, $location_id, $otedcode);
 if (in_array($login_grade_code, $ot_allowance_grade_arr))
 {
   
   	$purpose 	= "view";
	$title 		= "View O.T Detail";
	$view_img 	= get_icon_img($purpose, $title);

	$purpose 	= "edit";
	$title 		= "Edit O.T Detail";
	$edit_img 	= get_icon_img($purpose, $title);

	$purpose 		= "delete";
	$title 			= "Delete O.T Detail";
	$delete_img 	= get_icon_img($purpose, $title);

	$pms_role_id	= 	get_pms_roleid($empid);			//Get Mandatory Role ID from PMS EMPLOYEE Table
	$steps          =   approval_steps($module_name);	//Get Stepwise Role Ids from PMS_SETTING_WORKFLOW Table

	$wf_array 					= 	array();
	$wf_array['myempid']		=	$empid;
	$wf_array['myroleid']		=	$pms_role_id;
	$wf_array['module_name']	=	$module_name;
	$wf_array['table_name']		=	$table_name;
	$wf_array['steps']			=	$steps;
	
/*echo "SELECT * 
							FROM pms_ot_summary 
						   WHERE employee_id = '".$empid."' and ot_status='".$selected_status."'
						ORDER BY application_id DESC 
						   ";*/
//==========================================================
//		Select from Database
//==========================================================	
$result='';
	$result	=	db_query("SELECT * 
							FROM pms_ot_summary 
						   WHERE employee_id = '".$empid."' and ot_status='".$selected_status."'
						ORDER BY application_id DESC 
						   ");	
 	$i=0;
	foreach($result as $record){
		$application_id[]		= $record->application_id;
		$employee_id[]			= $record->employee_id;
		$application_date[]		= $record->application_date;
		$total_work_hours[]		= $record->total_work_hours;
		$total_excess_hours[]	= $record->total_excess_hours;
		$total_ot_hours[]		= $record->total_ot_hours;
		$total_approved_ot_hours[]		= $record->total_approved_ot_hours;
		$ot_status[]			= $record->ot_status;
		$month[]				= $record->month;
		$year[]					= $record->year;
		$i++; 
	}
	$row_count	= $i;

//==========================================================
//		Display List Table on Page
//==========================================================
		$applied_detail[] = "<div style='clear:both;'> <table id='report_table'> <tr>"; 
		$applied_detail[] = "<th style='text-align:center;'> Sr Number		  			</th>
							 <th> Application Details		</th>";							 
		$wf_array['request']	=	'Headers';
		$applied_detail[] 		=	workflow_logic($wf_array);		
		
		$applied_detail[] =		"<th> Action	 </th> </tr>";
		
	for($i=0; $i<$row_count; $i++){	
		$wf_array['application_id']	=	$application_id[$i];		
		$wf_array['applicant_id']	=	$employee_id[$i];
		$wf_array['request']		=	'Status';
		
		$applied_detail[] = "<tr> 
									<td style='text-align:center;'>".($i+1)."													</td>
									<td><div id='ot_detail_block'>
											<b>Application ID:</b> ".$application_id[$i].", <b>Application Date:</b> ".date('d/m/Y', strtotime($application_date[$i]))."</br>
											<b>OT Month:</b> ". date('M',strtotime(date('Y-'. $month[$i] .'-d')))  ." - ". $year[$i] ."  &nbsp; | &nbsp;<b>Total OT Hrs: </b> " .$total_ot_hours[$i]." Hrs
										</div>
									</td>";
																
	    $applied_detail[] = 	workflow_logic($wf_array);
		
		$edit_status_count = get_edit_status_count($application_id[$i], 'pms_ot_workflow', 'application_id');
		if($edit_status_count == 0){
				$editstatus 	= "<a href='overtime_application_monthly?application_id=$application_id[$i]'>  ". $edit_img ."		</a>";  
				$deletestatus 	= "<a href='overtime_application_delete?application_id=$application_id[$i]'>   ". $delete_img ." 	</a>";
		}else{
				$editstatus 	= "";  
				$deletestatus 	= "";
                                
		}
						
		$applied_detail[] =			"<td>	
											<a href='overtime_application_monthly_view?application_id=$application_id[$i]&viewer=O&month=$month[$i]&year=$year[$i]'> ". $view_img."		</a> 
											". $editstatus  ."
											". $deletestatus  ."
									</td>
									
								</tr>";
													
	} // End of For Loop 
	
	$applied_detail[] = "</table></div>";
	
	if($row_count == 0){
		$applied_detail[] = "<div style='line-height:50px;height:50px;width:100%;border:1px solid #666; background-color:#ffc;color:red;margin:0 auto;text-align:center;'> 
										List is Empty
								   </div>";
	}
  
   
 }
 else {
     
       $applied_detail[] = "<div style='line-height:50px;height:50px;width:100%;border:1px solid #666; background-color:#ffc;color:red;margin:0 auto;text-align:center;'> 
										This service not applicable for your grade.
								   </div>";
 }


	
	$detail = con_array_elements($applied_detail);
	return $detail;
}

function edit_inks($applid){
	$count = 0;
	$result	=	db_query("SELECT count(*) as idct from pms_ot_workflow 
						   WHERE application_id = '".$applid."' ");	
	foreach($result as $record){
		$count = $record->idct;
	}
	
	return $count;
}

// ==================================================================================================
//                 LIST OF APPLIED  OVER TIME FOR APPROVER 
// ==================================================================================================
function list_ot_approver_block($ids, $status, $module_name, $table_name){	
	
//==========================================================
//		Preparation
//==========================================================
	$purpose 	= "view";
	$title 		= "View O.T Detail";
	$view_img 	= get_icon_img($purpose, $title);


	$ids_str 		= implode("', '",$ids);
	$current_year 	= date('Y');
	$empid 			= get_empid();
	$pms_roleid 	= get_pms_roleid($empid);
	$my_step_num	= steps_in_workflow($module_name, $pms_roleid);
	
	$wf_array 					= 	array();
	$wf_array['myempid']		=	$empid;
	$wf_array['myroleid']		=	$pms_roleid;
	$wf_array['module_name']	=	$module_name;
	$wf_array['table_name']		=	$table_name;
//==========================================================
//		Select from Database
//==========================================================		

	switch($status){
		case('P'):
				$query = "SELECT * FROM pms_ot_summary 
						   WHERE employee_id in ('".$ids_str."')
							 AND EXTRACT(YEAR FROM application_date)  = ". $current_year ."
						     AND application_id NOT IN ( SELECT application_id FROM ".$table_name." WHERE step_number = '".$my_step_num."')
						 ";
				$selecte_status = 'Pending';
				break;
		case('A'):
				$query = "SELECT * FROM pms_ot_summary 
						   WHERE employee_id in ('".$ids_str."')
							 AND EXTRACT(YEAR FROM application_date)  = ". $current_year ."
						     AND application_id IN ( SELECT application_id FROM ".$table_name." WHERE STEP_NUMBER = '".$my_step_num."' AND decision = '".$status."')
						 ";
				$selecte_status = 'Approved';
				break;
		
		case('R'):
				$query = "SELECT * FROM pms_ot_summary 
						   WHERE employee_id in ('".$ids_str."')
							 AND EXTRACT(YEAR FROM application_date)  = ". $current_year ."
						     AND application_id IN ( SELECT application_id FROM ".$table_name." WHERE STEP_NUMBER = '".$my_step_num."' AND decision = '".$status."')
						 ";
				$selecte_status = 'Rejected';
				break;
	}
	
	$result	=	db_query($query);	
						 
	$i = 0;					 
	foreach($result as $record){
		$application_id[]		= $record->application_id;
		$employee_id[]			= $record->employee_id;
		$application_date[]		= $record->application_date;
		$total_work_hours[]		= $record->total_work_hours;
		$total_excess_hours[]	= $record->total_excess_hours;
		$total_ot_hours[]		= $record->total_ot_hours;
		$total_approved_ot_hours[]		= $record->total_approved_ot_hours;
		$ot_status[]			= $record->ot_status;
		$month[]				= $record->month;
		$year[]					= $record->year;
		$excess_status[]		= $record->excess_status;
		$i++; 
	}
	$row_count	=	$i;
		
//==========================================================
//		Display List Table on Page
//==========================================================		
			
		$applied_detail[] = "<div> <table id='report_table'> <tr>"; 
		$applied_detail[] = "<th> Sr Number		  		</th>
							 <th> Application Details	</th>";
			
		$wf_array['request']	=	'ApproverHeaders';	
		$applied_detail[] 		=	 workflow_logic($wf_array); 
		
		$applied_detail[] =		"<th> Action	 </th> </tr>";
	
	for($i=0; $i<$row_count; $i++){	
		$wf_array['application_id']	=	$application_id[$i];		
		$wf_array['applicant_id']	=	$employee_id[$i];
		$wf_array['request']		=	'RecordAccess';
				
		$rec_access = workflow_logic($wf_array); 

		if($rec_access==1){			// It means, Logged In person can see this Record. 
		
			$applied_detail[] = "<tr> 
									<td style='text-align:center;'>".($i+1)."													</td>
									<td><div id='ot_detail_block'>
											<b>Application ID:</b> ".$application_id[$i].", <b>Application Date:</b> ".date('d/m/Y', strtotime($application_date[$i]))."</br>
											<b>OT Month:</b> ". date('M',strtotime(date('Y-'. $month[$i] .'-d')))  ." - ". $year[$i] ."  &nbsp; | &nbsp;<b>Total OT Hrs: </b> " .$total_ot_hours[$i]." Hrs
										</div>
									</td>";
	
			$wf_array['request']	=	'ApproverStatus';
			$applied_detail[] 		=	 workflow_logic($wf_array); 

			$applied_detail[] = "<td><a href='overtime_application_monthly_view?application_id=$application_id[$i]&viewer=E&month=$month[$i]&year=$year[$i]'> ".$view_img." </a></td> </tr>";
		}
		
	} // End of For Loop 

	$applied_detail[] = "</table></div>";
	
	$detail = con_array_elements($applied_detail);

	if($i == 0){
		$detail = "<div style='line-height:50px;height:50px;width:100%;border:1px solid #666; background-color:#ffc;color:red;margin:0 auto;text-align:center;'> 
										No Overtime Request for ".$selecte_status.". 
								   </div>";
	}
	
	return $detail;
}

// ==================================================================================================
//                 LIST OF APPLIED  OVER TIME MONTHLY FOR APPROVER 
// ==================================================================================================
function list_ot_monthly_approver_block($ids, $status, $module_name, $table_name){	
	
//==========================================================
//		Preparation
//==========================================================
	$purpose 	= "view";
	$title 		= "View O.T Detail";
	$view_img 	= get_icon_img($purpose, $title);


	$ids_str 	= implode("', '",$ids);
	$current_year 	= date('Y');
	$empid 		= get_empid();
	$pms_roleid 	= get_pms_roleid($empid);
	$my_step_num	= steps_in_workflow($module_name, $pms_roleid);
	
	$wf_array 			= 	array();
	$wf_array['myempid']		=	$empid;
	$wf_array['myroleid']		=	$pms_roleid;
	$wf_array['module_name']	=	$module_name;
	$wf_array['table_name']		=	$table_name;
//==========================================================
//		Select from Database
//==========================================================		
$flag = 0;	
$row_count=0;// Flag set 0 up to first lebel MGR shows List is empty 
$current_year = date('Y');
$last_year    = $current_year - 1;
$all_employees_ids = array_chunk($ids, 10,true);
$i = 0;		
 for ($j = 0; $j < count($all_employees_ids); $j++) { 
 $all_employees_list_comma_separated = implode("','" , $all_employees_ids[$j]);
   $query='';
   $result='';
	switch($status){
		case('P'):
				$query = "SELECT * FROM pms_ot_summary 
						   WHERE employee_id in ('".$all_employees_list_comma_separated."')
							 AND (year   = '". $current_year ."' OR year   = '". $last_year ."')
						     AND application_id NOT IN ( SELECT application_id FROM ".$table_name." WHERE step_number = '".$my_step_num."' )
						 ";
				$selecte_status = 'Pending';
				break;
		case('A'):
				$query = "SELECT * FROM pms_ot_summary 
						   WHERE employee_id in ('".$all_employees_list_comma_separated."')
							 AND (year   = '". $current_year ."' OR year   = '". $last_year ."')
						     AND application_id  IN ( SELECT application_id FROM ".$table_name." WHERE step_number = '".$my_step_num."' AND decision = '".$status."')
						 ";
				$selecte_status = 'Approved';
				break;
		
		case('R'):
				$query = "SELECT * FROM pms_ot_summary 
						   WHERE employee_id in ('".$all_employees_list_comma_separated."')
							 AND (year   = '". $current_year ."' OR year   = '". $last_year ."')
						     AND application_id  IN ( SELECT application_id FROM ".$table_name." WHERE step_number = '".$my_step_num."' AND decision = '".$status."')
						 ";
				$selecte_status = 'Rejected';
				break;
	}
 //echo  $query;
  $result=array();
	$result	=	db_query($query);	
		if(count($result)>0)
    {
      foreach($result as $record){
		$application_id[$i]				= $record->application_id;
		$employee_id[$i]				= $record->employee_id;
		$application_date[$i]				= $record->application_date;
		$total_work_hours[$i]				= $record->total_work_hours;
		$total_excess_hours[$i]				= $record->total_excess_hours;
		$total_ot_hours[$i]				= $record->total_ot_hours;
		$total_approved_ot_hours[$i]                    = $record->total_approved_ot_hours;
		$ot_status[$i]					= $record->ot_status;
		$month[$i]					= $record->month;
		$year[$i]					= $record->year;
		$excess_status[]                                = $record->excess_status;
		$i++;
	}
	
      
    }
	
  
  
	
  
   }
  $row_count	=	$i;
   //display($application_id);
//==========================================================
//		Display List Table on Page
//==========================================================		
		$applied_detail[] = "<div> <table id='report_table'> <tr>"; 
		$applied_detail[] = "<th class='sr_no'> Sr No		  		</th>
                <th class='sr_no'> Application id		  		</th>
							 <th class='app_details'> Application Details	</th>";
			
		$wf_array['request']	=	'ApproverHeaders';	
		$applied_detail[] 	=	 workflow_logic($wf_array); 
		
		$applied_detail[]       =	"<th class='action'> Action	 </th> </tr>";
	//echo $row_count;
    
	for($i=0; $i<$row_count; $i++){	
   // echo $application_id[$i];	
		$wf_array['application_id']	=	$application_id[$i];		
		$wf_array['applicant_id']	=	$employee_id[$i];
		$wf_array['request']		=	'RecordAccess';
				
		//$rec_access = workflow_logic($wf_array); 
		
		//if($rec_access==1){			// It means, Logged In person can see this Record. 
		     $flag = 1; 				// Flag set 1 List is not empty 
			$applied_detail[] = "<tr> 
                                                <td  class='sr_no' style='text-align:center;'>".($i+1)."					 </td>
                                                  <td  class='sr_no' style='text-align:center;'>".$wf_array['application_id']."					 </td>
                                                <td  class='app_details'><div id='ot_detail_block'>
                                                        <b>Employee ID:</b> ".$employee_id[$i] ." &nbsp;&nbsp; | &nbsp;<b>Name :</b> ".get_empname_wtmn($employee_id[$i]) ."</br>
                                                        <b>OT Month:</b> ". date('M',strtotime(date('Y-'. $month[$i] .'-d')))  ." - ". $year[$i] ."  &nbsp; | &nbsp;<b>Total OT Hrs: </b> " .$total_ot_hours[$i]." Hrs
                                                </div></td>";
	
			$wf_array['request']	=	'ApproverStatus';
			$applied_detail[] 	=	 workflow_logic($wf_array); 

			$applied_detail[] = "<td class='action'><a href='overtime_application_monthly_approver_form?application_id=$application_id[$i]&viewer=E&month=$month[$i]&year=$year[$i]' title='View O.T Reciept'> ".$view_img." </a></td> </tr>";
		//}
		
	} // End of For Loop 

	$applied_detail[] = "</table></div>";
	
	$detail = con_array_elements($applied_detail);
   //display($wf_array);     
	if($flag == 0){
		$detail = "<div style='line-height:50px;height:50px;width:100%;border:1px solid #666; background-color:#ffc;color:red;margin:0 auto;text-align:center;'> 
										No Overtime Request for ".$selecte_status.". 
								   </div>";
	}
	return $detail;
}


// ==================================================================================================
//                 LIST OF LOCATION WISE MONTHLY OVERTIME LIST
// ==================================================================================================
function location_wise_monthly_ot_list($ids, $status, $module_name, $table_name, $location){	
	
//==========================================================
//		Preparation
//==========================================================
	$purpose 	= "view";
	$title 		= "View O.T Detail";
	$view_img 	= get_icon_img($purpose, $title);


	$ids_str 	= implode("', '",$ids);
	$current_year 	= date('Y');
	$empid 		= get_empid();
	$pms_roleid 	= get_pms_roleid($empid);
	$my_step_num	= steps_in_workflow($module_name, $pms_roleid);
	
	$wf_array 					= 	array();
	$wf_array['myempid']		=	$empid;
	$wf_array['myroleid']		=	$pms_roleid;
	$wf_array['module_name']	=	$module_name;
	$wf_array['table_name']		=	$table_name;
//==========================================================
//		Select from Database
//==========================================================		
$current_year = date('Y');
$last_year    = $current_year - 1;
// AND employee_id in (SELECT employee_id FROM pms_employee WHERE location_id ='".$location."')
	switch($status){
		case('P'):
				$query = "SELECT * FROM pms_ot_summary 
						   WHERE employee_id in (SELECT employee_id 
                                                                           FROM pms_employee 
                                                                          WHERE location_id = '".$location."')
						     AND ot_status = '".$status."'
							 AND (year   = '". $current_year ."' OR year   = '". $last_year ."')
							 
						    -- AND application_id NOT IN ( SELECT application_id FROM ".$table_name." WHERE step_number = '".$my_step_num."')
						 ";
				$selecte_status = 'Pending';
				break;
		case('A'):
				$query = "SELECT * FROM pms_ot_summary 
						   WHERE employee_id in (SELECT employee_id 
                                                                           FROM pms_employee 
                                                                          WHERE location_id = '".$location."')
						     AND ot_status = '".$status."'
							 AND (year   = '". $current_year ."' OR year   = '". $last_year ."')
						
						    -- AND application_id NOT IN ( SELECT application_id FROM ".$table_name." WHERE step_number = '".$my_step_num."')
						 ";
				$selecte_status = 'Approved';
				break;
		
		case('R'):
				$query = "SELECT * FROM pms_ot_summary 
						   WHERE employee_id in (SELECT employee_id 
                                                                           FROM pms_employee 
                                                                          WHERE location_id = '".$location."')
						     AND ot_status = '".$status."'
							 AND (year   = '". $current_year ."' OR year   = '". $last_year ."')
							
						     --AND application_id NOT IN ( SELECT application_id FROM ".$table_name." WHERE step_number = '".$my_step_num."')
						 ";
				$selecte_status = 'Rejected';
				break;
	}
 // echo $query;
	$result	=	db_query($query);	
	$i = 0;					 
	foreach($result as $record){
		$application_id[$i]				= $record->application_id;
		$employee_id[$i]				= $record->employee_id;
		$application_date[$i]				= $record->application_date;
		$total_work_hours[$i]				= $record->total_work_hours;
		$total_excess_hours[$i]				= $record->total_excess_hours;
		$total_ot_hours[$i]				= $record->total_ot_hours;
		$total_approved_ot_hours[$i]                    = $record->total_approved_ot_hours;
		$ot_status[$i]					= $record->ot_status;
		$month[$i]					= $record->month;
		$year[$i]					= $record->year;
		$excess_status[]				= $record->excess_status;
                
		$i++;
	}
	
	 $row_count	=	$i;
//==========================================================
//		Display List Table on Page
//==========================================================		
		$applied_detail[] = "<div> <table id='report_table'> <tr>"; 
		$applied_detail[] = "<th class='sr-no'> Sr Number		  		</th>
				     <th class='app_details'> Application Details	</th>";
			
		$wf_array['request']        =	'ApproverHeaders';	
		$applied_detail[]           =	 workflow_logic($wf_array); 
		
		$applied_detail[]           =	"<th class='action'> Action	 </th> </tr>";
	
	for($i=0; $i<$row_count; $i++){	
                if(empty($total_approved_ot_hours[$i])){$aprothrs = $total_ot_hours[$i];}
                else{$aprothrs = $total_approved_ot_hours[$i];}
		$wf_array['application_id']	=	$application_id[$i];		
		$wf_array['applicant_id']	=	$employee_id[$i];
		$wf_array['request']		=	'RecordAccess';
				
		$rec_access = workflow_logic($wf_array); 

		//if($rec_access==1){			// It means, Logged In person can see this Record. 
		
			$applied_detail[] = "<tr> 
										<td style='text-align:center;'>".($i+1)."					 </td>
										<td><div id='ot_detail_block'>
											<b>Employee ID:</b> ".$employee_id[$i] ." &nbsp;&nbsp; | &nbsp;<b>Name :</b> ".get_empname_wtmn($employee_id[$i]) ."</br>
											<b>OT Month:</b> ". date('M',strtotime(date('Y-'. $month[$i] .'-d')))  ." - ". $year[$i] ."  &nbsp; | &nbsp;<b>Total OT Hrs: </b> " .$total_ot_hours[$i]." Hrs 	</div></td>";
	
			$wf_array['request']	=	'ApproverStatus';
			$applied_detail[] 		=	 workflow_logic($wf_array); 

			$applied_detail[] = "<td><a href='overtime_application_monthly_approver_form?application_id=$application_id[$i]&viewer=E&month=$month[$i]&year=$year[$i]' title='View O.T Reciept'> ".$view_img." </a></td> </tr>";
	//	}
		
	} // End of For Loop 

	$applied_detail[] = "</table></div>";
	
	$detail = con_array_elements($applied_detail);

	if($i == 0){
		$detail = "<div style='line-height:50px;height:50px;width:100%;border:1px solid #666; background-color:#ffc;color:red;margin:0 auto;text-align:center;'> 
										There are no pending requests. 
								   </div>";
	}
	return $detail;
}


// ==================================================================================================
//                 LIST OF MONTH WISE MONTHLY OVERTIME LIST
// ==================================================================================================
function month_wise_monthly_ot_list($ids, $status, $module_name, $table_name, $selected_year, $selected_month,$selected_comp,$selected_loc){	
//==========================================================
//		Preparation
//==========================================================
	$purpose 	= "view";
	$title 		= "View O.T Detail";
	$view_img 	= get_icon_img($purpose, $title);


	$ids_str 	= implode("', '",$ids);
	$current_year 	= date('Y');
	$empid 		= get_empid();
	$pms_roleid 	= get_pms_roleid($empid);
	$my_step_num	= steps_in_workflow($module_name, $pms_roleid);
	
	$wf_array 					= 	array();
	$wf_array['myempid']		=	$empid;
	$wf_array['myroleid']		=	$pms_roleid;
	$wf_array['module_name']	=	$module_name;
	$wf_array['table_name']		=	$table_name;
//==========================================================
//		Select from Database
//==========================================================
$erid = get_erid($empid);
$emp_location = get_emp_basic_details($erid); 

$current_year = date('Y');
$last_year    = $current_year - 1;
	switch($status){
		case('P'):
				$query = "SELECT * FROM pms_ot_summary 
						   WHERE employee_id in (SELECT employee_id 
                                          FROM pms_employee WHERE
                                          company_id = '".$selected_comp."' AND
                                          location_id = '".$selected_loc."')
						     AND ot_status = '".$status."'
							 AND year   = '". $selected_year ."' 
							 AND month   = '". $selected_month ."'
						   --  AND application_id NOT IN ( SELECT application_id FROM ".$table_name." WHERE step_number = '".$my_step_num."')
						 ";
				$selecte_status = 'Pending';
				break;
		case('A'):
				$query = "SELECT * FROM pms_ot_summary 
						   WHERE employee_id in (SELECT employee_id 
                                                                            FROM pms_employee 
                                                                           WHERE location_id = '".$emp_location['location_id']."')
						     AND ot_status = '".$status."'
							 AND year   = '". $selected_year ."' 
							 AND month   = '". $selected_month ."'
						    -- AND application_id NOT IN ( SELECT application_id FROM ".$table_name." WHERE step_number = '".$my_step_num."')
						 ";
				$selecte_status = 'Approved';
				break;
		
		case('R'):
				$query = "SELECT * FROM pms_ot_summary 
						   WHERE employee_id in (SELECT employee_id 
                                                                            FROM pms_employee 
                                                                           WHERE location_id = '".$emp_location['location_id']."')
						     AND ot_status = '".$status."'
							 AND year   = '". $selected_year ."' 
							 AND month   = '". $selected_month ."'
						    -- AND application_id NOT IN ( SELECT application_id FROM ".$table_name." WHERE step_number = '".$my_step_num."')
						 ";
				$selecte_status = 'Rejected';
				break;
	}
	$result	=	db_query($query);	
	$i = 0;					 
	foreach($result as $record){
		$application_id[$i]					= $record->application_id;
		$employee_id[$i]					= $record->employee_id;
		$application_date[$i]				= $record->application_date;
		$total_work_hours[$i]				= $record->total_work_hours;
		$total_excess_hours[$i]				= $record->total_excess_hours;
		$total_ot_hours[$i]					= $record->total_ot_hours;
		$total_approved_ot_hours[$i]		= $record->total_approved_ot_hours;
		$ot_status[$i]						= $record->ot_status;
		$month[$i]							= $record->month;
		$year[$i]							= $record->year;
		$excess_status[]					= $record->excess_status;
		$i++;
	}
	
	$row_count	=	$i;
//==========================================================
//		Display List Table on Page
//==========================================================		
		$applied_detail[] = "<div> <table id='report_table'> <tr>"; 
		$applied_detail[] = "<th> Sr Number		  		</th>
                <th> Application id		  		</th>
							 <th> Application Details	</th>";
			
		$wf_array['request']	=	'ApproverHeaders';	
		$applied_detail[] 		=	 workflow_logic($wf_array); 
		
		$applied_detail[] =		"<th> Action	 </th> </tr>";
	
	for($i=0; $i<$row_count; $i++){	
		$wf_array['application_id']	=	$application_id[$i];		
		$wf_array['applicant_id']	=	$employee_id[$i];
		$wf_array['request']		=	'RecordAccess';
				
		$rec_access = workflow_logic($wf_array); 

		//if($rec_access==1){			// It means, Logged In person can see this Record. 
		
			$applied_detail[] = "<tr> 
										<td style='text-align:center;'>".($i+1)."					 </td>
                      <td style='text-align:center;'>".$wf_array['application_id']."					 </td>
										<td><div id='ot_detail_block'>
											<b>Employee ID:</b> ".$employee_id[$i] ." &nbsp;&nbsp; | &nbsp;<b>Name :</b> ".get_empname_wtmn($employee_id[$i]) ."</br>
											<b>OT Month:</b> ". date('M',strtotime(date('Y-'. $month[$i] .'-d')))  ." - ". $year[$i] ."  &nbsp; | &nbsp;<b>Total OT Hrs: </b> " .$total_ot_hours[$i]." Hrs
										</div></td>";
	
			$wf_array['request']	=	'ApproverStatus';
			$applied_detail[] 		=	 workflow_logic($wf_array); 

			$applied_detail[] = "<td><a href='overtime_application_monthly_approver_form?application_id=$application_id[$i]&viewer=E&month=$month[$i]&year=$year[$i]' title='View O.T Reciept'> ".$view_img." </a></td> </tr>";
		//}
		
	} // End of For Loop 

	$applied_detail[] = "</table></div>";
	
	$detail = con_array_elements($applied_detail);

	if($i == 0){
		$detail = "<div style='line-height:50px;height:50px;width:100%;border:1px solid #666; background-color:#ffc;color:red;margin:0 auto;text-align:center;'> 
										There are no pending requests. 
								   </div>";
	}
	return $detail;
}

// ==================================================================================================
//                 LIST OF APPLIED OVER TIME FOR MORE THAN 50 HOURS OPERATIONAL HEAD APPROVEL
// ==================================================================================================

function excess_monthly_ot_list($ids, $module_name, $table_name, $selected_year, $selected_month, $selected_status){	
    
$image      = '../sites/all/modules/pms/support/images/pending.png';
$show_img   = "<img src='".$image."' width=35px; height = 35px; /> ";

if($selected_status == 'A'){
    $image      = '../sites/all/modules/pms/support/images/approved.png';
    $show_img 	= "<img src='".$image."' width=40px; height = 40px; /> ";
    
}
if($selected_status == 'R'){
    $image 	= '../sites/all/modules/pms/support/images/rejected.jpg';
    $show_img 	= "<img src='".$image."' width=40px; height = 40px; /> ";
    
}
//==========================================================
//		Preparation
//==========================================================
	$purpose 	= "view";
	$title 		= "View O.T Detail";
	$view_img 	= get_icon_img($purpose, $title);

        $ids_arr        = array_chunk($ids, 1000);
	//$ids_str 	= implode("', '",$ids);
        //$ids_str 	= '103374';
	$current_year 	= date('Y');
	$empid 		= get_empid();
	$pms_roleid 	= get_pms_roleid($empid);
	$my_step_num	= steps_in_workflow($module_name, $pms_roleid);
	
	$wf_array 			= 	array();
	$wf_array['myempid']		=	$empid;
	$wf_array['myroleid']		=	$pms_roleid;
	$wf_array['module_name']	=	$module_name;
	$wf_array['table_name']		=	$table_name;
//==========================================================
//		Select from Database
//==========================================================	
$erid = get_erid($empid);
$emp_location = get_emp_basic_details($erid);   

$max_ot_hours_op = 50;
//drupal_set_message('-- '.$ids_str);
$current_year = date('Y');
$last_year    = $current_year - 1;
 $i = 0;	
    //for($k = 0; $k < count($ids_arr); $k++){
            //$ids_str = implode("', '",$ids_arr[$k]);
            //$ids_str = '103374';
            $query = "SELECT * FROM pms_ot_summary 
                       WHERE employee_id in (SELECT employee_id 
                                               FROM pms_employee 
                                              WHERE location_id = '".$emp_location['location_id']."'
                                                AND company_id = '".$emp_location['company_id']."')
                                     AND year   = '". $selected_year ."' 
                                     AND month   = '". $selected_month ."'
                                     AND total_ot_hours   > ". $max_ot_hours_op ."
                                     AND ot_status   = '".$selected_status."'
                             ";
            $result = db_query($query);	
            //drupal_set_message($query);
            foreach($result as $record){
                    $application_id[$i]					= $record->application_id;
                    $employee_id[$i]					= $record->employee_id;
                    $application_date[$i]				= $record->application_date;
                    $total_work_hours[$i]				= $record->total_work_hours;
                    $total_excess_hours[$i]				= $record->total_excess_hours;
                    $total_ot_hours[$i]					= $record->total_ot_hours;
                    $total_approved_ot_hours[$i]                        = $record->total_approved_ot_hours;
                    $ot_status[$i]					= $record->ot_status;
                    $month[$i]						= $record->month;
                    $year[$i]						= $record->year;
                    $excess_status[]					= $record->excess_status;
                    $i++;
            }
    //}
	$row_count	=	$i;
        //drupal_set_message($row_count);
//==========================================================
//		Display List Table on Page
//==========================================================		
		$applied_detail[] = "<div> <table id='report_table'> <tr>"; 
		$applied_detail[] = "<th> Sr Number                                     </th>
							 <th> Application Details	</th>";
			
		$wf_array['request']	=	'ApproverHeaders';	
		$applied_detail[] 	=	 workflow_logic($wf_array); 
		$applied_detail[] =		"<th> Status	 </th> ";
		$applied_detail[] =		"<th> Action	 </th> </tr>";
	
	for($i=0; $i<$row_count; $i++){	
		$wf_array['application_id']	=	$application_id[$i];		
		$wf_array['applicant_id']	=	$employee_id[$i];
		$wf_array['request']		=	'RecordAccess';
				
		$rec_access = workflow_logic($wf_array); 

		$roleid 	= get_pms_roleid($empid);
                
		if($roleid == 18){$rec_access = 1;}

		if($rec_access==1){		// It means, Logged In person can see this Record. 
		
			$applied_detail[] = "<tr> 
                                                <td style='text-align:center;'>".($i+1)."					 </td>
                                                <td><div id='ot_detail_block'>
                                                        <b>Employee ID:</b> ".$employee_id[$i] ." &nbsp;&nbsp; | &nbsp;<b>Name :</b> ".get_empname_wtmn($employee_id[$i]) ."</br>
                                                        <b>OT Month:</b> ". date('M',strtotime(date('Y-'. $month[$i] .'-d')))  ." - ". $year[$i] ."  &nbsp; | &nbsp;<b>Total OT Hrs: </b> " .$total_ot_hours[$i]." Hrs
                                                </div></td>";
	
			$wf_array['request']	=	'ApproverStatus';
			$applied_detail[] 	=	 workflow_logic($wf_array); 
                        $applied_detail[]	=	'<td> '.$show_img.' </td>';
			$applied_detail[] = "<td><a href='overtime_application_monthly_approver_form?application_id=$application_id[$i]&viewer=E&month=$month[$i]&year=$year[$i]' title='View O.T Reciept'> ".$view_img." </a></td> </tr>";
		}
		
	} // End of For Loop 

	$applied_detail[] = "</table></div>";
	
	$detail = con_array_elements($applied_detail);

	if($i == 0){
		$detail = "<div style='line-height:50px;height:50px;width:100%;border:1px solid #666; background-color:#ffc;color:red;margin:0 auto;text-align:center;'> 
										List is Empty. 
								   </div>";
	}
	return $detail;
}




function get_supid($empid){
	$result	=	db_query("SELECT reporting_manager_emp_id 
						    FROM pms_employee 
						   WHERE employee_id ='". $empid ."'");	
	foreach($result as $record){
		$boss_id 	= $record->reporting_manager_emp_id;
	}
	return $boss_id;
}
function get_supid2($empid){
	$result	=	db_query("SELECT reporting_manager_emp_id 
						    FROM pms_employee 
						   WHERE employee_id ='". $empid ."'");	
	foreach($result as $record){
		$boss_id 	= $record->reporting_manager_emp_id;
	}
	return $boss_id;
}

function get_ids_of_role($roleid){
	$result	=	db_query("SELECT employee_id 
						    FROM pms_employee 
						   WHERE pms_role_id =".$roleid);	
	foreach($result as $record){
		$employee_id[] 	= $record->employee_id;
	}
	return $employee_id;
}





// ==================================================================================================
//                 LIST OF APPLIED OVER TIME MONTH-WISE
// ==================================================================================================
function monthwise_list_ot_applied_block($ids , $status, $module_name, $table_name, $year, $month){
	
//==========================================================
//		Preparation
//==========================================================
	$purpose 	= "view";
	$title 		= "View O.T Detail";
	$view_img 	= get_icon_img($purpose, $title);


	$ids_str 		= implode("', '",$ids);
	$current_year 	= date('Y');
	$empid 			= get_empid();
	$pms_roleid 	= get_pms_roleid($empid);
	$my_step_num	= steps_in_workflow($module_name, $pms_roleid);
	
	$wf_array 					= 	array();
	$wf_array['myempid']		=	$empid;
	$wf_array['myroleid']		=	$pms_roleid;
	$wf_array['module_name']	=	$module_name;
	$wf_array['table_name']		=	$table_name;
//==========================================================
//		Select from Database
//==========================================================		

	switch($status){
		case('P'):
				$query = "SELECT * FROM pms_ot_details 
						   WHERE employee_id in ('".$ids_str."')
						     AND EXTRACT(MONTH FROM overtime_date)  = '".$month."' 
							 AND EXTRACT(YEAR FROM application_date)  = ". $year ."
						     AND ot_id NOT IN ( SELECT application_id FROM pms_ot_workflow WHERE step_number = '".$my_step_num."')
						 ";
				$selecte_status = 'Pending';
				break;
				
				break;
		case('A'):
				$query = "SELECT * FROM pms_ot_details 
						   WHERE employee_id in ('".$ids_str."')
						     AND EXTRACT(MONTH FROM overtime_date)  = '".$month."' 
							 AND EXTRACT(YEAR FROM application_date)  = ". $year ."
						     AND ot_id IN ( SELECT application_id FROM pms_ot_workflow WHERE STEP_NUMBER = '".$my_step_num."' AND decision = '".$status."')
						 ";
				$selecte_status = 'Approved';
				break;
		
		case('R'):
				$query = "SELECT * FROM pms_ot_details 
						   WHERE employee_id in ('".$ids_str."')
						     AND EXTRACT(MONTH FROM overtime_date)  = '".$month."' 
							 AND EXTRACT(YEAR FROM application_date)  = ". $year ."
						     AND ot_id IN ( SELECT application_id FROM pms_ot_workflow WHERE STEP_NUMBER = '".$my_step_num."' AND decision = '".$status."')
						 ";
				$selecte_status = 'Rejected';
				break;
	}
	
	$result	=	db_query($query);	
	
						 
	$i = 0;					 
	foreach($result as $record){
		$ot_id[$i]					= $record->ot_id;
		$employee_id[$i]			= $record->employee_id;
		$application_date[$i]		= $record->application_date;
		$overtime_date[$i]			= $record->overtime_date;
		$allocated_shift[$i]		= $record->allocated_shift;
		$in_time[$i]				= $record->in_time;
		$out_time[$i]				= $record->out_time;
		$total_hours_worked[$i]		= $record->total_hours_worked;
		$ot_start_time[$i]			= $record->ot_start_time;
		$ot_end_time[$i]			= $record->ot_end_time;
		$applied_ot_hours[$i]		= $record->applied_ot_hours;
		$ot_reason[$i]				= $record->ot_reason;
		$approved_ot_hours[$i]		= $record->approved_ot_hours;
		$created[$i]				= $record->created;
		$changed[$i]				= $record->changed;
		$i++;
	}

		$row_count	=	$i;
		
//==========================================================
//		Display List Table on Page
//==========================================================		
			
		$applied_detail[] = "<div> <table id='report_table'> <tr>"; 
		$applied_detail[] = "<th> Sr Number		  		</th>
							 <th> Application Details	</th>";
			
		$wf_array['request']	=	'ApproverHeaders';	
		$applied_detail[] 		=	 workflow_logic($wf_array); 
		
		$applied_detail[] =		"<th> Action	 </th> </tr>";
	
	for($i=0; $i<$row_count; $i++){	
		$wf_array['application_id']	=	$ot_id[$i];		
		$wf_array['applicant_id']	=	$employee_id[$i];
		$wf_array['request']		=	'RecordAccess';
				
		$rec_access = workflow_logic($wf_array); 

		if($rec_access==1){			// It means, Logged In person can see this Record. 
		
			$applied_detail[] = "<tr> 
										<td>".($i+1)."					 </td>
										<td><div id='ot_detail_block'>
											<b>Employee ID:</b> ".$employee_id[$i] ."</br>
											<b>Application ID:</b> ".$wf_array['application_id'].", <b>Date:</b> ".date('d/m/Y',strtotime($overtime_date[$i]))."</br>
										 	<b>Duration: </b> ".$ot_start_time[$i]." to ".$ot_end_time[$i].", <b>Hrs:</b> " .$applied_ot_hours[$i]." 
										</div></td>";
	
			$wf_array['request']	=	'ApproverStatus';
			$applied_detail[] 		=	 workflow_logic($wf_array); 

			$applied_detail[] = "<td><a href='overtime_application_view?ot_id=$ot_id[$i]&viewer=E' title='View O.T Reciept'> ".$view_img." </a></td> </tr>";
		}
		
	} // End of For Loop 

	$applied_detail[] = "</table></div>";
	
	$detail = con_array_elements($applied_detail);
	if($i == 0){
		$detail = "<div style='line-height:50px;height:50px;width:100%;border:1px solid #666; background-color:#ffc;color:red;margin:0 auto;text-align:center;'> 
										No Overtime Request for ".$selecte_status.". 
								   </div>";
	}
	
	return $detail;


}


// ==================================================================================================
//                 LIST OF APPLIED OVER TIME LOCATION-WISE
// ==================================================================================================
function location_wise_list_ot_applied_block($ids , $status, $module_name, $table_name, $location){

//==========================================================
//		Preparation
//==========================================================
	$purpose 	= "view";
	$title 		= "View O.T Detail";
	$view_img 	= get_icon_img($purpose, $title);


	$ids_str 		= implode("', '", $ids);
	$current_year 	= date('Y');
	$empid 			= get_empid();
	$pms_roleid 	= get_pms_roleid($empid);
	$my_step_num	= steps_in_workflow($module_name, $pms_roleid);
	
	$wf_array 					= 	array();
	$wf_array['myempid']		=	$empid;
	$wf_array['myroleid']		=	$pms_roleid;
	$wf_array['module_name']	=	$module_name;
	$wf_array['table_name']		=	$table_name;
//==========================================================
//		Select from Database
//==========================================================		

	switch($status){
		case('P'):
				$query = "SELECT * FROM pms_ot_details 
						   WHERE employee_id in ('".$ids_str."')
						     AND employee_id in (SELECT employee_id FROM pms_employee WHERE location_id ='".$location."')
						     AND ot_id NOT IN ( SELECT application_id FROM ".$table_name." WHERE step_number = '".$my_step_num."')
						 ";
				$selecte_status = 'Pending';
				break;
		case('A'):
				$query = "SELECT * FROM pms_ot_details 
						   WHERE employee_id in ('".$ids_str."')
						     AND employee_id in (SELECT employee_id FROM pms_employee WHERE location_id ='".$location."')
						     AND ot_id IN ( SELECT application_id FROM ".$table_name." WHERE STEP_NUMBER = '".$my_step_num."' AND decision = '".$status."')
						 ";
				$selecte_status = 'Approved';
				break;
		
		case('R'):
				$query = "SELECT * FROM pms_ot_details 
						   WHERE employee_id in ('".$ids_str."')
						     AND employee_id in (SELECT employee_id FROM pms_employee WHERE location_id ='".$location."')
						     AND ot_id IN ( SELECT application_id FROM ".$table_name." WHERE STEP_NUMBER = '".$my_step_num."' AND decision = '".$status."')
						 ";
				$selecte_status = 'Rejected';
				break;
	}
	
	$result	=	db_query($query);	
	
						 
	$i = 0;					 
	foreach($result as $record){
		$ot_id[$i]					= $record->ot_id;
		$employee_id[$i]			= $record->employee_id;
		$application_date[$i]		= $record->application_date;
		$overtime_date[$i]			= $record->overtime_date;
		$allocated_shift[$i]		= $record->allocated_shift;
		$in_time[$i]				= $record->in_time;
		$out_time[$i]				= $record->out_time;
		$total_hours_worked[$i]		= $record->total_hours_worked;
		$ot_start_time[$i]			= $record->ot_start_time;
		$ot_end_time[$i]			= $record->ot_end_time;
		$applied_ot_hours[$i]		= $record->applied_ot_hours;
		$ot_reason[$i]				= $record->ot_reason;
		$approved_ot_hours[$i]		= $record->approved_ot_hours;
		$created[$i]				= $record->created;
		$changed[$i]				= $record->changed;
		$i++;
	}

		$row_count	=	$i;
		
//==========================================================
//		Display List Table on Page
//==========================================================		
			
		$applied_detail[] = "<div> <table id='report_table'> <tr>"; 
		$applied_detail[] = "<th> Sr Number		  		</th>
							 <th> Application Details	</th>";
			
		$wf_array['request']	=	'ApproverHeaders';	
		$applied_detail[] 		=	 workflow_logic($wf_array); 
		
		$applied_detail[] =		"<th> Action	 </th> </tr>";
	
	for($i=0; $i<$row_count; $i++){	
		$wf_array['application_id']	=	$ot_id[$i];		
		$wf_array['applicant_id']	=	$employee_id[$i];
		$wf_array['request']		=	'RecordAccess';
				
		$rec_access = workflow_logic($wf_array); 

		if($rec_access==1){			// It means, Logged In person can see this Record. 
		
			$applied_detail[] = "<tr> 
										<td>".($i+1)."					 </td>
										<td><div id='ot_detail_block'>
											<b>Employee ID:</b> ".$employee_id[$i] ."</br>
											<b>Application ID:</b> ".$wf_array['application_id'].", <b>Date:</b> ".date('d/m/Y',strtotime($overtime_date[$i]))."</br>
										 	<b>Duration: </b> ".$ot_start_time[$i]." to ".$ot_end_time[$i].", <b>Hrs:</b> " .$applied_ot_hours[$i]." 
										</div></td>";
	
			$wf_array['request']	=	'ApproverStatus';
			$applied_detail[] 		=	 workflow_logic($wf_array); 

			$applied_detail[] = "<td><a href='overtime_application_view?ot_id=$ot_id[$i]&viewer=E' title='View O.T Reciept'> ".$view_img." </a></td> </tr>";
		}
		
	} // End of For Loop 

	$applied_detail[] = "</table></div>";
	
	$detail = con_array_elements($applied_detail);

	if($i == 0){
		$detail = "<div style='line-height:50px;height:50px;width:100%;border:1px solid #666; background-color:#ffc;color:red;margin:0 auto;text-align:center;'> 
										No Overtime Request for ".$selecte_status.". 
								   </div>";
	}
	
	
	return $detail;

}


// ==================================================================================================
//                 LIST OF APPLIED OVER TIME FOR MORE THAN 50 HOURS OPERATIONAL HEAD APPROVEL
// ==================================================================================================
function excess_claims_list_ot_applied_block($ids , $module_name, $month, $year, $table_name){
	$ids_str 		= implode("', '", $ids);
//==========================================================
//		Preparation
//==========================================================
	$purpose 	= "view";
	$title 		= "View O.T Detail";
	$view_img 	= get_icon_img($purpose, $title);

	$result	=	db_query("SELECT employee_id, sum(applied_ot_hours) as sum_applied_ot_hours 
							FROM pms_ot_details 
						   WHERE employee_id in ('".$ids_str."')
						     AND EXTRACT(MONTH FROM overtime_date) = '".$month."'
						     AND EXTRACT(YEAR FROM overtime_date)  = '".$year."'
						     AND status = 'A'
					    GROUP BY employee_id
						  HAVING sum(applied_ot_hours) > 1
						ORDER BY 1 ASC
						");	
	$i = 0;						   
	foreach($result as $record){
		$employee_id[$i]			= $record->employee_id;
		$applied_ot_hours[$i]		= $record->sum_applied_ot_hours;
		$i++;
	}
	
		$row_count	=	$i;
		$applied_detail[] = "<div> <table id='report_table'> <tr>"; 
		$applied_detail[] = "<th> Sr Number		  			</th>
							 <th> Applicant OT Details			</th>
							 <th> Action	 			</th> </tr>";
	
	for($i=0; $i<$row_count; $i++){	
		$applied_detail[] = "<tr> 
									<td>".  ($i+1)."									</td>
									<td><div id='ot_detail_block'>
										<b>Employee ID:</b> ".$employee_id[$i] ."</br>
										<b>Employee Name:</b> ". get_empname_wtmn($employee_id[$i]) ."</br>
										<b>OT in Month: </b> ". $applied_ot_hours[$i] ." 
									</div></td>";
		$applied_detail[] = "<td><a href='excess_overtime_application_details?employee_id=".$employee_id[$i]."&month=".$month."&year=".$year."' title='View '> ".$view_img." </a></td> </tr>";
	} // End of For Loop 

	$applied_detail[] = "</table></div>";
	$detail = con_array_elements($applied_detail);
	if($row_count == 0){
		$detail = "<div style='line-height:50px;height:50px;width:100%;border:1px solid #666; background-color:#ffc;color:red;margin:0 auto;text-align:center;'> 
										List is Empty 
								   </div>";
	}
	return $detail;
}



// ==================================================================================================
//               DETAIL LIST OF EMPLOYEE FOR MORE THAN 50 HOURS
// ==================================================================================================
function excess_overtime_detail_applied_block($pmsemployee_id, $module_name, $table_name, $month, $year){
//==========================================================
//		Preparation
//==========================================================
	$purpose 	= "view";
	$title 		= "View O.T Detail";
	$view_img 	= get_icon_img($purpose, $title);


	$current_year 	= date('Y');
	$empid 			= get_empid();
	$pms_roleid 	= get_pms_roleid($empid);
	$my_step_num	= steps_in_workflow($module_name, $pms_roleid);
	
	$wf_array 					= 	array();
	$wf_array['myempid']		=	$empid;
	$wf_array['myroleid']		=	$pms_roleid;
	$wf_array['module_name']	=	$module_name;
	$wf_array['table_name']		=	$table_name;
	
//==========================================================
//		Select from Database
//==========================================================		

	$result	=	db_query("SELECT * from pms_ot_details 
						   WHERE employee_id = '".$pmsemployee_id."' 
						     AND EXTRACT(MONTH FROM overtime_date) = '".$month."'
						   ");	
	$i = 0;
	foreach($result as $record){
		$ot_id[$i]					= $record->ot_id;
		$employee_id[$i]			= $record->employee_id;
		$application_date[$i]		= $record->application_date;
		$overtime_date[$i]			= $record->overtime_date;
		$allocated_shift[$i]		= $record->allocated_shift;
		$in_time[$i]				= $record->in_time;
		$out_time[$i]				= $record->out_time;
		$total_hours_worked[$i]		= $record->total_hours_worked;
		$ot_start_time[$i]			= $record->ot_start_time;
		$ot_end_time[$i]			= $record->ot_end_time;
		$applied_ot_hours[$i]		= $record->applied_ot_hours;
		$ot_reason[$i]				= $record->ot_reason;
		$approved_ot_hours[$i]		= $record->approved_ot_hours;
		$created[$i]				= $record->created;
		$changed[$i]				= $record->changed;
		$i++;
	}
		$row_count	=	$i;
		
//==========================================================
//		Display List Table on Page
//==========================================================		
			
		$applied_detail[] = "<div> <table id='report_table'> <tr>"; 
		$applied_detail[] = "<th> Sr Number		  		</th>
							 <th> Application Details	</th>";
			
		$wf_array['request']	=	'ApproverHeaders';	
		$applied_detail[] 		=	 workflow_logic($wf_array); 
		
		$applied_detail[] =		"<th> Action	 </th> </tr>";
	
	for($i=0; $i<$row_count; $i++){	
		$wf_array['application_id']	=	$ot_id[$i];		
		$wf_array['applicant_id']	=	$employee_id[$i];
		$wf_array['request']		=	'RecordAccess';
				
		$rec_access = workflow_logic($wf_array); 

		if($rec_access==1){			// It means, Logged In person can see this Record. 
		
			$applied_detail[] = "<tr> 
										<td>".($i+1)."					 </td>
										<td><div id='ot_detail_block'>
											<b>Employee ID:</b> ".$employee_id[$i] ."</br>
											<b>Application ID:</b> ".$wf_array['application_id'].", <b>Date:</b> ".date('d/m/Y',strtotime($overtime_date[$i]))."</br>
										 	<b>Duration: </b> ".$ot_start_time[$i]." to ".$ot_end_time[$i].", <b>Hrs:</b> " .$applied_ot_hours[$i]." 
										</div></td>";
	
			$wf_array['request']	=	'ApproverStatus';
			$applied_detail[] 		=	 workflow_logic($wf_array); 

			$applied_detail[] = "<td><a href='overtime_application_view?ot_id=$ot_id[$i]&viewer=E' title='View O.T Reciept'> ".$view_img." </a></td> </tr>";
		}
		
	} // End of For Loop 

	$applied_detail[] = "</table></div>";
	
	$detail = con_array_elements($applied_detail);

	if($i == 0){
		$detail = "<div style='line-height:50px;height:50px;width:100%;border:1px solid #666; background-color:#ffc;color:red;margin:0 auto;text-align:center;'> 
										List Is Empty 
								   </div>";
	}
	
	return $detail;
}



// ==================================================================================================
//                EXCESS OVER-TIME LIST OF EMPLOYEE
// ==================================================================================================
function excess_ot_list_block(){

	$result	=	db_query("SELECT * from pms_ot_details ");	
	$i=0;
	foreach($result as $record){
		$ot_id[$i]				= $record->ot_id;
		//$employee_id[$i]		= $record->employee_id;
		$application_date[$i]	= $record->overtime_date;
		$overtime_date[$i]		= $record->overtime_date;
		$allocated_shift[$i]	= $record->allocated_shift;
		$in_time[$i]			= $record->in_time;
		$out_time[$i]			= $record->out_time;
		$total_hours_worked[$i]	= $record->total_hours_worked;
		$ot_start_time[$i]		= $record->ot_start_time;
		$ot_end_time[$i]		= $record->ot_end_time;
		$applied_ot_hours[$i]	= $record->applied_ot_hours;
		$ot_reason[$i]			= $record->ot_reason;
		$approved_ot_hours[$i]	= $record->approved_ot_hours;
		$created[$i]			= $record->created;
		$changed[$i]			= $record->changed;
		$i++;
	}
	
		$row_count	=	$i;
		$applied_detail[] = "<div> <table id='report_table'> <tr>"; 
		$applied_detail[] = "<th> Sr Number		  		</th>
							 <th> Application Num		</th>
							 <th> Over-Time Date		</th>
							 <th> From Time	 			</th>
							 <th> To TIme				</th>
							 <th> Hours		 			</th>";
		$pms_role_id	  = 	get_pms_roleid($empid);		
		$applied_detail[] =		workflow_headers('OVERTIME',$pms_role_id);
		$applied_detail[] =		"<th> Action	 </th> </tr>";
	
	for($i=0; $i<$row_count; $i++){	
		$application_id = $ot_id[$i];		
		$applied_detail[] = "<tr> 
									<td>".($i+1)."										</td>
									<td>".$application_id."								</td>
									<td> ".date('d/m/Y',strtotime($overtime_date[$i]))."	</td>
									<td>". $ot_start_time[$i] ." 						</td>
									<td> ".$ot_end_time[$i]. "							</td>
									<td> ".$applied_ot_hours[$i]. "						</td>";
									
									$module_name = 'OVERTIME';
									$applied_detail[] = workflow_status($module_name,$table_name, $application_id, $employee_id[$i],$pms_role_id, 'approver_list'); 									
									
		$applied_detail[] =			"<td><a href='overtime_application_view?ot_id=$ot_id[$i]'  title='View O.T Reciept'> View </a> </td>
									
								</tr>";
													
	} // End of For Loop 
	$applied_detail[] = "</table></div>";
	$detail = con_array_elements($applied_detail);
	return $detail;
}




// ==================================================================================================
//                 SUB ORDINATE LIST OF APPLIED  OVER TIME 
// ==================================================================================================
function suordinate_list_ot_block($ids){
	
	$applied_detail[] = "<div><table id='report_table'> <tr>"; 

	for($i=0; $i<count($ids); $i++){	
		$applied_detail[] = "<tr> 
									<td><a href='excess_overtime_application_details?employee_id=$ids[$i]'> ".$ids[$i]. "	</td>
							</tr>";
													
	} // End of For Loop 
	$applied_detail[] = "</table></div>";
	
	$detail = con_array_elements($applied_detail);
	return $detail;

}

// ==================================================================================================
//                 OVER TIME APPLICATION DELETE FUNCTION
// ==================================================================================================

function overtime_application_delete($form, &$form_state) {

	$application_id = $_GET['application_id'];	
	$result	=	db_query("DELETE FROM pms_ot_details WHERE application_id=".$application_id." ");
	$result	=	db_query("DELETE FROM pms_ot_summary WHERE application_id=".$application_id." ");
	
	drupal_set_message('Over-Time Detail Deleted Successfully');
	header("location:../pms/overtime_application_monthly_employee_list");
}


//function get_max_role_id($module_name){
// 
//	$result	=	db_query("SELECT max(role_id) as maxrid
//							FROM pms_setting_workflow 
//						   WHERE module_name = '".$module_name."' 
//							");	
//	foreach($result as $record){
//		$maxrid				= $record->maxrid;
//	}
//	
//	return $maxrid;
//}


function get_attendance_details_date($att_date){

	$empid = get_empid(); 	
	$total_hours = '';
	if($att_date <> ''){
		$result	=	db_query("SELECT total_hours 
								FROM pms_attendance_details 
							   WHERE attendance_date = '".$att_date."' 
							   AND  employee_id = '".$empid."' 
								");	
		foreach($result as $record){
			$total_hours				= $record->total_hours;
		}
	}	

	$appl_ot  = $total_hours - 8;
	
	if($appl_ot<0){
	$detail = "<div id='get-attendance-wrap'> 
									You Can Not Apply Over-Time for This Date 
							   </div>";
	}else{
		$detail ='';;
	}
	
	
	return $detail;
}



function specific_overtime_application_validate($form, &$form_state)
{
	$employee_id		    =   $form_state['values']['emp_id'];
	$ot_id		   			=   $form_state['values']['ot_id'];
	
	$ot_date				=   $form_state['values']['ot_date'];

	$attendance_details['time_in'] 		= 0;
	$attendance_details['time_out'] 	= 0;
	$otcount							= 0;
	
	if(!empty($ot_date[0])){
		$allocated_shift		=   allocated_shift($employee_id, $ot_date);
		$attendance_details		=   attendance_details($employee_id, $ot_date);
	}
		
	$in_time				=   $attendance_details['time_in'];
	$out_time				=   $attendance_details['time_out'];
	
	$total_hours_worked		=	$attendance_details['total_hours'];
	
	$ot_start_time			=   $form_state['values']['ot_start_time'];
	$ot_start_time_ampm		=   $form_state['values']['ot_start_time_ampm'];
	$ot_end_time			=   $form_state['values']['ot_end_time'];
	$ot_end_time_ampm		=   $form_state['values']['ot_end_time_ampm'];
	$ot_hours				=   $form_state['values']['ot_hours'];
	
	$ot_for					=   $form_state['values']['ot_reason'];
	$status					=   '1';
	
	$start_time  			=  $ot_start_time.$ot_start_time_ampm;
	$end_time    			=  $ot_end_time.$ot_end_time_ampm;
	$exist = 0;

	if(!empty($ot_date[0])){
			$result = db_query("SELECT count(overtime_date) as count 
								  FROM pms_ot_details 
								 WHERE employee_id = '".$employee_id."' 
								   AND overtime_date ='".$ot_date."' 
							 ");
			foreach($result as $value){
				$otcount 			= $value->count;
			}
	}
	if($otcount > 0){
		$exist = 1;
	}

	if($out_time == 0)
	{
	  form_set_error('overtime1', 'Out Time is Missing on This Date ( '.date('d/m/Y', strtotime($ot_date)).' )');
	}
	if($in_time == 0)
	{
	  form_set_error('overtime2', 'In Time is Missing on This Date ( '.date('d/m/Y', strtotime($ot_date)).' )');
	}
	
	if($total_hours_worked <= 8)
	{
	  form_set_error('overtime3', 'Total Work Hours is Less Than  8 Hours on Date ( '.date('d/m/Y', strtotime($ot_date)).' )');
	}
	if($ot_id == 0){							
		if($exist == 1){
		  	form_set_error('overtime4', 'OverTime Already Exist for this Date ( '.date('d/m/Y', strtotime($ot_date)).' )');
		}
	}
	
	if($ot_hours <= 0.9){
	  form_set_error('overtime5', 'OverTime Could not be submited Less than One Hour');
	}	
}
//====================================================================================================================
//					Over Time Validation Form 
//====================================================================================================================

function overtime_application_validate($form, &$form_state)
{
	$employee_id		    =   $form_state['values']['emp_id'];
	$ot_id		   			=   $form_state['values']['ot_id'];
	
	$ot_date				=   $form_state['values']['ot_date'];

	$attendance_details['time_in'] 		= 0;
	$attendance_details['time_out'] 	= 0;
	$otcount							= 0;
	
	if(!empty($ot_date[0])){
		$allocated_shift		=   allocated_shift($employee_id, $ot_date);
		$attendance_details		=   attendance_details($employee_id, $ot_date);
	}
		
	$in_time				=   $attendance_details['time_in'];
	$out_time				=   $attendance_details['time_out'];
	
	$total_hours_worked		=	$attendance_details['total_hours'];
	
	$ot_start_time			=   $form_state['values']['ot_start_time'];
	$ot_start_time_ampm		=   $form_state['values']['ot_start_time_ampm'];
	$ot_end_time			=   $form_state['values']['ot_end_time'];
	$ot_end_time_ampm		=   $form_state['values']['ot_end_time_ampm'];
	$ot_hours				=   $form_state['values']['ot_hours'];
	
	$ot_for					=   $form_state['values']['ot_reason'];
	$status					=   '1';
	
	$start_time  			=  $ot_start_time.$ot_start_time_ampm;
	$end_time    			=  $ot_end_time.$ot_end_time_ampm;
	$exist = 0;

	if(!empty($ot_date[0])){
			$result = db_query("SELECT count(overtime_date) as count 
								  FROM pms_ot_details 
								 WHERE employee_id = '".$employee_id."' 
								   AND overtime_date ='".$ot_date."' 
							 ");
			foreach($result as $value){
				$otcount 			= $value->count;
			}
	}
	if($otcount > 0){
		$exist = 1;
	}

	if($out_time == 0)
	{
	  form_set_error('overtime1', 'Out Time is Missing on This Date ( '.date('d/m/Y', strtotime($ot_date)).' )');
	}
	if($in_time == 0)
	{
	  form_set_error('overtime2', 'In Time is Missing on This Date ( '.date('d/m/Y', strtotime($ot_date)).' )');
	}
	
	if($total_hours_worked <= 8)
	{
	  form_set_error('overtime3', 'Total Work Hours is Less Than  8 Hours on Date ( '.date('d/m/Y', strtotime($ot_date)).' )');
	}
	if($ot_id == 0){							
		if($exist == 1){
		  	form_set_error('overtime4', 'OverTime Already Exist for this Date ( '.date('d/m/Y', strtotime($ot_date)).' )');
		}
	}
	
	if($ot_hours <= 0.9){
	  form_set_error('overtime5', 'OverTime Could not be submited Less than One Hour');
	}	
}


function overtime_application_monthly_validate($form, &$form_state)
{
  $flag=0;
	$ot_rowcount 			= $form_state['values']['otfields']['ot_rowcount'];
	for($i=0; $i<$ot_rowcount; $i++){
		$ot_reason			= $form_state['values']['otfields']['ot_reason_'.$i];
		if(empty($ot_reason) || $ot_reason == '' || $ot_reason == ' '){
      $flag=1;
			
		}
	}// End Of For-loop
//  if($flag==1)
//  {
//    form_set_error('remark_1', 'Please Insert Remark Field ' );
//  }

}

function get_year_ot($current_year){
	$current_year 	= $current_year;
	$prev_year		= $current_year - 1;
	$years = array($prev_year=>$prev_year, $current_year=>$current_year);
	return $years;
}

function get_otdetails_monthly($application_id){
	$i = 0;
	$query =  "SELECT * 
				  FROM pms_ot_details
				 WHERE application_id 	= '".$application_id."' 
			  ORDER BY EXTRACT(DAY FROM overtime_date)";
	$result = db_query($query);	 
	foreach($result as $record)
	{ 	
	 	$otrecords['ot_id'][$i] 				= $record->ot_id;
	 	$otrecords['application_id'][$i] 		= $record->application_id;
	 	$otrecords['overtime_date'][$i] 		= $record->overtime_date;
	 	$otrecords['allocated_shift'][$i] 		= $record->allocated_shift;
	 	$otrecords['in_time'][$i] 				= $record->in_time;
	 	$otrecords['out_time'][$i] 				= $record->out_time;
	 	$otrecords['total_hours_worked'][$i] 	= $record->total_hours_worked;
	 	$otrecords['ot_start_time'][$i] 		= $record->ot_start_time;
	 	$otrecords['ot_end_time'][$i] 			= $record->ot_end_time;
	 	$otrecords['applied_ot_hours'][$i] 		= $record->applied_ot_hours;
	 	$otrecords['approved_ot_hours'][$i] 	= $record->approved_ot_hours;
	 	$otrecords['ot_reason'][$i] 			= $record->ot_reason;
		$i++;
	}
	$otrecords['rowcount'][0] 	= $i;
	return $otrecords;
}

function get_otsummary_monthly($application_id){
	$otrecords ='';
	$query =  "SELECT * 
				  FROM pms_ot_summary
				 WHERE application_id 	= '".$application_id."' 
			  ";
	$result = db_query($query);	 
	foreach($result as $record)
	{ 	
	 	$otrecords['application_id'] 		= $record->application_id;
	 	$otrecords['application_date'] 		= $record->application_date;
	 	$otrecords['month'] 			= $record->month;
	 	$otrecords['year'] 			= $record->year;
	 	$otrecords['employee_id'] 		= $record->employee_id;
	 	$otrecords['total_work_hours'] 		= $record->total_work_hours;
	 	$otrecords['total_excess_hours'] 	= $record->total_excess_hours;
	 	$otrecords['total_ot_hours'] 		= $record->total_ot_hours;
	 	$otrecords['total_approved_ot_hours']	= $record->total_approved_ot_hours;
	 	$otrecords['ot_status'] 			= $record->ot_status;
	}
	return $otrecords;
}

function get_otsummary_monthly_check($empid, $month, $year){
	$query =  "SELECT count(*) as totct 
				  FROM pms_ot_summary
				 WHERE employee_id 	= '".$empid."' 
				   AND month 	= '".$month."' 
				   AND year 	= '".$year."' 
			  ";

	$result = db_query($query);	 
	foreach($result as $record)
	{ 	
	 	$otcount 		= $record->totct;
	}
	return $otcount;
}


function get_attendance_records($empid, $month, $year){

	// AND (a.attendance_date not in (SELECT from_date FROM pms_leave_details WHERE employee_id =  '".$empid."' AND leave_code='CO') OR TO_NUMBER(a.total_hours) > 9)
	// AND a.attendance_date not in (SELECT to_date FROM pms_leave_details WHERE employee_id =  '".$empid."' )
	
	// In Workers catg if worked for 8 hours on paid holiday then they will be eligible for O.T. + one day as compensatory off
	// CO is applied applied from employee than shift hours is equal to 8 hours when emplouyee category is worker than shift hours is 0 using in select query.

	$emp_category = get_description_detail('PMS_EMPLOYEE', 'category_id', 'employee_id', $empid);
	
        $shift_time = 8;
        
        $i = 0;
	$query =  "
				SELECT attendance_date, status_code, time_in, time_out, total_hours
				  FROM
			   (
			  -- -------------------------------------------------------------------------------------------------------------
			  -- Find OT Hours when worked on normal days. 54 Mins is considered 1 Hour. 
			  -- -------------------------------------------------------------------------------------------------------------
				SELECT a.employee_id, a.attendance_date, a.status_code, a.time_in, a.time_out, a.total_hours, a.status_change_date 
				  FROM pms_attendance_details a, pms_shift_roster b
				 WHERE EXTRACT(YEAR FROM a.attendance_date) 	= '".$year."' 
				   AND EXTRACT(MONTH FROM a.attendance_date) 	= '".$month."' 
				   AND a.time_in  <> '0'
				   AND a.time_out <> '0'
				   AND EXTRACT(YEAR FROM a.attendance_date) 	= EXTRACT(YEAR FROM b.shift_date)
				   AND EXTRACT(MONTH FROM a.attendance_date) 	= EXTRACT(MONTH FROM b.shift_date)     
				   AND EXTRACT(DAY FROM a.attendance_date) 	= EXTRACT(DAY FROM b.shift_date)     
				   AND a.employee_id = b.employee_id  AND a.employee_id = '".$empid."'
				   AND TO_NUMBER(a.total_hours) > (SELECT time_diff(c.start_time, c.end_time)+0.54 FROM pms_shift_setting c  WHERE c.shift_id = b.shift_id)
				   AND a.status_code <> '155'
           AND a.attendance_date not in(select overtime_date from pms_ot_details where application_id in
           (select application_id from pms_ot_summary where employee_id = '".$empid."'))
				   
			  UNION ALL
			  -- -------------------------------------------------------------------------------------------------------------
			  -- Find Work Hours on WO/PH when CO is NOT applied. 			  	
			  -- -------------------------------------------------------------------------------------------------------------
			  
			  	SELECT d.employee_id, d.attendance_date, d.status_code, d.time_in, d.time_out, d.total_hours, d.status_change_date 
				  FROM pms_attendance_details d
				 WHERE EXTRACT(YEAR FROM d.attendance_date) 	= '".$year."' 
				   AND EXTRACT(MONTH FROM d.attendance_date) 	= '".$month."' 
				   AND d.status_code = '155'
				   AND d.employee_id = '".$empid."'
				   AND d.attendance_date NOT IN (SELECT from_date FROM pms_leave_details WHERE employee_id =  '".$empid."' AND leave_code='CO' AND EXTRACT(YEAR FROM from_date) = '".$year."' ) 
           AND d.attendance_date not in(select overtime_date from pms_ot_details where application_id in
           (select application_id from pms_ot_summary where employee_id = '".$empid."'))
			  UNION ALL
			  -- -------------------------------------------------------------------------------------------------------------
			  -- Find Work Hours on WO/PH when CO is applied. 			  	
			  -- -------------------------------------------------------------------------------------------------------------
				SELECT e.employee_id, e.attendance_date, e.status_code, e.time_in, e.time_out, (e.total_hours - time_diff(d.start_time, d.end_time)) as total_hours, e.status_change_date 
				  FROM pms_attendance_details e, pms_leave_details f, pms_shift_roster b, pms_shift_setting d
				 WHERE EXTRACT(YEAR FROM e.attendance_date) 	= '".$year."'  
				   AND EXTRACT(MONTH FROM e.attendance_date) 	= '".$month."' 
				   AND e.status_code = '155'
				   AND e.total_hours > time_diff(d.start_time, d.end_time)
				   AND e.employee_id = '".$empid."'
				   AND e.employee_id =  f.employee_id 
				   AND e.attendance_date = f.from_date 
				   AND f.leave_code = 'CO'     
                                   AND e.employee_id =  b.employee_id 
                                   AND e.attendance_date =  b.shift_date
                                   AND b.shift_id = d.shift_id
           AND e.attendance_date not in(select overtime_date from pms_ot_details where application_id in
           (select application_id from pms_ot_summary where employee_id = '".$empid."'))                                   
				   
			  UNION ALL
			  -- -------------------------------------------------------------------------------------------------------------
			  -- Find Total Hours = Work Hours + OutDoor Duty Hours	(When worked on normal days and Not on WO or PH)
			  -- -------------------------------------------------------------------------------------------------------------
			  	  SELECT e.employee_id, e.attendance_date, e.status_code, e.time_in, e.time_out, (e.total_hours +  f.hours) as total_hours, e.status_change_date 
					FROM pms_attendance_details e, pms_leave_details f
				   WHERE EXTRACT(YEAR FROM e.attendance_date) 	= '".$year."' 
					 AND EXTRACT(MONTH FROM e.attendance_date) 	= '".$month."' 
				     AND e.status_code <> '155'
					 AND e.employee_id = '".$empid."'
					 AND e.employee_id =  f.employee_id 
					 AND e.attendance_date = f.from_date 
					 AND f.leave_code = 'OD'
           AND e.attendance_date not in(select overtime_date from pms_ot_details where application_id in
           (select application_id from pms_ot_summary where employee_id = '".$empid."'))           
				) attendance_temp
			  ORDER BY attendance_date ASC
			  ";
			  
	$result = db_query($query);	 
	foreach($result as $record)
	{ 	
	 	$otrecords['ot_date'][$i] 	= $record->attendance_date;
	 	$otrecords['status_code'][$i] 	= $record->status_code;
		$otrecords['time_in'][$i] 	= $record->time_in;
	 	$otrecords['time_out'][$i] 	= $record->time_out;
	 	$otrecords['total_hours'][$i] 	= $record->total_hours;
		$i++;
	}
	$otrecords['rowcount'][0] 	= $i;




	/*		
		$result_od = db_query("SELECT hours FROM pms_leave_details 
								WHERE employee_id =  '".$empid."' 
								  AND leave_code='OD' 
								  AND from_date = '".$record->attendance_date."' 
								  AND approval_status = 'A'
							  ");
		foreach($result_od as $record_od){ $od_hours = $record_od->hours;}
		$otrecords['total_hours'][$i] +=  $od_hours ;


		SELECT f.employee_id, f.attendance_date, f.status_code, f.time_in, f.time_out, f.total_hours, f.status_change_date 
								  FROM pms_attendance_details f
								 WHERE EXTRACT(YEAR FROM f.attendance_date) 	= '".$year."' 
								   AND EXTRACT(MONTH FROM f.attendance_date) 	= '".$month."' 
								   AND f.employee_id = '".$empid."'
								   AND f.attendance_date IN (
	*/

	return $otrecords;
}

function get_otdetails_shift($empid, $date){
$otrecords ='';
	$i = 0;
	$query =  "SELECT time_diff(b.start_time, b.end_time) as shift_hours 
				 FROM pms_shift_roster a, pms_shift_setting b
				 WHERE a.shift_date 	=  '". $date ."'
				   AND a.employee_id 	= '".$empid."'
				   AND b.shift_id 		= a.shift_id
			  ORDER BY EXTRACT(DAY FROM a.shift_date)";
	$result = db_query($query);	 
	foreach($result as $record)
	{ 	
	 	$otrecords	= $record->shift_hours;
		$i++;
	}
	return $otrecords;
}

function get_allcated_shift($empid, $date){
$otrecords =array();
	$i = 0;
	$query =  "SELECT b.*
                        FROM pms_shift_roster a, pms_shift_setting b
                        WHERE a.shift_id    = b.shift_id
                          AND a.shift_date  =  '". $date ."'
                          AND a.employee_id = '".$empid."'
                              
                 ORDER BY EXTRACT(DAY FROM a.shift_date)";
	$result = db_query($query);	 
	foreach($result as $record)
	{ 	
	 	$otrecords['shift_name'] 		= $record->shift_name;
	 	$otrecords['start_time'] 		= $record->start_time;
	 	$otrecords['end_time'] 			= $record->end_time;
		$i++;
	}
	if($i == 0){
	 	$otrecords['shift_name'] = '';
	 	$otrecords['start_time'] = '';
	 	$otrecords['end_time'] 	 = '';
	}
	return $otrecords;
}



function monthly_current_overtime_block($application_id){
	$hours = 0; $minute = 0;
	$monthly_overtime_details 	= monthly_overtime_details($application_id);
	$monthly_overtime_summary 	= monthly_overtime_summary($application_id);

$detail[] = "<div id='ot_monthly_history_view'>
					<table id='report_table' style='table-layout:fixed; word-wrap:break-word;'>
						<tr class='table_header'> 
							<th class='ot_date'> Over-Time Date</th>
							<th class='frm_time'>From Time	</th>
							<th class='to_time'>To Time </th>
							<th class='applied_hrs'>Applied O.T Hours</th>
							<th class='reason_for_ot'>Reason for O.T / Remark:</th>
							<th class='approved_hrs'>Approved O.T Hours:</th>
						</tr>";

	$total_ot_hrs = 0;
	for($i=0; $i<$monthly_overtime_details['rowcount'][0]; $i++){
            
		//$fromtime1 = substr($monthly_overtime_details['ot_start_time'][$i],0,4);
		//$fromtime2 = substr($monthly_overtime_details['ot_start_time'][$i],4);
		//$fromtime  = $fromtime1 .'&nbsp;'.$fromtime2;
            
                 $fromtime  = $monthly_overtime_details['ot_start_time'][$i];
                 //$fromtime  = str_pad(number_format($fromtime, 2), 5, 0, STR_PAD_LEFT);
	
		//$totime1 = substr($monthly_overtime_details['ot_end_time'][$i],0,4);
		//$totime2 = substr($monthly_overtime_details['ot_end_time'][$i],4);
		//$totime	 = $totime1 .'&nbsp;'.$totime2;
                 $totime        = $monthly_overtime_details['ot_end_time'][$i];
		 //$totime        = str_pad(number_format($totime, 2), 5, 0, STR_PAD_LEFT);
                 
                 $fromtime      = preg_replace("/[^0-9]/",":",$fromtime);
                 $totime        = preg_replace("/[^0-9]/",":",$totime);
                 $fromtime  = str_pad($fromtime, 5, 0, STR_PAD_LEFT);
                 $totime    = str_pad($totime, 5, 0, STR_PAD_LEFT);
	
		if( empty($monthly_overtime_details['approved_ot_hours'][$i]) ){ $app_ot_hrs = '- NA -';}
		else{$app_ot_hrs = $monthly_overtime_details['approved_ot_hours'][$i];}
		
                $othrs = preg_replace("/[^0-9]/",":",$monthly_overtime_details['applied_ot_hours'][$i]);
                $othrs = str_pad($othrs, 5, 0, STR_PAD_LEFT);
                
		$detail[] = "
						<tr> 
							<td class='ot_date'>". date('d/m/Y', strtotime($monthly_overtime_details['overtime_date'][$i])) . "	</td>
							<td class='frm_time'>". $fromtime . "            </td>
							<td class='to_time'>". $totime . "		</td>
							<td class='applied_hrs'>". $othrs . " Hrs	</td>
							<td class='reason_for_ot'>". $monthly_overtime_details['ot_reason'][$i] . "	</td>
							<td class='approved_hrs'>". $app_ot_hrs . "	</td>
						</tr>";
						
						//$total_ot_hrs = $total_ot_hrs + $monthly_overtime_details['applied_ot_hours'][$i] ;
						
						$ot_hrs = explode(".", $monthly_overtime_details['applied_ot_hours'][$i]);
						$hours = $hours + $ot_hrs[0];
						$minute = $minute + $ot_hrs[1];
						
	}// for loop ends
	$quo 			= intval($minute/60);
	$rem 			= $minute%60;
	
	$total_hours 	= $hours+$quo + $rem/100;
	if(empty($monthly_overtime_summary['total_approved_ot_hours'])){
		$monthly_overtime_summary['total_approved_ot_hours'] = '- NA -';
	}

		$detail[] = " <tr> 
							<th class='ot_details_hrs' colspan=3> Total OT Hours: 										</th>
							<th class='ot_details_hrs' >". number_format($total_hours,2,'.','') . " Hrs					</th>
							<th class='ot_details_hrs'  colspan=1> &nbsp; 												</th>
							<th class='ot_details_hrs' > ". $monthly_overtime_summary['total_approved_ot_hours']  ." 			</th>
					  </tr>";

	$detail[] = "
					</table>
				</div>";
	$data  =  con_array_elements($detail);	
	return $data;
}

function monthly_overtime_details($application_id){
	$i = 0;
	$result	=	db_query("SELECT * 
							FROM pms_ot_details 
						   WHERE application_id = '". $application_id ."'
					  	ORDER BY EXTRACT(DAY FROM overtime_date)
						   ");	
	foreach($result as $record){
		$overtime_details['ot_id'][$i] 				= $record->ot_id;
		$overtime_details['application_id'][0] 		= $record->application_id;
		$overtime_details['overtime_date'][$i] 		= $record->overtime_date;
		$overtime_details['allocated_shift'][$i] 	= $record->allocated_shift;
		$overtime_details['in_time'][$i] 			= $record->in_time;
		$overtime_details['out_time'][$i] 			= $record->out_time;
		$overtime_details['total_hours_worked'][$i] = $record->total_hours_worked;
		$overtime_details['ot_start_time'][$i] 		= $record->ot_start_time;
		$overtime_details['ot_end_time'][$i] 		= $record->ot_end_time;
		$overtime_details['applied_ot_hours'][$i] 	= $record->applied_ot_hours;
		$overtime_details['ot_reason'][$i] 			= $record->ot_reason;
		$overtime_details['approved_ot_hours'][$i] 	= $record->approved_ot_hours;
		$overtime_details['created'][$i] 			= $record->created;
		$overtime_details['changed'][$i] 			= $record->changed;
		$i++;
	}
	$overtime_details['rowcount'][0] 				= $i;
	return $overtime_details;
}
function monthly_overtime_summary($application_id){
	$result	=	db_query("SELECT * 
							FROM pms_ot_summary 
						   WHERE application_id = '". $application_id ."'
						   ");	
	foreach($result as $record){
		$overtime_details['application_id'] 			= $record->application_id;
		$overtime_details['employee_id'] 				= $record->employee_id;
		$overtime_details['application_date'] 			= $record->application_date;
		$overtime_details['total_work_hours'] 			= $record->total_work_hours;
		$overtime_details['total_excess_hours'] 		= $record->total_excess_hours;
		$overtime_details['total_ot_hours']				= $record->total_ot_hours;
		$overtime_details['total_approved_ot_hours'] 	= $record->total_approved_ot_hours;
		$overtime_details['ot_status']					= $record->ot_status;
		$overtime_details['excess_status']				= $record->excess_status;
		$overtime_details['operation_head_empid']		= $record->operation_head_empid;
		$overtime_details['operation_head_remark']		= $record->operation_head_remark;
		$overtime_details['created']		= $record->created;
		$overtime_details['changed']		= $record->changed;
	}
	return $overtime_details;
}







function get_otdetails_attendance_call($form,&$form_state){

	$payroll_month			=   $form_state['values']['payroll_month'];
	$payroll_year			=   $form_state['values']['payroll_year'];

	$form_state['redirect'] = array(
		'pms/overtime_application_monthly',
		  array(
			'query' => array(
			'month' 	=> $payroll_month,
			'year' 		=> $payroll_year,
			),
		),
	);
	
}

function get_otdetails_refresh_call($form,&$form_state){
	$form_state['redirect'] = array(
		'pms/overtime_application_monthly',
		  array(
			'query' => array(
			),
		),
	);
	
}




function get_wo_date_count($empid, $ot_date){
	$result = db_query("SELECT COUNT(shift_date) as totct
						 FROM pms_shift_roster
                        WHERE allocated_shift = 'WO'
                          AND shift_date = '". $ot_date ."'
                          AND employee_id = '". $empid ."'
		");
	foreach($result as $record){
		$totct = $record->totct;
	}
	return $totct;
}

function get_ph_date_count($ot_date){
        $empid = get_empid();
        $location_id = get_description_detail('pms_employee', 'location_id', 'employee_id', $empid);
	$result = db_query("SELECT COUNT(holiday_date) as totct 
                            FROM pms_master_company_holidays 
                            WHERE holiday_date = '". $ot_date ."' 
                              AND location_id = '".$location_id."'  
		");
	foreach($result as $record){
		$totct = $record->totct;
	}
	
	return $totct;
}


function get_edit_status_count($application_id, $table, $column){

	$result = db_query("SELECT COUNT(". $column .") as totct
						 FROM ". $table ."
                        WHERE ". $column ." = '". $application_id ."'
		");
		
	foreach($result as $record){
		$totct = $record->totct;
	}
	return $totct;
}

function emp_grade_dd_ot() {
  $grade[NULL] = '- Select -';
  $result = db_query("SELECT * FROM pms_master_grade");
  foreach($result as $value){ 
   $grade[$value->grade_id]    = $value->grade_code.' ( '.$value->grade_name.' )';
  } 
  return $grade;
}

function get_count_ot_setting($company_id, $location_id, $category_id, $grade_id,$ot_rate_id) {
    if(empty($company_id) || empty($location_id) || empty($category_id) || empty($grade_id) ){
        $company_id = 0; $location_id = 0; $category_id=0; $grade_id = 0;
    }
      if($ot_rate_id!=0 || $ot_rate_id!='0')
      {
        $ot_seeting_count = 0;
            $result = db_query(" SELECT COUNT(*) as recordcount 
                     FROM pms_setting_overtime
                    WHERE company_id = '".$company_id."'
                      AND location_id = '".$location_id."'
                      AND category_id = '".$category_id."'
                      AND grade_id = '".$grade_id."' AND ot_rate_id !='".$ot_rate_id."'					  						  
              ");
            foreach($result as $record){
            $ot_seeting_count = $record->recordcount;
            }  
        
      }
      else 
      {
            $ot_seeting_count = 0;
            $result = db_query(" SELECT COUNT(*) as recordcount 
                     FROM pms_setting_overtime
                    WHERE company_id = '".$company_id."'
                      AND location_id = '".$location_id."'
                      AND category_id = '".$category_id."'
                      AND grade_id = '".$grade_id."'						  						  
              ");
            foreach($result as $record){
            $ot_seeting_count = $record->recordcount;
            }  
      }
	return $ot_seeting_count ;
}



function overtime_setting_validate($form, &$form_state)
{
	$company_id		    =   $form_state['values']['company_id'];
	$location_id	   	=   $form_state['values']['location_id'];
	$category		   	=   $form_state['values']['category'];
	$grade		   		=   $form_state['values']['grade'];
	$ot_rate_id		   	=   $form_state['values']['ot_rate_id'];

	 $count_ot_setting 	= get_count_ot_setting($company_id, $location_id, $category, $grade,$ot_rate_id);
	//die;
	//if($ot_rate_id == 0){
		if( $count_ot_setting > 0)
		{
		  form_set_error('msg1', 'Duplicate record found');
		}
	//}
}

function get_operation_head_approval_block($empid, $application_id){
	
	$image 			= '../sites/all/modules/pms/support/images/pending.png';
	$show_img 		= "<img src='".$image."' width=35px; height = 35px; /> ";

	$monthly_overtime_summary	= monthly_overtime_summary($application_id);
	
	$dec = $monthly_overtime_summary['excess_status'];
	
	if($dec == 'A'){
		$image 		= '../sites/all/modules/pms/support/images/approved.png';
		$show_img 	= "<img src='".$image."' width=40px; height = 40px; /> ";
		$dec		= 'Approved';	
	}
	if($dec == 'R'){
		$image 		= '../sites/all/modules/pms/support/images/rejected.jpg';
		$show_img 	= "<img src='".$image."' width=40px; height = 40px; /> ";
		$dec		= 'Rejected';	
	}
	if($dec == 'P'){
		$dec		= 'Pending';	
	}
	
	$excess_status 	= $monthly_overtime_summary['excess_status'];
	$id		   	= $monthly_overtime_summary['operation_head_empid'];
	$remark		   	= $monthly_overtime_summary['operation_head_remark'];
	$date		   	= $monthly_overtime_summary['changed'];

	if(empty($id)){ $id = '----------'; $name =  '----------'; $remark = '----------'; $date = '----------';}	
	else{$name = get_empname_wtmn($id); $date = date('d/m/Y', $date);}
	
	$tbl[] = "<table id='ot-approval-table'> 
				<tr>
					<td id='ot-approval-td1' colspan=5> Operational head approval for more than 50 hours in a month	</td>
				</tr>
				<tr>
					<td id='ot-approval-td1'> Name: 														</td>
					<td id='ot-approval-td2'> ".$name."													</td>
					<td id='ot-approval-td1'> (Emp ID:					  									</td>
					<td id='ot-approval-td4'> ".$id.") 													</td>
					<td id='ot-approval-td3' rowspan='3'> ". $show_img ."									</td>
				</tr>
				<tr> 
					<td id='ot-approval-td1'> Date: 						  								</td>
					<td id='ot-approval-td2'> ".$date."													</td>
					<td id='ot-approval-td1'> Status:					        							</td>
					<td id='ot-approval-td4'>	".$dec." 													</td>
				</tr>							
				<tr> 
					<td id='ot-approval-td1' > Remarks:		 												</td>
					<td id='ot-approval-td2' colspan='4' >".$remark." 			    							</td>
				</tr>							
		 </table>";
		 
	$approval_block = con_array_elements($tbl);
	
	return $approval_block;

}


function get_allowance_gradewise_arr($company_id, $location_id, $edcode){
    $grade_code = array();
    $result = db_query("SELECT grade_code
                        FROM pms_pr_gradewise_salary_master
                       WHERE location_code = '".$location_id."'
                         AND ed_code = '".$edcode."'	  						  
		");
	foreach($result as $record){
		$grade_code[] = $record->grade_code;
	}
        return $grade_code;
}








