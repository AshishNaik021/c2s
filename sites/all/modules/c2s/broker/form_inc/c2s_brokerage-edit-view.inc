<?php 
$brokerage_id = arg(3);
$result = db_query("SELECT * FROM c2s_brokerage_details WHERE brokerage_id = ".$brokerage_id);
foreach($result as $value){
    $brokerage_name 		  = $value->brokerage_name;
    $brokerage_start_date 	  = $value->brokerage_start_date;
    $number_of_owners         = $value->number_of_owners;
    $franchise_fee_cap		  = $value->franchise_fee_cap;
    $reap_amount_cap	      = $value->reap_amount_cap;
    $created 		          = $value->created;
    $changed 		          = $value->changed;
}

	$result_paperwork = db_query("select paperwork_document_name from c2s_required_paperwork where `paperwork_id` in
								(SELECT `paperwork_id` FROM `c2s_brokerage_paperwork` where `brokerage_id` = ".$brokerage_id.")") ;

$form['#attributes']['class'][] = 'brokerage_form';


$form['brokerage_tab'] = array(
    '#type' => 'item',
    '#suffix' => '<div class="form_section_tab selected" data-item="form_tab_0" onclick="click_tabs(0)" id="tab_0" > Brokerage Details </div>',
);
$query = "SELECT broker_agent_id FROM c2s_broker_master WHERE brokerage_id = ".$brokerage_id." and status = 'A'";

$result = db_query($query);
$broker_id = array();
$n=0;
foreach($result as $value){
    $n++;
    $broker_id[$n] = $value->broker_agent_id;
}

$total_brokers = $n;
$number_to_words = array(1=>"One", 2=> "Two", 3=> "Three", 4=>"Four", 5=>"Five", 6=>"Six");
for($i=1; $i<=$total_brokers; $i++){

    $form['broker_tab_'.$i] = array(
        '#type' => 'item',
        '#suffix' => '<div class="form_section_tab" data-item="form_tab_'.$broker_id[$i].'" onclick="click_tabs('.$broker_id[$i].')" id="tab_'.$broker_id[$i].'" > Broker '.$number_to_words[$i].' </div>',
    );

}

$form['brokerage_details_start'] = array(
    '#type' => 'item',
    '#suffix' => '<div id="form_tab_0" class="form_sections" style="display:block">',
);
$form['brokerage_details_seperator'] = array(
	    '#type' => 'item',
	    '#prefix' => '<input type="button" value="Edit Brokerage" style="float: right; margin:5px;" onclick="convert_edit('.$broker_details[$i]['id'].')">
	     <input type="button" value="Deactivate Brokerage" style="float: right; margin:5px;" onclick="window.location=\''.base_path().'c2s/broker/deactivate/'.$broker_details[$i]['id'].'/'.$brokerage_id.'\'">',
	    '#suffix' => '<div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;"></div>',
	);


$form['brokerage_section_left_start'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '<div class="section_left">',
);



$form['brokerage_name'] = array(
    '#type'		       => 'textfield',
    '#maxlength'	   => 100,
    '#theme_wrappers'  => array(),
    '#default_value'   => $brokerage_name,
    '#disabled'        =>'true',
    '#attributes'       => array(
        'class'=> array('input_disabled'),
        'placeholder'=> 'City2Shore',
        'onKeyPress' => array('return isAlphaNumeric(event, this);',),
        'onChange'   => array('addPrefix(this, "City2Shore ")'),
        'onClick'    => array('removePrefix(this)')
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w60"><label class="label_left"> Name of Brokerage </label><span class="value_left">',
    '#suffix' => '</span></span> ',
);


$form['brokerage_start_date'] = array(
    '#label'          => 'invisible',
    '#type'		      => 'date_popup',
    '#theme_wrappers'  => array(),
    '#date_label_position' => 'Within',
    '#disabled'       => 'true',
    '#default_value'  => $brokerage_start_date,
    '#date_format'	  => 'm/d/Y',
    '#date_year_range'  => '-3:+3',
    '#attributes'       => array(
        'placeholder'=> t('mm/dd/YYYY'),
        'class'=> array('date-input-medium input_disabled'),
        'onKeyPress' => array('return false;'),
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left"> Start Date </label><span class="value_left">',
    '#suffix' => '</span></span>',
);



$form['franchise_fee_cap'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#disabled'		  => 'true',
    '#theme_wrappers'  => array(),
    '#default_value'  => $franchise_fee_cap,
    '#attributes'     => array(
        'placeholder'=> t('$3000'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Franchise Cap</label><span class="value_left">',
    '#suffix' => '</span></span>',
);
$form['transaction_management_fee'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#disabled'		  => 'true',
    '#theme_wrappers'  => array(),
    '#default_value'  => '10',
    '#attributes'     => array(
        'placeholder'=> t('$2.96'),
        'class'=> array('input_disabled'),
        //	        'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Transaction Fee</label><span class="value_left">',
    '#suffix' => '</span></span>',
);

$form['reap_amount_cap'] = array(
    '#type'		      => 'textfield',
    '#maxlength'	  => 100,
    '#disabled'		  => 'true',
    '#theme_wrappers'  => array(),
    '#default_value'  => $reap_amount_cap,
    '#attributes'     => array(
        'placeholder'=> t('$18,000'),
        'class'=> array('input_disabled'),
        //'onKeyPress' => array('return numbersonly(this, event)',),
        //'readonly'=>'readonly',
    ),
    '#prefix' => '<span class="wrapper-w33"><label class="label_left">Reap Cap</label><span class="value_left">',
    '#suffix' => '</span></span><div class="seperator" style="height: 10px;width: 100%;float: left;clear: both;">',
);

$form['brokerage_section_left_end'] = array(
    '#type' => 'item',
    '#theme_wrappers'  => array(),
    '#prefix' => '</div></div>',
);

$paperwork_selected = getPaperworkSelected($brokerage_id);
$form['names_fieldset']['brokerage_paperwork'] = array(
	'#title' 	=> t('Selected Paperwork'),
    '#type' 	=> 'checkboxes',
    '#required' => 'true',
	'#options'	=> $paperwork_selected,
	'#value'	=> $paperwork_selected,
	'#disabled' => TRUE,
    '#prefix' 	=> '<div class="section_left"> <div class="form_subsection_title" data-item="inner_section_1" >Statutory Requirements</div>',
    '#suffix' 	=> '</div>',
);


$form['brokerage_details_end'] = array(
    '#type' 	=> 'item',
    '#suffix' 	=> '</div>',
);


?>