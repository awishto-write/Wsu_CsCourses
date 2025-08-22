import React, { useEffect, useState } from "react";
import PetitionForm from "./PetitionForm";
import SignatureTable from "./SignatureTable";
import "./style.css";

function App() {
  const [signatures, setSignatures] = useState([]);

  useEffect(() => {
    const fetchSignatures = async () => {
      try {
        const res = await fetch("http://localhost:4000/api/signature");
        const data = await res.json();
        setSignatures(data);
      } catch (err) {
        console.error("Backend not running or fetch failed:", err);
        setSignatures([]); // prevent page from breaking
      }
    };
    fetchSignatures();
  }, []);

  const addSignature = (newSig) => {
    setSignatures([newSig, ...signatures]);
  };

  return (
    <>
      <nav className="navbefore"></nav>
      <nav className="navbar">
        <ul>
          <li><a href="#">Home</a></li>
          <li><a href="#">About</a></li>
          <li><a href="#">Categories</a></li>
          <li><a href="#">Contact</a></li>
        </ul>
      </nav>

      <div className="outer-container">
        <div className="content-box">
          <h2 className="title">Move CPTS 489 to Afternoon in Winter!</h2>

          <div className="petition-content">
            <p>
              The image you see on the right is a representation of our professor every
              morning, right before his much-needed coffee that helps thaw him out a bit.
              Imagine having to wake up at 4 or 5 AM in the dead of winter just to prepare
              for class. Technically, since the sun hasn’t even risen yet, can we really
              call 4 AM "morning"? The frigid cold, combined with the mental fog of early
              hours, is an unfair battle both for students and faculty alike. No one should
              have to endure sub-zero temperatures just to attend an 8 AM lecture. Morning
              brain freeze inevitably leads to null pointer exceptions in our heads! For these
              reasons, we humbly request the administration to consider shifting CPTS 489 to
              a more humane afternoon time slot.
            </p>
            <img className="prof" src="/profImage.jpg" alt="Cold Professor" />
          </div>

          <h3 className="subheading">Sign the Petition</h3>
          <PetitionForm add={addSignature} />

          <h3 className="subheading">Signatures</h3>
          <SignatureTable signatures={signatures} />
        </div>
      </div>
    </>
  );
}

export default App;