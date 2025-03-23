#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(void *a,void *b, int n)
{
    void *t;
    t=malloc(n);
    memcpy(t,a,n);
    memcpy(a,b,n);
    memcpy(b,t,n);
    free(t);
}
typedef long lt;
int main()
{
    lt x,y;
    scanf("%ld %ld", &x,&y);
    if(x>y)
        swap(&x,&y,sizeof(lt));
    x=(y*(y+1)/2)-((x-1)*x/2);
    printf("%ld",x);
    return 0;
}