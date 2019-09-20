app.controller('indexCtrl', ($scope, $location, $auth) => {
  if ($auth.isAuthentified) {
    $location.path('/home');
  }
  $scope.lol = 'lol';
});
