import Vue from 'vue';
const { log, Level } = require('@bloom42/astro');
import * as Sentry from '@sentry/browser';
import * as Integrations from '@sentry/integrations';
import Vuetify from 'vuetify';

import 'vuetify/dist/vuetify.min.css';
import '@mdi/font/css/materialdesignicons.css';

import App from '@/App.vue';
import router from '@/router';
import store from '@/store';
// import './registerServiceWorker';

import Footer from '@/components/bloom/Footer.vue';
import Toolbar from '@/components/bloom/Toolbar.vue';
import Projects from '@/components/Projects.vue';


// init sentry for bug tracking
Sentry.init({
  dsn: process.env.VUE_APP_SENTRY_URL,
  environment: process.env.NODE_ENV,
  integrations: [new Integrations.Vue({ Vue })],
});


// Check environement
[
  'NODE_ENV',
  'VUE_APP_SENTRY_URL',
].forEach((env_var) => {
  if (!env_var) {
    throw new Error(`Missing environment variable: ${env_var}`);
  }
});


// init stage dependant stuff
if (process.env.NODE_ENV === 'development') {
  Vue.config.productionTip = true;
} else {
  Vue.config.productionTip = false;

  if (process.env.NODE_ENV === 'production') {
    log.config({ level: Level.INFO });
  }
}

// init libraries and components
Vue.use(Vuetify, {
  iconfont: 'mdi',
  icons: {
    loading: 'mdi-loading',
  },
});

// register components
Vue.component('blm-footer', Footer);
Vue.component('blm-toolbar', Toolbar);
Vue.component('blm-projects', Projects);


new Vue({
  render: (h) => h(App),
  router,
  store,
}).$mount('#app');
