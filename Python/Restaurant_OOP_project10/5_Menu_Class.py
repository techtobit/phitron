class Food:
    def __init__(self, name, price) -> None:
        self.name = name
        self.price = price
        self.cooking_time =15
class Burger(Food):
    def __init__(self, name, price, meat, ingredients) -> None:
        super().__init__(name, price)
        self.meat = meat
        self.ingredients = ingredients
class Pizza(Food):
    def __init__(self, name, price, size, toppings) -> None:
        super().__init__(name, price)
        self.size = size
        self.toppings = toppings

class Drinks(Food):
    def __init__(self, name, price) -> None:
        super().__init__(name, price)

class Jusice(Food):
    def __init__(self, name, price) -> None:
        super().__init__(name, price)

class Salad(Food):
    def __init__(self, name, price) -> None:
        super().__init__(name, price)