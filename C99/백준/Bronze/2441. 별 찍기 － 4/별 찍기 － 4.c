#include<stdio.h>
int main()
{
    int x,h,i;
    scanf("%d",&x);
    for(h=0;h<x;h++)
    {
        for(i=0;i<h;i++)
            putchar(' ');
        for(i=0;i<x-h;i++)
            putchar('*');
        putchar('\n');
    }
}