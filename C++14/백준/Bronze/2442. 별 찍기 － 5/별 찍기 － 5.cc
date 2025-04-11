#include<stdio.h>
int main()
{
    int x;
    register int i,ii,iii,xx;
    scanf("%d",&x);
    xx=x-1;
    iii=1;
    for(i=0;i<x;i++)
    {
        for(ii=xx;ii>0;ii--)
            putchar(' ');
        for(ii=0;ii<iii;ii++)
            putchar('*');
        iii+=2;
        xx--;
        putchar('\n');
    }
}