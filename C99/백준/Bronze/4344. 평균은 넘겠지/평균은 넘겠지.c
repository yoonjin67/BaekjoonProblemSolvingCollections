#include<stdio.h>
#include<stdlib.h>
int main()
{
    register short n,i;
    float average,result;
    short x,people,*ptr;
    scanf("%hd",&x);
    float result_arr[x];
    for(n=0;n<x;n++)
    {
        average=0;
        result=0;
        scanf("%hd",&people);
        switch(n)
    {
        case 0:
            ptr=malloc(people*sizeof(short));
            break;
        default:
            realloc(ptr,people*sizeof(short));
            break;
    }
        for(i=0;i<people;i++)
        {
            scanf("%hd",ptr+i);
            average+=ptr[i];
        }
        average/=people;
        for(i=0;i<people;i++)
            if(ptr[i]>average)
                result++;
        result/=people;
        result_arr[n]=result*100;
    }
for(n=0;n<x;n++)
    printf("%.3f%\n", result_arr[n]);
free(ptr);
 return 0;
}
