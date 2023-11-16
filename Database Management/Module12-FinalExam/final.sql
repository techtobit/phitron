USE library;
CREATE TABLE Student (
    StudentID INT AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    Email VARCHAR(255) NOT NULL,
    Phone VARCHAR(15),
    Address TEXT
);


CREATE TABLE Book (
    ISBN VARCHAR(13) PRIMARY KEY,
    Title VARCHAR(255) NOT NULL,
    Author VARCHAR(255) NOT NULL,
    Genre VARCHAR(50),
    TotalCopies INT NOT NULL,
    AvailableCopies INT NOT NULL
);



INSERT INTO Student
VALUE('12', 'Xefer', 'xefer@gmail.com', '0175..', 'dhak');
INSERT INTO Student
VALUE('15', 'Alex', 'Alex@gmail.com', '971..', 'london');
INSERT INTO Student
VALUE('10', 'jhon', 'jhon@gmail.com', '995..', 'wash');