#include<stdio.h>
int main()
{
    int x[50],dest;
    register int i;
    for(i=0;i<50;i++)
        scanf("%d", &x[i]);
    scanf("%d",&dest);
    i=0;
    for(i=0;i<50;i++)
        if(x[i]==dest)break;
    if(0<=i & i<=4)
        puts("A+");
    else if(5<=i & i<=14)
        puts("A0");
    else if(15<=i & i<=29)
        puts("B+");
    else if(30<=i & i<=34)
        puts("B0");
    else if(35<=i & i<=44)
        puts("C+");
    else if(45<=i & i<=47)
        puts("C0");
    else
        puts("F");
return 0;
}