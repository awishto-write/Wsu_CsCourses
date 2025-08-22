import React from "react";

function SignatureTable({ signatures }) {
  return (
    <table className="signatures-table">
      <thead>
        <tr>
          <th>Name</th>
          <th>City</th>
          <th>State</th>
        </tr>
      </thead>
      <tbody>
        {signatures.map((sig) => (
          <tr key={sig.id}>
            <td>{sig.name}</td>
            <td>{sig.city}</td>
            <td>{sig.state}</td>
          </tr>
        ))}
      </tbody>
    </table>
  );
}

export default SignatureTable;