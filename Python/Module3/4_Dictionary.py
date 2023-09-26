number = [12, 14, 15, 16, 18, 20, 22, 25]
person = ['Apple', 'Bannana', 'Pinaple']

# key value pair 
# dictonary 
# object
# hash table 
# overlap with set 
# structure - {key: val}

person = {'name' : 'Xrive', 'address': 'USA', 'age': 23, 'job': 'Developer'}
print(person)
print(person['age'])
print(person.keys())
print(person.values())
# add key value 
person['Company'] = 'Google'
print(person)

# special dictionary looping 
for key, val in person.items():
    print(key, val)