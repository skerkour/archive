import mailConfig from '../../../../../../config/email';
var mailgun = require('mailgun-js')({ apiKey: mailConfig.apiKey, domain: mailConfig.domain });

export default (req, res, next) => {

  var id = req.params.id;

  if (req.decodedToken.isAdmin !== true) {
    var err = new Error();
    err.code = 403;
    return next(err);
  }

  var subject = req.body.subject,
    body = req.body.body;

  if (!subject || !body) {
    var err = new Error();
    err.code = 400;
    err.informations = 'Body and subject are required.';
    return next(err);
  }

  req.models.user.get(id, (err, user) => {
    if (err)
      return next(err);

    var data = {
      from: 'z0mbie42 <admin@sandbox65242bfe09874f0ab05de8774d08d741.mailgun.org>',
      to: user.email,
      subject: subject,
      text: body
    };

    mailgun.messages().send(data, (error, body) => {
      if (err)
        return next(err);

      return res.json({
        code: 200,
        informations: `Email successfully sent to the user with id : ${user.id}.`
      });
    });

  });

};
