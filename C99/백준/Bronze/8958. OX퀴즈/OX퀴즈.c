#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,x,score=0,n,y;
    scanf("%d\n",&y);
    char string[y][80];
    for(i=0;i<y;i++)
    {
        scanf("%s",string[i]);
        x=0;
        score=0;
        while(x<strlen(string[i]))
        {
            for(n=0;string[i][x]=='O';x++,n++,score+=n);
            while(string[i][x]=='X')            
                x++;           
        }
        printf("%d\n",score);
    }
return 0;
}
    
