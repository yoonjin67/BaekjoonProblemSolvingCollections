#include<stdio.h>
int main()
{
        int x,y,z=0,a,b,c,save;
        scanf("%d", &x);
        save=x;
        while(x!=y | z==0)
        {
                a=save/10;
                b=save%10;
                y=(a+b)%10+b*10;
                save=y;
                z++;
        }
        printf("%d", z);
        return 0;
        }