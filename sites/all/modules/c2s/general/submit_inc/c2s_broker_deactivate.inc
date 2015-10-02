<?php

// ==================================================================================================
//                   Deactivate Broker 
// ==================================================================================================


try{
    $id = arg(3);
    db_update('broker_master')
    ->fields(array(
        'deactivate'				=>	1,
        'changed'         			=>  REQUEST_TIME,
    ))
    ->condition('broker_agent_id', $id, '=')
    ->execute();
    
    drupal_set_message("Broker Successfully Deactivated"); 
    drupal_goto('c2s/broker/view/'.arg(4));
}
catch(Exception $e)
{
    drupal_set_message("Over-Time Setting Records could not be Inserted <br>" . $e, 'error');
}

				
// --------------------------------------------------------------------------------------------------

