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

INSERT INTO Student(Roll, Name, Email, Age, Address, Marks) 
VALUE('103', 'Ashraf', 'ashraf@gmail.com', '18', 'chittagong', '97');