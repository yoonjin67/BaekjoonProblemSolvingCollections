#include<iostream>
using namespace std;
int main() {
    int n,res;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    res = arr[0];
    for(int i = 1; i < n; i++) {
        arr[i] += arr[i-1]+arr[i] > arr[i] ? arr[i-1] : 0; //더하는 게 진짜 기존보다 최대인지 검증.
        res = max(res,arr[i]); //최종 결과인 최대 연속합에 반영할지 여부도 마찬가지로 검증.
    }
    cout << res;
    return 0;
}