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

    $result = db_query("select employee_id, marriage_date from pms_employee 
						 where extract(month from marriage_date) between '".date("m", strtotime($next_date))."' and '".date("m", strtotime($last_date))."'
						   and extract(day from marriage_date) between '".date("d", strtotime($next_date))."' and '".date("d",strtotime( $last_date))."'
						   and marital_status = 'Married'
					  group by employee_id, marriage_date
					  order by marriage_date
					  ");
	$i=0;
	$temp_marriage_date = '';
	foreach ($result as $record){ 
		$marriage_date 		= $record->marriage_date;
		$emp_id 	= $record->employee_id;
		if($marriage_date <> $temp_marriage_date){
			if($i <> 0){ ?>
				</ul> </li>
			<?php }
			?>
			
			<li>
				<div class="b_date"><?php print date('l', strtotime($marriage_date)) ?>, <?php  print date('d', strtotime($marriage_date)) ?>th  <?php print date('M', strtotime($marriage_date))?> </div>
				<ul>
				<li><?php print get_empname_wtmn($emp_id) ?> <a href="#">(<?php print $emp_id ?>)</a></li>
					
			<?php
		} else { ?>			
			<li><?php print get_empname_wtmn($emp_id) ?> <a href="#">(<?php print $emp_id ?>)</a></li>
		<?php }
		
		$temp_marriage_date = $marriage_date;
?>						
<?php 	$i++; } if($i == 0){ ?> 
<div class="empty_record_message"> There are no records available for coming week's Anniversary .</div>
<?php }
?>
</ul>
</div>
</div>











