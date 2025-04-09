#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    n*=2;
    int flag = 0;
    int j,i,k=1;
    for(i=0;i<n;i++) {
        for(j=0;j<k;j++) {
            printf("*");
        }
        for(j=0;j<n-2*k;j++) {
            printf(" ");
            
        }
        for(j=0;j<k;j++) {
            printf("*");
        }
        printf("\n");
        if(2*k==n) {
            flag=1;
        }
        if(flag) {
            k--;
        }
        else {
            k++;
        }
    }
}