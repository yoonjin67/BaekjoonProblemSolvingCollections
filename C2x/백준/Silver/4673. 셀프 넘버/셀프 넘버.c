#include <stdio.h>
int self_number(int a)
{
    int sv=a;
    while(a>0)
    {
         sv+=a%10;
         a/=10;
    }
    return sv;
}
int main()
{
    int i=1,array[10000], j,check;
    for(j=0;j<10000;j++)
        array[j]=j+1;
    while(i<10001)
    {
        check=self_number(i);
        if(check<10001)
            array[check-1]=-1;
        i++;
    }
    for(j=0;j<10000;j++)
    {
        if(array[j]!=-1)
            printf("%d\n", array[j]);
    }
    return 0;
}
