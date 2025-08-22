const sequelize = require('../db');
const { Model, DataTypes } = require('sequelize');

class Signer extends Model {
  static async getAll() {
    return await Signer.findAll({ order: [['id', 'DESC']] });
  }

  static async add(signerObj) {
    return await Signer.create(signerObj);
  }
}

Signer.init({
  name: {
    type: DataTypes.STRING,
    allowNull: false
  },
  email: {
    type: DataTypes.STRING,
    allowNull: false
  },
  city: {
    type: DataTypes.STRING,
    allowNull: false
  },
  state: {
    type: DataTypes.STRING,
    allowNull: false
  }
}, {
  sequelize,
  modelName: 'Signer'
});

module.exports = Signer;