import jwt from 'jsonwebtoken';
import config from '../../../config/server';

export default (req, res, next) => {
  var token = req.body.token || req.query.token || req.headers['x-access-token'];

  if (token) {
    jwt.verify(token, config.tokenSecret, (err, decoded) => {
      if (err) {
        var err = new Error();
        err.code = 403;
        err.informations = 'Failed to authenticate token.';
        err.devInfos = err;
        return next(err);
      } else {
        req.decodedToken = decoded;
        return next();
      }
    });

  } else {
    var err = new Error();
    err.code = 403;
    err.informations = 'No token provided. You can use the \'token\' parameter, or the \'x-access-token\' header.';
    return next(err);
  }
};
