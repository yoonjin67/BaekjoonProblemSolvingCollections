#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    unsigned int k;
    int i,x[2],y[2],r[2];
    scanf("%d", &k);
    for(i=0;i<k;i++)
    {
        scanf("%d %d %d %d %d %d", x,y,r,x+1,y+1,r+1);
        int distance=(x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1]), sub=r[0]-r[1], add=r[0]+r[1];
        sub*=sub;
        add*=add;
        if(sub<distance && distance<add) puts("2");
        else if(distance==add) puts("1");
        else if(sub==distance && distance!=0) puts("1");
        else if(sub>distance | add<distance) puts("0");
        else if(distance==0)
        {
            if(r[0]==r[1]) puts("-1");
            else puts("0");
        }
    }
    return 0;
}

