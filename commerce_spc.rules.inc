<?php 
/**
 * @file
 * Default rules conditions for Commerce Single Page Checkout
 */

/**
 * Implements hook_rules_condition_info().
 *
 * Add a condition to commerce_cart_add_to_cart_message rule to
 * not display Add to Cart message on this content type
 */
function commerce_spc_rules_condition_info() {
  $conditions = array();

  $conditions['commerce_current_node_has_enabled_product_type'] = array(
    'label' => t('Current node has enabled product type'),
    'group' => t('Commerce Single Page Checkout'),
    'callbacks' => array(
      'execute' => 'commerce_spc_rules_node_has_enabled_product_type',
    ),
  );

  return $conditions;
}

/**
 * Rules condition: checks to see if current node is of a specific
 * content type. 
 */
function commerce_spc_rules_node_has_enabled_product_type() {
  // I feel like there's a better way to do this.
  $is_not_type = NULL;

  $nid = (arg(0) == 'node' && is_numeric(arg(1))) ? arg(1): FALSE;
  if ($nid != FALSE) {
    $node = node_load($nid);
    $node->content = node_view(node_load($nid));
    // Does this node have an enabled product type?
    $enabled = commerce_spc_enabled_product_types($node);
    $is_not_type = TRUE;
    if ($enabled) {
      $is_not_type = FALSE;
    }
  }

  return $is_not_type;
}
