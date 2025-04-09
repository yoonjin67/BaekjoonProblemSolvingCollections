#include<stdio.h>
#include<stdlib.h>
#define PISANO 2000000016
#define MOD 1000000007
unsigned long long **base;
unsigned long long **result;
void multiply(unsigned long long *** a, unsigned long long *** b) {
    unsigned long long ** a1 = *a;
    unsigned long long ** b1 = *b;
    unsigned long long tmp[2][2];
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            tmp[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                tmp[i][j] += a1[i][k]*b1[k][j];
            }
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            a1[i][j] = tmp[i][j] % MOD;
        }
    }
}
void fibonacci(unsigned long long N) {
    while(N>0) {
        if(N%2 == 1) {
            multiply(&result,&base);
        }
        multiply(&base,&base); //base 제곱
        N /= 2;
    }
}

int main()
{
    unsigned long long N;
    scanf("%llu", &N);
    if(N==0) {
        putchar('0');
        return 0;
    } else if (N<2) {
        putchar('1');
        return 0;
    }
    result = malloc(sizeof(int*)*2);
    base = malloc(sizeof(int*)*2);
    for(int i = 0; i < 2; i++) {
        base[i] = malloc(sizeof(int)*2);
        result[i] = malloc(sizeof(int)*2);
    }
    base[0][0] = 1; base[0][1] = 1;
    base[1][0] = 1; base[1][1] = 0;
    result[0][0] = 1; result[0][1] = 0;
    result[1][0] = 0; result[1][1] = 1;
    fibonacci(N%PISANO);
    printf("%llu", result[0][1]%MOD);
    return 0;
}