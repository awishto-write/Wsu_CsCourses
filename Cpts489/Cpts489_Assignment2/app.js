const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const sequelize = require('./db');
const Signer = require('./models/Signer');
const signerRoutes = require('./routes/signerRouter');

const app = express();
// Setup
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));
app.use(bodyParser.urlencoded({ extended: false }));
app.use(express.static(path.join(__dirname, 'public')));

// Routes
app.use("/", signerRoutes);

sequelize.sync().then(() => {
  console.log("Database synced.");
  app.listen(3000, () => console.log("Server running on http://localhost:3000"));
});

