string = list('abcdefghijklmnopqrstuvwxyz')
lst = list(input())
for i in string:
    idx = -1
    if i in lst:
        idx = lst.index(i)
    print(idx, end=' ', sep='')