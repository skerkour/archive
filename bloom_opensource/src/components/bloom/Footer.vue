<template>
  <v-footer
  color="white"
      height="auto"
      class="text-xs-left"
    >
    <v-container>
      <v-layout row wrap class="text-xs-center text-sm-left">
        <v-flex xs12 sm4 class="pa-4">
          <h5 class="title pb-3">Organization</h5>
          <ul>
            <li><a class="nav-link" href="https://bloom.sh/about">About</a></li>
            <li><a class="nav-link" href="https://bloom.sh/contact">Contact</a></li>
            <li><a class="nav-link" href="https://bloom.sh/security">Security</a></li>
            <li><a class="nav-link" href="https://bloom.sh/terms">Terms</a></li>
            <li><a class="nav-link" href="https://bloom.sh/privacy">Privacy</a></li>
            <li><a class="nav-link" href="https://bloom.sh/become-a-sponsor">Sponsoring</a></li>
          </ul>
        </v-flex>
        <v-flex xs12 sm4 class="pa-4">
          <h5 class="title pb-3">Product</h5>
          <ul>

            <li><a class="nav-link" href="https://help.bloom.sh">Help & Support</a></li>
            <li><a class="nav-link" href="https://bloom.sh/download-apps">Mobile Apps</a></li>
            <li><a class="nav-link" href="https://bloom.sh/contribute">Contribute</a></li>
            <li><a class="nav-link" href="https://help.bloom.sh">Documentation</a></li>
            <li><a class="nav-link" href="https://status.bloom.sh" target="_blank" rel="noopener">System Status</a></li>
          </ul>
        </v-flex>
        <v-flex xs12 sm4 class="pa-4">
          <h5 class="title pb-3">Community</h5>
          <ul>
            <li><a class="nav-link" href="https://opensource.bloom.sh" target="_blank" rel="noopener">Open Source</a></li>
            <li><a class="nav-link" href="https://twitter.com/42bloom" target="_blank" rel="noopener">Twitter</a></li>
            <li><a class="nav-link" href="https://forum.bloom.sh" target="_blank" rel="noopener">Forum</a></li>
            <li><a class="nav-link" href="https://discord.gg/HmDQDGv" target="_blank" rel="noopener">Discord Chat</a></li>
            <li><a class="nav-link" href="https://gitlab.com/bloom42" target="_blank" rel="noopener">GitLab</a></li>
          </ul>
        </v-flex>

        <v-flex xs12>
          <p class="text-xs-center">
            <span><a href="mailto:hello@bloom.sh">hello@bloom.sh</a></span><br/><br/>
            <span>&copy; 2018 - {{ new Date().getFullYear() }} Bloom</span>
          </p>
        </v-flex>

      </v-layout>
    </v-container>

    </v-footer>
</template>


<script lang="ts">
import { Component, Prop, Vue } from 'vue-property-decorator';


@Component
export default class Footer extends Vue {
  // props
  // data
  // computed
  // lifecycle
  // watch
  // methods
}
</script>


<style scoped lang="scss">
a {
  text-decoration: none;
  color: black;
}

ul li {
  margin-bottom: 10px;
}

ul {
  list-style-type: none;
}

ol, ul {
  padding-left: 0px;
}
</style>

