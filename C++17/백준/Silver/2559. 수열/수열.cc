#include<iostream>
#include<climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    short arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int sum = 0, res = INT_MIN;
    size_t start = -1;
    
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(i>=k) sum -= arr[++start];
        if(i-start == k) res = sum>res?sum:res;
    }
    cout << res;
    return 0;
}