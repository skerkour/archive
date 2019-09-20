import Vue from 'vue';
import Router from 'vue-router';
import Index from '@/views/Index.vue';
import Licensing from '@/views/Licensing.vue';


Vue.use(Router);

export default new Router({
  base: process.env.BASE_URL,
  mode: 'history',
  routes: [
    {
      component: Index,
      name: 'index',
      path: '/',
    },
    {
      component: Licensing,
      name: 'licensing',
      path: '/licensing',
    },
    { path: '**', redirect: '/' },
  ],
});
