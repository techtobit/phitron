t = int(input())
while t!=0:
    x, y= input().split()
    num1 = int(x)
    num2 = int(y)
    sumOfOdd = 0
    if(num1 < num2):
        for i in range(num1+1, num2):
            if(i%2!=0) :
                sumOfOdd += i
    else:
        for i in range(num2+1, num1):
            if(i%2!=0) :
                sumOfOdd +=i
    print(sumOfOdd)
    t-=1