lst = []
repeat = int(input())
for i in range(repeat):
        i = int(input())
        if i == 0:
                lst=lst[:-1]
        else:
                lst.append(i)
print(sum(lst))