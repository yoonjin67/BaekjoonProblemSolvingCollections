n,r = map(int,input().split(' '))
def factorial(v):
    s = 1
    for i in range(v):
        s *= i+1
    return s
print(int(factorial(n)/(factorial(r)*factorial(n-r))))