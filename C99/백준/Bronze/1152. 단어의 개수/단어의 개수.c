#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int getresult(char a[])
{    int x=0;
     char *y=strtok(a," ");
 if (y!=NULL)
    x++;     
    while(1)
    {
        
        y=strtok(NULL," ");
        if(y==NULL)
            break;
        x++;
    }
return x;
}

int main()
{
int x;
char a[1000001];
scanf("%[^\n]", a);
x=getresult(a);
 printf("%d", x);
 return 0;
}