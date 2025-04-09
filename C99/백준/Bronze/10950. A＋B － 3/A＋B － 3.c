#include<stdio.h>
int main()
{
    int x,i;
    scanf("%d", &x);
    int arr[x][2];
    for(i=0;i<x;i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    for(i=0;i<x;i++)
        printf("%d\n", arr[i][0]+arr[i][1]);
    return 0;
}