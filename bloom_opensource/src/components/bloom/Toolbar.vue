<template>
  <v-toolbar dark color="primary" fixed>
    <router-link to="/">
      <v-toolbar-title class="">
        Bloom Open Source
      </v-toolbar-title>
    </router-link>

    <v-spacer></v-spacer>

    <v-tooltip bottom>
      <v-btn slot="activator" icon href="https://help.bloom.sh" target="_blank" rel="noopener">
        <v-icon>mdi-help-circle</v-icon>
      </v-btn>
      <span>Help</span>
    </v-tooltip>

    <v-toolbar-items>
      <v-btn flat href="https://bloom.sh/sign_in" id="sign-in-btn">Sign in</v-btn>
      <v-btn outline dark href="https://bloom.sh/register" id="register-btn">Try it Free</v-btn>
    </v-toolbar-items>

  </v-toolbar>
</template>


<script lang="ts">
import { Component, Prop, Vue } from 'vue-property-decorator';


@Component
export default class Toolbar extends Vue {
  // props
  // data
  // computed
  // lifecycle
  // watch
  // methods
}
</script>


<style scoped lang="scss">
.v-toolbar a {
  color: white;
  text-decoration: none;
  text-overflow: ellipsis;
  overflow: hidden;
}

.v-content {
  height: 100%;
}

#register-btn, #sign-in-btn {
  height: 36px;
}
</style>
