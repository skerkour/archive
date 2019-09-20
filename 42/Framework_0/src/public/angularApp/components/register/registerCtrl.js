app.controller('registerCtrl', ($scope, Restangular, $auth, $location, ipCookie) => {

  if ($auth.isAuthentified) {
    location.path('/home');
  }

  $scope.sendRegistrationRequest = sendRegistrationRequest;
  $scope.closeAlertErrorOnRegister = closeAlertErrorOnRegister;

  function sendRegistrationRequest() {
    var baseRegister = Restangular.all('users');

    var data = {
      username: $scope.username,
      email: $scope.email,
      password: $scope.password
    };
    baseRegister.post(data).then((res) => {
      $auth.username = res.username;
      $auth.token = res.token;
      $auth.isAuthentified = true;
      $auth.isAdmin = res.isAdmin;
      $auth.id = res.id;
      ipCookie('username', res.username, { expires: 1337 });
      ipCookie('token', res.token, { expires: 1337 });
      ipCookie('isAdmin', res.isAdmin, { expires: 1337 });
      ipCookie('id', res.id, { expires: 1337 });
      $location.path('/home');
    }).catch((err) => {
      $scope.errorOnRegister = {
        informations: err.data.informations
      };
    });
  }

  function closeAlertErrorOnRegister() {
    $scope.errorOnRegister = null;
  };

});
