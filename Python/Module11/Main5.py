from SchoolClasses2 import School, ClassRoom
from Person4 import Student
def main():
    # print('Main is runing')
    school = School('Howla Hight', 'Popadia')

    eight = ClassRoom('eight')
    school.add_classroom(eight)
    nine = ClassRoom('nine')
    school.add_classroom(nine)
    ten = ClassRoom('ten')
    school.add_classroom(ten)

    print(school)

    student = Student('Abul Kalam', eight)
    school.student_addmision(student)

if __name__ == '__main__':
    main()