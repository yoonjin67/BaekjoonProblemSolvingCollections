#include<stdio.h>
#include<stdlib.h>
int top = 0;
int *dp;
int *path;
int main() {
    int n;
    scanf("%d",&n);
    dp = (int *)calloc(n+1,sizeof(int));
    path = (int *)calloc(n+1,sizeof(int));
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1]+1;
        path[i] = i-1;
        if(dp[i] > dp[i/2]+1 && i%2 == 0) {
            dp[i] = dp[i/2] + 1;
            path[i] = i/2;
        }
        if(dp[i] > dp[i/3]+1 && i%3 == 0) {
            dp[i] = dp[i/3] + 1;
            path[i] = i/3;
        }
    }
    printf("%d\n",dp[n]);
    while(n != 0) {
        printf("%d ", n);
        n = path[n];
    }
    return 0;
}