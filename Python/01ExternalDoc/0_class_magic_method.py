class NewPerson:
    def __init__(self, name, age):
        self.name = name
        self.age = age

#  // __str__ use for concatinate 2 things
    def __str__(self) -> str:
        return f'{self.name   } ({self.age})'

habib = NewPerson('Habib', 23)
print(habib.name, habib.age)