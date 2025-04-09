#include<stdio.h>


int main() {
    int X,i;
    int n,t;
    /*
     I am following c90 standard!
     So All variables should be
     declared above functions. 
     */
    scanf("%d", &X);
    int array_sort[10000];
    memset(array_sort,0,sizeof(int)*10000);
    for(i=0;i<X;i++) {
        scanf("%d",&n);
        array_sort[n-1]++;
    }
    
    
    for(i=0;i<10000;i++) {
        for(t=0;t<array_sort[i];t++) {
            printf("%d\n", i+1);
        }
    }
    return 0;
    
}