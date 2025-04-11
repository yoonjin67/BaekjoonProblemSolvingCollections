#include<stdio.h>
int main()
{
    int x;
    register int y,i,n=0,c,m;
    scanf("%d",&x);
    y=x;
    y*=2;
    y--;
    for(i=0;i<x;i++)
    {
        for(c=0;c<n;c++)
            putchar(' ');
        for(m=0;m<y;m++)
            putchar('*');
        n++;
        y-=2;
        putchar('\n');
    }
}