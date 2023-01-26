<?php
class PricingModule {
  // Properties
  public $price;
  public $gallons;

  // Methods
  function set_price($price) {
    $this->price = $price;
  }
  function get_price() {
    return $this->price;
  }
}
?>