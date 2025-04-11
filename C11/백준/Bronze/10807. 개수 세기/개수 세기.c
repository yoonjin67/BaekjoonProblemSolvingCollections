#include<stdio.h>
int main() {
    int X, i,j,Y,cnt=0;
    scanf("%d", &X);
    int array[X];
    for(i=0;i<X;i++) {
        scanf("%d", array+i);
    }
    scanf("%d", &Y);
    for(i=0,j=array[i];i<X;i++,j=array[i]) {
        if(j==Y) {
            cnt++;
        }
    }
    printf("%d", cnt);
}