#include<stdio.h>
void printcalendar(int x, int y)
{
    int datecode[12]={0,31,28,31,30,31,30,31,31,30,31,30},result=y,i;
    for(i=0;i<x;i++)
        result+=datecode[i];
    result%=7;
    switch(result)
    {
        case 0:
            puts("SUN");
            break;
        case 1:
            puts("MON");
            break;
        case 2:
            puts("TUE");
            break;
        case 3:
            puts("WED");
            break;
        case 4:
            puts("THU");
            break;
        case 5:
            puts("FRI");
            break;
        case 6:
            puts("SAT");
            break;
    }
}
int main()
{
    int x,y;
    scanf("%d %d",&x, &y);
    printcalendar(x,y);
    return 0;
}