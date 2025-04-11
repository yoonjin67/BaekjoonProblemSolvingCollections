#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000000
#define MAT_SIZE 2
typedef long long ll;

ll **base, **result;

void multiply(ll ***a, ll ***b) {
    ll **mat1 = *a;
    ll **mat2 = *b;
    ll mat3[MAT_SIZE][MAT_SIZE] = {0}; 
    for (ll i = 0; i < MAT_SIZE; i++) {
        for (ll j = 0; j < MAT_SIZE; j++) {
            for (ll k = 0; k < MAT_SIZE; k++) {
                mat3[i][j] = (mat3[i][j] + mat1[i][k] * mat2[k][j]) % MOD; 
            }
        }
    }
    for (ll i = 0; i < MAT_SIZE; i++) {
        for (ll j = 0; j < MAT_SIZE; j++) {
            mat1[i][j] = mat3[i][j];
        }
    }
}


void fibonacci(ll N) {
    while(N > 0) {
        if(N%2) {
          multiply((ll***)&result,(ll***)&base);
        }
        multiply((ll***)&base,(ll***)&base);
        N/=2;
    }
}
void reset_matrix() {
    base[0][0] = 1; base[0][1] = 1;
    base[1][0] = 1; base[1][1] = 0;
    result[0][0] = 1; result[0][1] = 0;
    result[1][0] = 0; result[1][1] = 1;
}

int main() {
    ll sum = 0, A,B;
    scanf("%lld%lld",&A,&B);
    base = calloc(MAT_SIZE,sizeof(ll*));
    result = calloc(MAT_SIZE,sizeof(ll*));
    for(int k = 0; k < MAT_SIZE; k++) {
      base[k] = calloc(MAT_SIZE,sizeof(ll));
      result[k] = calloc(MAT_SIZE,sizeof(ll));
    }
    //f(0)부터 f(n)까지의 피보나치 수의 합은 f(n+2)-1이다. 기억하자.
    //여기선 -1-(-1) == 0이니 뺄셈은 생략한다.
    reset_matrix();
    fibonacci(B+2); //f(0)~f(b)
    ll b_res = result[0][1];
    reset_matrix();
    fibonacci(A+1); //f(0)~f(a-1)
    ll a_res = result[0][1];
    sum = ((b_res-a_res)%MOD+MOD)%MOD;
    printf("%lld",sum);
    return 0;
}
