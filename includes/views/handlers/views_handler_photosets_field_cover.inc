<?php

/**
 * @file
 * Views field handler for Photoset Cover field.
 */


/**
 * Class views_handler_photosets_field_cover.
 */
class views_handler_photosets_field_cover extends views_handler_field {

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
    $options['image_style'] = array('default' => 'thumbnail');
    $options['image_style_size'] = array('default' => 'b');
    $options['use_colorbox'] = array('default' => 0);
    $options['colorbox_size'] = array('default' => 'b');
    $options['link_to_photoset'] = array('default' => FALSE);
    $options['only_url'] = array('default' => FALSE);

    return $options;
  }

  /**
   * Provides link.
   *
   * @param $form
   * @param $form_state
   */
  function options_form(&$form, &$form_state) {
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

    $options = array();

    // TRUE if the module is both installed and enabled, FALSE otherwise.
    if (module_exists('imagecache_external')) {
      $options['imagecache_external'] = t('Use Imagecache External module');
    }

    $form['size'] = array(
      '#type'          => 'select',
      '#title'         => t('Size'),
      '#options'       => $options + array(
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
          // 'o' => t('original image, either a jpg, gif or png, depending on source format'),
        ),
      '#description'   => t('* Before May 25th 2010 large photos only exist for very large original images.') . '<br/>' . t('** Medium 800, large 1600, and large 2048 photos only exist after March 1st 2012.'),
      '#default_value' => isset($this->options['size']) ? $this->options['size'] : '-',
    );

    $image_styles = image_styles();
    $options = array();

    foreach ($image_styles as $style_id => $style) {
      $options[$style_id] = $style['name'];
    }

    $form['image_style'] = array(
      '#type'          => 'select',
      '#title'         => t('Image Style'),
      '#options'       => $options,
      '#default_value' => isset($this->options['image_style']) ? $this->options['image_style'] : 'thumbnail',
      // We have to use states instead of ctools dependency because dependency
      // doesn't handle multiple conditions.
      '#states'        => array(
        'visible' => array(
          '#edit-options-size' => array('value' => 'imagecache_external'),
        ),
      ),
      // We have to use ctools dependency too because states doesn't add the
      // correct left margin to the element's wrapper.
      '#dependency'    => array(
        // This condition is handled by form API's states.
        'edit-options-size' => array('imagecache_external'),
      ),
    );

    $form['image_style_size'] = array(
      '#type'          => 'select',
      '#title'         => t('Source Image size'),
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
        // 'o' => t('original image, either a jpg, gif or png, depending on source format'),
      ),
      '#description'   => t('* Before May 25th 2010 large photos only exist for very large original images.') . '<br/>' . t('** Medium 800, large 1600, and large 2048 photos only exist after March 1st 2012.'),
      '#default_value' => isset($this->options['image_style_size']) ? $this->options['image_style_size'] : 'b',
      // We have to use states instead of ctools dependency because dependency
      // doesn't handle multiple conditions.
      '#states'        => array(
        'visible' => array(
          '#edit-options-size' => array('value' => 'imagecache_external'),
        ),
      ),
      // We have to use ctools dependency too because states doesn't add the
      // correct left margin to the element's wrapper.
      '#dependency'    => array(
        // This condition is handled by form API's states.
        'edit-options-size' => array('imagecache_external'),
      ),
    );

    // TRUE if the module is both installed and enabled, FALSE otherwise.
    if (module_exists('colorbox')) {
      $form['use_colorbox'] = array(
        '#type'          => 'select',
        '#title'         => t('Use Colorbox'),
        '#options'       => array(
          0 => t('No'),
          1 => t('Yes'),
        ),
        '#default_value' => isset($this->options['use_colorbox']) ? $this->options['use_colorbox'] : 0,
      );

      $form['colorbox_size'] = array(
        '#type'          => 'select',
        '#title'         => t('Colorbox Image size'),
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
          // 'o' => t('original image, either a jpg, gif or png, depending on source format'),
        ),
        '#description'   => t('* Before May 25th 2010 large photos only exist for very large original images.') . '<br/>' . t('** Medium 800, large 1600, and large 2048 photos only exist after March 1st 2012.'),
        '#default_value' => isset($this->options['image_style_size']) ? $this->options['image_style_size'] : 'b',
        // We have to use states instead of ctools dependency because dependency
        // doesn't handle multiple conditions.
        '#states'        => array(
          'visible' => array(
            '#edit-options-use-colorbox' => array('value' => 1),
          ),
        ),
        // We have to use ctools dependency too because states doesn't add the
        // correct left margin to the element's wrapper.
        '#dependency'    => array(
          // This condition is handled by form API's states.
          'edit-options-use-colorbox' => array(1),
        ),
      );
    }

    $form['link_to_photoset'] = array(
      '#title'         => t('Link this field to the Photoset page.'),
      '#description'   => t("Enable to override this field's links."),
      '#type'          => 'checkbox',
      '#default_value' => !empty($this->options['link_to_photoset']),
      '#states'        => array(
        'visible' => array(
          '#edit-options-use-colorbox' => array('value' => 0),
        ),
      ),
    );

    $form['only_url'] = array(
      '#title'         => t('Only URL.'),
      '#description'   => t("Renders only an URL for image."),
      '#type'          => 'checkbox',
      '#default_value' => !empty($this->options['only_url']),
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

    if ($this->options['size'] == 'imagecache_external') {
      $size = $this->options['image_style_size'];
    }

    $url = views_flickr_photo_img($photo, $size, $format);

    if (!empty($this->options['only_url'])) {
      if ($this->options['size'] == 'imagecache_external') {
        $image_path = imagecache_external_generate_path($url);
        $image = image_style_url($this->options['image_style'], $image_path);
      }
      else {
        $image = $url;
      }
    }
    else {
      $renderable = array(
        '#theme'      => 'image',
        '#path'       => $url,
        '#attributes' => array(),
      );

      if ($this->options['size'] == 'imagecache_external') {
        $renderable['#theme'] = 'imagecache_external';
        $renderable['#style_name'] = $this->options['image_style'];
      }

      $image = drupal_render($renderable);

      if (module_exists('colorbox') && $this->options['use_colorbox'] == 1) {
        _colorbox_doheader();

        $url = views_flickr_photo_img($photo, $this->options['colorbox_size'], $format);
        return l($image, $url, array(
          'external'   => TRUE,
          'html'       => TRUE,
          'attributes' => array(
            'class' => array(
              'colorbox',
            ),
            'rel'   => 'colorbox',
          ),
        ));
      }
    }

    if (!empty($this->options['link_to_photoset'])) {
      return l($image, 'photosets/' . check_plain($values->id), array(
        'html' => TRUE,
      ));
    }

    return $image;
  }

  /**
   * Called to add the field to a query.
   */
  function query() {

  }

}
