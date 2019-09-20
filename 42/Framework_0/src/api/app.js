import express from 'express';
import compression from 'compression';
import bodyParser from 'body-parser';
import multer from 'multer';
import errorHandler from 'errorhandler';
import morgan from 'morgan';
import path from 'path';
import orm from 'orm';

import errors from './v1/errors';
import routesV1 from './v1/routes';
import models from './v1/models';

var app = express();

var env = process.env.NODE_ENV || 'development';
if (env === 'production') {

  app.set('json spaces', 0);

} else {

  app.set('json spaces', 2);

  app.use(errorHandler({
    dumpExceptions: true,
    showStack: true
  }));

}

var upload = multer(); // for parsing multipart/form-data
app.use(bodyParser.json()); // for parsing application/json
// for parsing application/x-www-form-urlencoded
app.use(bodyParser.urlencoded({ extended: true }));
app.disable('x-powered-by');
app.disable('etag');
app.use(compression({ threshold: 512 }));
app.use(morgan('combined'));

app.use((req, res, next) => { // CORS checker
  res.set('Access-Control-Allow-Origin', '*');
  res.set("Access-Control-Allow-Headers", "Cache-Control, Pragma, Origin, Authorization, Content-Type, X-Requested-With, x-access-token");
  res.set("Access-Control-Allow-Methods", "DELETE, GET, PUT, POST");
  if (req.method == 'OPTIONS') {
    if (req.headers['access-control-request-method']
      && (req.headers['access-control-request-method'] === 'GET'
      || req.headers['access-control-request-method'] === 'DELETE'
      || req.headers['access-control-request-method'] === 'POST'
      || req.headers['access-control-request-method'] === 'PUT')) {

      res.set('Access-Control-Allow-Origin', '*');
      res.set('Access-Control-Allow-Headers', 'x-access-token, content-type');
      return res.send();

    }
  }
  return next();
});

app.use('/', express.static(__dirname + '/../public'));

app.use((req, res, next) => {
  models((err, db) => {
    if (err) {
      console.error(err);
      return next(err);
    }
    req.models = db.models;
    req.db     = db;

    return next();
  });
});

app.use('/api/v1', routesV1);


app.get('/', (req, res) => {
  res.sendFile(path.resolve(__dirname + '/../public/angularApp/layout.html'));
});


app.all('*', (req, res, next) => {
  var err = new Error('Not Found');
  err.code = 404;
  err.information = 'Rotue not defined.';
  return next(err);
});

app.use(errors);

export default app;
