#include<stdio.h>
int main() {
    int x1, y1, x2, y2, x3, y3, x,y;
    scanf("%d %d\n%d %d\n%d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    if(x1==x3) x=x2;
    if(x2==x1) x=x3;
    if(x2==x3) x=x1;
    if(y1==y3) y=y2;
    if(y2==y3) y=y1;
    if(y2==y1) y=y3;
    
    printf("%d %d", x, y);
    return 0;
}