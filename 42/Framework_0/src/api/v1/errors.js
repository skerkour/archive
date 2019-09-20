export default function errorHandler(err, req, res, next) {

  console.error(err.stack);

  switch (err.code) {
    case 400:
      err.message = 'Bad request';
      break;
    case 401:
      err.message = 'Unauthorized';
      break;
    case 403:
      err.message = 'Forbidden';
      break;
    case 404:
      err.message = 'Not Found';
      break;
    case 409:
        err.message = 'Conflict';
        break;
    case 410:
      err.message = 'Gone';
      break;
    default:
      err.code = 500;
      err.message = 'Internal Server Error';
      break;
  }

  res.status(err.code)
    .json({
      code: err.code,
      message: err.message,
      informations: err.informations
    });
}
