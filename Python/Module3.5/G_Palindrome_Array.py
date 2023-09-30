n = int(input())
nums = list(map(int, input().split()))
newArr = []
newArr= nums[::-1]
if newArr == nums:
    print("YES")
else:
    print('NO')
