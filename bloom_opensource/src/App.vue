<template>
  <v-app>
    <blm-toolbar />
    <div class="routes">
      <router-link class="main-links" to="/">Projects</router-link> &nbsp; - &nbsp;
      <router-link class="main-links" to="/licensing">Licensing</router-link> &nbsp; - &nbsp;
      <a class="nav-link main-links" href="https://bloom.sh/contribute">Contribute</a> &nbsp; - &nbsp;
      <a class="nav-link main-links" href="https://bloom.sh/about#sponsors">Sponsors</a>
    </div>
      <router-view/>
    <blm-footer />
  </v-app>
</template>

<script lang="ts">
import { Component, Vue } from 'vue-property-decorator';

@Component
export default class App extends Vue {
}
</script>


<style lang="scss">
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  background-color: #fff;
}

.routes {
  margin-top: 100px;
  font-size: 18px;
}

.main-links {
  color: #2c3e50;
}

a {
  text-decoration: none;
  &.router-link-exact-active {
    color: #1976d2;
  }
}

.font-18 {
  font-size: 18px;
}
</style>
