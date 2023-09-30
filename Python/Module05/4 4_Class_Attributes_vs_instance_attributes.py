class Shop:

    # //cart is a global class attribute 
    cart = []
    def __init__(self, buyer):
        self.buyer = buyer
    
    def add_to_cart(self, item):
        self.cart.append(item)


mehz = Shop('Mehz')
mehz.add_to_cart('Bike')
mehz.add_to_cart('BMW')
# print(mehz.cart)

nisho = Shop('Nisho')
nisho.add_to_cart('Car')
nisho.add_to_cart('tesla')
print(nisho.cart)


# ANs - ['Bike', 'BMW', 'Car', 'tesla']
# mehz data showing into nisho instance beacuse cart in in global 

class ShopTwo:
    shopping_mall = 'NewMarket'
    def __init__(self, buyer):
        self.buyer = buyer
        # // instance attribute - private
        self.cart = []
    
    def add_to_cart(self, item):
        self.cart.append(item)


mehz = ShopTwo('Mehz')
mehz.add_to_cart('Watch')
mehz.add_to_cart('Rolex')
print(mehz.cart)

nisho = ShopTwo('Nisho')
nisho.add_to_cart('Leptop')
nisho.add_to_cart('Mackbook')
print(nisho.cart)

# ans - ['Bike', 'BMW']
# ['Car', 'tesla']