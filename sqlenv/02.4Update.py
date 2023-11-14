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
        UPDATE Student
        SET Name = 'xrive'
        WHERE NAME  = 'Ashraf Uddin'
"""
myCursor.execute(sqlQuery)
mydbConnection.commit()
print('Update table Successfully!')