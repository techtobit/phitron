class User:
    def __init__(self, name, age, money) -> None:
        self._name = name
        self._age = age
        self.__money = money

    def age(self):
        return self._age
    
    @property
    def age2(self):
        return self._age

person1 = User('Kopa', 21, 12000)
# print(person1.__money)
print(person1.age())

# //if use @property use