#include<stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    int array[x][2];
    register int i;
    for(i=0;i<x;i++)
        scanf("%d %d", &array[i][0], &array[i][1]);
    for(i=0;i<x;i++)
        printf("Case #%d: %d + %d = %d\n", i+1,array[i][0],array[i][1],array[i][0]+array[i][1]);
return 0;
}