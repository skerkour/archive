app.controller('profileShowCtrl', ($uibModal, $scope, $rootScope, $auth, $location, Restangular, $routeParams) => {
  if (!$auth.isAuthentified) {
    window.location.href = '/';
  }
  $scope.user = {};
  $scope.goToEdit = goToEdit;
  $scope.closeAlertError = closeAlertError;
  $scope.closeAlertSuccessSuccess = closeAlertSuccess;
  getUser();

  function getUser() {
    Restangular.one('users', $auth.id).get({}, { 'x-access-token': $auth.token }).then((user) => {
      $scope.user = user;

    }).catch((err) => {
      $scope.alertError = {
        informations: err.data.informations
      };
    });
  };

  function closeAlertError() {
    $scope.alertError = null;
  }

  function closeAlertSuccess() {
    $scope.alertSuccess = null;
  }

  function goToEdit() {
    $rootScope.go('/profile/edit');
  }
});
