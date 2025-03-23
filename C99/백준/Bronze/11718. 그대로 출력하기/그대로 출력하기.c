#include<stdio.h>
int main()
{
    register int i;
    char x[101]={0,};
    while(fgets(x,101,stdin))
        printf("%s",x);
    return 0;
}