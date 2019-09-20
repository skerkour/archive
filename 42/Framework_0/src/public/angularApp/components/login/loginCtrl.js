app.controller('loginCtrl', ($scope, $auth, $location, Restangular, ipCookie) => {
  if ($auth.isAuthentified) {
    $location.path('/home');
  }

  $scope.sendLoginRequest = sendLoginRequest;
  $scope.closeAlertErrorOnLogin = closeAlertErrorOnLogin;

  function sendLoginRequest() {
    var baseLogin = Restangular.all('authenticate');

    var data = {
      username: $scope.username,
      password: $scope.password
    };
    baseLogin.post(data).then((res) => {
      $auth.username = res.username;
      $auth.token = res.token;
      $auth.isAdmin = res.isAdmin;
      $auth.id = res.id;
      $auth.isAuthentified = true;
      ipCookie('username', res.username, { expires: 1337 });
      ipCookie('token', res.token, { expires: 1337 });
      ipCookie('isAdmin', res.isAdmin, { expires: 1337 });
      ipCookie('id', res.id, { expires: 1337 });
      $location.path('/home');
    }).catch((err) => {
      $scope.errorOnLogin = {
        informations: err.data.informations
      };
    });
  }

  function closeAlertErrorOnLogin() {
    $scope.errorOnLogin = null;
  }
});
