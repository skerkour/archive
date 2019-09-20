import mailConfig from '../../../../../config/email';

var mailgun = require('mailgun-js')({ apiKey: mailConfig.apiKey, domain: mailConfig.domain });

export default (req, res, next) => {

  var subject = req.body.subject;
  var body = req.body.body;
  var from = req.body.from;

  if (!subject || !body || !from) {
    var err = new Error();
    err.code = 400;
    err.informations = 'Body, subject, and from are required.';
    return next(err);
  }

  var data = {
    from: 'z0mbie42 <postmaster@mg.z0mbie42.com>',
    to: 'sylvain.kerkour@gmail.com',
    subject: `[FROM: ${from}] - ${subject}`,
    text: body
  };

  mailgun.messages().send(data, (err, body) => {
    if (err)
      return next(err);

    return res.json({
      code: 200,
      informations: 'Email successfully sent to the administrator.'
    });
  });

}
