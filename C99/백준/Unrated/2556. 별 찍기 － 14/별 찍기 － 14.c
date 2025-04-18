#include<stdio.h>
int main()
{
    short x,i,a;
    scanf("%hd", &x);
    for(i=0;i<x;i++)
    {
     for(a=0;a<x;a++)
         printf("*");
     printf("\n");
    }
    return 0;
}