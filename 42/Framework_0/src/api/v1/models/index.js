import orm from 'orm';

import user from './user';
import config from '../../../../config/database';

var connection = null;

function setup(db, cb) {
  user(orm, db);

  return cb(null, db);
}

export default (cb) => {
  if (connection)
    return cb(null, connection);

  orm.connect(config, (err, db) => {
    if (err)
      return cb(err);

    connection = db;
    db.settings.set('instance.returnAllErrors', true);
    setup(db, cb);
  });
};
