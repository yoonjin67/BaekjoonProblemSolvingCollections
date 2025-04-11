#include<stdio.h>
int main() {
    int i,x,sum=0;
    for(i=0;i<5;i++) {
        scanf("%d", &x);
        sum+=pow(x,2);
    }
    printf("%d",sum%10);
    return 0;
}