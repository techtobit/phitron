class Phone:
    # //attribute 
    price = 1200
    color = 'blue'
    brand = 'samsung'
    features = ['camra', '32 Ram', '512G Storage']

    # //mehtod 
    def cal(self):  #self to solve error 
        print('calling phone')

    def send_sms(self, phone, sms):
        text = f'sending SMS to: {phone} and message: {sms}'
        return text

my_phone = Phone()
print(my_phone.price)
my_phone.cal()
res = my_phone.send_sms(17, 'Hello World')
print(res)