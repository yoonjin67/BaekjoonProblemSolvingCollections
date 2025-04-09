#include<stdio.h>
int main() {
  int btn[3];
  btn[0] = 0;
  btn[1] = 0;
  btn[2] = 0;
  int n;
  scanf("%d",&n);
  if(n%10) {
    printf("-1");
    return 0;
  }
  btn[0] = n / 300;
  btn[1] = (n % 300) / 60;
  btn[2] = ((n % 300) % 60) / 10;
  printf("%d %d %d", btn[0], btn[1], btn[2]);
  return 0;
}
