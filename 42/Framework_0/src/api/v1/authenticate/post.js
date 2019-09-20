import jwt from 'jsonwebtoken';

import config from '../../../../config/server';
import createJwt from '../createJwt';

function formatTokenResponse(user, token) {
  return {
    code: 200,
    token: token,
    username: user.username,
    id: user.id,
    isAdmin: user.is_admin
  };
}

function authPassword(req, res, next, username, password) {
  req.models.user.find({ username: username }, (err, ret) => {
    if (err)
      return next(new Error());

    if (ret.length === 0) {
      var err = new Error();
      err.code = 404;
      err.informations = `User wih username: '${username}' not found.`;
      return next(err);

    } else {
      var user = ret[0];

      if (user.verifyPassword(password)) {
        var token = createJwt(user);
        return user.save({ last_token: token }, (err) => {
          if (err)
            return next(err);
          return res.json(formatTokenResponse(user, token));
        });

      } else {
        var err = new Error();
        err.code = 401;
        err.informations = 'Invalid password.';
        return next(err);
      }
    }
  });
}

function authToken(req, res, next, username, superToken) {
  req.models.user.find({ username: username }, (err, ret) => {
    if (err)
      return next(new Error());

    if (ret.length === 0) {
      var err = new Error();
      err.code = 404;
      err.informations = `User wih username: '${username}' not found.`;
      return next(err);

    } else {
      var user = ret[0];

      if (user.verifyLastToken(superToken)) {
        var token = createJwt(user);
        return user.save({ last_token: token }, (err) => {
          if (err)
            return next(err);
          return res.json(formatTokenResponse(user, token));
        });
      } else {
        var err = new Error();
        err.code = 401;
        err.informations = 'Invalid token.';
        return next(err);
      }
    }
  });
}

export default (req, res, next) => {
  var username = req.body.username,
    password = req.body.password,
    token = req.body.token;

    if (username && password) {

      return authPassword(req, res, next, username, password);
    } else if (username && token) {

      return authToken(req, res, next, username, token);
    } else {
      var err = new Error();
      err.code = 400;
      err.informations = 'An username and a password or a token are required.';
      return next(err);
    }
};
