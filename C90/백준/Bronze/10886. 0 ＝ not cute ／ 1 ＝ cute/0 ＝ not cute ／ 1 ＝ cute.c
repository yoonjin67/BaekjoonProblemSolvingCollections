#include<stdio.h>
main() {
    int x,rep,i,cnt=0;
    scanf("%d",&rep);
    for(i=0;i<rep;i++) {
        scanf("%d",&x);
        if(x) {
            cnt++;
        }
    }
    rep/=2;
    printf("Junhee is %s!", cnt>rep?"cute":"not cute");
          return 0;
}