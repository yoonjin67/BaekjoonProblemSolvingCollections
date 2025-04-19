#include<stdio.h>

int main() {
  int n;
  scanf("%d",&n);
  int sum = 0;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= i; j++) { // j <= n이 아닌이유? 위 아래 구분 X
      sum += i+j;
    }
  }
  printf("%d", sum);
  return 0;
}