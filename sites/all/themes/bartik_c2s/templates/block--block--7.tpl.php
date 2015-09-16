<div id="block-<?php print $block->module . '-' . $block->delta; ?>" class="<?php print $classes; ?> " <?php print $attributes; ?>>
<?php print render($title_prefix); ?>
<?php if ($block->subject): ?>
  <h2><?php print $block->subject ?></h2>
<?php endif;?>
<?php print render($title_suffix); ?>

<div class="content"<?php print $content_attributes; ?>>
<div id ="back_button"><a href="intranet"> Close Search </a></div>
<ul>
<?php 
	$s_type  = $_GET['s_type'];
	$s_value  = $_GET['s_value'];
	$s_val_arr = explode(' ',$s_value);
	
	if($s_type == 'ID'){

		$result = db_query("select erid from pms_employee
								  where employee_id = ".$s_value."
						 	   ");
		$i=0;
		foreach ($result as $record){ 
			header("Location: pms/pms_employee_view?erid=".$s_value);
			$i++;
		}
		
	} else {
		
		$sarr_count = count($s_val_arr);
		
		if($sarr_count < 2){
			
			$result = db_query("select * from pms_employee
								  where first_name LIKE '%".$s_val_arr[0]."%'
						       order by employee_id
						 	   ");
		}
		else if($sarr_count == 3){
		
			 $result = db_query("select * from pms_employee
								  where first_name LIKE '%".$s_val_arr[1]."%'
									and last_name LIKE '%".$s_val_arr[2]."%'
						       order by employee_id
						 	   ");
		} else{
			
			$result = db_query("select * from pms_employee
								  where first_name LIKE '%".$s_val_arr[0]."%'
									and last_name LIKE '%".$s_val_arr[1]."%'
						       order by employee_id
						 	   ");
		}
		$i=0;
		foreach ($result as $record){ 
			$empid[$i]		 = $record->employee_id;
			$erid[$i] 		 = $record->erid;
			$profile_pic[$i] = get_profile_image($record->profile_picture);
			$emp_name[$i]    = get_empname_wtmn($record->employee_id);
			$company[$i]	 = get_description_detail('PMS_MASTER_COMPANY','name','code', $record->company_id);
			$location[$i]	 = get_description_detail('PMS_MASTER_ENTITY','name','code', $record->location_id);
			if($record->designation_id == '' || $record->designation_id == null){
				$designation[$i] = '-- NA --';
			} else {
				$designation[$i] = get_description_detail('PMS_MASTER_DESIGNATION','designation_name','designation_id', $record->designation_id);
			}
			if($record->category_id == '' || $record->category_id == null){
				$category[$i] = '-- NA --';
			} else {
				$category[$i] = get_description_detail('PMS_MASTER_CATEGORY','description','category_id', $record->category_id);
			}
			
			if($record->grade_id == '' || $record->grade_id == null){
				$grade[$i] = '-- NA --';
				
			} else {
				$grade[$i] = get_description_detail('PMS_MASTER_GRADE','grade_name','grade_id', $record->grade_id);
			}

			$i++;
		}

		if($i == 1){
			header("Location: pms/pms_employee_view?erid=".$erid[0]);
		} else {
			
			if(isset($erid) <> ''){
				for($j=0;$j<count($erid); $j++){ 
					if(empty($profile_pic[$j])){
						$profile_pic[$j] = 'User_0.png';
					}
					$imgurl 	= 'sites/default/files/profile/';?>
					
					<li>
						<div id="e_image"><?php print "<img src=".$imgurl.$profile_pic[$j]." />";?></div>
						<div id="e_name"><h3><?php print $emp_name[$j];?> ( <?php print $empid[$j];?> )</h3></div>
						<div id="e_des"><?php print $designation[$j];?></div>
						<div id="e_comp"><?php print $company[$j];?> , <?php print $location[$j];?></div>
						<div id="wrapper_div">
							<div id="e_cat"><b>Category: </b><?php print $category[$j];?> </div>
							<div id="e_grade"><b>Grade: </b><?php print $grade[$j];?> </div>
						</div>
						<div id="view_button"><a href="pms/pms_employee_view?erid=<?php print $erid[$j]; ?>">View Profile</a></div>
					</li>	
				<?php }
			}
		}
	}
	
	

?>
</ul>
<?php if($i == 0) {?>

<div class="empty_record_message"> There are no records available.</div>

<?php } ?>
</div>
</div>











