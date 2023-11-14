import mysql.connector
db_name = 'python_test_db'
mydbConnection = mysql.connector.connect(
host="localhost",
user="root",
database=db_name
#remove this line or password="" 
)

myCursor = mydbConnection.cursor()
sqlQuery = """
        CREATE TABLE Student
        (
            Roll VARCHAR(4),
            NAME VARCHAR(50)
        )
"""
myCursor.execute(sqlQuery)
print('Table Created Successfully!')