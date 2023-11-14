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