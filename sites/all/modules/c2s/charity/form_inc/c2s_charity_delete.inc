<?php
	$arg = arg();
// ===============  When in Edit mode, 3rd Arg will be set to Charity Org ID =======================
if(isset($arg[3])){
	$charity_organization_id = arg(3);
	$query = "SELECT * FROM c2s_charity_org_master WHERE charity_organization_id = ".$charity_organization_id ;
	$result = db_query($query);
	foreach($result as $value){
		$charity_org_name 				= $value->charity_org_name;
	}
}