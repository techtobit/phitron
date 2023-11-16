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

CREATE TABLE Borrowing (
    BorrowID INT AUTO_INCREMENT PRIMARY KEY,
    StudentID INT,
    ISBN VARCHAR(13),
    BorrowDate DATE NOT NULL,
    DueDate DATE NOT NULL,
    ReturnDate DATE,
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
    FOREIGN KEY (ISBN) REFERENCES Book(ISBN)
);



INSERT INTO Student
VALUE('12', 'Xefer', 'xefer@gmail.com', '0175..', 'dhak');
INSERT INTO Student
VALUE('15', 'Alex', 'Alex@gmail.com', '971..', 'london');
INSERT INTO Student
VALUE('10', 'jhon', 'jhon@gmail.com', '995..', 'wash');


INSERT INTO Book
VALUE('20', 'Himu', 'Humayan', 'fictional', 11, 7);
INSERT INTO Book
VALUE('25', 'Advance Javascript', 'Junayed', 'CSE', 15, 9);
INSERT INTO Book
VALUE('30', 'English Grammar', 'Walk Hary', 'English', 23, 22);

-- INSERT INTO Borrowing
INSERT INTO Borrowing
VALUE('1', '12', '25', '2023-10-12', '2023-11-12', '2023-11-12');
INSERT INTO Borrowing
VALUE('2', '12', '25', '2023-10-12', '2023-11-12', '2023-11-12');
INSERT INTO Borrowing
VALUE('3', '12', '25', '2023-10-12', '2023-11-12', '2023-11-12');


-- Updateing book in book library
UPDATE Book
SET AvailableCopies= AvailableCopies-1
WHERE ISBN = '20';


-- Return  Most borrwing book student name
SELECT s.Name, COUNT(b.BorrowId) AS TotalBorrow
FROM Borrowing b
LEFT JOIN Student s
ON b.StudentId = s.StudentId
GROUP BY s.Name
ORDER BY TotalBorrow DESC
LIMIT 1;

-- 2nd lowest salary 
SELECT DISTINCT salary
FROM employees
ORDER BY salary ASC
LIMIT 1
OFFSET 1;