import _ from 'lodash';

export default (req, res, next) => {

  if (!req.decodedToken.isAdmin) {
    var err = new Error();
    err.code = 403;
    return next(err);
  }

  req.models.user.find({}, (err, users) => {
    if (err)
      return next(err);

    var purifiedUsers  = _.map(users, (user) => {
      return _.mapKeys(
        _.pick(user, ['username', 'id', 'email', 'first_name', 'last_name', 'created_at', 'is_admin']),
        (v, k) => { return _.camelCase(k); });
    });

    return res.json(purifiedUsers);

  });

};
