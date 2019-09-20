app.controller('profileEditCtrl', ($scope, $rootScope, $auth, $location, Restangular, $routeParams) => {

  $scope.user = {};
  getUser();
  $scope.goToShow = goToShow;
  $scope.submitEdition = submitEdition;
  $scope.closeAdminError = closeAdminError;

  function getUser() {
    Restangular.one('users', $auth.id).get({}, { 'x-access-token': $auth.token }).then((user) => {
      $scope.user = user;

    }).catch((err) => {
      $scope.alertError = {
        informations: err.data.informations
      };
    });
  };

  function submitEdition() {
    var user = $scope.user;

	if (user.password != user.password2) {
		alert("Error: your passwords must match");
		return ;
	}

    delete user.isAdmin;

    user.put({}, { 'x-access-token': $auth.token }).then((user) => {
      $scope.user = user;
      goToShow();

    }).catch((err) => {
      $scope.alertError = {
        informations: err.informations
      };
    });
  }

  function closeAdminError() {
    $scope.alertError = null;
  }

  function goToShow() {
    $rootScope.go('/profile');
  }

});
