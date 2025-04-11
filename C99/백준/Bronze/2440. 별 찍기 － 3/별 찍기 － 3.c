#include<stdio.h>
int main()
{
    int x,i,a;
    scanf("%d", &a);
    for(x=a;x>0;x--)   
    {
        for(i=0;i<x;i++)
            printf("*");
        printf("\n");
    }
    return 0;
}