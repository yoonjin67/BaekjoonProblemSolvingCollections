total = int(input())
repeat = int(input())
tot = 0 
for i in range(repeat):
    val, rep = input().split()
    tot += int(val)*int(rep)
print("Yes" if tot == total else "No")