export default (req, res, next) => {

  if (req.decodedToken.isAdmin !== true) {
      var err = new Error();
      err.code = 403;
      return next(err);
    }

  req.models.user.get(req.params.id, (err, user) => {
    if (err)
      return next(err);

    req.models.user.find({ is_admin: true }).count((err, nAdmin) => {
      if (err)
        return next(err);

      if (nAdmin == 1) {
        var err = new Error();
        err.code = 409;
        err.informations = `You can't delete the last admin user with id: ${req.params.id}.`;
        return next(err);
      }

      user.remove((err) => {
        if (err)
          return next(err);

        return res.json({
          code: 200,
          informations: `User with id: ${user.id} successfully deleted.`,
          id: user.id
        });
      });
    });


  });

};
