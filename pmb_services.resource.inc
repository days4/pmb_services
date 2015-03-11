<?php

/**
 * Helper function for pmb_services_services_resources.
 */

function _pmb_services_resource_definition() {
  $resources['og'] = array();
  // [GET] {endpoint}/og/{gid}
  $resources['pmb_services']['actions']['pmb_bet_add'] = array(
    'help' => 'Places bet on selected outcome',
    'callback' => '_pmb_services_resource_bet_add',
    'file' => array('type' => 'inc', 'module' => 'pmb_services', 'name' => 'pmb_services.resource'),
    'access callback' => 'user_access',
    'access arguments' => array('administer group'),
    'access arguments append' => FALSE,
    'args' => array(
      array(
        'name' => 'node',
        'type' => 'int',
        'description' => 'The nid of the Question  to place bet.',
        'source' => array('data' => 'node'),
        'optional' => FALSE,
      ),
	  array(
        'name' => 'user',
        'type' => 'int',
        'description' => 'The uid of the user',
        'source' => array('data' => 'user'),
        'optional' => FALSE,
      ),
	  array(
        'name' => 'pmb_bet_amount',
        'type' => 'int',
        'description' => 'The bet amount for outcome.',
        'source' => array('data' => 'pmb_bet_amount'),
        'optional' => FALSE,
      ),
	  array(
        'name' => 'pmb_bet_outcome',
        'type' => 'int',
        'description' => 'selected outcome to place a bet',
        'source' => array('data' => 'pmb_bet_outcome'),
        'optional' => FALSE,
      ),
    ),
  );
 

  return $resources;
}
function _pmb_services_resource_bet_add($node,$user,$pmb_bet_amount,$pmb_bet_outcome)
{
$u=user_load($user,$reset = TRUE);
  
dpm($u);
$n=node_load($node, $vid = NULL, $reset = TRUE);

dpm($n);
drupal_set_message($node);
drupal_set_message($user);
drupal_set_message($pmb_bet_amount);
drupal_set_message($pmb_bet_outcome);
return pmb_bet_add($n, $u, $pmb_bet_amount, $pmb_bet_outcome) ;
}