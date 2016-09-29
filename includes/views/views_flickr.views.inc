<?php

/**
 * @file
 * Contains Views module hooks.
 */


/**
 * Implements hook_views_plugins().
 */
function views_flickr_views_plugins() {
  $plugins = array(
    'query' => array(
      'ViewsFlickrPhotosetQuery' => array(
        'title'   => t('Views Flickr Photoset Query'),
        'help'    => t('Uses ViewsFlickrAPIRequest for querying information about photosets.'),
        'handler' => 'ViewsFlickrPhotosetQuery',
      ),
    ),
  );

  return $plugins;
}

/**
 * Implementation of hook_views_handlers().
 */
function views_flickr_views_handlers() {
  $path = drupal_get_path('module', 'views_flickr');

  return array(
    'handlers' => array(
      'views_flickr_views_handler_photoset_field_id'             => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_flickr_views_handler_photoset_field_title'          => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_flickr_views_handler_photoset_field_description'    => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_flickr_views_handler_photoset_field_date_create'    => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_flickr_views_handler_photoset_field_date_update'    => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_flickr_views_handler_photoset_field_count_views'    => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_flickr_views_handler_photoset_field_count_comments' => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_flickr_views_handler_photoset_field_photos' => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_flickr_views_handler_photoset_field_cover' => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function views_flickr_views_data() {
  $data = array();

  // Base table definition.
  $data['views_flickr_photoset']['table'] = array(
    'group' => t('Views Flickr'),
    'base'  => array(
      'title'       => t('Flickr Photoset'),
      'help'        => t('Lists photosets belonging to the specified user.'),
      'query class' => 'ViewsFlickrPhotosetQuery',
    ),
  );

  // ID.
  $data['views_flickr_photoset']['id'] = array(
    'title' => t('ID'),
    'help'  => t('Identifier of the Photoset.'),
    'field' => array(
      'handler' => 'views_flickr_views_handler_photoset_field_id',
    ),
  );

  // Title.
  $data['views_flickr_photoset']['title'] = array(
    'title' => t('Title'),
    'help'  => t('Title of the Photoset.'),
    'field' => array(
      'handler' => 'views_flickr_views_handler_photoset_field_title',
    ),
  );

  // Description.
  $data['views_flickr_photoset']['description'] = array(
    'title' => t('Description'),
    'help'  => t('Description of the Photoset.'),
    'field' => array(
      'handler' => 'views_flickr_views_handler_photoset_field_description',
    ),
  );

  // Date created.
  $data['views_flickr_photoset']['date_create'] = array(
    'title' => t('Created'),
    'help'  => t('The date the Photoset was created.'),
    'field' => array(
      'handler' => 'views_flickr_views_handler_photoset_field_date_create',
    ),
  );

  // Date updated.
  $data['views_flickr_photoset']['date_update'] = array(
    'title' => t('Updated'),
    'help'  => t('The date the Photoset was updated.'),
    'field' => array(
      'handler' => 'views_flickr_views_handler_photoset_field_date_update',
    ),
  );

  // Count views.
  $data['views_flickr_photoset']['count_views'] = array(
    'title' => t('Count views'),
    'help'  => t('Number of views.'),
    'field' => array(
      'handler' => 'views_flickr_views_handler_photoset_field_count_views',
    ),
  );

  // Count comments.
  $data['views_flickr_photoset']['count_comments'] = array(
    'title' => t('Count comments'),
    'help'  => t('Number of comments.'),
    'field' => array(
      'handler' => 'views_flickr_views_handler_photoset_field_count_comments',
    ),
  );

  // Photos.
  $data['views_flickr_photoset']['photos'] = array(
    'title' => t('Photos'),
    'help'  => t('Number of photos.'),
    'field' => array(
      'handler' => 'views_flickr_views_handler_photoset_field_photos',
    ),
  );

  // Cover photo.
  $data['views_flickr_photoset']['cover'] = array(
    'title' => t('Cover photo'),
    'help'  => t('Cover photo of photoset.'),
    'field' => array(
      'handler' => 'views_flickr_views_handler_photoset_field_cover',
    ),
  );

  return $data;
}
