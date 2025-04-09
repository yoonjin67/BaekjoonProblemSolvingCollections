#include<stdio.h>
unsigned long long cache[1500000];
#define MOD 1000000007
void fibonacci(int N) {
    static unsigned long long i = 0;
    cache[0]=0;
    cache[1]=1;
    for(i=2;i<1500000;i++) {
        cache[i] = (cache[i-1]+cache[i-2])%MOD;
    }
}

int main()
{
    unsigned long long int N;
    scanf("%llu", &N);
    if(N==0) {
        putchar('0');
        return 0;
    } else if (N<2) {
        putchar('1');
        return 0;
    }
    fibonacci(1500000);
    printf("%llu", cache[N%1500000]);
    return 0;
}