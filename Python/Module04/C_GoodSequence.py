
n = int(input())
nums = list(map(int, input().split()))
newNums = {}
for num in nums:
    if num in newNums:
        newNums[num] +=1
    else:
        newNums[num] =1
sum=0
for key, value in newNums.items():
    if value < key:
        sum+=value
    elif value > key:
        sum+=(value-key)
print(sum)
