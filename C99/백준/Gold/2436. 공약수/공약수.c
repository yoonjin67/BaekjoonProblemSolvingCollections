#include <stdio.h>
#include <limits.h>
#include <math.h>

long gcd(long a, long b) {
    if(!b) return a;
    else return gcd(b,a%b);
}

int main() {
    long x, y;
    scanf("%ld%ld", &x,&y);
    long div = y/x;

    long min_sum = LONG_MAX; 
    long a_min, b_min;

    for(int i = 1; i <= sqrt(div); i++) {
        if(div % i == 0) {
            long j = div/i;
            if(gcd(i,j) == 1) {
                long sum = i*x + j*x;
                if (sum < min_sum) {
                    min_sum = sum;
                    a_min = i*x;
                    b_min = j*x;
                }
            }
        }
    }

    printf("%ld %ld\n", a_min, b_min); 
    return 0;
}