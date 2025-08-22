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

// Get one survey by ID (for details page)
exports.getSurveyById = async (req, res) => {
  const id = req.params.id;
  try {
    const survey = await Survey.findByPk(id);
    if (!survey) {
      return res.status(404).json({ error: "Survey not found" });
    }
    res.json(survey);
  } catch (err) {
    console.error("Error fetching survey:", err);
    res.status(500).json({ error: "Internal Server Error" });
  }
};

exports.deleteSurvey = async (req, res) => {
  try {
    const id = req.params.id;
    const deleted = await Survey.destroy({ where: { id } });
    if (!deleted) return res.status(404).json({ error: "Survey not found" });
    res.json({ message: "Survey deleted" });
  } catch (err) {
    res.status(500).json({ error: "Delete failed" });
  }
};

exports.updateSurvey = async (req, res) => {
  const id = req.params.id;
  const errors = validationResult(req);
  if (!errors.isEmpty()) return res.status(400).json({ errors: errors.array() });

  try {
    const [updated] = await Survey.update(req.body, { where: { id } });
    if (!updated) return res.status(404).json({ error: "Survey not found" });
    const updatedSurvey = await Survey.findByPk(id);
    res.json(updatedSurvey);
  } catch (err) {
    res.status(500).json({ error: "Update failed" });
  }
};
