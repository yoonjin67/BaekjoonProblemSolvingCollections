#include<stdio.h>

int compare(const void *a, const void *b) {
    return *(const long long *)a-*(const long long *)b;
}

int main() {
    int X, i;
    /*
     I am following c90 standard!
     So All variables should be
     declared above functions. 
     */
    scanf("%d", &X);
    long long array_sort[X];
    for(i=0;i<X;i++) {
        scanf("%lld",array_sort+i);
    }
    
    qsort(array_sort, X, sizeof(long long), compare);
    
    for(i=0;i<X;i++) {
        printf("%lld\n", *(array_sort+i));
    }
    return 0;
    
}