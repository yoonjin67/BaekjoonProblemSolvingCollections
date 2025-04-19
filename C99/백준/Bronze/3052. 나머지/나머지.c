#include<stdio.h>
int main()
{
    int x[10],i,result=0,ii,quotient[10],value[42];
    for(i=0;i<42;i++)
        value[i]=i;
    for(i=0;i<10;i++)
        scanf("%d",x+i);
    for(i=0;i<10;i++)
        quotient[i]=x[i]%42;
    for(i=0;i<10;i++)
        {
        for(ii=0;ii<42;ii++)
            {
                if(value[ii]==quotient[i])
                    {
                    value[ii]=-1;
                    }
            }
        }
    for(i=0;i<42;i++)
    {
        if(value[i]==-1)
            result++;
    }
    //putchar(result+48);
    printf("%d",result);
    return 0;
}