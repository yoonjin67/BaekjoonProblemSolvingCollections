#include<stdio.h>
int main()
{
    short x,result=0,i;
    scanf("%hd",&x);
    char string[x+1];
    scanf("%s",string);
    for(i=0;i<x;i++)
        result+=string[i]-'0';
    printf("%d",result);
    return 0;
}