#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,m;
    scanf("%d %d", &n,&m);
    int i;
    short arr[n];
    int SUM = 0;
    for(i=0;i<n;i++)  {
        scanf("%hd", arr+i);
    }
    SUM = 0;
    int len = 0;
    short * p = &arr[0], * t = &arr[0], cnt = 0;
    for(;p<=&arr[n-1];p++) {
        while(SUM<m && t<=&arr[n-1]) {
            SUM += *t;
            t++;
        }
        if(SUM>=m) {
            cnt++;
            if(!len) {
                len = abs(p-t);
            } else {
                len = len<abs(p-t)?len:abs(p-t);
            }
        }
        SUM-=*p;
    }
    printf("%d",len);
    return 0;
}