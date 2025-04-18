rep = int(input())
for i in range(rep):
    val, string = input().split()
    val = int(val)
    print(string[:val-1]+string[val:])