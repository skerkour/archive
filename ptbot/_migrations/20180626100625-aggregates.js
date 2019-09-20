'use strict';

module.exports = {
  up: async (queryInterface, Sequelize) => {

    await queryInterface.createTable('chats', {
      // base
      id: {
        type: Sequelize.UUID,
        unique: true,
        primaryKey: true,
      },
      created_at: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      updated_at: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      deleted_at: {
        type: Sequelize.DATE,
        allowNull: true,
      },
      version: {
        type: Sequelize.BIGINT,
        allowNull: false,
      },

      // attributes
      telegram_id: {
        type: Sequelize.BIGINT,
        allowNull: false,
        unique: true,
      },
      title: {
        type: Sequelize.TEXT,
        allowNull: false,
      },
      username: {
        type: Sequelize.TEXT,
        allowNull: false,
      },
      type: {
        type: Sequelize.TEXT,
        allowNull: false,
      },
    });
    await queryInterface.addIndex('chats', {
      fields: ['telegram_id'],
    });
    /*await queryInterface.addIndex('accounts', {
      fields: ['emails'],
      type: 'gin',
    });
    */

    await queryInterface.createTable('messages', {
      // base
      id: {
        type: Sequelize.UUID,
        unique: true,
        primaryKey: true,
      },
      created_at: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      updated_at: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      deleted_at: {
        type: Sequelize.DATE,
        allowNull: true,
      },
      version: {
        type: Sequelize.BIGINT,
        allowNull: false,
      },

      // attributes
      sender_id: {
        type: Sequelize.BIGINT,
        allowNull: false,
      },
      text: {
        type: Sequelize.TEXT,
        allowNull: false,
      },
      chat_id: {
        type: Sequelize.UUID,
        allowNull: false,
        references: {
          model: 'chats',
          key: 'id',
        },
      },
    });

    


    await queryInterface.createTable('products', {
      // base
      id: {
        type: Sequelize.UUID,
        unique: true,
        primaryKey: true,
      },
      created_at: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      updated_at: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      deleted_at: {
        type: Sequelize.DATE,
        allowNull: true,
      },
      version: {
        type: Sequelize.BIGINT,
        allowNull: false,
      },

      // attributes
      asin: {
        type: Sequelize.TEXT,
        allowNull: false,
      },
      url: {
        type: Sequelize.TEXT,
        allowNull: false,
      },
      marketplace: {
        type: Sequelize.TEXT,
        allowNull: false,
      },
    });







    await queryInterface.createTable('products_data', {
      // base
      id: {
        type: Sequelize.UUID,
        unique: true,
        primaryKey: true,
      },
      created_at: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      updated_at: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      deleted_at: {
        type: Sequelize.DATE,
        allowNull: true,
      },
      version: {
        type: Sequelize.BIGINT,
        allowNull: false,
      },

      // attributes
      title: {
        type: Sequelize.TEXT,
        allowNull: false,
      },
      price: {
        type: Sequelize.DOUBLE,
        allowNull: false,
      },
      currency: {
        type: Sequelize.TEXT,
        allowNull: false,
      },

      // relations
      product_id: {
        type: Sequelize.UUID,
        allowNull: false,
        references: {
          model: 'products',
          key: 'id',
        },
      },
    });



    await queryInterface.createTable('subscriptions', {
      // base
      id: {
        type: Sequelize.UUID,
        unique: true,
        primaryKey: true,
      },
      created_at: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      updated_at: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      deleted_at: {
        type: Sequelize.DATE,
        allowNull: true,
      },
      version: {
        type: Sequelize.BIGINT,
        allowNull: false,
      },

      // attributes
      webhook: {
        type: Sequelize.TEXT,
        allowNull: true,
      },
      notification: {
        type: Sequelize.BOOLEAN,
        allowNull: false,
      },

      // relations
      product_id: {
        type: Sequelize.UUID,
        allowNull: false,
        references: {
          model: 'products',
          key: 'id',
        },
      },
      chat_id: {
        type: Sequelize.UUID,
        allowNull: false,
        references: {
          model: 'chats',
          key: 'id',
        },
      },
    });

  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.dropTable('chats', { force: true });
    await queryInterface.dropTable('messages', { force: true });
    await queryInterface.dropTable('products', { force: true });
    await queryInterface.dropTable('products_data', { force: true });
    await queryInterface.dropTable('subscriptions', { force: true });
  }
};
