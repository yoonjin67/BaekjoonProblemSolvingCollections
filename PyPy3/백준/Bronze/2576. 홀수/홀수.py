lst = []
for i in range(7):
    n = int(input())
    lst.append(n)
lst.sort()
m = -1
sumofodd = 0
for i in range(7):
    if lst[i] % 2 == 1:
        if m == -1:
            m = lst[i]
        sumofodd += lst[i]
if m == -1:
    print(-1)
else:
    print(sumofodd)
    print(m)