

n = int(input())
arr = list(map(int, input().split()))
# newArr = []
count=0
# for num in arr:
#     if num%2 !=0:
#         break
#     else:
#         newArr[:]=[int(num / 2) for num in arr]
#         count =1

# for num in newArr:
#     if num % 2 !=0:
#         break
#     else:
#         newArr[:]=[int(num / 2) for num in newArr]
#         count += 1

# print(count)

while all(num % 2 == 0 for num in arr):
    arr = [num // 2 for num in arr]
    count +=1
print(count)
