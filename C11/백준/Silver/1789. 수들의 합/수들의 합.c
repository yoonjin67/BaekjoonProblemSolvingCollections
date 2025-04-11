#include<stdio.h>
#include<math.h>
int main () {
    long x;
    scanf("%d",&x);
    long i;
    for(i=1;x>=0;i++) {
        x-=i;
    }
    printf("%ld",i==2?1:i-2);
}