#include <stdio.h>
main() {
    int i,j,k;
    scanf("%d",&j);
    for(i=1;i<=j;i++) {
        int k;
        for(k=0;k<i;k++) {
            putchar('*');
        }
        if(k) {
          putchar('\n');
        }
    }
    i--;
    while(i>=0) {
        for(k=0;k<i-1;k++) {
            putchar('*');
        }
        i--;
        if(k) {
          putchar('\n');
        }
    }
}