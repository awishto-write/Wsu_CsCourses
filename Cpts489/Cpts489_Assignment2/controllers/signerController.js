const Signer = require("../models/Signer");

exports.showHomePage = async (req, res) => {
  const signers = await Signer.getAll();
  res.render("index", { signers });
  
  console.log("Signers loaded from database:", signers);
};

exports.addSigner = async (req, res) => {
  try {
    await Signer.add(req.body);
    res.redirect("/");
  } catch (error) {
    console.log("Error adding signer:", error);
    res.status(500).send("Error saving signer");
  }
};