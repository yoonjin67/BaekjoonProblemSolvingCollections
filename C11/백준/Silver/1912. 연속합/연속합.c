#include<stdio.h>
int main() {
    int n,res;
    scanf("%d",&n);
    int arr[n];
    register int i;
    for(i = 0; i < n; i++) scanf("%d", arr+i);
    res = arr[0];
    for(i = 1; i < n; i++) {
        arr[i] += arr[i-1]+arr[i] > arr[i] ? arr[i-1] : 0; //더하는 게 진짜 기존보다 최대인지 검증.
        res = res>arr[i]?res:arr[i]; //최종 결과인 최대 연속합에 반영할지 여부도 마찬가지로 검증.
    }
    printf("%d",res);
    return 0;
}