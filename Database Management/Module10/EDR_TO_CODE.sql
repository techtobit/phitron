USE python_test_db;

CREATE TABLE Student(
	Roll VARCHAR(4) PRIMARY	KEY,
    Name VARCHAR(50)
);

CREATE TABLE Book(
	Book_Id VARCHAR(4) PRIMARY KEY,
    Book_Name VARCHAR(50),
    Book_Genra VARCHAR(50)
);

CREATE TABLE Libarion(
	Lib_Id VARCHAR(4) PRIMARY KEY,
    Lib_Name VARCHAR(50)
);

-- RELETIONSHIP CREATIONS
CREATE TABLE Borrow(
	Borrow_Date DATE,
    Return_Date DATE,
    Who_Borrow_Book VARCHAR(4),
    Borrow_Book_Id VARCHAR(4),
    FOREIGN KEY (Who_Borrow_Book) REFERENCES Student(Roll),
    FOREIGN KEY (Borrow_Book_Id) REFERENCES Book(Book_Id),
    PRIMARY KEY(Who_Borrow_Book,Borrow_Book_Id)
);