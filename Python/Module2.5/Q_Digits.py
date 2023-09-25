t = int(input())
while t != 0:
    val = input()
    reve = str(val[::-1])
    res = ' '.join(reve)
    print(res)
    t-=1