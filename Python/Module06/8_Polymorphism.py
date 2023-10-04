from math import pi

class Shape:
    def __init__(self, name) -> None:
        self.name = name

class Rectangle(Shape):
    def __init__(self, name, lenght, width) -> None:
        self.lenght = lenght
        self.lenght = width
        super.__init__(name)

    def area(self):
        return self.lenght*self.widht
    
class Circle(Shape):
    def __init__(self, name, radius) -> None:
        self.radius = radius
        super().__init__(name)

    def area(self):
        return pi * self.radius