#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    n*=2;
    int flag = 0;
    int j,i,k=0;
    for(i=0;i<n-1;i++) {
        for(j=0;j<k;j++) {
            printf(" ");
        }
        for(j=1;j<n-k*2;j++) {
            printf("*");
        }
        printf("\n");
        if(n-k*2==2) {
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