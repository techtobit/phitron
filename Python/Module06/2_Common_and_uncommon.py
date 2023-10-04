class Laptop:
    def __init__(self, name, brand, price, color, memory) -> None:
        self.name = name
        self.brand = brand
        self.price = price
        self.memory = memory

    def run(self):
        return f'Runing laptop: {self.name}'
    
    def coding(self):
        return f'learing python'
    
class Phone:
    def __init__(self, name, brand, price, color, dual_sim) -> None:
        self.name = name
        self.brand = brand
        self.pirce = price
        self.dual_sim = dual_sim

    def run(self):
        return f'Useing Phone: {self.name}'
    
    def phone_call(self, number, text):
        return f'Calling : {number} with {text}'