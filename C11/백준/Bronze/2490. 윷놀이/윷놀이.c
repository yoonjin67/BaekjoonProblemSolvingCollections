#include<stdio.h>
void printStatus(int *arr) {
    int cnt=0, num,i;
    for(i=0;i<4;i++) {
        scanf("%d",&num);
        if(num==0) {
            cnt++;
        }
    }
    switch(cnt) {
    case 1:
        puts("A");
        break;
    case 2:
        puts("B");
        break;
    case 3:
        puts("C");
        break;
    case 4:
        puts("D");
        break;
    default:
        puts("E");
        break;            
    }
}

int main() {
    int i, *arr=malloc(sizeof(int)*4);
    for(i=0;i<3;i++) {
        printStatus(arr);
    }
    free(arr);
    return 0;
}