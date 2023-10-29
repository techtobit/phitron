class School:
    def __init__(self, name, address) -> None:
        self.name = name
        self.address = address
        self.teachers=[]
        #composition
        self.classrooms = {}
    def add_classroom(self, classroom):
        self.classrooms[classroom.name] = classroom
        
    def __repr__(self) -> str:
        print('----- ALL CLASSROOMS -------')
        for key, value in self.classrooms.items():
            print(key)
        return ''
    
    def add_teacher(self, subject, teacher):
        # if subject in self.teachers:
        self.teachers[subject]=teacher

    def student_addmision(self, student):
        className = student.classroom.name
        if className in self.classrooms:
            # TODO: set student id, (roll num) at the time of adding the student
            self.classrooms[className].add_student(student)
        else:
            print(f'No Classroom as named{className}')
    
class ClassRoom:
    
    def __init__(self, name) -> None:
        self.name = name
        #composition
        self.students = []
        self.subjects = []

    def add_student(self, student):
        serial_id = f'{self.name}-{len(self.students)+1}'
        student.id = serial_id
        self.classroom = student.name
        self.students.append(student)

    # string method to display data
    def __str__(self) -> str:
        return f'{self.name}-{len(self.students)}'
    
    #Todo : sort students by grade
    def get_topstudents(self):
        pass
