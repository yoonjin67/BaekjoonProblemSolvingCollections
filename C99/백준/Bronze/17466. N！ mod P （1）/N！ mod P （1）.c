#include<stdio.h>
void factorial(unsigned long long x, unsigned long long y)
{       register unsigned long long i,ii=1;
        for(i=1;i<=x;ii*=i,i++,ii%=y);
        printf("%llu", ii);
}
int main()
{
        unsigned long long a,b;
        scanf("%llu %llu", &a, &b);
        factorial(a,b);
        return 0;
}