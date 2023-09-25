balance = 5000
def by_things(item, price):
    # print('Blance',balance)
    global balance
    balance = balance-price
    print(item, balance)

by_things('Rest amount', 1000)
print('Global Total Blance', balance)