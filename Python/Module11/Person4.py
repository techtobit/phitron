import random
class Person:
        # __init__ it is a constructor or initializer method
    def __init__(self, name) -> None:
        self.name = name
class Teacher(Person):
    def __init__(self, name) -> None:
        super().__init__(name)
        # self.subject = subject
    
    def teach(self):
        pass
    
    def evaluate_exam(self):
        marks = random.randint(0, 100)
        return marks
        # TODO: set marks for the subject for each student

class Student(Person):
    def __init__(self, name, classroom) -> None:
        super().__init__(name)
            # __id : private attribute. Can't accessed directly from ouside the class
        self.__id = None
        self.classroom = classroom
        self.subjects=[]
        self.marks={}
        self.grad = None

    # @property : it's a decorator for id Mehtod.
    @property
    # def id() is a getter method to rretrive the id value of __id as a regular attribiute
    def id(self):
        return self.__id
    # the is a decorator for id method indicating setter method.
    @id.setter
    def id(self, value):
        self.__id == value