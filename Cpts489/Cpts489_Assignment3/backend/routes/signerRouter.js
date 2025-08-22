const express = require("express");
const router = express.Router();
const controller = require("../controllers/signerController");

router.get("/signature", controller.getSigner);
router.post("/signature", controller.addSigner);

module.exports = router;