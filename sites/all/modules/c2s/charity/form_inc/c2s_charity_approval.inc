<?php

	$form['approve'] = array(
	    '#type' => 'submit',
	    '#value' => t('Approve'),
	);

	$form['reject'] = array(
	    '#type' => 'submit',
	    '#value' => t('Reject'),
	);
	
	$form['approve'] = array(
		'#type'		    	=> 'textarea',
		'#required'			=>	$true_false,
		'#attributes'       => array(
			'placeholder'=> t('mm/dd/YYYY'),
			'class'=> array('date-input-medium form_text'),
			'onKeyPress' => array('return false;'),
		),
		'#prefix' => '<span class="wrapper-w33">',
		'#suffix' => '</span></span>',
	);



