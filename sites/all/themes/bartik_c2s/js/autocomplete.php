<?php
	/*?>$q=$_GET['q'];
	$my_data=mysql_real_escape_string($q);
	
	$conn = oci_connect("pms_rnd","pms_rnd", "203.201.225.124");
	if (!$conn) {
		$e = oci_error();
		trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);		
	}
	
	$stid = oci_parse($conn, "SELECT first_name, last_name FROM pms_employee WHERE first_name LIKE '%$my_data%' or last_name LIKE '%$my_data%' ORDER BY first_name");
	oci_execute($stid);
	

	while($row = oci_fetch_array($stid, OCI_ASSOC+OCI_RETURN_NULLS))
	{
		echo $row['first_name'];	
	}<?php */
	
	$q=$_GET['q'];
	$my_data=oci_escape_string($q);
	$conn = oci_connect("pms_rnd","pms_rnd", "203.201.225.124/ipcatest");
	if (!$conn) {
		$e = oci_error();
		trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);		
	}
	$stid = oci_parse($conn, "SELECT first_name, last_name FROM pms_employee WHERE first_name LIKE '%$my_data%' or last_name LIKE '%$my_data%' ORDER BY first_name");
	oci_execute($stid);
	
	while($row = oci_fetch_array($stid, OCI_ASSOC+OCI_RETURN_NULLS))
	{
		echo $row['title']." ".$row['first_name']." ".$row['last_name']."\n";
	}
	
function oci_escape_string($string) {
  return str_replace(array('"', "'", '\\'), array('\\"', '\\\'', '\\\\'), $string);
}	
?>