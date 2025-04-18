#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll MOD = 1000000000;
ll n;
int main() {
    cin >> n;
    ll dp[n][10];
    memset(dp,0,sizeof(dp));
    for(ll i = 1; i < 10; i++) dp[0][i] = 1;
    for(ll i = 1; i < n; i++) {
                dp[i][0] = dp[i-1][1];
        for(ll j = 1; j < 9; j++) {
            dp[i][j] = dp[i-1][j-1]%MOD+dp[i-1][j+1]%MOD;
            dp[i][j]%=MOD;
        }
                dp[i][9] = dp[i-1][8];
    }
    ll sum = 0;
    for(ll i = 0; i < 10; i++) {
                sum+=dp[n-1][i];
    }
    sum %= MOD;
    cout << sum;
}