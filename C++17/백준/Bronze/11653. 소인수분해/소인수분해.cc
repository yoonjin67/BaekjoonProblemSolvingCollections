#include<stdio.h>

int main() {
    int A;
    scanf("%d",&A);
    if(A==1) {
        return 0;
    }
    int a;
    for(a=2;a<=A;a++) {
       while(A%a==0) {
            printf("%d\n",a);
            if(A%a==0) {
                A/=a;
            }
        }
    }
}