#include<stdio.h>
int main()
{
    int x,y;
    while(scanf("%d %d", &x,&y)!=-1)
    {
        printf("%d\n", x+y);
    }
}