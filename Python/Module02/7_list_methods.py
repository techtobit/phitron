numbers = [12, 14, 15, 18, 21]

numbers.append(24)
numbers.insert(3, 98)
if 12 in numbers:
    numbers.remove(12)
last = numbers.pop(5)
index = numbers.index(21)
sorted = numbers.sort()
print(numbers, last, index, sorted)