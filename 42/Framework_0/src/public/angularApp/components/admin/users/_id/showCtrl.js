app.controller('adminUsersShowByIdCtrl', ($uibModal, $scope, $rootScope, $auth, $location, Restangular, $routeParams) => {
  if (!$auth.isAdmin) {
    window.location.href = '/';
  }

  var editUrl = $location.path();

  $scope.user = {};
  $scope.goToEdit = goToEdit;
  $scope.closeAdminError = closeAdminError;
  $scope.deleteUser = deleteUser;
  $scope.openEmailModal = openEmailModal;
  $scope.closeAdminSuccess = closeAdminSuccess;
  getUser();

  function getUser() {
    Restangular.one('users', $routeParams.id).get({}, { 'x-access-token': $auth.token }).then((user) => {
      $scope.user = user;

      editUrl = '/admin/users/' + user.id + '/edit';

    }).catch((err) => {
      $scope.adminError = {
        informations: err.data.informations
      };
    });
  };

  function closeAdminError() {
    $scope.adminError = null;
  }

  function closeAdminSuccess() {
    $scope.adminSuccess = null;
  }

  function goToEdit() {
    $rootScope.go(editUrl);
  }

  function deleteUser() {

    Restangular.one('users', $routeParams.id).remove({}, { 'x-access-token': $auth.token }).then((res) => {
      $rootScope.go('/admin/users');
    }).catch((err) => {
      $scope.adminError = {
        informations: err.data.informations
      };
    });
  }

  function openEmailModal() {

    var emailModal = $uibModal.open({
       animation: true,
       templateUrl: 'emailModal.html',
       controller: 'adminUsersShowByIdEmailCtrl',
       size: ''
    });

    emailModal.result.then((res) => {
      $scope.adminSuccess = {
        informations: 'Email successfully sent.'
      };
    }, () => {
      $scope.adminError = {
        information: 'Error sending the email.'
      };

    });

  }

});

app.controller('adminUsersShowByIdEmailCtrl', ($uibModalInstance, $scope, $rootScope, $auth, $location, Restangular, $routeParams) => {
  $scope.sendEmail = sendEmail;
  
  function sendEmail() {
    Restangular.one('users', $routeParams.id).post("email", { subject: $scope.emailSubject, body: $scope.emailBody }, {}, { 'x-access-token': $auth.token }).then((res) => {
      $uibModalInstance.close();
    }).catch((err) => {
      $uibModalInstance.dismiss();
    });
  }
});
