CREATE TABLE IF NOT EXISTS Surveys (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  firstName TEXT NOT NULL,
  CHECK (length(firstName) >= 5 AND length(firstName) <= 15),
  lastName TEXT NOT NULL,
  CHECK (length(lastName) >= 5 AND length(lastName) <= 15),
  gender TEXT,
  age INTEGER CHECK (age >= 18),
  programmingLanguage TEXT,
  ide TEXT,
  framework TEXT, 
  versionControl TEXT,
);