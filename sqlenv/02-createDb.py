import mysql.connector
mydbConnection = mysql.connector.connect(
host="localhost",
user="root",
#remove this line or password="" 
)
print(mydbConnection)
db_name = 'python_test_db'
myCursor = mydbConnection.cursor()
sqlQuery = 'CREATE DATABASE ' + db_name
myCursor.execute(sqlQuery)