#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll> DP;
void dp(int N) {
    if(N<2) return;
    vector<int> perm;
    for(int i = 0; i < N; i++) {
        perm.push_back(i);
    }
    for(int i = 0; i < N; i++) DP[N] += DP[i]*DP[N-1-i];
}
int main() {
   int N;
   cin >> N; 
   DP = vector<ll>(N+1,0);
   DP[0] = 1;
   DP[1] = 1;
   for(int i = 2; i <= N; i++) dp(i);
   cout << DP[N];
}