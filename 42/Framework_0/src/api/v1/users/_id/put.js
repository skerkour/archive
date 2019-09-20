import crypto from 'crypto';
import _ from 'lodash';

export default (req, res, next) => {

  var id = req.params.id;

  if (req.decodedToken.isAdmin != true
      && req.decodedToken.id != id)
    {
      var err = new Error();
      err.code = 403;
      return next(err);
    }

  req.models.user.get(id, (err, user) => {
    if (err)
      return next(err);

    req.body = _.mapKeys(req.body, (v, k) => { return _.snakeCase(k); });

    user.first_name = req.body.first_name || user.first_name;
    user.last_name = req.body.last_name || user.last_name;
    user.username = req.body.username || user.username;
    if (req.body.password) {
      var password = req.body.password + user.salt;
      user.password = crypto.createHash('sha512').update(password).digest('hex');
    }
    user.email = req.body.email || user.email;
    if (_.isBoolean(req.body.is_admin)) {
      if (req.decodedToken.isAdmin) {
        user.is_admin = req.body.is_admin;
      } else {
        var err = new Error();
        err.code = 403;
        return next(err);
      }
    }

    user.save((err) => {
      if (err)
        return next(err);

      return res.json({
        code: 200,
        informations: `User with id: ${user.id} successfully updated.`,
        firstName: user.first_name,
        lastName: user.last_name,
        username: user.username,
        email: user.email,
        isAdmin: user.is_admin
      });
    });
  });
};
