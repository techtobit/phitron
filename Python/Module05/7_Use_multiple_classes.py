class Student:
    def __init__(self, name, current_class, id):
        self.name = name
        self.current_class = current_class
        self.id = id

    def __repr__(self) -> str:
        return f'StudentName: {self.name}, class: {self.current_class}, id: {self.id}'


class Teacher:
    def __init__(self, name, subject, id):
        self.name = name
        self.subject = subject
        self.id = id

    def __repr__(self) -> str:
        return f'TeachertName: {self.name}, subject: {self.subject}, id: {self.id}'


class School:
    def __init__(self, name) -> None:
        self.name = name
        self.teachers = []

    def add_teacher(self, name, subject):
        id = len(self.teachers)+101
        teacher = Teacher(name, subject, id)
        self.teachers.append(teacher)

mahabub = Student('Ali Mahabub', 8, 23)
print(mahabub)

Rahat = Teacher('Rahat Ullha', 'Math', 3)
print(Rahat)