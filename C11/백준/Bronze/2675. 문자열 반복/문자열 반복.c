#include <stdio.h>
#include <string.h>
void string_rep() {
    int a,i,j;
    scanf("%d",&a);
    char str[512];
    scanf("%s",str);
    for(i=0;i<strlen(str);i++) {
        for(j=0;j<a;j++) {
            putchar(str[i]);
        }
    }
    return;
}
int main() {
    int X;
    scanf("%d",&X);
    while(X>0) {
        string_rep();
        X--;
        putchar('\n');
    }
}