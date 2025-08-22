const Signer = require("../models/Signer");

exports.getSigner = async (req, res) => {
  try {
    const signers = await Signer.getAll();
    res.json(signers);
  } catch (error) {
    console.error("Error fetching signers:", error);
    res.status(500).json({ error: "Internal Server Error" });
  }
};

exports.addSigner = async (req, res) => {
  try {
    const newSigner = await Signer.add(req.body);
    res.status(201).json(newSigner);
  } catch (error) {
    console.error("Error adding signer:", error);
    res.status(400).json({ error: "Invalid data" });
  }
};