#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> stairs;
vector<int> DP;
void dp(int i) {
    DP[i] = stairs[i]+max(DP[i-2],stairs[i-1]+DP[i-3]);
}
int main() {
    int n;
    cin >> n;
    stairs = vector<int>(n,0);
    DP = vector<int>(n,0);
    for(auto &c:stairs) cin >> c;
    DP = stairs;
    DP[2] = stairs[2]+max(stairs[1],stairs[0]);
    DP[1] = stairs[1]+stairs[0];
    if(n>=3) {
        for(int i = 3; i < n; i++) {
            dp(i);
        }
    }
    cout << DP[n-1];
    return 0;
}