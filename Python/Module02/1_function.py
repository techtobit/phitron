#-- define --
# def double_it(num):
#     result = num * 2
#     print(result)
# double_it(4)

# -- args - * can pass multiples parameters --
# def all_sum(*numbers):
#     print(numbers)

# total = all_sum(45, 66, 78)
# print('all sum', total)

# -- avoid frist & second arguments --
# def all_sum(num1, num2, *numbers):
#     print(numbers)

# total = all_sum(45, 66, 78)
# print('all sum', total)

#  -- kargs , multiple return --
# def full_name(first, last):
#     name = f'Fulll Name : {first} {last}'
#     return name

# #take parameters in order(serial wise)
# # name = full_name('Alu', 'Kodu')
# name = full_name(last='kodu', first='alu')
# print(name)

# -- ** find additonal or string titles --
def famous_name(first, last, **addition):
    name=f'{first}{last}'
    #print addition(['title'])
    for key, value in addition.items():
        print(key, value)
    return name

name = famous_name(first='Abdula', last='Al', title='Mamun', title2='Hojur')
print(name)
