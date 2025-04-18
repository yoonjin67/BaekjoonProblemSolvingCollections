#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b) {
    return *(int *)a-*(int *)b;
}
main () {
    int a[3];
    scanf("%d %d %d", a,a+1,a+2);
    qsort(a,3,sizeof(int),comp);
    printf("%d %d %d", a[0],a[1],a[2]);
    return 0;
}