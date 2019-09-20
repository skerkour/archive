app.factory('$auth', (ipCookie) => {
  var isAuthentified = false;
  var username = '';
  var token = '';
  var isAdmin = false;

  return {
    isAuthentified: isAuthentified,
    username: username,
    token: token,
    isAdmin: isAdmin,
    id: 0
  };
});
