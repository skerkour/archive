app.controller('homeCtrl', ($scope, $auth) => {
  if (!$auth.isAuthentified) {
    window.location.href = '/';
  }


});
