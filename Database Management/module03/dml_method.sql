USE demoDataBase;

-- Create Schema Table
-- General Method to create table
CREATE TABLE Student(
	Roll CHAR(4),
    Name VARCHAR(50),
    Email VARCHAR(50),
    Age INT,
    Address VARCHAR(50),
    Marks DOUBLE
);


-- Constraints (Used for maintain data integrity).
-- Method 01
CREATE TABLE Student(
	Roll CHAR(4) PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Email VARCHAR(50) UNIQUE,
    Age INT CHECK(Age > 17),
    Address VARCHAR(50),
    Marks DOUBLE
);

-- Method 02:
CREATE TABLE Student(
	Roll CHAR(4),
    Name VARCHAR(50) NOT NULL,
    Email VARCHAR(50),
    Age INT,
    Address VARCHAR(50),
    Marks DOUBLE,
    
    PRIMARY KEY(Roll),
    UNIQUE(Email),
    CHECK(Age < 17)
);


-- Method 03:
CREATE TABLE Student(
	Roll CHAR(4),
    Name VARCHAR(50) NOT NULL,  -- cant use not null outside of variable.
    Email VARCHAR(50),
    Age INT,
    Address VARCHAR(50),
    Marks DOUBLE,
    
    -- constraint key name
    constraint pk_rule PRIMARY KEY(Roll),
    constraint unique_rule UNIQUE(Email),
    constraint check_rule CHECK(Age < 17)
);

-- FOREIGN KEY ( Use Another table Primary Key into New table)
CREATE TABLE Library(
	Book_Name VARCHAR(50) PRIMARY KEY,
    WhoBorrow_Book CHAR(4),
    
    FOREIGN KEY (WhoBorrow_Book) REFERENCES Student(Roll)
);


-- Composite Primary Key ( Create One Key by useing two Primary Key)
CREATE TABLE Course(
	CourseName VARCHAR(10),
    University VARCHAR(10),
    Credit INT,
    
    constraint PRIMARY KEY(CourseName, University)
);


-- Insert values in table schema
INSERT INTO Student(Roll, Name, Email, Age, Address, Marks) 
VALUE('103', 'Ashraf', 'ashraf@gmail.com', '18', 'chittagong', '97');

INSERT INTO Student(Roll, Name, Email, Age, Address, Marks) 
VALUE('106', 'Rifat', 'riaft@gmail.com', '19', 'Dhaka', '63');

-- Update Method
 -- make true/fale safe update mod
SET SQL_SAFE_UPDATES = 0;
UPDATE Student SET Roll= '107';


-- Delete Mehtod(Will Delete Specific Row.
SET SQL_SAFE_UPDATES = 0;
DELETE FROM Student WHERE Address='Dhaka';
SET SQL_SAFE_UPDATES = 1;


-- DROP TABLE ( Complitedly delete Table)
DROP TABLE Student;



