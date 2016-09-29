<?php

/**
 * @file
 * Page callbacks for "views_flickr" module.
 */


/**
 * Menu callback.
 */
function views_flickr_api_test_page() {
  $output_method = (module_exists('devel')) ? 'dpm' : 'var_dump';

  /*
  $request = new ViewsFlickrAPIRequest();
  $result = $request
    ->addArgument('method', 'flickr.photosets.getList')
    ->addArgument('per_page', 12)
    ->addArgument('page', 1)
    ->execute();

  $output_method($result);
  */

  /*
  $request = new ViewsFlickrAPIRequest();
  $result = $request
    ->addArgument('method', 'flickr.photosets.getPhotos')
    ->addArgument('photoset_id', 72157670833905785)
    ->addArgument('per_page', 12)
    ->addArgument('page', 1)
    ->execute();

  $output_method($result);
  */

  return t('Testing...');
}
