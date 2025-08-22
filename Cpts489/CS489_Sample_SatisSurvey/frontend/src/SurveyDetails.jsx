import React, { useEffect, useState } from "react";
import { useParams, Link } from "react-router-dom";
import "./style.css";

function SurveyDetails() {
  const { id } = useParams();
  const [survey, setSurvey] = useState(null);
  const [error, setError] = useState(null);

  useEffect(() => {
    const fetchSurvey = async () => {
      try {
        const res = await fetch(`http://localhost:4000/api/survey/${id}`);
        if (!res.ok) throw new Error("Survey not found.");
        const data = await res.json();
        setSurvey(data);
      } catch (err) {
        setError(err.message);
      }
    };

    fetchSurvey();
  }, [id]);

  if (error) {
    return <p style={{ color: "red", textAlign: "center" }}>{error}</p>;
  }

  if (!survey) {
    return <p style={{ textAlign: "center" }}>Loading survey details...</p>;
  }

  return (
    <div>
      <h2 className="title">Survey Details (ID: {id})</h2>
      <div style={{ marginTop: "20px", lineHeight: "1.8" }}>
        <p><strong>First Name:</strong> {survey.firstName}</p>
        <p><strong>Last Name:</strong> {survey.lastName}</p>
        <p><strong>Gender:</strong> {survey.gender}</p>
        <p><strong>Age:</strong> {survey.age}</p>
        <p><strong>Franchise Location:</strong> {survey.location}</p>
        <p><strong>Drinks Ordered:</strong> {survey.drinksOrdered}</p>
        <p><strong>Amount Spent:</strong> ${survey.amountSpent}</p>
        <p><strong>Member:</strong> {survey.member}</p>
      </div>
      <div style={{ marginTop: "20px" }}>
        <Link to="/" style={{ color: "#1a5cff", textDecoration: "underline" }}>
          ← Back to Survey List
        </Link>
      </div>
    </div>
  );
}

export default SurveyDetails;