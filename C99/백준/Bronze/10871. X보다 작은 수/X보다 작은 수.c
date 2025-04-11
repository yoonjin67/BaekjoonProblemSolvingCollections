#include<stdio.h>
int main()
{
        short x,y;
        register short i,num;
        scanf("%hd %hd", &x, &y);
        short array[x];
        for(i=0;i<x;i++)
        {
                scanf("%hd", &array[i]);
                if(array[i]<y)
                        printf("%hd ", array[i]);
        }
        return 0;
}
