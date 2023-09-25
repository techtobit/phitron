numbers = [12, 14, 15, 18, 21]

odds=[]

for num in numbers:
    if num % 2 == 1 and num % 5 ==0:
        odds.append(num)

print(odds)
# shortcut
odd_nums = [num for num in numbers if num % 2==1]
print(odd_nums)

numbers =[22,19,19,14,33]
numbers.sort()
print(numbers)