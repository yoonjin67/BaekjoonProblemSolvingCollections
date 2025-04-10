#include <stdio.h>
int main() {
    int k;
    scanf("%d",&k);
    if(!(k%4)|(k%4==2)) {
        printf("SK");
    } else {
        printf("CY");
    }
    return 0;
}