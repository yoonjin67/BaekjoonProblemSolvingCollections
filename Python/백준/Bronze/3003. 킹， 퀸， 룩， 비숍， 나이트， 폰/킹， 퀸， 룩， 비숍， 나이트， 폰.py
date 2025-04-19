chess = [1,1,2,2,2,8]
lst = list(map(int,input().split(' ')))
idx = 0
for i in lst:
    j = chess[idx]
    print(j-i,end = ' ', sep = '')
    idx+=1