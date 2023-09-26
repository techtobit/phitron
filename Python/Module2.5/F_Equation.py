x, n = input().split()

X = int(x)
N = int(n)

res = 0
for i in range(0, N+1, 2):
    if i== 0:
        res = (X**i)-1
    else:
        res += X ** i
print(res)
