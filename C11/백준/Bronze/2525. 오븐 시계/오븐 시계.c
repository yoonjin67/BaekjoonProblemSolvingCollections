#include <stdio.h>
#include <time.h>

int main() {
    int H,M,ADD;
    scanf("%d %d\n%d",&H,&M,&ADD);
    M+=ADD;
    H+=M/60;
    H%=24;
    M%=60;
    printf("%d %d", H,M);
    return 0;
}