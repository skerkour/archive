import createJwt from '../createJwt';

export default (req, res, next) => {
  var username = req.body.username,
    password = req.body.password,
    email = req.body.email;

  if (!username || !password || !email) {
    var err = new Error();
    err.code = 400;
    err.informations = 'Username, password and email are required.';
    return next(err);
  }

  req.models.user.exists({ username: username }, (err, exists) => {
    if (exists) {
      var err = new Error();
      err.code = 409;
      err.informations = `User with the username: \'${username}\' already exists.`;
      return next(err);
    } else {
      req.models.user.exists({ email: email }, (err, exists) => {
        if (exists) {
          var err = new Error();
          err.code = 409;
          err.informations = `User with the email: \'${email}\' already exists.`;
          return next(err);
        } else {

          req.models.user.create({
            username: username,
            email: email,
            password: password,
            is_admin: false
          }, (err, user) => {
            if (err) {
              if (err[0].msg == 'Invalid email.') {
                var err = new Error();
                err.code = 400;
                err.informations = 'Invalid email.';
                return next(err);
              } else {
                return next(err);
              }
            }
            var token = createJwt(user);
            user.last_token = token;
            return user.save((err) => {

              if (err)
                return next(err);

              return res.status(201)
              .json({
                code: 201,
                message: 'User Successfully created',
                token: token,
                username: username,
                isAdmin: false,
                id: user.id
              });
            });
          });

        }
      });
    }
  });
}
