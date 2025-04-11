#include <stdio.h>

int main() {
    int i;
    scanf("%d",&i);

    if((i%7==3)|(i%7==1)) {
        printf("CY");
    } else {
        printf("SK");
    }
    return 0;
}