def main():
    student  = get_person()
    if student['name'] == 'Ashraf':
        student['ocupation'] = 'Programming'
    print(f"{student['name']} age is {student['age']} and his occupaiton is {student['ocupation']}")

def get_person():
    # //easy method 
    # student = {}
    # student['name'] = input('Name :')
    # student['age'] = input('Age :')
    # return student

    # shortcut 
    name = input('Name :')
    age = input('Age :')
    return {"name" : name, "age":age}

if __name__ == '__main__':
    main()