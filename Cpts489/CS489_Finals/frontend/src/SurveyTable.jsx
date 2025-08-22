import React, { useState } from "react";

function SurveyTable({ surveys }) {
  return (
    <div>
     <table className="signatures-table">
      <thead>
        <tr>
          <th>First Name</th>
          <th>Last Name</th>
          <th>Gender</th>
          <th>Age</th>
          <th>Programming Languages</th>
          <th>IDEs</th>
          <th>Most frequently used Frameworks/Libraries</th>
          <th>Version Control</th>
        </tr>
      </thead>
      <tbody>
        {surveys.map((s) => (
          <tr key={s.id}>
            <td>{s.firstName}</td>
            <td>{s.lastName}</td>
            <td>{s.gender}</td>
            <td>{s.age}</td>
            <td>{s.programmingLanguage}</td>
            <td>{s.ide}</td>
            <td>{s.framework}</td>
            <td>{s.versionControl}</td>
          </tr>
        ))}
      </tbody>
    </table>

  </div>
  );
}

export default SurveyTable;