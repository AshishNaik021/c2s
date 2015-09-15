<?php //print $output; 
global $base_path;
$buser = user_load($output);
$result = db_query("SELECT FIRST_NAME, LAST_NAME FROM pms_employee where employee_id='".$buser->name."'"); 
$user = reset($buser);
foreach ($result as $value) {  
   print $value->first_name.' '.$value->last_name;
}
?>
