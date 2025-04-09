#include<stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    if(x%4==0 & x%100 != 0)
        printf("1");
    else if(x%400==0)
        printf("1");
    else
        printf("0");
return 0;
}