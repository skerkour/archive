const path = require('path');

require('./dotenv').config();

module.exports = {
  development: {
    url: process.env.DATABASE_URL,
    dialect: 'postgres',
  },
  test: {
    url: process.env.DATABASE_URL,
    dialect: 'postgres',
  },
  staging: {
    url: process.env.DATABASE_URL,
    dialect: 'postgres',
    ssl: true,
    dialectOptions: {
      ssl: {
        require:true
      },
    },
  },
  production: {
    url: process.env.DATABASE_URL,
    dialect: 'postgres',
    ssl: true,
    dialectOptions: {
      ssl: {
        require:true
      },
    },
  },
};
