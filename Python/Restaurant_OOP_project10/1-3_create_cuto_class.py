from abc import ABC, abstractmethod
class User(ABC):
    def __init__(self, name, phone, email, address) -> None:
        # super().__init__()
        self.name=name
        self.phone=phone
        self.email=email
        self.address=address

class Customer(User):
    def __init__(self, name, money, phone, email, address) -> None:
        super().__init__(name, phone, email, address)
        self.wallet = money
        self.__order = None
    
    @property
    def order(self):
        return self.__order
    
    @order.setter
    def order(self, order):
        self.__order = order
    
    def place_order(self, order):
        self.order = order
        print(f'{self.name} placed an order {order.items}')
    
    def eat_food(self, order):
        self.order = order
        print(f'{self.name} item food {order.items}')
    
    def pay_for_order(self, amount):
        pass

    def give_tips(slef, tips_amount):
        pass

    def wirte_review(self, start):
        pass 

class Employee(User):
    def __init__(self, name, salary, starting_date, department, phone, email, address) -> None:
        super().__init__(name, phone, email, address)
        self.salary=salary
        self.due = salary
        self.starting_date=starting_date
        self.department=department
    
    def receive_salary(self):
        self.due =0


class Chaf(Employee):
    def __init__(self, name, salary, starting_date, department, cooking, phone, email, address) -> None:
        super().__init__(name, salary, starting_date, department, cooking, phone, email, address)
        self.cooking = cooking

class Server(Employee):
    def __init__(self, name, salary, starting_date, department, phone, email, address) -> None:
        super().__init__(name, salary, starting_date, department, phone, email, address)
    
    def take_order(self, order):
        pass
    def transfer_order(self, order):
        pass
    def serve_food(self, order):
        pass
    def recive_tips(self, amount):
        pass
    
class Manger(Employee):
    def __init__(self, name, salary, starting_date, department, phone, email, address) -> None:
        super().__init__(name, salary, starting_date, department, phone, email, address)
        