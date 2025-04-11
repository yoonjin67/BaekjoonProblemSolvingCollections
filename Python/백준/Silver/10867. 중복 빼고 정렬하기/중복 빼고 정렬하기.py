i = int(input())
lst = map(int,input().split())
lst2 = []
for i in lst:
    if i not in lst2:
        lst2.append(i)
lst = lst2
lst.sort()
for i in lst:
    print(i, end = ' ', sep = '')