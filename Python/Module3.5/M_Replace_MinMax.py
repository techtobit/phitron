n = int(input())
a = list(map(int, input().split()))

# newArr = a

# newArr = newArr[1:n-1:]
# newArr.sort(reverse=True)

# res = [a[0]] + newArr + [a[-1]]
# print(*res)


min_val = min(a)
max_val = max(a)

min_idx = a.index(min_val)
max_idx = a.index(max_val)

a[min_idx], a[max_idx] = a[max_idx], a[min_idx]
print(*a)