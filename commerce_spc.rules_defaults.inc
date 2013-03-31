<?php 
/**
 * @file
 * Default rule configurations for Commerce Single Page Checkout.
 */

/*
 * @TODO: This causes the features admin to break when commerce_features is enabled.
 */
function commerce_spc_default_rules_configuration_alter(&$configs) {
  $configs['commerce_cart_add_to_cart_message']->condition('commerce_current_node_has_enabled_product_type');
}