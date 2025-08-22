import React, { useEffect, useState } from "react";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import SurveyForm from "./SurveyForm";
import SurveyTable from "./SurveyTable";
import SurveyDetails from "./SurveyDetails"; 
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

  // return (
  //   <div className="outer-container">
  //     <div className="content-box">
  //       <h2 className="title">MoonBucks Customer Satisfaction Survey</h2>

  //       <h3 className="subheading">Submit Your Feedback</h3>
  //       <SurveyForm add={addSurvey} />

  //       <h3 className="subheading">Survey Submissions</h3>
  //       <SurveyTable surveys={surveys} />
  //     </div>
  //   </div>
  // );

  return (
    <Router>
      <div className="outer-container">
        <div className="content-box">
          <Routes>
            <Route
              path="/"
              element={
                <>
                  <h2 className="title">MoonBucks Customer Satisfaction Survey</h2>

                  <h3 className="subheading">Submit Your Feedback</h3>
                  <SurveyForm add={addSurvey} />

                  <h3 className="subheading">Survey Submissions</h3>
                  {/* <SurveyTable surveys={surveys} /> */}
                  <SurveyTable surveys={surveys} setSurveys={setSurveys} />

                </>
              }
            />
            <Route path="/survey/:id" element={<SurveyDetails />} />
          </Routes>
        </div>
      </div>
    </Router>
  );

}

export default App;