n = int(input())
for x in range(n):
    lst = [int(i) for i in input().split()]
    lst.sort(reverse=True)
    print(lst[2])
