#include<stdio.h>
#include<string.h>

int dp[10];

int solve(int len) {
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j < 10; j++) {
            dp[j]=dp[j]%10007+dp[j-1]%10007;
            dp[j]%=10007;
        }
    }
    return dp[9];
}
            
int main() {
    int n;
    for(int i = 0; i < 10; i++) {
        dp[i] = 1;
    }
    scanf("%d",&n);
    printf("%d", solve(n));
    return 0;
}


