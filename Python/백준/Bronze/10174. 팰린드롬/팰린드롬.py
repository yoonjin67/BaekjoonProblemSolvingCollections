i = int(input())
for v in range(i):
    string = input()
    string = string.lower()
    if string == string[::-1]:
        print("Yes")
    else:
        print("No")