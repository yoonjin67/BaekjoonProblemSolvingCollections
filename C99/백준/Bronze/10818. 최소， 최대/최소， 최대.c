#include<stdio.h>
int main()
{
    int i;
    register int ii,result;
    scanf("%d", &i);
    int x[i];
    for(ii=0;ii<i;ii++)
        scanf("%d", &x[ii]);
    result=x[0];
    for(ii=0;ii<i;ii++)
        result= result <= x[ii] ? result: x[ii];
    printf("%d ",result);
    for(ii=0;ii<i;ii++)
        result= result >= x[ii] ? result: x[ii];
    printf("%d",result);
    return 0;
}