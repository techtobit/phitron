from abc import ABC, abstractclassmethod
#abstract base class

class Animal(ABC):
    @abstractclassmethod #enforce all drived class ot a eat method
    def eat(self):
        pass
    def move(self):
        pass

class Monkey(Animal):
    def __init__(self,name) -> None:
        self.category = 'Monkey'
        self.name = name
        super().__init__()

        #call eat fun after useing ABS to prevent error.
    def eat(self) -> None:
        pass

ani_name = Monkey('Amazon')
print(ani_name.name)