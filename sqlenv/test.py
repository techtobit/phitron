import mysql.connector
mydb = mysql.connector.connect(
host="localhost",
user="root",
#remove this line or password="" 
)
print(mydb)