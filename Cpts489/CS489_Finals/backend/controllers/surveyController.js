const { validationResult } = require("express-validator");
const Survey = require("../models/Survey");

exports.getSurveys = async (req, res) => {
  try {
    const surveys = await Survey.getAll();
    res.json(surveys);
  } catch (err) {
    res.status(500).json({ error: "Failed to fetch surveys" });
  }
};

exports.addSurvey = async (req, res) => {
  try {
    const newSurvey = await Survey.add(req.body);
    res.status(201).json(newSurvey);
  } catch (err) {
    console.error("Validation error:", err);
    res.status(400).json({ error: "Invalid data" });
  }
};