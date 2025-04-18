#include<stdio.h>
int main()
{
    register int n;
    int x,y;
    scanf("%d %d", &x,&y);
    printf("%d\n", y%10*x);
    printf("%d\n", (y%100-y%10)/10*x);
    printf("%d\n", y/100*x);
    printf("%d\n", x*y);
    return 0;
}