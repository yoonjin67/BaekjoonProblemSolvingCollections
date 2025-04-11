#include<stdio.h>
int main()
{
    auto int x , y;
    scanf("%d %d", &x, &y);
    if ( x < 0 & y < 0 )
        putc( '3' , stdout );
    else if ( x < 0 & y > 0 )
        putc( '2' , stdout );
    else if ( x > 0 & y > 0 )
        putc( '1' , stdout );
    else
        putc( '4' , stdout );
    return 0;
}