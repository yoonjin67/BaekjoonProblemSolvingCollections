#include <stdio.h>
int main () {
    unsigned int x=1,y=1;
    while(x+y) {
        scanf("%d %d",&x,&y);
        if(x+y) {
            printf("%d\n",x+y);
        }
    }
}