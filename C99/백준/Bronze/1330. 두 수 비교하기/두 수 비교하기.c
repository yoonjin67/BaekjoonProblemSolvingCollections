#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d %d", &x, &y);
    if(x==y)
    {
        printf("==");
        return 0;
    }
    int z= x>y ? '>': '<';
    printf("%c", z);
    return 0;
}