#include<stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    int y[x][2];
    register int i;
    for(i=0;i<x;i++)
        scanf("%d %d", &y[i][0], &y[i][1]);
    for(i=0;i<x;i++)
        printf("Case #%d: %d\n", i+1, y[i][0]+y[i][1]);
    return 0;
}