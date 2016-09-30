<?php

/**
 * @file
 * Views field handler for Photoset Title field.
 */


/**
 * Class views_handler_photosets_field_title.
 */
class views_handler_photosets_field_title extends views_handler_field {

  /**
   * Initializes.
   *
   * @param $view
   * @param $options
   */
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->aliases['title'] = 'title';
  }

  /**
   * Default options.
   *
   * @return array
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['link_to_photoset'] = array('default' => FALSE);
    
    return $options;
  }

  /**
   * Provides link.
   *
   * @param $form
   * @param $form_state
   */
  function options_form(&$form, &$form_state) {
    $form['link_to_photoset'] = array(
      '#title'         => t('Link this field to the Photoset page.'),
      '#description'   => t("Enable to override this field's links."),
      '#type'          => 'checkbox',
      '#default_value' => !empty($this->options['link_to_photoset']),
    );
    
    parent::options_form($form, $form_state);
  }

  /**
   * Render whatever the data is as a link to the Photoset page. Data should be
   * made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_photoset']) && $data !== NULL && $data !== '') {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "photosets/" . check_plain($values->id);
    }

    return $data;
  }

  /**
   * Renders value.
   *
   * @param $values
   * @return mixed
   */
  function render($values) {
    $value = $this->get_value($values, 'title');
    $sanitized = isset($value->_content) ? $this->sanitize_value($value->_content) : '';
    return $this->render_link($sanitized, $values);
  }

  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->field_alias = $this->real_field;
  }
}

