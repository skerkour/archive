import express from 'express';

import authenticatePost from './authenticate/post';
import usersPost from './users/post';
import usersGet from './users/get';
import userIdPut from './users/_id/put';
import userIdGet from './users/_id/get';
import userIdEmailPost from './users/_id/email/post';
import userIdDelete from './users/_id/delete';
import verifyToken from './verifyToken';
import emailsContactPost from './emails/contact/post';

var routes = express.Router();

routes.route('/')
  .all((req, res) => {
    return res.json({
      message: 'Hello :)'
    });
  });

routes.route('/authenticate')
  .post(authenticatePost);

routes.route('/users')
  .post(usersPost);

routes.route('/emails/contact')
  .post(emailsContactPost);



routes.use(verifyToken);

routes.route('/users')
  .get(usersGet);

routes.route('/users/:id')
  .put(userIdPut)
  .get(userIdGet)
  .delete(userIdDelete);

routes.route('/users/:id/email')
  .post(userIdEmailPost);

export default routes;
