from MenuClass import Pizza, Burger, Drink, Menu
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

    # add drinks 
    coke = Drink('coke', 75, True)
    menu.add_menu_item('drink', coke)
    coffe = Drink('coffe', 120, False)
    menu.add_menu_item('coffe', coffe)
    
# main()
if __name__ == '__main__ ':
    main()