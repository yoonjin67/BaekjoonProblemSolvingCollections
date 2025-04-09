a = int(input())
lst = list(map(int,input().split()))
lst.sort()
N = lst[0]*lst[-1]
print(N)