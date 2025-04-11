#include<stdio.h>
#include<string.h>

#define and &

int dp[10000000];

int main() {
    int n;
    memset(dp,0,sizeof(dp));
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1]+1;
        if(i%3 == 0 and dp[i]>dp[i/3]+1) {
            dp[i]=dp[i/3]+1;
        }
        if(i%2 == 0 and dp[i]>dp[i/2]+1) {
            dp[i]=dp[i/2]+1;
        }
    }
    printf("%d",dp[n]);
    return 0;
}