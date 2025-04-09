#include<stdio.h>
int main()
{
    int x[9];
    register int i,save;
    for(i=0;i<9;i++)
        scanf("%d",&x[i]);
    save=x[0];
    for(i=0;i<9;i++)
        save=save<x[i]?x[i]:save;
    for(i=0;i<9;i++)
    {
        if(x[i]==save)
        {
                printf("%d\n%d",x[i],i+1);
                return 0;
        }
    }
    return 0;
}