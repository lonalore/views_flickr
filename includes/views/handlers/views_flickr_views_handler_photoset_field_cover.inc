<?php

/**
 * @file
 * Views field handler for Photoset Cover field.
 */


/**
 * Class views_flickr_views_handler_photoset_field_cover.
 */
class views_flickr_views_handler_photoset_field_cover extends views_handler_field {
  
  /**
   * Initializes.
   *
   * @param $view
   * @param $options
   */
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->additional_fields['cover'] = 'cover';
  }
  
  /**
   * Default options.
   *
   * @return array
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['size'] = array('default' => '-');
    $options['format'] = array('default' => 'jpg');

    return $options;
  }

  /**
   * Provides link.
   *
   * @param $form
   * @param $form_state
   */
  function options_form(&$form, &$form_state) {
    $form['size'] = array(
      '#type'          => 'select',
      '#title'         => t('Size'),
      '#options'       => array(
        's' => t('small square 75x75'),
        'q' => t('large square 150x150'),
        't' => t('thumbnail, 100 on longest side'),
        'm' => t('small, 240 on longest side'),
        'n' => t('small, 320 on longest side'),
        '-' => t('medium, 500 on longest side'),
        'z' => t('medium 640, 640 on longest side'),
        'c' => t('medium 800, 800 on longest side**'),
        'b' => t('large, 1024 on longest side*'),
        'h' => t('large 1600, 1600 on longest side**'),
        'k' => t('large 2048, 2048 on longest side**'),
        'o' => t('original image, either a jpg, gif or png, depending on source format'),
      ),
      '#description'   => t('* Before May 25th 2010 large photos only exist for very large original images.') . '<br/>' . t('** Medium 800, large 1600, and large 2048 photos only exist after March 1st 2012.'),
      '#default_value' => isset($this->options['size']) ? $this->options['size'] : '-',
    );

    $form['format'] = array(
      '#type'          => 'select',
      '#title'         => t('Format'),
      '#options'       => array(
        'jpg' => 'jpg',
        'png' => 'png',
        'gif' => 'gif',
      ),
      '#default_value' => isset($this->options['format']) ? $this->options['format'] : 'jpg',
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
    $photo = array(
      'farm'    => isset($values->farm) ? $values->farm : '',
      'server'  => isset($values->server) ? $values->server : '',
      'primary' => isset($values->primary) ? $values->primary : '',
      'secret'  => isset($values->secret) ? $values->secret : '',
    );

    $size = $this->options['size'];
    $format = $this->options['format'];

    $url = views_flickr_photo_img($photo, $size, $format);

    $variables = array(
      'path' => $url,
      'attributes' => array(),
    );

    return theme_image($variables);
  }

  /**
   * Called to add the field to a query.
   */
  function query() {
    
  }

}
