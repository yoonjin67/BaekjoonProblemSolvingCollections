#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
int main()
{
    int a;
    scanf("%d", &a);
    register int i;
    register int count=0;
    char *str=malloc(sizeof(char)*200000000);
    for(i=1;i<=a;i++)
    {
        sprintf(str,"%d", i);
        int x=strlen(str);
        register int j;
        for(j=0;j<x;j++)
        {
            if(str[j]=='3' | str[j]=='6' | str[j]=='9')
                count++;
        }
    }
    printf("%d", count);
    free(str);
    return 0;
}