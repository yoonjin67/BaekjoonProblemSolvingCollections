import sys
input = sys.stdin.readline

l_list = {}
work = set()

for _ in range(int(input())):
  log = input().rstrip().split()
  l_list[log[0]]=log[1] 
  work.add(log[0])
working = sorted(list(work), reverse=True)
for w in working:
  if l_list[w]=="enter":
    print(w)