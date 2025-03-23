#include <stdio.h>

// 제곱하면서 모듈러
long long power(long long  base, long long r, long long mod) {
    if(r==0) return 1;
    if (r == 1) return base%mod;
    long long b = power(base,r/2,mod);
    if (r % 2) return (base%mod * (b%mod*b%mod)) % mod;
    return (b%mod*b%mod)%mod;
}

long long solve(long long r, long long nth, long long mod) {
    if (nth == 1) return 1;
    int x = (1+power(r,nth/2,mod))%mod;
    int y = solve(r,nth/2,mod)%mod;
    int z = power(r,2*(nth/2),mod)%mod;
    if (nth % 2) {
        return (z%mod+x%mod*y%mod%mod);
    } else {
        return (x%mod*y%mod)%mod;
    }
}

int main() {
    long long a, r, n, mod;
    scanf("%lld %lld %lld %lld", &a, &r, &n, &mod);
    if(mod==1) {
        printf("0");
        return 0;
    }
    if(r==1) {
        printf("%lld",(a%mod*n%mod)%mod);
        return 0;
    }
    printf("%lld", (solve(r, n, mod) % mod * a % mod) % mod);
    return 0;
}
