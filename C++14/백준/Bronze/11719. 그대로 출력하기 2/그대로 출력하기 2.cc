#include<stdio.h>
int main()
{
    char x[10001]={0,};
    while(fgets(x,10000,stdin))
        printf("%s",x);
    return 0;
}