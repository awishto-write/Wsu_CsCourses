// Perform the following JavaScript validations on form submission
// Email should have an '@'Name should be within 5 to 20 characters in length
// State should be a string of length 2 and uppercase
// When the user submits the form, the user should be informed of failed validations.
// Basic javascript 'alert' to notify the user of the result of form validation is sufficient
// Bonus +1 for using Bootstrap (or some other) dismissibleLinks to an external site. alert

function validatePetition() {
    // We use trim(): To avoid all the extra space that can be included in the input

  const name = document.getElementById("name").value.trim(); 
  const email = document.getElementById("email").value.trim();
  const state = document.getElementById("state").value.trim();

    if (name.length < 5 || name.length > 20) {
        alert("Fix it! Name must be between 5 and 20 characters.");
        return false;
    }

    if (!email.includes("@")) {
        alert("Fix it! Email must contain '@'.");
        return false;
    }

    if (state.length !== 2 || state !== state.toUpperCase()) {
        alert("Fix it! State must be exactly 2 uppercase letters (e.g., WA).");
        return false;
    }

  return true;
}