SELECT department_id, MAX(salary)
FROM employees
GROUP BY department_id
HAVING MAX(salary) < 8000;

SELECT * FROM employees WHERE department_id = '20';



-- How to use SubQuery
SELECT * 
FROM employees
WHERE salary < (
	-- SubQuery
	SELECT salary FROM employees WHERE employee_id = 144
    );
    
    
SELECT *
FROM departments 
WHERE department_id=(
					SELECT department_id 
                    FROM departments 
                    WHERE department_name = 'Marketing'
					);
                    

SELECT COUNT(*) AS Members
FROM departments 
WHERE department_id=(
					SELECT department_id 
                    FROM departments 
                    WHERE department_name = 'IT'
					);
                    
                    
                    
-- Advance SubQuery
-- Way 01:
SELECT DISTINCT salary
FROM employees ORDER BY salary DESC
LIMIT 1
OFFSET 1;

-- Way 02:
SELECT * FROM 
employees WHERE salary = (
			SELECT DISTINCT salary
			FROM employees ORDER BY salary DESC
			LIMIT 1
			OFFSET 1
			);
            
-- Way 03 : Best and Efficent Way
SELECT * 
FROM employees
WHERE salary = (
			SELECT MAX(salary)
			FROM employees WHERE salary < (
							SELECT MAX(salary)
							FROM employees)
			);

SELECT *
FROM employees AS emp
WHERE salary >  (
				SELECT salary
                FROM employees AS mag
                WHERE emp.manager_id = mag.employee_id
                );
                
SELECT *
FROM employees AS emp
WHERE job_id =  (
				SELECT job_id
                FROM employees AS mag
                WHERE emp.manager_id = mag.employee_id
                );


-- Common Table Expressions 
WITH temp AS(
SELECT *
FROM employees
LIMIT 5
)

SELECT first_name
FROM temp;



WITH AVGIT AS(
	SELECT AVG(salary) AS sal1
	FROM employees
	WHERE department_id = 60 -- IT
),
MAXMK AS(
	SELECT MAX(salary) AS sal2
    FROM employees
    WHERE department_id = 20 -- mak
)

SELECT *
FROM employees
WHERE salary > (SELECT sal1 FROM AVGIT) AND (SELECT sal2 FROM MAXMK);