t = int(input())

n1, n2 = 0, 1

count =0

if t ==1 :
    print(n1, end=' ')
else:
    while count<t :
        print(n1, end=' ')
        nth = n1+n2
        n1 = n2
        n2 = nth
        count+=1

