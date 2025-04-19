#include<stdio.h>
int main() {
  while(1) {
    int x,y;
    scanf("%d %d", &x,&y);
    if(!(x&&y)) break;
    if(x<y) {
      if(!(y%x)) puts("factor");
    } else {
      if(!(x%y)) puts("multiple");
      else puts("neither");
    }
    if(x==y) break;
  }
  return 0;
}