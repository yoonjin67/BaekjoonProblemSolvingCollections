#include<stdio.h>
int main()
{
    int hour,minute;
    scanf("%d %d", &hour, &minute);
    if(minute<45)
    {
        hour--;
        minute+=15;
    }
    else
        minute-=45;
    if(hour<0)
        hour+=24;
    printf("%d %d",hour, minute);
    return 0;
}