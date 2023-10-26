from MenuClass5 import Pizza, Burger, Drinks, Menu
from RestaurantClass4 import Restaurant
from CreateAutoClass3 import Chef, Customer, Server, Manager
from Orders8 import Order

def main():
    # print('Main fun runing')
    menu = Menu()
    pizza_1 = Pizza('spark pizza', 600, 'large', ['Strobari, Oil, Onion'])
    menu.add_menu_item('pizza', pizza_1)
    pizza_2 = Pizza('Red Katal', 700, 'large', ['katal, Oil, Onion'])
    menu.add_menu_item('pizza', pizza_2)
    pizza_3 = Pizza('Kumra Pizza', 600, 'large', ['Kumra, Oil, Onion'])
    menu.add_menu_item('pizza', pizza_3)

    # add burger 
    burger_1 = Burger('Chicken Burger', 250, 'Chicken', ['chicken, salad'])
    menu.add_menu_item('burger', burger_1)
    burger_2 = Burger('Graby Burger', 250, 'Beef', ['Beef, salad'])
    menu.add_menu_item('burger', burger_2)
    burger_3 = Burger('Mattan Burger', 250, 'Mattan', ['Mattan, salad'])
    menu.add_menu_item('burger', burger_3)

    # add Drinkss 
    coke = Drinks('coke', 75, True)
    menu.add_menu_item('Drinks', coke)
    coffe = Drinks('coffe', 120, False)
    menu.add_menu_item('coffe', coffe) 

    #show menu
    # menu.show_menu()

    restaurant = Restaurant('All Madina Restaurant', 2000, menu)

    # add employess
    manager = Manager('Habul Basar', 53213, '10 jan 2023', 'Core', '0186627127', 'xyz@gamil.com', 'chittagong')
    restaurant.add_employee('manager', manager)
    
    chef = Chef('Ullha', 1421, 'jun 2023', '', 'everyting', '018..', 'xyz@..', 'resturant')
    restaurant.add_employee('chef', chef)
    
    server = Server('Kudoos', 5000, '23 dec 2023', 'server', '0186627127', 'xyz@gamil.com', 'chittagong')
    restaurant.add_employee('server', server)


    #sow employees :
    # restaurant.show_employees()

    #customer
    customer_1 = Customer('Tamin Iqbal', 6, 'iqbal@gamil.com', 'banni', 10000)
    order_1 = Order(customer_1, [pizza_3, coffe])
    customer_1.pay_for_order(order_1)
    restaurant.add_orders(order_1)


    restaurant.receive_payment(order_1, 2000, customer_1)
    print('revenue and balance', restaurant.revenue, restaurant.balance)

    # pay rent
    restaurant.pay_expense(restaurant.rent, 'Rent Paid')
    print('After Rent', restaurant.revenue, restaurant.balance, restaurant.expense)

main()
# if __name__ == '__main__':
#     main() 