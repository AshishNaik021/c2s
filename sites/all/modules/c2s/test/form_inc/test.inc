<?php

	$city_options = array();
	$state_options = array();

	$state_options = get_States();
		
	//--------------  Ajax CallBack for Cities and ZipCodes  ---------------------

	if (isset($form_state['values']['state_id'])) {
		$selected_state_id = isset($form_state['values']['state_id']) ? $form_state['values']['state_id'] : key($state_options);
	}else{
		$selected_state_id = 1;
	}
	$city_options = get_Cities1($selected_state_id);
	

	$form['state_id'] = array(
	    '#type'=>'select',
	    '#title' => t('State'),
	    '#options' =>$state_options,
		'#default_value' => $selected_state_id,
	    '#required'=>'true',
	    '#attributes' => array(
	        'class' => array('select-xlarge', 'uniform'),
	    ),
		'#ajax' => array(
			'callback' => 'find_cities_callback1',
			'wrapper' => 'cities-wrapper',
		),
	    '#prefix' => '<span class="wrapper-w16">',
	    '#suffix' => '</span>',
	);

	$form['city_id'] = array(
	    '#type'=>'select',
	    '#title' => t('City'),
	    '#required'=>'true',
		'#default_value' => isset($form_state['values']['city_id']) ? $form_state['values']['city_id'] : '',
	    '#options' => get_Cities1($selected_state_id),
	    '#attributes' => array(
	        'placeholder' => t(''),
	        'class' => array('select-xlarge', 'uniform'),
	    ),
	    '#prefix' => '<div id="cities-wrapper"> <span class="wrapper-w16"> Selected State Id = '.$selected_state_id,
	    '#suffix' => '</span></div>',
	);
 
