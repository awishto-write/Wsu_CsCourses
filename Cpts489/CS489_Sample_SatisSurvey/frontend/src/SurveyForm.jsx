import React, { useState } from "react";

function SurveyForm({ add }) {
  const [formData, setFormData] = useState({
    firstName: "",
    lastName: "",
    gender: "",
    age: "",
    location: "",
    drinksOrdered: "",
    amountSpent: "",
    member: ""
  });

  const handleChange = (e) => {
    setFormData((prev) => ({ ...prev, [e.target.name]: e.target.value }));
  };

  const handleSubmit = async (e) => {
    e.preventDefault();

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
        return;
    }

    const newSurvey = await res.json();
    add(newSurvey);

    setFormData({
      firstName: "",
      lastName: "",
      gender: "",
      age: "",
      location: "",
      drinksOrdered: "",
      amountSpent: "",
      member: ""
    });
  };

  return (
    <form className="petition-form" onSubmit={handleSubmit}>
      <input name="firstName" placeholder="First Name" value={formData.firstName} onChange={handleChange} />
      <input name="lastName" placeholder="Last Name" value={formData.lastName} onChange={handleChange} />
      <input name="gender" placeholder="Gender" value={formData.gender} onChange={handleChange} />
      <input name="age" type="number" placeholder="Age" value={formData.age} onChange={handleChange} required />
      <input name="location" placeholder="Franchise Location" value={formData.location} onChange={handleChange} />
      <input name="drinksOrdered" placeholder="Drinks Ordered" value={formData.drinksOrdered} onChange={handleChange} />
      <input name="amountSpent" type="number" placeholder="Amount Spent" value={formData.amountSpent} onChange={handleChange} required />
      <select name="member" value={formData.member} onChange={handleChange}>
        <option value="">Are you a member?</option>
        <option value="Yes">Yes</option>
        <option value="No">No</option>
      </select>
      <button type="submit">Submit Survey</button>
    </form>
  );
}

export default SurveyForm;