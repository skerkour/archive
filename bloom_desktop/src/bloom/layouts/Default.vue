<template>
  <div class="blm-content">
    <blm-left-bar />
    <div class="blm-content">
      <blm-app-bar />

      <blm-navigation-drawer :app="app" />

      <v-content>
        <!-- <v-container fluid class="fill-height"> -->
          <router-view />
        <!-- </v-container> -->
      </v-content>
    </div>
  </div>
</template>

<script lang="ts">
import {
  Component,
  Prop,
  Vue,
  Watch,
} from 'vue-property-decorator';
import { Route } from 'vue-router';
import BlmAppBar from '@/bloom/kernel/components/AppBar.vue';
import LeftBar from '@/bloom/kernel/components/LeftBar.vue';
import NavigationDrawer from '@/bloom/kernel/components/NavigationDrawer.vue';


@Component({
  components: {
    'blm-app-bar': BlmAppBar,
    'blm-left-bar': LeftBar,
    'blm-navigation-drawer': NavigationDrawer,
  },
})
export default class Auth extends Vue {
  // props
  // data
  app = '';


  // computed
  created() {
    this.app = this.extractApp(this.$route.path);
  }


  // lifecycle
  // watch
  @Watch('$route')
  onRouteChange(to: Route) {
    this.app = this.extractApp(to.path);
  }


  // methods
  extractApp(path: string) {
    const parts = path.split('/');
    return parts.length > 1 ? parts[1] : '';
  }
}
</script>

<style lang="scss" scoped>
.v-content, .blm-content {
  height: 100%;
}

.v-content {
  margin-left: 80px;

  padding-top: 64px !important;

  @media screen and (max-width: 960px) {
    padding-top: 56px !important;
  }
}
</style>
