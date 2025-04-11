#include<stdio.h>
void print(int n)
{
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
    putc('\n',stdout);
}
int main()
{
    int x;
    register int y=0,z;
    scanf("%d",&x);
    short words[x*2], results[x];
    for(z=0;z<2*x;z+=2)
    {
        scanf("%hd  %hd", words+z,words+z+1);
        results[y]=words[z]+words[z+1];
        y++;
    }
    for(z=0;z<x;z++)
    {
        print(results[z]);
    }
    return 0;
} 