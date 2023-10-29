from SchoolClasses2 import School, ClassRoom, Subject
from Person4 import Student, Teacher
def main():
    # print('Main is runing')
    school = School('Howla Hight', 'Popadia')

    eight = ClassRoom('eight')
    school.add_classroom(eight)
    nine = ClassRoom('nine')
    school.add_classroom(nine)
    ten = ClassRoom('ten')
    school.add_classroom(ten)


    # add students
    studentA = Student('Abul Kalam', eight)
    school.student_addmision(studentA)
    
    studentB = Student('Habibur Rahaman', eight)
    school.student_addmision(studentB)

    studentC = Student('Jerin Akter', eight)
    school.student_addmision(studentC)
    
    #subjects 
    physics_teacher = Teacher('Shahjahan Tapon Rana')
    physics = Subject('physics', physics_teacher)
    eight.add_subject(physics)
    
    chemisty_teacher = Teacher('Subrot Sir')
    chemisty = Subject('chemisty', chemisty_teacher)
    eight.add_subject(chemisty)
    
    print(school)
if __name__ == '__main__':
    main()