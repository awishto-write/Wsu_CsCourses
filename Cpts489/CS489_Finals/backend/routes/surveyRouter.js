const express = require("express");
const { body, validationResult } = require("express-validator");
const controller = require("../controllers/surveyController");

const router = express.Router();

router.get("/survey", controller.getSurveys);

router.post("/survey", [
  //body("firstName").trim().notEmpty().withMessage("First name is required"),
  body("firstName").trim().notEmpty().withMessage("First name is required").isLength({ min: 5, max: 15 }).withMessage('First name must be between 5 and 15 characters'),
  //body("lastName").trim().notEmpty().withMessage("Last name is required"),
  body("lastName").trim().notEmpty().withMessage("Last name is required").isLength({ min: 5, max: 15 }).withMessage('Last name must be between 5 and 15 characters'),
  body("age").notEmpty().withMessage("Age is required").isInt({ min: 18 }).withMessage("Must be 18 or older")],
  
  async (req, res) => {
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
      return res.status(400).json({ errors: errors.array() });
   }
  return controller.addSurvey(req, res);
});


module.exports = router;