import math
def fnd(target, data):
    start = 0
    end = len(data) - 1

    while start <= end:
        mid = (start + end) // 2

        if data[mid] == target:
            return mid
        elif data[mid] < target:
            start = mid + 1
        else:
            end = mid -1

    return -1

i = input()
lst = list(map(int,input().split(' ')))
ii = input()
lst2 = input().split(' ')
lst.sort()
for i in lst2:
    piv = fnd(int(i),lst)
    if piv != -1:
        print(1,sep='')
    else:
        print(0,sep='')
