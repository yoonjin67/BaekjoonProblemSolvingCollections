#include<stdio.h>
int main()
{
    short X;
    register short i;
    scanf("%hd",&X);
    short AB[X][2];
    for(i=0;i<X;i++)
        scanf("%hd,%hd",&AB[i][0],&AB[i][1]);
    for(i=0;i<X;i++)
        printf("%d\n",AB[i][0]+AB[i][1]);
    return 0;
}