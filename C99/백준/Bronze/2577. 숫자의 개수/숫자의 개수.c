#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    char string[10];
    int count[10]={0,};
    sprintf(string,"%d",a*b*c);
    for(a=0;a<10;a++)
    {
        for(b=0;b<10;b++)
        {
            if(string[b]==a+48)
                count[a]++;
        }
    }
    for(c=0;c<10;c++)
        printf("%d\n",count[c]);
    return 0;
}