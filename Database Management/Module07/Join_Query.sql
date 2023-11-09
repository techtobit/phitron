-- ----------JOIN--------------------
-- Join Table Wtihout Useing Join Table
SELECT first_name, department_name
FROM employees, departments
WHERE employees.department_id = departments.department_id;

-- Use Joing Method
SELECT first_name, salary
FROM employees 
    JOIN departments 
    ON employees.department_id = departments.department_id