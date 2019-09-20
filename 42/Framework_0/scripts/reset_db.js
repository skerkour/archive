var models = require('../target/api/v1/models').default;

models((err, db) => {
  if (err)
    throw err;

  db.drop((err) => {
    if (err)
      throw err;

    db.sync((err) => {
      if (err)
        throw err;

      db.models.user.create({
        username: 'lol',
        email: 'lol@lol.com',
        password: 'lol',
        is_admin: true
      }, (err, res) => {
        if (err)
          throw err;

        db.close();
        console.log("Done!");
      });
    });
  });
});
