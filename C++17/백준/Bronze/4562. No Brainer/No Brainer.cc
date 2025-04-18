#include<stdio.h>
int main() {
    int X;
    scanf("%d",&X);
    int i;
    for(i=0;i<X;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%s BRAINS\n", a>=b?"MMM":"NO");
    }
    return 0;
}