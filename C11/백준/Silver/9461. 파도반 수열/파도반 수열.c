#include<stdio.h>
unsigned long long dp[101];
void init_padovan() {
  for(int i = 1; i <=3 ; i++) dp[i] = 1;
  for(int i = 4; i <= 5; i++) dp[i] = 2;
  dp[6] = 3;
  dp[7] = 4;
  dp[8] = 5;
  dp[9] = 7;
  dp[10] = 9;
}
void _padovan(int x) {
  dp[x] = dp[x-2]+dp[x-3];
}

unsigned long long trigger_padovan(int x) {
  if(x<=10) return dp[x];
  for(int i = 11; i <= x; i++) {
    _padovan(i);
  }
  return dp[x];
}

int main() {
  int n;
  init_padovan();
  scanf("%d%",&n);
  for(int i = 0; i < n; i++) {
    int x;
    scanf("%d%",&x);
    printf("%llu", trigger_padovan(x));
    if(i<n-1) puts("");
  }
  return 0;
}
