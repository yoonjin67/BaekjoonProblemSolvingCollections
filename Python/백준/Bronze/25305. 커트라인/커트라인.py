n,m = map(int,input().split(' '))
lst = []
v = input().split()
for w in v:
    lst.append(int(w))
lst.sort(reverse = True)
print(lst[m-1])
