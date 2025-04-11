def main():
    while True:
        a,b,c = map(int,input().split())
        if a==b==c==0:
            return
        s = set([a,b,c])
        if len(s) == 1:
            print('Equilateral')
        else:
            l = [a,b,c]
            l.sort()
            if l[0]+l[1] <= l[2]:
                print('Invalid')
                continue
            if len(s) == 3:
                print('Scalene')
            else:
                print('Isosceles')
if __name__ == "__main__":
    main()