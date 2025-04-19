#include<stdio.h>
int main()
{
    register int i;
    int x;
    scanf("%d", &x);
    for(i=1;i<=x;i++)
        printf("%d\n", i);
    return 0;
}
