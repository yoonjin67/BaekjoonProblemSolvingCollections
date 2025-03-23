val=input()
val=int(val)

if val < 2:
    print(val)
else:
    prev = 1
    nex = 1
    s=0
    for i in range(1,val):
        temp0=prev
        temp1=nex
        s=prev+nex
        prev=temp1
        nex=s
    print(prev)
