CREATE TABLE IF NOT EXISTS Surveys (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  firstName TEXT,
  lastName TEXT NOT NULL,
  gender TEXT,
  age INTEGER CHECK (age >= 18),
  location TEXT,
  drinksOrdered TEXT,
  amountSpent REAL CHECK (amountSpent <= 150),
  member TEXT
);