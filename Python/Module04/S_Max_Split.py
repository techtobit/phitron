

S = input()
count_L =0
count_R = 0
result=[]

for char in S:
    if char == 'L':
        count_L +=1
    else:
        count_R +=1

    if count_L == count_R:
        result.append(S[:count_L + count_R])
        S = S[count_L + count_R:]
        count_L = 0
        count_R = 0

print(len(result))
for a in result:
    print(a)