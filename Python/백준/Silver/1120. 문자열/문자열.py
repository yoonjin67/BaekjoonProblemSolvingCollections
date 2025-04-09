a,b = input().split(' ')
a=list(a)
b=list(b)
length = len(b) if len(b)>len(a) else len(a)
flag = 'b' if len(b)>len(a) else 'a'
iteration = len(b) if len(b)<len(a) else len(a)
n = []
for i in range(length-iteration+1): 
    if flag=='b':
        v = b[i:i+iteration]
        w = a
    else:
        v = a[i:i+iteration]
        w = b
    cnt = 0
    for i in range(iteration):
        if v[i]==w[i]:
            cnt+=1
    n.append(len(v)-cnt)

n=sorted(n)
print(n[0])
    
