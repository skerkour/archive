const webpack = require('webpack');

module.exports = {
  configureWebpack: {
    externals: {
      // Tricky: Whenever we see `require("bloom_native")`, use the following
      // JavaScript to implement a stub module.  We can't use `node-loader` for
      // this because it bakes in hard-coded paths and breaks the ability to
      // move compiled Electron apps between systems.
      bloom_native: "require('../../../../../../../../native')",
    },
  },
  chainWebpack: (config) => {
    config.plugin('define').tap((args) => {
      const v = JSON.stringify(require('./package.json').version); // eslint-disable-line global-require
      args[0]['process.env'].VERSION = v; // eslint-disable-line no-param-reassign
      return args;
    });

    config.module
      .rule('vue')
      .use('vue-loader')
      .loader('vue-loader')
      .tap((options) => {
        options.transformAssetUrls = { // eslint-disable-line
          video: ['src', 'poster'],
          source: 'src',
          img: 'src',
          image: ['xlink:href', 'href'],
          use: ['xlink:href', 'href'],
          'v-img': 'src',
        };

        return options;
      });
  },
  pwa: {
    name: 'Bloom',
    iconPaths: {
      favicon64: 'kernel/imgs/icons/bloom_64.png',
      favicon32: 'kernel/imgs/icons/bloom_64.png',
      favicon16: 'kernel/imgs/icons/bloom_32.png',
      appleTouchIcon: 'kernel/imgs/icons/bloom_256.png',
      maskIcon: 'kernel/imgs/icons/bloom_256.png',
      msTileImage: 'kernel/imgs/icons/bloom_256.png',
    },
  },
};
