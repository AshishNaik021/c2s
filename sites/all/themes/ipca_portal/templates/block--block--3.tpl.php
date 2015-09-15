<div id="block-<?php print $block->module . '-' . $block->delta; ?>" class="<?php print $classes; ?> " <?php print $attributes; ?>>
<?php print render($title_prefix); ?>
<?php if ($block->subject): ?>
  <h2><?php print $block->subject ?></h2>
<?php endif;?>
<?php print render($title_suffix); ?>

<div class="content"<?php print $content_attributes; ?>>

<ul>
<?php 
	$current_date = date("Y-m-d");
	$date = strtotime($current_date);
	$next_date = date('Y-m-d', strtotime("+1 day", $date) );
	$last_date = date('Y-m-d', strtotime("+7 day", $date));

    $result = db_query("select employee_id, dob from pms_employee 
						 where extract(month from dob) between '".date("m", strtotime($next_date))."' and '".date("m", strtotime($last_date))."'
						   and extract(day from dob) between '".date("d", strtotime($next_date))."' and '".date("d",strtotime( $last_date))."'
					  group by employee_id, dob
					  order by dob
					  ");
	$i=0;
	$temp_dob = '';
	foreach ($result as $record){ 
		$dob 		= $record->dob;
		$emp_id 	= $record->employee_id;
		if($dob <> $temp_dob){
			if($i <> 0){ ?>
				</ul> </li>
			<?php }
			?>
			
			<li>
				<div class="b_date"><?php print date('l', strtotime($dob)) ?>, <?php  print date('d', strtotime($dob)) ?>th  <?php print date('M', strtotime($dob))?> </div>
				<ul>
				<li><?php print get_empname_wtmn($emp_id) ?> <a href="#">(<?php print $emp_id ?>)</a></li>
					
			<?php
		} else { ?>			
			<li><?php print get_empname_wtmn($emp_id) ?> <a href="#">(<?php print $emp_id ?>)</a></li>
		<?php }
		
		$temp_dob = $dob;
?>						
<?php 	$i++; }
if($i == 0){ ?> 
<div class="empty_record_message"> There are no records available for coming week's birthday.</div>
<?php } ?>
</ul>
</div>
</div>











