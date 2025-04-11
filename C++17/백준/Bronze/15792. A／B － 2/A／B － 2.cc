#include<stdio.h>
#include<string.h>
void print(int n)
{
    if(n<10)
    {
        putc(n+48,stdout);
        return;
    }
    int i=n,count=0,y=0;
    while(i!=0)
    {
        i/=10;
        ++count;
    }
    char x[count+1];
    x[count]='\0';
    count--;
    while(count>=0)
    {
        y=n%10;
        x[count]=y+48;
        n=n/10;
        count--;
    }
    y=0;
    while(x[y]!='\0')
    {
       putc(x[y],stdout);
       y++;
    }
}

int main()
{
    int i=0;
    int x=1,y=3;
    scanf("%d %d",&x,&y);
    print(x/y);
    x%=y;
    putc('.',stdout);
    while(i<1998)
    {
        x*=10;
        print(x/y);
        x%=y;
        i++;
    }
    return 0;
}

