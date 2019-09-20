/*
 * initialisation de l'app, et réglages généraux
 */

// variables declaration
// bind $scope funcitons
// set intervalls call
// initialise state
// functions definitions

var app = angular.module('fmw0', [
  'ngRoute',
  'ipCookie',
  'restangular',
  'ui.bootstrap'
]);

app.run(($rootScope, $location, ipCookie, Restangular, $auth) => {
  Restangular.setBaseUrl('/api');

  $rootScope.go = (path) => {
    $location.path(path);
  };

  $rootScope.$on('$locationChangeStart', (event, next) => {
  });

  if (ipCookie('token') && ipCookie('username') && ipCookie('isAdmin') != undefined  && ipCookie('id')) {

    $auth.isAuthentified = true;
    $auth.token = ipCookie('token');
    $auth.username = ipCookie('username');
    $auth.isAdmin = ipCookie('isAdmin');
    $auth.id = ipCookie('id');

    Restangular.one('authenticate').post('', { username: ipCookie('username'), token: ipCookie('token') }).then((res) => {
      $auth.isAuthentified = true;
      $auth.token = res.token;
      $auth.username = res.username;
      $auth.isAdmin = res.isAdmin;
      $auth.id = res.id;
      ipCookie('token', res.token);
      ipCookie('username', res.username);
      ipCookie('isAdmin', res.isAdmin);
      ipCookie('id', res.id);
    }).catch((err) => {
      $auth.isAuthentified = false;
      $auth.token = '';
      $auth.username = '';
      $auth.isAdmin = false;
      $auth.id = 0;
      ipCookie.remove('token');
      ipCookie.remove('username');
      ipCookie.remove('isAdmin');
      ipCookie.remove('id');
      window.location.href = '/';
    });
  } else {
    $auth.isAuthentified = false;
    $auth.token = '';
    $auth.username = '';
    $auth.isAdmin = false;
    $auth.id = 0;
  }
});
