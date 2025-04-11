#include<stdio.h>

int compare(const void *a, const void *b) {
    return (*(const int *)a-*(const int *)b)>0?1:0;
}

int main() {
    int X, i;
    /*
     I am following c90 standard!
     So All variables should be
     declared above functions. 
     */
    scanf("%d", &X);
    int array_sort[X];
    for(i=0;i<X;i++) {
        scanf("%d",array_sort+i);
    }
    
    qsort(array_sort, X, sizeof(int), compare);
    
    for(i=0;i<X;i++) {
        printf("%d\n", *(array_sort+i));
    }
    return 0;
    
}