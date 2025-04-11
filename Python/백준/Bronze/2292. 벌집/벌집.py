n=int(input())
c=0
t=1
for i in range(n):
 t+=6*i
 c+=1
 if t>=n:
  break
print(c)