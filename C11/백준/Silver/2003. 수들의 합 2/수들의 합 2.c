#include <stdio.h>
int main() {
    int n,m;
    scanf("%d %d", &n,&m);
    int i;
    int arr[n];
    int SUM = 0;
    for(i=0;i<n;i++)  {
        scanf("%d", arr+i);
    }

    SUM = 0;
    int * p = &arr[0], * t = &arr[0], cnt = 0;
    for(;p<=&arr[n-1];p++) {
        while(SUM<m && t<=&arr[n-1]) {
            SUM += *t;
            t++;
        }
        if(SUM==m) {
            cnt++;
        }
        SUM-=*p;

    }
    printf("%d",cnt);
    return 0;
}

