import React, { useState } from "react";

function PetitionForm({ add }) {
  const [formData, setFormData] = useState({
    name: "",
    email: "",
    city: "",
    state: ""
  });

  const handleChange = (e) => {
    setFormData((prev) => ({ ...prev, [e.target.name]: e.target.value }));
  };

  const handleSubmit = async (e) => {
    e.preventDefault();

    const { name, email, state } = formData;

    // Assuring that name, email and state have valid values
    if (name.trim().length < 5 || name.trim().length > 20) {
      alert("Fix it! Name must be between 5 and 20 characters.");
      return;
    }
    if (!email.includes("@")) {
      alert("Fix it! Email must contain '@'.");
      return;
    }
    if (state.length !== 2 || state !== state.toUpperCase()) {
      alert("Fix it! State must be exactly 2 uppercase letters (e.g., WA).");
      return;
    }

    const res = await fetch("http://localhost:4000/api/signature", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(formData)
    });
    const newSignature = await res.json();
    add(newSignature);
    setFormData({ name: "", email: "", city: "", state: "" });
  };

  return (
    <form className="petition-form" onSubmit={handleSubmit}>
      <input
        name="name"
        placeholder="Your Name"
        required
        value={formData.name}
        onChange={handleChange}
      />
      <input
        name="email"
        type="email"
        placeholder="Your Email"
        required
        value={formData.email}
        onChange={handleChange}
      />
      <input
        name="city"
        placeholder="City"
        required
        value={formData.city}
        onChange={handleChange}
      />
      <input
        name="state"
        placeholder="State (e.g., WA)"
        required
        value={formData.state}
        onChange={handleChange}
      />
      <button type="submit">Sign Petition</button>
    </form>
  );
}

export default PetitionForm;