#include<stdlib.h>
#include<stdio.h>
typedef struct Tuple{
    int x, y;
} tpl;
int compare(const void *a, const void *b) {
    tpl A = *(tpl *)a;
    tpl B = *(tpl *)b;
    if(A.y!=B.y) {
        return A.y-B.y;
    } else {
        return A.x-B.x;
    }
}


int main(void) {
    int N;
    scanf("%d",&N);
    tpl arr[N];
    int i;
    for(i=0;i<N;i++){
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    qsort(arr,N,sizeof(tpl),compare);
    for(i=0;i<N;i++){
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
    return 0;
}
    
