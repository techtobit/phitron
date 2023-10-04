#  // Encapsulation --> hide implementions
#   // Access Modifiers (Public, Private, Protected)
class Bank :
    def __init__(self, holder_name, initial_deposit) -> None:
        self.holder_name = holder_name
        #  // protected Attribute - accessable in outside (_name)
        self._branch = 'Agrabath'
        # //privat Attribute - only accessable inside class (__name)
        self.__balance = initial_deposit
    
    def deposit(self, amount):
        # // incaptulation 
        self.__balance += amount
    
    def get_balance(self):
        return self.__balance

refsun = Bank('Rafsan', 25320)
print(refsun.holder_name)
refsun.deposit(12004)
print(refsun.get_balance())
print(refsun._branch)

# //access privat 
print(refsun._Bank__balance)