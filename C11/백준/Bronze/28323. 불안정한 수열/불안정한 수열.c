#include<stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    int res = 1;
    for(int i = 1; i < n; i++) {
        if((arr[i-1]+arr[i])%2) res++;
    }
    printf("%d",res);
    return 0;
}