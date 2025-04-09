#include<stdio.h>
int main()
{
    int i,x,result=0;
    for(i=0;i<5;i++){
        scanf("%d",&x);
        if(x<=40)
            result+=40;
        else
            result+=x;
    }
    result/=5;
    printf("%d",result);
}