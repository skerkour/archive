import jwt from 'jsonwebtoken';

import config from '../../../config/server';

export default (user, expiresIn = 172800) => {
  return jwt.sign({
    username: user.username,
    id: user.id,
    isAdmin: user.is_admin
  }, config.tokenSecret, {
    expiresIn: expiresIn
  });
};
