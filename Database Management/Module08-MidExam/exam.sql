CREATE TABLE Employees(
	first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    dob DATE NOT NULL,
    emp_id VARCHAR(4) PRIMARY KEY,
    salary VARCHAR(10) NOT NULL
);

CREATE TABLE Departments(
	dep_id VARCHAR(5) PRIMARY KEY,
    dep_name VARCHAR(50)
);


-- GET 2nd MAX SALARY
SELECT DISTINCT salary
FROM employees
ORDER BY salary DESC
LIMIT 1
OFFSET 1;