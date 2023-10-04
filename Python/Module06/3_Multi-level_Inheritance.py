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
    
class Phone(Gadget):
    # // before calling Gadget
    # def __init__(self, dual_sim) -> None:
    #     self.dual_sim = dual_sim
    
    #  // After calling Gadget- have pass common in __int__ 
    def __init__(self, name, brand, price, color, memory, dual_sim) -> None:
        self.dual_sim = dual_sim 
        super().__init__(name, brand, price, color, memory) 

    # // __repr__ dispalay & print values 
    def __repr__(self) -> str:
        return f'Phone : {self.name}, {self.brand}, {self.price}, {self.memory}'
    
    def phone_call(self, number, text):
        return f'Calling : {number} with {text}'
    
class androidTab(Phone):
    def __init__(self, name, brand, price, color, memory, dual_sim) -> None:
        super().__init__(name, brand, price, color, memory, dual_sim)



#inheritance
my_phone  = Phone('Samsung S20', 'Samsung', 12350, 'Gray', '32GB', 'Dual Sim 5G')
# print(my_phone.price)
print(my_phone)

my_androidTab  = androidTab('Samsung z-book', 'Samsung', 12350, 'Gray', '32GB', 'Dual Sim 5G')
print(my_androidTab)