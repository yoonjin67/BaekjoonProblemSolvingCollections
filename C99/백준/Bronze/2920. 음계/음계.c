#include<stdio.h>
int main()
{
    int x[8];
    register int i,ascend=0,descend=0;
    for(i=0;i<8;i++)
        scanf("%d",&x[i]);
    for(i=1;i<8;i++)
    {
        if(x[i-1]>x[i])
            descend++;
        else if(x[i-1]<x[i])
            ascend++;
    }
    if(ascend==0)
        printf("descending");
    else if(descend==0)
        printf("ascending");
    else
        printf("mixed");
return 0;  
    }