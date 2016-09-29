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
      'ViewsFlickrPhotosetsGetListQuery' => array(
        'title'   => t('Views Flickr Photosets getList Query'),
        'help'    => t('Uses ViewsFlickrAPIRequest for querying information about photosets.'),
        'handler' => 'ViewsFlickrPhotosetsGetListQuery',
      ),
      'ViewsFlickrPhotosetsGetPhotosQuery' => array(
        'title'   => t('Views Flickr Photosets getPhotos Query'),
        'help'    => t('Uses ViewsFlickrAPIRequest for querying photos from a photoset.'),
        'handler' => 'ViewsFlickrPhotosetsGetPhotosQuery',
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
      'views_handler_photosets_field_id'             => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_handler_photosets_field_title'          => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_handler_photosets_field_description'    => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_handler_photosets_field_date_create'    => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_handler_photosets_field_date_update'    => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_handler_photosets_field_count_views'    => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_handler_photosets_field_count_comments' => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_handler_photosets_field_photos'         => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_handler_photosets_field_cover'          => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),

      'views_handler_photosets_photos_field_id'             => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_handler_photosets_photos_field_title'          => array(
        'parent' => 'views_handler_field',
        'path'   => $path . '/includes/views/handlers',
      ),
      'views_handler_photosets_photos_field_photo'          => array(
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
  $data['views_flickr_photosets']['table'] = array(
    'group' => t('Views Flickr'),
    'base'  => array(
      'title'       => t('Flickr Photosets'),
      'help'        => t('Lists photosets belonging to the specified user.'),
      'query class' => 'ViewsFlickrPhotosetsGetListQuery',
    ),
  );

  // ID.
  $data['views_flickr_photosets']['id'] = array(
    'title' => t('ID'),
    'help'  => t('Identifier of the Photoset.'),
    'field' => array(
      'handler' => 'views_handler_photosets_field_id',
    ),
  );

  // Title.
  $data['views_flickr_photosets']['title'] = array(
    'title' => t('Title'),
    'help'  => t('Title of the Photoset.'),
    'field' => array(
      'handler' => 'views_handler_photosets_field_title',
    ),
  );

  // Description.
  $data['views_flickr_photosets']['description'] = array(
    'title' => t('Description'),
    'help'  => t('Description of the Photoset.'),
    'field' => array(
      'handler' => 'views_handler_photosets_field_description',
    ),
  );

  // Date created.
  $data['views_flickr_photosets']['date_create'] = array(
    'title' => t('Created'),
    'help'  => t('The date the Photoset was created.'),
    'field' => array(
      'handler' => 'views_handler_photosets_field_date_create',
    ),
  );

  // Date updated.
  $data['views_flickr_photosets']['date_update'] = array(
    'title' => t('Updated'),
    'help'  => t('The date the Photoset was updated.'),
    'field' => array(
      'handler' => 'views_handler_photosets_field_date_update',
    ),
  );

  // Count views.
  $data['views_flickr_photosets']['count_views'] = array(
    'title' => t('Count views'),
    'help'  => t('Number of views.'),
    'field' => array(
      'handler' => 'views_handler_photosets_field_count_views',
    ),
  );

  // Count comments.
  $data['views_flickr_photosets']['count_comments'] = array(
    'title' => t('Count comments'),
    'help'  => t('Number of comments.'),
    'field' => array(
      'handler' => 'views_handler_photosets_field_count_comments',
    ),
  );

  // Photos.
  $data['views_flickr_photosets']['photos'] = array(
    'title' => t('Photos'),
    'help'  => t('Number of photos.'),
    'field' => array(
      'handler' => 'views_handler_photosets_field_photos',
    ),
  );

  // Cover photo.
  $data['views_flickr_photosets']['cover'] = array(
    'title' => t('Cover photo'),
    'help'  => t('Cover photo of photoset.'),
    'field' => array(
      'handler' => 'views_handler_photosets_field_cover',
    ),
  );

  // Base table definition.
  $data['views_flickr_photosets_photos']['table'] = array(
    'group' => t('Views Flickr'),
    'base'  => array(
      'title'       => t('Flickr Photosets - Photos'),
      'help'        => t('Lists photos from the specified photoset belonging to the specified user.'),
      'query class' => 'ViewsFlickrPhotosetsGetPhotosQuery',
    ),
  );

  // ID.
  $data['views_flickr_photosets_photos']['id'] = array(
    'title' => t('ID'),
    'help'  => t('Identifier of the Photo.'),
    'field' => array(
      'handler' => 'views_handler_photosets_photos_field_id',
    ),
  );

  // Title.
  $data['views_flickr_photosets_photos']['title'] = array(
    'title' => t('Title'),
    'help'  => t('Title of the Photo.'),
    'field' => array(
      'handler' => 'views_handler_photosets_photos_field_title',
    ),
  );

  // Photo.
  $data['views_flickr_photosets_photos']['photo'] = array(
    'title' => t('Photo'),
    'help'  => t('Photo.'),
    'field' => array(
      'handler' => 'views_handler_photosets_photos_field_photo',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_default_views().
 */
function views_flickr_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'flickr_photosets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'views_flickr_photosets';
  $view->human_name = 'Flickr Photosets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Flickr Photosets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'id',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Views Flickr: ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'views_flickr_photosets';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['link_to_photoset'] = 1;
  /* Field: Views Flickr: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'views_flickr_photosets';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_photoset'] = 1;
  /* Field: Views Flickr: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'views_flickr_photosets';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  /* Field: Views Flickr: Count comments */
  $handler->display->display_options['fields']['count_comments']['id'] = 'count_comments';
  $handler->display->display_options['fields']['count_comments']['table'] = 'views_flickr_photosets';
  $handler->display->display_options['fields']['count_comments']['field'] = 'count_comments';
  $handler->display->display_options['fields']['count_comments']['precision'] = '0';
  /* Field: Views Flickr: Count views */
  $handler->display->display_options['fields']['count_views']['id'] = 'count_views';
  $handler->display->display_options['fields']['count_views']['table'] = 'views_flickr_photosets';
  $handler->display->display_options['fields']['count_views']['field'] = 'count_views';
  $handler->display->display_options['fields']['count_views']['precision'] = '0';
  /* Field: Views Flickr: Photos */
  $handler->display->display_options['fields']['photos']['id'] = 'photos';
  $handler->display->display_options['fields']['photos']['table'] = 'views_flickr_photosets';
  $handler->display->display_options['fields']['photos']['field'] = 'photos';
  $handler->display->display_options['fields']['photos']['precision'] = '0';
  /* Field: Views Flickr: Created */
  $handler->display->display_options['fields']['date_create']['id'] = 'date_create';
  $handler->display->display_options['fields']['date_create']['table'] = 'views_flickr_photosets';
  $handler->display->display_options['fields']['date_create']['field'] = 'date_create';
  $handler->display->display_options['fields']['date_create']['date_format'] = 'long';
  $handler->display->display_options['fields']['date_create']['second_date_format'] = 'long';
  /* Field: Views Flickr: Updated */
  $handler->display->display_options['fields']['date_update']['id'] = 'date_update';
  $handler->display->display_options['fields']['date_update']['table'] = 'views_flickr_photosets';
  $handler->display->display_options['fields']['date_update']['field'] = 'date_update';
  $handler->display->display_options['fields']['date_update']['date_format'] = 'long';
  $handler->display->display_options['fields']['date_update']['second_date_format'] = 'long';
  /* Field: Views Flickr: Cover photo */
  $handler->display->display_options['fields']['cover']['id'] = 'cover';
  $handler->display->display_options['fields']['cover']['table'] = 'views_flickr_photosets';
  $handler->display->display_options['fields']['cover']['field'] = 'cover';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'photosets';
  $translatables['flickr_photosets'] = array(
    t('Master'),
    t('Flickr Photosets'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('ID'),
    t('Title'),
    t('Description'),
    t('Count comments'),
    t('.'),
    t(','),
    t('Count views'),
    t('Photos'),
    t('Created'),
    t('Updated'),
    t('Cover photo'),
    t('Page'),
  );

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'flickr_photoset_photos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'views_flickr_photosets_photos';
  $view->human_name = 'Flickr Photoset Photos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Flickr Photoset Photos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Views Flickr: Photo */
  $handler->display->display_options['fields']['photo']['id'] = 'photo';
  $handler->display->display_options['fields']['photo']['table'] = 'views_flickr_photosets_photos';
  $handler->display->display_options['fields']['photo']['field'] = 'photo';
  $handler->display->display_options['fields']['photo']['label'] = '';
  $handler->display->display_options['fields']['photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['photo']['size'] = 'm';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['null']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'photoset/%';
  $translatables['flickr_photoset_photos'] = array(
    t('Master'),
    t('Flickr Photoset Photos'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Page'),
    t('All'),
  );

  $views[$view->name] = $view;

  return $views;
}
