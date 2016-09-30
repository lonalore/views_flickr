<?php

/**
 * @file
 * Simple class for putting together a URL for the API call, and doing an HTTP
 * request for retrieving information from Flickr.
 *
 * All public methods return $this and can be chained together, except the
 * execute(), which returns the response data.
 *
 * @FIXME Possible and recommended improvement: implementing a caching logic.
 */


/**
 * Class ViewsFlickrAPIRequest.
 */
class ViewsFlickrAPIRequest {

  // Default API URL for the request.
  private $apiURL;

  // Default Key for the request.
  private $apiKey;

  // Default User ID for the request.
  private $userID;

  // Flag to designate whether we are in debug mode.
  private $debugMode;

  // API call arguments. Use ViewsFlickrAPIRequest->addArgument() to set.
  private $arguments = array();

  /**
   * Constructor.
   */
  public function __construct() {
    $this->apiURL = variable_get('views_flickr_api_url', VIEWS_FLICKR_DEFAULT_API_URL);
    $this->apiKey = variable_get('views_flickr_api_key', '');
    $this->userID = variable_get('views_flickr_user_id', '');
    $this->debugMode = variable_get('views_flickr_debug_mode', VIEWS_FLICKR_DEFAULT_DEBUG_MODE);
  }

  /**
   * Sets an argument for the request.
   */
  public function addArgument($key, $value) {
    $this->arguments[$key] = $value;
    return $this;
  }

  /**
   * Executes the request. Returns the response data.
   */
  public function execute() {
    $options = array();
    $options['absolute'] = TRUE;
    $options['query'] = $this->arguments;
    $options['query']['format'] = 'json';
    $options['query']['nojsoncallback'] = 1;

    if (!isset($options['query']['api_key'])) {
      $options['query']['api_key'] = $this->apiKey;
    }

    if (!isset($options['query']['user_id'])) {
      $options['query']['user_id'] = $this->userID;
    }

    $request_url = url($this->apiURL, $options);

    if ($this->debugMode) {
      drupal_set_message(t('Request URL: !url', array('!url' => urldecode($request_url))));
    }

    return $this->request($request_url);
  }

  /**
   * Actual HTTP request.
   */
  private function request($request_url) {
    $response = drupal_http_request($request_url);

    if ($response->code != 200) {
      drupal_set_message(t('HTTP error !code received.', array(
        '!code' => $response->code,
      )), 'error');
      return FALSE;
    }

    $data = json_decode($response->data);

    if (!is_object($data)) {
      drupal_set_message(t('Did not receive valid API response (invalid JSON).'), 'error');
      return FALSE;
    }

    if (isset($data->error)) {
      drupal_set_message(t('Error !code received: %message', array(
        '!code'    => $data->error,
        '%message' => $data->message,
      )), 'error');
      return FALSE;
    }

    if (isset($data->stat) && $data->stat == 'fail') {
      drupal_set_message(t('Error !code received: %message', array(
        '!code'    => $data->code,
        '%message' => $data->message,
      )), 'error');
      return FALSE;
    }

    return $data;
  }

}
