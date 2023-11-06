-- Questions 1-2:

CREATE TABLE Student(
    Roll CHAR(4) PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Email VARCHAR(50) UNIQUE,
    Age INT CHECK(Age > 17),
    Address VARCHAR(50),
    Marks DOUBLE
);

-- b):

CREATE TABLE Library(
    Book_Name VARCHAR(50) PRIMARY KEY,
    WhoBorrow_Book CHAR(4),
    FOREIGN KEY (WhoBorrow_Book) REFERENCES Student(Roll)
);

-- c):

CREATE TABLE Fees(
    Fees INT CHECK(Fees == 1360) PRIMARY KEY;
    FOREIGN KEY (Fees) REFERENCES Student(Roll)
);



-- Question 3: Difference Between Data and Information.

-- Data
-- Information
-- Data is a raw fact that helps to develop ideas and conclusions
-- Information is processed from data that creates meaningful data.
-- Date means various information like number, text, bool ect. 
-- Information is a verified organized combination of data.
-- It’s a low-level language.
-- It’s a second-level language.
-- Data are not meaningful and hard to understand. 
-- Information is meaningful and easy to understand.


-- Question 4: Update/deleted method not executing because of safe mode. To disable it use SET SQL_SAFE_UPDATES = 0; For Enable it SET SQL_SAFE_UPDATES = 1;

-- Question 5: 
SELECT DISTINCT Emp_Depart FROM Company;


-- Question 6:
SELECT Emp_Age, Emp_LN FROM Company ORDER BY Emp_Age DESC;


-- Question 7:
SELECT Emp_LN FROM Company WHERE Emp_Age > 30 AND Emp_Depart = 'Marketing';


-- Question 8:
SELECT * FROM Company;


-- Question 9:
SELECT * FROM Company WHERE Emp_LN LIKE '%son%';


-- Question 10:
SELECT * FROM Company WHERE Emp_Job = 'Engineer';


