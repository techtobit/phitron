import mysql.connector
mydbConnection = mysql.connector.connect(
host="localhost",
user="root",
#remove this line or password="" 
)
print(mydbConnection)