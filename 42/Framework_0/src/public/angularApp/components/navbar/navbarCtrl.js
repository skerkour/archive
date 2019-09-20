app.controller('navbarCtrl', ($scope, $auth, $location, ipCookie, $uibModal) => {
  // variables declaration
  $scope.navbarCollapsed = true;
  
  $scope.$on('$locationChangeStart', (event, next) => {
    $scope.isAuthentified = $auth.isAuthentified;
    $scope.username = $auth.username;
    $scope.isAdmin = $auth.isAdmin;
  });
  
  $scope.logout = logout;
  $scope.openContactModal = openContactModal;

  function logout() {
    $auth.isAuthentified = false;
    $auth.username = '';
    $auth.token = '';
    $auth.id = 0;
    ipCookie.remove('username');
    ipCookie.remove('token');
    ipCookie.remove('isAdmin');
    ipCookie.remove('id');
    window.location.href = '/';
  }

  function openContactModal() {
    var emailModal = $uibModal.open({
       animation: true,
       templateUrl: 'emailContactModal.html',
       controller: 'contactEmailCtrl',
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

app.controller('contactEmailCtrl', ($uibModalInstance, $scope, $rootScope, $auth, $location, Restangular, $routeParams) => {

  $scope.sendEmail = sendEmail;
  $scope.isAuthentified = $auth.isAuthentified;
  $scope.emailFrom = {};
  $scope.emailFrom.value = '';
  
  function sendEmail() {
    
    var from = $scope.emailFrom.value;
    console.log(from);
    if (!from) {
      from = $auth.username;
    }
    Restangular.one('emails').post('contact', { from: from, subject: $scope.emailSubject, body: $scope.emailBody }).then((res) => {
      $uibModalInstance.close();
    }).catch((err) => {
      $uibModalInstance.dismiss();
    });
  }
});
