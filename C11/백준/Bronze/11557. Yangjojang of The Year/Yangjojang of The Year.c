#include<stdio.h>
#include<stdlib.h>
typedef struct SCHOOL_INFO {
    char str[21];
    int  L;
} sch_info_t;
int compare(const void *a, const void *b) {
    return ((sch_info_t *)a)->L-
    ((sch_info_t *)b)->L;
}
int main() {
    int x,y;
    scanf("%d",&x);
    int i,j;
    for(i=0;i<x;i++) {
        scanf("%d",&y);
        sch_info_t arr[y];
        for(j=0;j<y;j++) {
            scanf("%s %d",arr[j].str,&arr[j].L);
        }
        qsort(arr,y,sizeof(sch_info_t),compare);
        puts(arr[y-1].str);
    }
    return 0;
}

