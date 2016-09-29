<?php

/**
 * @file
 * Views field handler for Photoset Description field.
 */


/**
 * Class views_flickr_views_handler_photoset_field_description.
 */
class views_flickr_views_handler_photoset_field_description extends views_handler_field {

  /**
   * Initializes.
   *
   * @param $view
   * @param $options
   */
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->aliases['description'] = 'description';
  }

  /**
   * Default options.
   *
   * @return array
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Provides link.
   *
   * @param $form
   * @param $form_state
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Renders value.
   *
   * @param $values
   * @return mixed
   */
  function render($values) {
    $value = $this->get_value($values, 'description');
    return isset($value->_content) ? $value->_content : '';
  }

  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->field_alias = $this->real_field;
  }
}

