<?php

/**
 * @file
 * Administrative page callbacks for "views_flickr" module.
 */


/**
 * Configuration form for controlling the "views_flickr" behaviour.
 */
function views_flickr_settings_form($form, &$form_state) {
  $form['api'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('API settings'),
    '#collapsible' => FALSE,
    '#collapsed'   => FALSE,
  );

  $form['api']['views_flickr_api_key'] = array(
    '#type'          => 'textfield',
    '#title'         => t('API Key'),
    '#default_value' => variable_get('views_flickr_api_key', ''),
  );

  $form['api']['views_flickr_user_id'] = array(
    '#type'          => 'textfield',
    '#title'         => t('User ID'),
    '#default_value' => variable_get('views_flickr_user_id', ''),
  );

  $form['api']['views_flickr_api_url'] = array(
    '#type'          => 'textfield',
    '#title'         => t('API URL'),
    '#default_value' => variable_get('views_flickr_api_url', VIEWS_FLICKR_DEFAULT_API_URL),
  );

  $form['api']['views_flickr_debug_mode'] = array(
    '#type'          => 'select',
    '#title'         => t('Debug mode'),
    '#options'       => array(
      1 => t('Yes'),
      0 => t('No'),
    ),
    '#default_value' => variable_get('views_flickr_debug_mode', VIEWS_FLICKR_DEFAULT_DEBUG_MODE),
  );

  return system_settings_form($form);
}
