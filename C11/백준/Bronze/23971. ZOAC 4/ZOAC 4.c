#include<stdio.h>
#define CAL(x,y) (x-1)/(y+1)+1
int main()
{
    unsigned H,W,N,M;
    scanf("%u %u %u %u",&H,&W,&N,&M);
    printf("%u",(CAL(H,N))*(CAL(W,M)));
    return 0;

}