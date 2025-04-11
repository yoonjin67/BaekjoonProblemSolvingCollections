#include<stdio.h>
int main()
{
        short x,y,z;
        scanf("%hd %hd %hd", &x, &y, &z);
        if ( (x>=y & y>=z) | (z>=y & y>=x) )
                printf("%hd", y);
        else if ( ( z>=x & x>=y) | (y>=x & x>=z) )
                printf("%hd", x);
        else
                printf("%hd", z);
        return 0;
}