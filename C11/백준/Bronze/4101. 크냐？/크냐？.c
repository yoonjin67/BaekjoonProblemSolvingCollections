#include<stdio.h>
int main() {
    int A=1,B=1;
    while(1) {
        scanf("%d %d", &A,&B);
        if(A==B && A==0) {
            break;
        }
        if(A>B) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}