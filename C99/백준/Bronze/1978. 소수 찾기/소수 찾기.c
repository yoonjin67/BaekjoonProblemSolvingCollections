#include<stdio.h>
int main()
{
    int x;
    register int i,ii,count=0,answer=0;
    scanf("%d\n", &x);
    int array[x];
    for(i=0;i<x;i++)
        scanf("%d", &array[i]);
    for(i=0;i<x;i++)
    {
        count=0;
        for(ii=2;ii<array[i];ii++)
        {
            if((array[i]%ii==0))
                count++;
        }
        if (array[i]==1)
            count++;
        else if (array[i]==2)
            count=0;
        if(count==0)
            answer++;
    }
    printf("%d",answer);
    return 0;
}