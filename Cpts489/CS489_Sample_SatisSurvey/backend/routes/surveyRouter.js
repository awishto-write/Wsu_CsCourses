const express = require("express");
const { body, validationResult } = require("express-validator");
const controller = require("../controllers/surveyController");

const router = express.Router();

router.get("/survey", controller.getSurveys);

router.post("/survey", [
  body("lastName").trim().notEmpty().withMessage("Last name is required"),
  body("age").notEmpty().withMessage("Age is required").isInt({ min: 18 }).withMessage("Must be 18 or older"),
  body("amountSpent").notEmpty().withMessage("Amount is required").isFloat({ max: 150 }).withMessage("Must not exceed $150")], 
  async (req, res) => {
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
      return res.status(400).json({ errors: errors.array() });
   }
  return controller.addSurvey(req, res);
});

// Get a single survey by ID
router.get("/survey/:id", controller.getSurveyById);

router.delete("/survey/:id", controller.deleteSurvey);

router.put("/survey/:id", [
  body("lastName").trim().notEmpty().withMessage("Last name is required"),
  body("age").notEmpty().withMessage("Age is required").isInt({ min: 18 }).withMessage("Must be 18 or older"),
  body("amountSpent").notEmpty().withMessage("Amount is required").isFloat({ max: 150 }).withMessage("Must not exceed $150")
], controller.updateSurvey);

//router.put("/survey/:id", [validation middleware], controller.updateSurvey);

module.exports = router;