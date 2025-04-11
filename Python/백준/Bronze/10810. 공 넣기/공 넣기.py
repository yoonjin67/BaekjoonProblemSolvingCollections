lst=[]
n,m = map(int,input().split(' '))
for i in range(n):
    lst.append(0)
for i in range(m):
    i,j,k = map(int,input().split(' '))
    for v in range(i-1,j):
        lst[v]=k
for m in lst:
    print(m, end=' ', sep='')