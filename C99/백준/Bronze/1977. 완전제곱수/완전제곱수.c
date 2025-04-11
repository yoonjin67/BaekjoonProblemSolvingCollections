#include<stdio.h>
#include<math.h>
void result(int x,int y)
{
    auto int i,r=0,count=0,first=0,v=0;
    float s;
    for(i=x;i<y+1;i++)
    {
        s=sqrt(i);
        v=(int)s;
        if(s==v)
        {
            r+=i;
            count++;
            if(count==1)
                first=i;
        }
    }
    if (first==0)
        puts("-1");
    else
        printf("%d\n%d",r,first);
}
int main()
{
    int a,b;
    scanf("%d\n%d",&a,&b);
    result(a,b);
    return 0;
}