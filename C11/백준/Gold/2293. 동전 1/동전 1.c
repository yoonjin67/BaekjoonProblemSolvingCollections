#include<stdio.h>
#include<string.h>
int dp[10001];

int main() {
  memset(dp,0,sizeof(dp));
  int n;
  int k;
  scanf("%d%d",&n, &k);
  int coins[n];
  for(int i = 0; i < n; i++) {
    scanf("%d",coins+i);
  }
  dp[0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = coins[i]; j <= k; j++) {
      dp[j] += dp[j-coins[i]];
    }
  }
  printf("%d", dp[k]);
  return 0;
}
