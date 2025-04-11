lst = []
for i in range(9):
    lst.append(int(input()))
lst.sort()
res = sum(lst)-100
for i in range(9):
    flag = 0
    for j in range(9):
        if j==i:
            continue
        if lst[i]+lst[j]==res:
            lst = lst[:i]+lst[i+1:j]+lst[j+1:]
            flag = 1
            break
    if flag == 1:
        break
for i in lst:
    print(i)