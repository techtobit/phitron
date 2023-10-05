def parentFun():
    print('This is Parent Functions')
    def childFun():
        print('This is child Fun')
        return 339
    return childFun

# print(parentFun())

# calling inner fun 
# print(parentFun()())

def call_outerFun(fun):
    fun()
    print('Inner Fun Printed')

def outerFun():
    print('Im calling outer fun')

call_outerFun(outerFun)

