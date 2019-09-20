app.controller('adminUsersEditByIdCtrl', ($scope, $rootScope, $auth, $location, Restangular, $routeParams) => {
  if (!$auth.isAdmin) {
    window.location.href = '/';
  }

  $scope.user = {};
  getUser();
  $scope.goToShow = goToShow;
  $scope.submitEdition = submitEdition;
  $scope.closeAdminError = closeAdminError;
  var showUrl = '';

  function getUser() {
    Restangular.one('users', $routeParams.id).get({}, { 'x-access-token': $auth.token }).then((user) => {
      $scope.user = user;
      showUrl = '/admin/users/'+user.id;

    }).catch((err) => {
      $scope.adminError = {
        informations: err.data.informations
      };
    });
  };

  function submitEdition() {
    var user = $scope.user;

    user.isAdmin = user.isAdmin == 'true' ? true : false;

    user.put({}, { 'x-access-token': $auth.token }).then((user) => {
      $scope.user = user;
      goToShow();

    }).catch((err) => {
      $scope.adminError = {
        informations: err.informations
      };
    });
  }

  function closeAdminError() {
    $scope.adminError = null;
  }

  function goToShow() {
    $rootScope.go(showUrl);
  }

});
