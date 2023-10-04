#  -- base class, parent class, common attribute + functionality class 
#   -- derived class, child class, uncommon attribute + functionality class 
class Gadget:
    def __init__(self, name, brand, price, color, memory) -> None:
        self.name = name
        self.brand = brand
        self.price = price
        self.memory = memory
        self.color = color  

    def run(self):
        return f'Runing laptop: {self.name}'
    
    

class Leptop:
    def __init__(self, dvd_drive) -> None:
        self.dvd_drive = dvd_drive
    
class Phone:
    def __init__(self, dual_sim) -> None:
        self.dual_sim = dual_sim
    
    def phone_call(self, number, text):
        return f'Calling : {number} with {text}'