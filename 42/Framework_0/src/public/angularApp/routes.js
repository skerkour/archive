app.config(($locationProvider, $routeProvider) => {
  $routeProvider
  .when('/', {
    templateUrl: '/angularApp/components/index/index.html',
    controller: 'indexCtrl'
  })
  .when('/login', {
    templateUrl: '/angularApp/components/login/login.html',
    controller: 'loginCtrl'
  })
  .when('/register', {
    templateUrl: '/angularApp/components/register/register.html',
    controller: 'registerCtrl'
  })
  .when('/home', {
    templateUrl: '/angularApp/components/home/home.html',
    controller: 'homeCtrl'
  })
  .when('/admin', {
    templateUrl: '/angularApp/components/admin/admin.html',
    controller: 'adminCtrl'
  })
  .when('/admin/users', {
    templateUrl: '/angularApp/components/admin/users/show.html',
    controller: 'adminUsersShowCtrl'
  })
  .when('/admin/users/:id', {
    templateUrl: '/angularApp/components/admin/users/_id/show.html',
    controller: 'adminUsersShowByIdCtrl'
  })
  .when('/admin/users/:id/edit', {
    templateUrl: '/angularApp/components/admin/users/_id/edit.html',
    controller: 'adminUsersEditByIdCtrl'
  })
  .when('/profile', {
    templateUrl: '/angularApp/components/profile/show.html',
    controller: 'profileShowCtrl'
  })
  .when('/profile/edit', {
    templateUrl: '/angularApp/components/profile/edit.html',
    controller: 'profileEditCtrl'
  })
  .otherwise({
    redirectTo: '/'
  });
});
