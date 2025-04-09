r = int(input())
cy = 100
sd = 100
for i in range(r):
    n,m = map(int,input().split())
    if n-m<0:
        cy-=m
    elif n-m>0:
        sd-=n
print(cy,sd,sep='\n')