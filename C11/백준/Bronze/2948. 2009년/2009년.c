#include<stdio.h>
void printcalendar(int x, int y)
{
    int datecode[12]={0,31,28,31,30,31,30,31,31,30,31,30},result=x,i;
    for(i=0;i<y;i++)
        result+=datecode[i];
    result%=7;
    switch(result)
    {
        case 0:
            puts("Wednesday");
            break;
        case 1:
            puts("Thursday");
            break;
        case 2:
            puts("Friday");
            break;
        case 3:
            puts("Saturday");
            break;
        case 4:
            puts("Sunday");
            break;
        case 5:
            puts("Monday");
            break;
        case 6:
            puts("Tuesday");
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