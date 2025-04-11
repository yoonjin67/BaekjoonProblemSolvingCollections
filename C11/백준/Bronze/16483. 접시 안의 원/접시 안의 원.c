#include<stdio.h>

int main() {
  float f;
  scanf("%f",&f);
  f/=2;
  printf("%d", (int)(f*f+0.5));
}