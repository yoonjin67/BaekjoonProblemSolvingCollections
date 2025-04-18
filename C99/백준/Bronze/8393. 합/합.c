#include<stdio.h>
int main()
{
    int x=0,i,a;
    scanf("%d", &a);
    for(i=1;i<=a;x+=i,i++);
    printf("%d", x);
    return 0;
}