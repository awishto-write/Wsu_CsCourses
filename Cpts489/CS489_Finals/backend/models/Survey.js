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
  firstName: {
    type: DataTypes.STRING,
    allowNull: false,
    validate: { min: 5, max: 15 }
  },
  lastName: {
    type: DataTypes.STRING,
    allowNull: false,
    validate: { min: 5, max: 15 }
  },
  gender: DataTypes.STRING,
  age: {
    type: DataTypes.INTEGER,
    validate: { min: 18 }
  },

  programmingLanguage: DataTypes.STRING,
  ide: DataTypes.STRING,
  framework: DataTypes.STRING, 
  versionControl: DataTypes.STRING,
}, {
  sequelize,
  modelName: 'Survey'
});

module.exports = Survey;