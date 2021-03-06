# Views Flickr (Drupal 7 module)

Views integration with [Flickr](https://www.flickr.com/) to list photosets and photos.

### Features

- Flickr Photoset fields integration with [Views](https://www.drupal.org/project/views)
- Flickr Photoset Photo fields integration with [Views](https://www.drupal.org/project/views)
- Supports [Imagecache External](http://drupal.org/project/imagecache_external) module
- Supports [Colorbox](https://www.drupal.org/project/colorbox) module

### Dependencies

- [Drupal 7](https://www.drupal.org/project/drupal)
- [Chaos Tool Suite](https://www.drupal.org/project/ctools) module (contributed)
- [Views 3](https://www.drupal.org/project/views) module (contributed)
- [Flickr API Key](https://www.flickr.com/services/api/misc.api_keys.html)

### Installation and Configuration

- Clone repository:
```
git clone https://github.com/lonalore/views_flickr.git views_flickr
```
- Copy ``views_flicker`` folder to ``sites/all/modules``
- Install ``views_flicker`` module ([Installing contributed modules](https://www.drupal.org/docs/7/extending-drupal/installing-contributed-modules-find-import-enable-configure))
- Goto ``views_flicker`` settings page (Admin > Configuration > WEB SERVICES > Views Flickr API settings)
- Provide your Flicker API Key and Flicker User ID
- Visit Photosets page at ``http://yoursite.com/photosets``

If you want to use Drupal Image Styles, you'll need to install [imagecache_external](http://drupal.org/project/imagecache_external) module.

## Support on Beerpay
Hey dude! Help me out for a couple of :beers:!

[![Beerpay](https://beerpay.io/lonalore/views_flickr/badge.svg?style=beer-square)](https://beerpay.io/lonalore/views_flickr)  [![Beerpay](https://beerpay.io/lonalore/views_flickr/make-wish.svg?style=flat-square)](https://beerpay.io/lonalore/views_flickr?focus=wish)