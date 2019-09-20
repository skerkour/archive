import crypto from 'crypto';
import uuid from 'node-uuid';

export default (orm, db) => {
  var User = db.define('user', {
    first_name: String,
    last_name: String,
    username: String,
    password: String,
    salt: String,
    created_at: Date,
    last_token: String,
    email: String,
    is_admin: Boolean
  },
  {
    hooks: {
      beforeCreate: function() {
        this.created_at = new Date();
        this.salt = uuid.v4();
        this.password = crypto
          .createHash('sha512')
          .update(this.password+this.salt)
          .digest('hex');
      }
    },
    methods: {
      fullName: function() {
        return this.first_name + ' ' + this.last_name;
      },
      verifyPassword: function(password) {
        password += this.salt;
        var hash = crypto.createHash('sha512').update(password).digest('hex');

        return this.password === hash;
      },
      verifyLastToken: function(token) {
        return token === this.last_token;
      }
    },
    validations: {
      email: orm.validators.patterns.email('Invalid email.')
    }
  });
};
