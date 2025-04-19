#include<stdio.h>
#define THRESHOLD 1002
int main() {
    int a;
    scanf("%d",&a);
    int i,j;
    for(i=0;i<THRESHOLD;i++) {
        for(j=0;j<THRESHOLD-i;j++) {
            if((j*5+i*3)==a) {
                printf("%d",j+i);
                return 0;                
            }
        }
    }
    puts("-1");
    return 0;
}