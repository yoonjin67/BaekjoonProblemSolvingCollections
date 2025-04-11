#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b)
{
    return *(double *)a - *(double *)b;
}
int main()
{
    int a,i;
    scanf("%d", &a);
    double arr[a];
    for(i=0;i<a;i++)
        scanf("%lf", arr+i);
    qsort(arr,sizeof(arr)/sizeof(double),sizeof(double),compare);
    double Max=arr[a-1], average=0;
    for(i=0;i<a;i++)
        average+=(arr[i]/Max*100)/a;
    printf("%lf", average);
    return 0;
}

