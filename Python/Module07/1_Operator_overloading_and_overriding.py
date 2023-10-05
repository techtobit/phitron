class Person:
    def __init__(self, name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight
    
    def eat(self):
        print('Parent Class')

    def exercise(self):
        raise NotImplementedError

class Cricketer(Person):
    def __init__(self, name, age, height, weight, team) -> None:
        self.team = team
        super().__init__(name, age, height, weight)

    # // Overwrite - defult will show the parent eat res 
    def eat(self):
        print('Vegitable')
        # return super().eat()
    
    # must have to use 
    def exercise(self):
        print('3 Time in a Day')

    # overriding - __add__ inbuild fun.
    def __add__(self, other):
        return self.age + other.age
    

sakib = Cricketer('Sakib', 39, 5.8, 65, 'BD')
mash = Cricketer('Mashrafi', 42, 6.2, 32, 'BD')
# sakib.eat()
# sakib.exercise()

print(sakib+mash)