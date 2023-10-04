class shapes:
    def __init__(self, no_sides):
        self.n = no_sides
        self.sides = [0 for i in range(no_sides)]

    def takeSides(self):
        self.sides = [float(input('Enter Side' + str(i+1) + ' : ')) for i in range(self.n)]
    
    def disSides(self):
        for i in range(self.n):
            print('Side', i+1, 'is', self.sides[i])

my_shape = shapes(4)
# my_shape.takeSides()
my_shape.disSides()