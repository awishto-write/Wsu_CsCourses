import React, { useEffect, useState } from "react";
import SurveyForm from "./SurveyForm";
import SurveyTable from "./SurveyTable";
import "./style.css";

function App() {
  const [surveys, setSurveys] = useState([]);

  useEffect(() => {
    const fetchSurveys = async () => {
      try {
        const res = await fetch("http://localhost:4000/api/survey");
        const data = await res.json();
        setSurveys(data);
      } 
      catch (err) {
        console.error("Fetch failed:", err);
        setSurveys([]);
      }
    };
    fetchSurveys();
  }, []);

  const addSurvey = (newSurvey) => {
    setSurveys([newSurvey, ...surveys]);
  };

  return (
    <div className="outer-container">
      <div className="content-box">
        <h2 className="title">Acme Software Solutions</h2>

        <h3 className="subheading">Submit Your Feedback</h3>
        <SurveyForm add={addSurvey} />

        <h3 className="subheading">Survey Submissions</h3>
        <SurveyTable surveys={surveys} />
      </div>
    </div>
  );
}

export default App;