import React, { useState } from "react";

function SurveyForm({ add }) {
  const [formData, setFormData] = useState({
    firstName: "",
    lastName: "",
    gender: "",
    age: "",
    programmingLanguage: "",
    ide: "",
    framework: "", 
    versionControl: "",
  });

  const handleChange = (e) => {
    setFormData((prev) => ({ ...prev, [e.target.name]: e.target.value }));
  };

  const handleSubmit = async (e) => {
    e.preventDefault();

    // For checks in the front end
    const { firstName, lastName, age } = formData;
    const num = parseInt(age, 10);

    // if (firstName.trim().length < 5 || firstName.trim().length > 15) {
    //   alert("Fix it! First Name must be between 5 and 15 characters.");
    //   console.log("Fix it! First Name must be between 5 and 15 characters.");
    //   return;
    // }
    // if (lastName.trim().length < 5 || lastName.trim().length > 15) {
    //   alert("Fix it! Last Name must be between 5 and 15 characters.");
    //   console.log("Fix it! Last Name must be between 5 and 15 characters.");
    //   return;
    // }
    // if (num < 18) {
    //   alert("Must be 18 or older");
    //   console.log("Must be 18 or older");
    //   //alert("Must be 18 or older");
    //   return;
    // }

    const res = await fetch("http://localhost:4000/api/survey", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(formData)
    });

       // Check of the errors from the backend 
    if (!res.ok) {
      const errorData = await res.json();
      const errorMessages = errorData.errors?.map(e => e.msg).join("\n") || "Submission failed.";
      alert("Backend Error:\n" + errorMessages);

         // Front end check errors - only
      if (firstName.trim().length < 5 || firstName.trim().length > 15) {
        alert("Fix it! First Name must be between 5 and 15 characters.");
        console.log("Fix it! First Name must be between 5 and 15 characters.");
        //return;
      }
      if (lastName.trim().length < 5 || lastName.trim().length > 15) {
        alert("Fix it! Last Name must be between 5 and 15 characters.");
        console.log("Fix it! Last Name must be between 5 and 15 characters.");
       //return;
      }
      if (num < 18) {
        alert("Must be 18 or older");
        console.log("Must be 18 or older");
        //return;
      }
      return;
    }

    const newSurvey = await res.json();
    add(newSurvey);

    setFormData({
      firstName: "",
      lastName: "",
      gender: "",
      age: "",
      programmingLanguage: "",
      ide: "",
      framework: "", 
      versionControl: "",
    });
  };

  return (
    <form className="petition-form" onSubmit={handleSubmit}>
      <input name="firstName" placeholder="First Name" value={formData.firstName} onChange={handleChange} required />
      <input name="lastName" placeholder="Last Name" value={formData.lastName} onChange={handleChange} required/>
      <input name="gender" placeholder="Gender" value={formData.gender} onChange={handleChange} />
      <input name="age" type="number" placeholder="Age" value={formData.age} onChange={handleChange} required />

      <select name="programmingLanguage" value={formData.programmingLanguage} onChange={handleChange}>
        <option value="">Select the language you prefer the most:</option>
        <option value="Python">Python</option>
        <option value="JavaScript">JavaScript</option>
        <option value="Java">Java</option>
        <option value="C++">C++</option>
        <option value="others">others</option>
      </select>
      <select name="ide" value={formData.ide} onChange={handleChange}>
        <option value="">Select the IDE (Integrated Development Environment) you prefer the most:</option>
        <option value="Visual Studio Code">Visual Studio Code</option>
        <option value="IntelliJ IDEA">IntelliJ IDEA</option>
        <option value="Sublime Text">Sublime Text</option>
        <option value="others">others</option>
      </select>
      <select name="framework" value={formData.framework} onChange={handleChange}>
        <option value="">Select a framework or a library you use most frequently</option>
        <option value="React">React</option>
        <option value="Angular">Angular</option>
        <option value="Django">Django</option>
        <option value="Express">Express</option>
        <option value="others">others</option>
      </select>
      <select name="versionControl" value={formData.versionControl} onChange={handleChange}>
        <option value="">Select the version control system you use right now:</option>
        <option value="Git">Git</option>
        <option value="SVN (Subversion)">SVN (Subversion)</option>
        <option value="Mercurial">Mercurial</option>
        <option value="Another">Another</option>
      </select>

      <button type="submit">Submit Survey</button>
    </form>
  );
}

export default SurveyForm;