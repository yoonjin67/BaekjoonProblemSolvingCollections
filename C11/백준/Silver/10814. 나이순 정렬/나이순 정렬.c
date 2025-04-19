#include<stdio.h>
#include<stdlib.h>
struct member{short num;char name[101];};
typedef struct member member;
int compare(member *a,member *b) 
{   
    return
        (
    a->num<b->num ?
        -1:
     a->num > b->num?
        1:       
        0
        );
}
int main()
{
    int i;
    scanf("%d",&i);
    member x[i];
    x[i].num=30000;
    i=0;
    while(x[i].num!=30000)
    {
        scanf("%hd %s", &x[i].num, x[i].name);
        i++;
    }
    qsort(x,i,sizeof(member),compare);
    i=0;
    while(x[i].num!=30000)
    {
        printf("%hd %s\n", x[i].num,x[i].name);
i++;
    }
    return 0;
}
