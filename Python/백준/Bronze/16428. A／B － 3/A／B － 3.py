def cal(a,b):
    c, d = divmod(a, b)
    if a!=0 and d<0:
        c, d = c+1, d-b
    print(c)
    print(d)

def main():
    a, b = map(int, input().split())
    cal(a,b)

main()