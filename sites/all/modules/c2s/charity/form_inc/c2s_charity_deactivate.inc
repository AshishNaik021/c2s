<?php
$arg = arg();
// ===============  3rd Arg will be set to Charity Org ID =======================
if(isset($arg[3])){
	$charity_organization_id = arg(3);
	$status_to_update = arg(4);
	
	if($status_to_update == 'De-Activate'){
		$query = "UPDATE c2s_charity_org_master 
				  SET charity_org_status = 'D'
				  WHERE charity_organization_id = ".$charity_organization_id ;
	}else{
		$query = "UPDATE c2s_charity_org_master 
				  SET charity_org_status = 'A'
				  WHERE charity_organization_id = ".$charity_organization_id ;
	}
			  
	$result = db_query($query);
	drupal_set_message('This Charity Organization is now Deactivated!' );

}else{

	drupal_set_message('Something is wrong. Charity Organization Can\'t Deactivated! <br>'. $e, 'error' );

}
	$url = '../../view/'.$charity_organization_id;
	header('Location: '.$url, TRUE);
