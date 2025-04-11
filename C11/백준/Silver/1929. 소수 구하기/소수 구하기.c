#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void sieve_of_eratosthenes(int start,int n) {
    bool *is_prime = (bool*) malloc(sizeof(bool) * (n+1));
    register int i, j;

    for (i = 0; i <= n; i++)
        is_prime[i] = true;
    for (i = 2; i*i <= n; i++) {
        if (is_prime[i]) {
            for (j = i*i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    for (i = start; i <= n; i++) {
        if (is_prime[i] && i>=2) {
            printf("%d\n", i);
        }
    }

    free(is_prime);
}

int main() {
    int n,m;
    scanf("%d %d", &n,&m);
    sieve_of_eratosthenes(n,m);
    return 0;
}
