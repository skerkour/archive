'use strict';

module.exports = {
  up: async (queryInterface, Sequelize) => {
    await queryInterface.createTable('events', {
      id: {
        type: Sequelize.UUID,
        unique: true,
        allowNull: false,
        primaryKey: true,
      },
      timestamp: {
        type: Sequelize.DATE,
        allowNull: false,
      },
      aggregate_id: {
        type: Sequelize.UUID,
        allowNull: false,
      },
      aggregate_type: {
        type: Sequelize.TEXT,
        allowNull: false,
      },
      action: {
        type: Sequelize.TEXT,
        allowNull: false,
      },
      type: {
        type: Sequelize.TEXT,
        allowNull: false,
      },
      version: {
        type: Sequelize.BIGINT,
        allowNull: false,
      },
      data: {
        type: Sequelize.JSONB,
        allowNull: false,
      },
      metadata: {
        type: Sequelize.JSONB,
        allowNull: false,
      },
    });
    await queryInterface.addIndex('events', {
      fields: ['timestamp'],
    });
    await queryInterface.addIndex('events', {
      fields: ['type'],
    });
    await queryInterface.addIndex('events', {
      fields: ['data'],
      type: 'gin',
    });
    await queryInterface.addIndex('events', {
      fields: ['metadata'],
      type: 'gin',
    });

  },

  down: async (queryInterface, Sequelize) => {
    await queryInterface.dropTable('events');
  }
};
