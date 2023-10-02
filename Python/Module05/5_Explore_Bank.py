# class Shop:
    
#     def __init__(self, balance):
#         self.balance = balance
#         self.min_withdraw = 100
#         self.max_withdraw = 9999

#     def get_balance(self):
#         return self.balance
    
#     def deposit(self, amount):
#         if amount > 0:
#             self.balance += amount
    

class Phone:
    price = 12000
    color = 'blue'
    brand = 'samsung'

    def call(self):
        print('calling one person')

    def send_sms(self, phone, sms):
        text = f'Sending SMS to: {phone+5}'
        return text


my_phone = Phone()
result = my_phone.send_sms(41524, 'Missy, I missed to miss you')
print(result)