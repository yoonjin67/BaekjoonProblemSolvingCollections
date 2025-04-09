#include<stdio.h>
long fibonacci(int n)
{
    if(n==0)
        return 0;
    else if(n<3)
        return 1;
    else
    {
        int i;
        long first=1,second=1,third;
        for(i=3;i<=n;i++)
        {
            third=first+second;
            first=second;
            second=third;
        }
        return third;
    }
}
int main()
{
    int i,N;
    long fib;
    scanf("%d", &N);
    fib=fibonacci(N);
    printf("%ld", fib);
    return 0;
}
