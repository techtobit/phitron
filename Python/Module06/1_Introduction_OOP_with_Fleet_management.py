# class Company:
#     def __init__(self, name, address) -> None:
#         self.name = name
#         self.bus = []
#         self.routes = []
#         self.dirvers = []
#         self.counter = []
#         self.manager = []
#         self.supervisors= []

class Driver:
    def __init__(self, name, license, age) -> None:
        self.name = name
        self.license = license
        self.age = age

# class Counter:
#     def __init__(self) -> None:
#         pass
#     def purchase_a_ticket(self, start, destination):
#         pass

# class Passenger:
#     pass


person1 = Driver('Kudus', 3023, 59)
print(person1.name, person1.license, person1.age)
