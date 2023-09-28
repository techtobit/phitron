#-- lamda


# gen fun 
# def dobuled(x):
#     return x*2

# lamda fun - convert multi fun in one line 
dobuled = lambda num:num*2
#     # fun              arg  arg * val 
# res = dobuled(10)
# print(res)

# addSum = lambda x,y : x+y
# res2 = addSum(10, 21)
# print(res2)

# -- Map method with lamda --
numbers = [12, 14, 16, 18, 20, 22, 24]
# doubled_nums = map(dobuled, numbeers)
doubled_nums = map(lambda x:x*2 , numbers)
print(list(doubled_nums))
