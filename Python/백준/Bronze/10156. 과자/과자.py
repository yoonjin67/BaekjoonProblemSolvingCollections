a,b,c = map(int,input().split(' '))
c-=a*b
print(max(-c,0))