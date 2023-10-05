
import math
def timer(fun):
    def inner(*args):
        print('...Inner fun start here')
        # print(fun)
        fun(*args)
        print('...Inner & Fectorial fun End')
    return inner

# // decorator - @function name 
@timer
def get_factorial(n):
    print('......Factorial Fun Runing')
    res = math.factorial(n)
    print(f'......Factorial of {n} is : {res}')

get_factorial(5)