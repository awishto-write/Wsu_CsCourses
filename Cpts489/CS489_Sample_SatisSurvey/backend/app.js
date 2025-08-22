const express = require("express");
const cors = require("cors");
const bodyParser = require("body-parser");
const sequelize = require("./db");
const surveyRouter = require("./routes/surveyRouter");
const app = express();

app.use(cors());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use("/api", surveyRouter);

sequelize.sync().then(() => {
  console.log("Database synced.");
  app.listen(4000, () => {
    console.log(`Backend running at http://localhost:4000`);
  });
});