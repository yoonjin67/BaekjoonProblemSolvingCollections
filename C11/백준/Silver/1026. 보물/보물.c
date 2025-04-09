#include<stdio.h>
#include<stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *)a-*(int *)b;
}
int comp2(const void *a, const void *b) {
    return *(int *)b-*(int *)a;
}
void main() {
    int n;
    scanf("%d",&n);
    int i;
    int a[n],b[n];
    for(i = 0; i < n; i++) {
        scanf("%d",a+i);
    }
    for(i = 0; i < n; i++) {
        scanf("%d",b+i);
    }
    qsort(a,n,sizeof(int),comp);
    qsort(b,n,sizeof(int),comp2);
    int sum = 0;
    for(i = 0; i < n; i++) {
        sum += a[i]*b[i];
    }
    printf("%d",sum);
    exit(0);
}
