import http from 'http';

import app from '../api/app';
import config from '../../config/server';

app.set('port', config.port);

var server = http.createServer(app)
  .listen(config.port, () => {
    console.log(`server listenning on port ${config.port}`);
  });
