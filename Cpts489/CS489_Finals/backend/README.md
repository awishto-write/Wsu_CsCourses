# Steps to Run the Application : Assignment 3 - Backend

  1. **Go to the backend folder** 
  In the terminal of the project folder
  ```cd backend ``` 

  2. **Install the dependencies** 
  ```npm install```
  ```npm install express-validator```

  To install the dependencies from the package.json file

  3. **Run the server: using the command below** 
  ```node app.js ```
  It creates the signer.sqlite file too
  This will start the server on port 4000: ```http://localhost:4000 ```


# Steps to check if the elements got stored in the database
```sqlite3 ./database/signer.sqlite```
  Then when sqlite > appears
  ```.tables```
  ```SELECT * FROM Signers;```