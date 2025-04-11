i = int(input())
j = i
i *= 2
for v in range(i):
    if (v+1)%2 == 0:
        for n in range(j):
            if n%2==0:
                print(' ', sep = '', end = '')
            else:
                print('*', sep = '', end = '')
    else:
        for n in range(j):
            if n%2==0:
                print('*', sep = '', end = '')
            else:
                print(' ', sep = '', end = '')
    print()