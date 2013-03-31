Commerce Single Page Checkout provides a single-page checkout experience so users 
can view a product, enter credit card info, and buy/pay/donate on the same page. 
In other words, it provides a true one-step, one-click checkout process.

Once enabled, Commerce Single Page Checkout adds a checkout_page, creates duplicate 
address/account/billing/cart panes, adds the panes to that page, and displays 
the checkout_page on nodes that have a product referenced to it.

If a node has 2 or more products referenced to it, it will automatically add/remove 
products to the cart via AJAX whenever you switch between products. It also adds a 
rule condition to remove the "Add to Cart" message displayed on a node when a 
product is added to the cart. 

Installation
============

  1. Install and enable module, including dependencies. See 
     http://drupal.org/documentation/install/modules-themes/modules-7 for details

  2. Patch the commerce_authnet module, see http://drupal.org/patch/apply for details.

  3. Navigate to admin/commerce/products/add and add a product. Alternatively create a new product type.

  4. Add a product reference field to the content type you want to use for single page checkout. 
     Configure with the following: 
       *widget type = select or checkboxes
       * required field
       * select a minimum of 1 product type
       * (preferrably) allow more than 1 values

  5. Navigate to node/add and select the content type with the product reference field, add products, and save
  
  6. The node will now have a single page checkout page attached to it

TODO
====

Add hook_commerce_checkout_router()
  * redirect to confirmation checkout page after checkout
  * Will fix issue that requires "completion" checkout page as last page

Create Admin Page to configure:
  * Select line item types to display on node->checkout_page
  * Add product to cart when loading node
  * Empty cart before adding product to cart
  * Disable commerce_cart_attributes_refresh_alter
  * Disable rules

Add hook_commerce_spc_line_item_type hook
  * users can pass product_types that checkout_page should be displayed on

Configur button and other options on $checkout_pages

Update the ajax url for the rule to include node nide

