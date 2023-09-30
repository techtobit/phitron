class Phone:
    manufactured = 'China'

    def __init__(self, owner, brand, price):
        self.owner = owner
        self.brand = brand
        self.price = price

my_phone = Phone('Xrive', 'Oppo', 9800 )
print(my_phone.owner, my_phone.brand, my_phone.price)

new_phone = Phone('Hardex', 'samsung', 12000)
print(new_phone.owner, new_phone.brand, new_phone.price)