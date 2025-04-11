h,m,s=input().split()
h=int(h)
m=int(m)
s=int(s)
sI=int(input())
s+=sI
store = 0
if s>59:
   store = s//60
   s%=60
m+=store
store = 0
if m>59:
   store = m//60
   m%=60
h+=store
h%=24


print(h,m,s)

