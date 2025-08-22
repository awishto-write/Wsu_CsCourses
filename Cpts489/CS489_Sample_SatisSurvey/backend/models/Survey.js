const sequelize = require('../db');
const { Model, DataTypes } = require('sequelize');

class Survey extends Model {
  static async getAll() {
    return await Survey.findAll({ order: [['id', 'DESC']] });
  }

  static async add(data) {
    return await Survey.create(data);
  }
}

Survey.init({
  firstName: DataTypes.STRING,
  lastName: {
    type: DataTypes.STRING,
    allowNull: false
  },
  gender: DataTypes.STRING,
  age: {
    type: DataTypes.INTEGER,
    validate: { min: 18 }
  },
  location: DataTypes.STRING,
  drinksOrdered: DataTypes.STRING,
  amountSpent: {
    type: DataTypes.FLOAT,
    validate: { max: 150 }
  },
  member: DataTypes.STRING
}, {
  sequelize,
  modelName: 'Survey'
});

module.exports = Survey;