# //--general 
# def main():
#     name = get_name()
#     age = get_age()
#     print(f'{name} age is {age}')


# def get_name():
#     return input('Name :')

# def get_age():
#     return input('Age :')

# if __name__ == "__main__":
#     main()

# //tuple 
def main():
    # name, age = get_person()
    # print(f'{name} age is {age}')

    student = get_person() #after use wrape value with ()
    print(f'{student[0]} age is {student[1]}')


def get_person():
    name = input('Name :')
    age = input('age :')
    # return name, age # returning tuple
    return (name, age) #more accurate tuple

if __name__ == "__main__":
    main()