<?php

// ==================================================================================================
//                   Deactivate Broker 
// ==================================================================================================


try{
    $id = arg(3);
    db_update('c2s_broker_master')
    ->fields(array(
        'status'				=>	'D',
        'changed'         		=>  REQUEST_TIME,
    ))
    ->condition('broker_agent_id', $id, '=')
    ->execute();
    
    drupal_set_message("Broker Successfully Deactivated"); 
    drupal_goto('c2s/broker/view/'.arg(4));
}
catch(Exception $e)
{
    drupal_set_message("Broker Could Not Be Successfully Deactivated <br>" . $e, 'error');
}

				
// --------------------------------------------------------------------------------------------------

