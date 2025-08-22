# Steps to Run the Application : Assignment 2

  1. **Install the dependencies** 
  ```npm install```
  To install the dependencies from the package.json file

  2. **Run the server: using the command below** 
  ```node app.js ```
  It creates the signer.sqlite file too

  3. **Run the app locally: manually type in a browser to see the content**
  ```http://localhost:3000 ```

Those commands can be run in the terminal for the root folder 

# Steps to check if the elements got stored in the database
```sqlite3 ./database/signer.sqlite```
  Then when sqlite > appears
  ```.tables```
  ```SELECT * FROM Signers;```