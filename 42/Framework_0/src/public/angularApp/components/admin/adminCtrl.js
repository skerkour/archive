app.controller('adminCtrl', ($scope, $auth, $location, Restangular) => {
  if (!$auth.isAdmin) {
    window.location.href = '/';
  }

  $scope.users = [];
  getAllusers();
  $scope.onSearchSelect = onSearchSelect;

  function getAllusers() {
    var baseUsers = Restangular.all('users');

    baseUsers.getList({}, { 'x-access-token': $auth.token }).then((users) => {
      $scope.users = users;

    }).catch((err) => {
      $scope.adminError = {
        information: err.information
      }; 
    });
  };

  function closeAdminError() {
    $scope.adminError = null;
  }

  function onSearchSelect(item, model, label) {
    $location.path(`/admin/users/${item.id}`);
  }

});
