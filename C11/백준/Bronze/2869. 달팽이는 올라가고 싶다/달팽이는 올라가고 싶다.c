#include<stdio.h>
int main() {
    long int v, b, a;
    scanf("%ld %ld %ld",&a, &b, &v);
    v-=b+1;
    a-=b;
    printf("%ld",v/a+1);
    return 0;
}