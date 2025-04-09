x=int(input())
for i in range(x):
    s=input().split(' ')
    v=float(s[0])
    for i in range(1,len(s)):
        if s[i]=='@':
            v*=3
        elif s[i]=='%':
            v+=5;
        else:
            v-=7;
    print('%.2f'%v)
