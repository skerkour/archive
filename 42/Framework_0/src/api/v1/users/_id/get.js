import _ from 'lodash';

export default (req, res, next) => {
  var id = req.params.id;

  if (req.decodedToken.isAdmin != true
      && req.decodedToken.id !=  id)
    {
      var err = new Error();
      err.code = 403;
      return next(err);
    }

  req.models.user.get(id, (err, user) => {
    if (err && err.message === 'Not found') {
      var err = new Error();
      err.code = 404;
      err.informations = `User with id: ${id} doesn't exists.`;
      return next(err);
    } else if (err) {
      return next(err);
    }

    var purifiedUser = _.mapKeys(
      _.pick(user, ['username', 'id', 'email', 'first_name', 'last_name', 'created_at', 'is_admin']),
      (v, k) => { return _.camelCase(k); }
    );
    return res.json(purifiedUser);

  });

};
