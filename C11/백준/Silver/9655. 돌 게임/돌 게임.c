#include <stdio.h>
int main() {
    int i;
    scanf("%d",&i);
    if(i%4==2 ||!(i%4)) {
        printf("CY");
        return 0;
    }
        printf("SK");
    return 0;
}