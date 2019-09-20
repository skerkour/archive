<template>
  <v-container>
    <v-layout row>
      <v-flex xs12>
          <v-container fluid grid-list-md>
            <v-layout row wrap >

              <v-flex xs12 class="mb-3 title blue-grey--text text--darken-1">
                <h1>
                  Projects
                </h1>
              </v-flex>

              <v-flex v-for="project in projects" xs6 sm4 :key="project.name" class="mt-5 text-xs-center">
                <v-img :src="project.img" height="150px" contain class="app-icon"></v-img>
                <p class="headline app-name mt-3">{{ project.name }}</p>
                <p class="subheading mt-3">{{ project.description }}</p>
                <p class="subheading">
                  <a :href="project.homepage" v-if="project.homepage">
                    Homepage
                  </a>
                  <span v-if="project.homepage && project.repository"> - </span>
                  <a :href="project.repository" v-if="project.repository">
                    Git Repository
                  </a>
                </p>
              </v-flex>

            </v-layout>
          </v-container>
      </v-flex>
    </v-layout>
  </v-container>
</template>

<script lang="ts">
import { Component, Vue } from 'vue-property-decorator';

@Component
export default class Projects extends Vue {
  // props
  // data
  projects = [
    {
      description: 'A simple piece of software that makes downloading ﬁles fast ⚡',
      homepage: '/bitflow',
      img: 'https://bloom.sh/kernel/static/imgs/logos/bitflow_256.png',
      name: 'Bitflow',
      repository: 'https://github.com/bloom42/bitflow',
    },
    {
      description: 'The cloud native security scanner ☁️',
      homepage: '/phaser',
      img: 'https://bloom.sh/kernel/static/imgs/logos/phaser_256.png',
      name: 'Phaser',
      repository: 'https://github.com/bloom42/phaser',
    },
    {
      description: 'Automated software delivery as fast and easy as possible',
      homepage: '/rocket',
      img: '/imgs/img_square_3.svg',
      name: 'Rocket',
      repository: 'https://github.com/bloom42/rocket',
    },
    {
      description: 'Simple and beautiful Analytics',
      homepage: '/signal',
      img: '/imgs/img_square_3.svg',
      name: 'Signal',
      repository: 'https://github.com/bloom42/signal',
    },
    {
      description: 'The Simple And NEeded configuration format',
      homepage: '/sane',
      img: '/imgs/img_square_3.svg',
      name: 'SANE',
      repository: 'https://github.com/bloom42/sane',
    },
    // {
    //   description: 'Automated Code Review for gO',
    //   homepage: '/acro',
    //   img: '/imgs/img_square_3.svg',
    //   name: 'Acro',
    //   repository: 'https://github.com/bloom42/acro',
    // },
    {
      description: 'Bloom\'s open source website',
      homepage: 'https://opensource.bloom.sh/',
      img: '/imgs/img_square_3.svg',
      name: 'Open Source',
      repository: 'https://github.com/bloom42/opensource',
    },
    {
      description: 'Correct commonly misspelled English words in source files 📖',
      img: '/imgs/img_square_3.svg',
      name: 'misspell',
      repository: 'https://github.com/bloom42/misspell',
    },
    {
      description: 'Automated Hacker News curation',
      img: '/imgs/img_square_3.svg',
      name: 'Newsbot',
      repository: 'https://github.com/bloom42/newsbot',
    },
    {
      description: 'RipZap - The fastest structured, leveled JSON logger for Go ⚡️. ' +
        'Dependency free.',
      img: '/imgs/img_square_3.svg',
      name: 'rz-go',
      repository: 'https://github.com/bloom42/rz-go',
    },
    {
      description: 'Fast, elegant, structured, pluggable and isomorphic logging for Javascript',
      img: '/imgs/img_square_3.svg',
      name: 'Astro-js',
      repository: 'https://github.com/bloom42/astro-js',
    },
    {
      description: 'Fast and configurable filesystem (file and directory names) linter',
      img: '/imgs/img_square_3.svg',
      name: 'Flint',
      repository: 'https://github.com/bloom42/flint',
    },
  ];


  // computed
  // lifecycle
  // watch
  // methods
}
</script>


<style scoped lang="scss">
a {
  text-decoration: none;
}
</style>
