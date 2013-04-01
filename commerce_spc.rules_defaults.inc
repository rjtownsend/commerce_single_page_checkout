<?php 
/**
 * @file
 * Default rule configurations for Commerce Single Page Checkout.
 */

/*
 * Implements hook_default_rules_configuration_alter()
 */
function commerce_spc_default_rules_configuration_alter(&$configs) {
  if (isset($configs['commerce_cart_add_to_cart_message'])) {
    $configs['commerce_cart_add_to_cart_message']->condition('commerce_current_node_has_enabled_product_type');
  }
}