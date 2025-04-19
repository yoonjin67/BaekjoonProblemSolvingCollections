#include<stdio.h>
#include<math.h>
int main()
{
    int M, N, i,j,sum=0,check=0,min=0,flag=0;
    scanf("%d\n%d", &M, &N);
    for(i=M;i<=N;i++)
    {
        for(j=2;j<=sqrt(i);j++)
        {
            flag=i%j;
            if(!flag)
                break;
        }
        if(flag | i==2 | i==3)
        {
            check++;
            if(check==1)
                min=i;
            sum+=i;
        }
    }
    if(!min & !flag)
        puts("-1");
    else
        printf("%d\n%d", sum, min);
    return 0;
}


