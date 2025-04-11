#include<stdio.h>
int main() {
    unsigned n;
    scanf("%d", &n);
    unsigned m = ~n + 1;
    unsigned cnt = 0;
    for(int i = 0; i < sizeof(unsigned)*8; i++) {
        if(m^n) cnt++;
        m <<= 1;
        n <<= 1;
    }
    printf("%u", cnt);
    return 0;
}
