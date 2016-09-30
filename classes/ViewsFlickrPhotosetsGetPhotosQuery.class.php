<?php

/**
 * @file
 * Class for implementing a simple Views query backend plugin, that uses our
 * custom class to execute requests to get photos for a Flickr photoset.
 */


/**
 * Class ViewsFlickrPhotosetsGetPhotosQuery.
 */
class ViewsFlickrPhotosetsGetPhotosQuery extends views_plugin_query {

  /**
   * The ViewsFlickrAPIRequest object.
   */
  var $request;

  /**
   * A pager plugin that should be provided by the display.
   *
   * @var views_plugin_pager
   */
  var $pager = NULL;

  /**
   * Constructor; Create the basic request object.
   */
  function init($base_table, $base_field, $options) {
    parent::init($base_table, $base_field, $options);
    $this->request = new ViewsFlickrAPIRequest();
  }

  /**
   * Builds the necessary info to execute the query.
   */
  function build(&$view) {
    $view->build_info['views_flickr_request'] = $this->request;
    $view->build_info['views_flickr_request']->addArgument('method', 'flickr.photosets.getPhotos');

    // Adding arguments to the request.
    if (isset($view->query->request_arguments)) {
      foreach ($view->query->request_arguments as $arg_key => $arg_value) {
        $view->build_info['views_flickr_request']->addArgument($arg_key, $arg_value);
      }
    }
  }

  /**
   * Executes the query and fills the associated view object with according
   * values.
   *
   * Values to set: $view->result, $view->total_rows, $view->execute_time,
   * $view->pager['current_page'].
   *
   * $view->result should contain an array of objects. The array must use a
   * numeric index starting at 0.
   *
   * @param view $view
   *   The view which is executed.
   */
  function execute(&$view) {
    $start = microtime(TRUE);

    // Setup pager.
    $view->init_pager();
    // View result array.
    $view->result = array();

    $request = $view->build_info['views_flickr_request'];

    if (isset($view->build_info['substitutions']['!1']) && is_numeric($view->build_info['substitutions']['!1'])) {
      $request->addArgument('photoset_id', $view->build_info['substitutions']['!1']);
    }

    if ($this->pager->use_pager()) {
      $request->addArgument('per_page', $this->pager->get_items_per_page());
      $request->addArgument('page', $this->pager->get_current_page() + 1);
    }

    $results = $request->execute();

    if (isset($results->photoset)) {
      foreach ($results->photoset->photo as $photo) {
        $view->result[] = $photo;
      }
    }

    if (isset($results->photoset->total)) {
      $view->total_rows = $results->photoset->total;

      if ($this->pager->use_pager()) {
        $this->pager->total_items = $results->photoset->total;
        $this->pager->update_page_info();
      }
    }

    $view->execute_time = microtime(TRUE) - $start;
  }

}
