def swapList(lst,a,b):
    lst[a],lst[b] = lst[b],lst[a]
    return lst
lst = []
n,m = map(int,input().split(' '))
for i in range(n):
    lst.append(i+1)
for i in range(m):
    v,w = map(int,input().split(' '))
    v , w = v-1, w-1
    swapList(lst,v,w)
for i in lst:
    print(i,end = ' ', sep = '')
