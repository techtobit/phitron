class School:
    def __init__(self, name, address) -> None:
        self.name = name
        self.address = address
        self.teachers=[]
        #composition
        self.classrooms = {}
    def add_classroom(self, classroom):
        self.classrooms[classroom.name] = classroom
    
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
    
    @staticmethod
    def calculate_grade(marks):
        if 80 <= marks <=100:
            return 'A+'
        elif 70<= marks <80:
            return 'A'
        elif 60<= marks <70:
            return 'A-'
        elif 50<= marks <60:
            return 'B'
        elif 40<= marks <50:
            return 'C'
        elif 33<= marks <40:
            return 'D'
        else:
            return 'F'
        

    def __repr__(self) -> str:
        print('----- ALL CLASSROOMS -------')
        for key, value in self.classrooms.items():
            print(key)
        
        print('----- Students -------')
        eight = self.classrooms['eight']
        for student in eight.students:
            print(student.name)
        
        print(len(eight.students))
        print('----- Students -------')
        for subject in eight.subjects:
            print(subject.name, subject.teacher.name)
        
        print('-----Students Exam Marks------')
        for student in eight.students:
            for key, value in student.marks.items():
                print(student.name, key, value)
        return ''

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

    def add_subject(self, subject):
        self.subjects.append(subject)
    
    def take_semester_final(self):
        for subject in self.subjects:
            subject.exam(self.students)

    # string method to display data
    def __str__(self) -> str:
        return f'{self.name}-{len(self.students)}'
    
    #Todo : sort students by grade
    def get_topstudents(self):
        pass


class Subject:
    def __init__(self, name, teacher) -> None:
        self.name = name
        self.teacher = teacher
        self.max_marks = 100
        self.pass_marks = 30
    
    def exam(self, students):
        for student in students:
            mark = self.teacher.evaluate_exam()
            student.marks[self.name] = mark