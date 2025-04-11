string = input()
stSet = sorted(set(string))
v = list(string)
n=[]
sortTest=[]
for i in stSet:
    n.append((v.count(i),i))
    sortTest.append(v.count(i))
j=sortTest[0]
flag = 0
for i in sortTest:
    if j != i:
        flag = 1
        break
    j = i
    if flag==1:
        n.sort(key = lambda x:x[0],reverse = True)
newStr = []
a=[]
for i in n:
    if i[0]%2==1:
        a.append(i[1])
    for m in range(i[0]//2):
        newStr.append(i[1])

nstr = ''
s = ''
for i in newStr:
    nstr+=i
for i in a:
    s+=i
string = nstr+s+nstr[::-1]
if string == string[::-1]:
    print(string)
else:
    print('I\'m Sorry Hansoo')