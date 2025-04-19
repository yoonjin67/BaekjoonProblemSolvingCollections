n,m = map(int,(input().split(' ')))
lst = []
lst2 = []
for i in range(n):
    lst.append(list(map(int,input().split(' '))))
for i in range(n):
    lst2.append(list(map(int,input().split(' '))))
for i in range(n):
    for j in range(m):
        print(lst[i][j]+lst2[i][j],end=' ',sep='')
    print()