lst = [0,0,0,0,0]

i = int(input())

for v in range(i):
    m,n = map(int,input().split(' '))
    if m==0 or n==0:
        lst[4]+=1
    elif m>0 and n>0:
        lst[0]+=1
    elif m<0 and n>0:
        lst[1]+=1
    elif m<0 and n<0:
        lst[2]+=1
    elif m>0 and n<0:
        lst[3]+=1

for i in range(len(lst)-1):
    print("Q",i+1,": ",lst[i],sep='')
print("AXIS:",lst[4])
    
