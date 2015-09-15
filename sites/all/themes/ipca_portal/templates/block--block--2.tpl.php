<div id="block-<?php print $block->module . '-' . $block->delta; ?>" class="<?php print $classes; ?> " <?php print $attributes; ?>>
<?php print render($title_prefix); ?>
<?php if ($block->subject): ?>
  <h2><?php print $block->subject ?></h2>
<?php endif;?>
<?php print render($title_suffix); ?>

<div class="content"<?php print $content_attributes; ?>>

<ul>
<?php 

    $result = db_query("select * from pms_employee where extract(month from dob) ='".date("m")."' and extract(day from dob) ='".date("d")."'");
	$i=0;
	foreach ($result as $record){ 
		$emp_id 	= $record->employee_id;
		$mobile 	= get_description_detail('pms_employee_address','mobile','employee_id',$emp_id);
		$name 		= get_empname_wtmn($emp_id);
		$image 		= get_profile_image($record->profile_picture);
		$imgurl 	= 'sites/default/files/profile/';
		if(empty($image)){
			$image = 'User_0.png';
		}
?>						
		<li>
			<div class="left_div">
				<div class="b_image">
					<?php print "<img src=".$imgurl.$image." />";?></div>
				<div class="b_title">
					<p style="width:81px; float:left;height: 14px;margin-bottom: 0px; overflow:hidden;"><?php print $name ;?></p>
					<a href="#" style="width:56px; float:left;">( <?php print $emp_id; ?> )</a></div>
				<div class="b_mob">
					Mob: +91 - <?php print $mobile;?></div>
				<h3>
					<a href="#" >Send Message to Wish Me</a> </h3>
			</div>
			<div class="right_div">
				<div class="b_icon">
					<a href="#" class="hint--left  hint--rounded" data-hint="Send eCards / Gifts"></a></div>
			</div>
		</li>

<?php 	$i++; }
if($i == 0){ ?> 
<div class="empty_record_message"> There are no records available for today's birthday .</div>
<?php } ?>
</ul>
</div>
</div>











