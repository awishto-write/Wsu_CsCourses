const express = require("express");
const router = express.Router();
const controller = require("../controllers/signerController");

router.get("/", controller.showHomePage);    
router.post("/sign", controller.addSigner);

module.exports = router;