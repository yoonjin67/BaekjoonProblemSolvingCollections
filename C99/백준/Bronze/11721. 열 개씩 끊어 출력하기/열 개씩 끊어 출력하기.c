#include<stdio.h>
#include<string.h>
int main()
{
    char a[101]={0,};
    scanf("%s", a);
    register int x;
    for(x=0;x<strlen(a);x++)
    {
        printf("%c", a[x]);
        if ((x+1)%10==0)
            printf("\n");
    }
return 0;
}