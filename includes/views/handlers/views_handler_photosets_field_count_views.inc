<?php

/**
 * @file
 * Views field handler for Photoset Count Views field.
 */


/**
 * Class views_handler_photosets_field_count_views.
 */
class views_handler_photosets_field_count_views extends views_handler_field {

  /**
   * Initializes.
   *
   * @param $view
   * @param $options
   */
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->aliases['count_views'] = 'count_views';
  }

  /**
   * Default options.
   *
   * @return array
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['set_precision'] = array('default' => FALSE, 'bool' => TRUE);
    $options['precision'] = array('default' => 0);
    $options['decimal'] = array('default' => '.', 'translatable' => TRUE);
    $options['separator'] = array('default' => ',', 'translatable' => TRUE);
    $options['format_plural'] = array('default' => FALSE, 'bool' => TRUE);
    $options['format_plural_singular'] = array('default' => '1');
    $options['format_plural_plural'] = array('default' => '@count');
    $options['prefix'] = array('default' => '', 'translatable' => TRUE);
    $options['suffix'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  /**
   * Provides link.
   *
   * @param $form
   * @param $form_state
   */
  function options_form(&$form, &$form_state) {
    $form['set_precision'] = array(
      '#type'          => 'checkbox',
      '#title'         => t('Round'),
      '#description'   => t('If checked, the number will be rounded.'),
      '#default_value' => $this->options['set_precision'],
    );

    $form['precision'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Precision'),
      '#default_value' => $this->options['precision'],
      '#description'   => t('Specify how many digits to print after the decimal point.'),
      '#dependency'    => array('edit-options-set-precision' => array(TRUE)),
      '#size'          => 2,
    );

    $form['decimal'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Decimal point'),
      '#default_value' => $this->options['decimal'],
      '#description'   => t('What single character to use as a decimal point.'),
      '#size'          => 2,
    );

    $form['separator'] = array(
      '#type'          => 'select',
      '#title'         => t('Thousands marker'),
      '#options'       => array(
        ''   => t('- None -'),
        ','  => t('Comma'),
        ' '  => t('Space'),
        '.'  => t('Decimal'),
        '\'' => t('Apostrophe'),
      ),
      '#default_value' => $this->options['separator'],
      '#description'   => t('What single character to use as the thousands separator.'),
      '#size'          => 2,
    );

    $form['format_plural'] = array(
      '#type'          => 'checkbox',
      '#title'         => t('Format plural'),
      '#description'   => t('If checked, special handling will be used for plurality.'),
      '#default_value' => $this->options['format_plural'],
    );

    $form['format_plural_singular'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Singular form'),
      '#default_value' => $this->options['format_plural_singular'],
      '#description'   => t('Text to use for the singular form.'),
      '#dependency'    => array('edit-options-format-plural' => array(TRUE)),
    );

    $form['format_plural_plural'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Plural form'),
      '#default_value' => $this->options['format_plural_plural'],
      '#description'   => t('Text to use for the plural form, @count will be replaced with the value.'),
      '#dependency'    => array('edit-options-format-plural' => array(TRUE)),
    );

    $form['prefix'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Prefix'),
      '#default_value' => $this->options['prefix'],
      '#description'   => t('Text to put before the number, such as currency symbol.'),
    );

    $form['suffix'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Suffix'),
      '#default_value' => $this->options['suffix'],
      '#description'   => t('Text to put after the number, such as currency symbol.'),
    );

    parent::options_form($form, $form_state);
  }

  /**
   * Renders value.
   *
   * @param $values
   * @return mixed
   */
  function render($values) {
    $value = $this->get_value($values, 'count_views');

    if (!empty($this->options['set_precision'])) {
      $value = number_format($value, $this->options['precision'], $this->options['decimal'], $this->options['separator']);
    }
    else {
      $remainder = abs($value) - intval(abs($value));
      $value = $value > 0 ? floor($value) : ceil($value);
      $value = number_format($value, 0, '', $this->options['separator']);
      if ($remainder) {
        // The substr may not be locale safe.
        $value .= $this->options['decimal'] . substr($remainder, 2);
      }
    }

    // Check to see if hiding should happen before adding prefix and suffix.
    if ($this->options['hide_empty'] && empty($value) && ($value !== 0 || $this->options['empty_zero'])) {
      return '';
    }

    // Should we format as a plural.
    if (!empty($this->options['format_plural'])) {
      $value = format_plural($value, $this->options['format_plural_singular'], $this->options['format_plural_plural']);
    }

    return $this->sanitize_value($this->options['prefix'], 'xss')
    . $this->sanitize_value($value)
    . $this->sanitize_value($this->options['suffix'], 'xss');
  }

  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->field_alias = $this->real_field;
  }
}

