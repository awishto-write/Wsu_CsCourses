import React, { useState } from "react";
import { useNavigate } from "react-router-dom";


//function SurveyTable({ surveys }) {
function SurveyTable({ surveys, setSurveys }) {
  
  // Only details
  // const navigate = useNavigate();
  // const handleRowClick = (id) => {
  //   navigate(`/survey/${id}`);
  // };


  // The section with all the elements (edit, delete, details)

  const navigate = useNavigate();
  const [selectedRowId, setSelectedRowId] = useState(null);
  const [showActionBox, setShowActionBox] = useState(null);
  const [confirmDeleteId, setConfirmDeleteId] = useState(null);
  const [editSurvey, setEditSurvey] = useState(null);
  const [editForm, setEditForm] = useState({});


  const handleRowClick = (id) => {
    setSelectedRowId(id === selectedRowId ? null : id);
    setShowActionBox(id === selectedRowId ? null : id);
  };

  const handleDetails = (id) => {
    navigate(`/survey/${id}`);
  };

  const handleEdit = (survey) => {
    setEditSurvey(survey);
    setEditForm({ ...survey });
  };
  const handleEditChange = (e) => {
    const { name, value } = e.target;
    setEditForm((prev) => ({ ...prev, [name]: value }));
  };
  const handleEditSave = async () => {
    try {
      const res = await fetch(`http://localhost:4000/api/survey/${editSurvey.id}`, {
        method: "PUT",
        headers: {
          "Content-Type": "application/json"
        },
        body: JSON.stringify(editForm)
      });

      if (res.ok) {
        const updated = await res.json();
        setSurveys((prev) => prev.map((s) => (s.id === updated.id ? updated : s)));
        setEditSurvey(null);
      } else {
        //alert("Update failed.");
        const errorData = await res.json();
        const errorMessages = errorData.errors?.map(e => e.msg).join("\n") || "Update failed.";
        alert("Backend Error:\n" + errorMessages);
        return;
      }
    } catch {
      alert("Error occurred while updating.");
    }
  };

  const handleDeleteConfirm = async () => {
    try {
      const res = await fetch(`http://localhost:4000/api/survey/${confirmDeleteId}`, {
        method: "DELETE",
      });
      if (res.ok) {
         // Remove the deleted item from the table instantly
         setSurveys((prev) => prev.filter((s) => s.id !== confirmDeleteId));
        alert("Survey deleted.");
      } else {
        alert("Delete failed.");
      }
    } catch {
      alert("Error occurred.");
    } finally {
      setConfirmDeleteId(null);
    }
  };
  

  return (
    <div>
     <table className="signatures-table">
      <thead>
        <tr>
          <th>First Name</th>
          <th>Last Name</th>
          <th>Gender</th>
          <th>Age</th>
          <th>Location</th>
          <th>Drinks</th>
          <th>Amount</th>
          <th>Member?</th>
        </tr>
      </thead>
      <tbody>
        {surveys.map((s) => (

          // <tr key={s.id}>
          <tr key={s.id} onClick={() => handleRowClick(s.id)} style={{ cursor: "pointer" }}>
            <td>{s.firstName}</td>
            <td>{s.lastName}</td>
            <td>{s.gender}</td>
            <td>{s.age}</td>
            <td>{s.location}</td>
            <td>{s.drinksOrdered}</td>
            <td>${s.amountSpent}</td>
            <td>{s.member}</td>

            <td>
              {showActionBox === s.id && (
                <div className="row-action-buttons">
                  <button onClick={(e) => { e.stopPropagation(); handleDetails(s.id); }}>Details</button>
                  {/* <button onClick={(e) => { e.stopPropagation(); handleEdit(s.id); }}>Edit</button> */}
                  <button onClick={(e) => { e.stopPropagation(); handleEdit(s); }}>Edit</button>
                  <button onClick={(e) => { e.stopPropagation(); setConfirmDeleteId(s.id); }}>Delete</button>
                </div>
              )}
            </td>

          </tr>
        ))}
      </tbody>
    </table>

    {confirmDeleteId !== null && (
      <div className="modal-overlay">
        <div className="modal-box">
          <p>Are you sure you want to delete this survey?</p>
          <div className="modal-buttons">
            <button onClick={handleDeleteConfirm} className="confirm-btn">Yes</button>
            <button onClick={() => setConfirmDeleteId(null)} className="cancel-btn">No</button>
          </div>
        </div>
      </div>
    )}


    {editSurvey && (
      <div className="modal-overlay">
          <div className="modal-box">
            <h3>Edit Survey (ID: {editSurvey.id})</h3>
            <div className="modal-form">
              <input name="firstName" value={editForm.firstName || ""} onChange={handleEditChange} placeholder="First Name" />
              <input name="lastName" value={editForm.lastName || ""} onChange={handleEditChange} placeholder="Last Name" />
              <input name="gender" value={editForm.gender || ""} onChange={handleEditChange} placeholder="Gender" />
              <input name="age" type="number" value={editForm.age || ""} onChange={handleEditChange} placeholder="Age" />
              <input name="location" value={editForm.location || ""} onChange={handleEditChange} placeholder="Location" />
              <input name="drinksOrdered" value={editForm.drinksOrdered || ""} onChange={handleEditChange} placeholder="Drinks Ordered" />
              <input name="amountSpent" type="number" value={editForm.amountSpent || ""} onChange={handleEditChange} placeholder="Amount Spent" />
              <select name="member" value={editForm.member || ""} onChange={handleEditChange}>
                <option value="">Are you a member?</option>
                <option value="Yes">Yes</option>
                <option value="No">No</option>
              </select>
            </div>
            <div className="modal-buttons">
              <button onClick={handleEditSave} className="confirm-btn">Save</button>
              <button onClick={() => setEditSurvey(null)} className="cancel-btn">Cancel</button>
            </div>
          </div>
      </div>
    )} 
      

  </div>
  );
}

export default SurveyTable;