function validatePetition() {
    const email = document.getElementById("email").value;
    console.log(email);
    const valid = email.includes("@");
    const name = document.getElementById("name").value;
    console.log(email);
    const valid_name = email.includes("@");
    if (!valid) {
      alert("Email is bad. Fix it!");
    }
    return valid;
  }
  