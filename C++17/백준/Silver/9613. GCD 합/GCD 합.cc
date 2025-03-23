#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        ll len;
        cin >> len;
        vector<ll> v(len);
        for(ll j = 0; j < len; j++) {
            cin >> v[j];
        }
        ll sum = 0;
        for(ll i = 0; i < len; i++) {
            for(ll j = i+1; j < len; j++) {
                sum += gcd(v[i],v[j]);
            }
        }
        cout << sum << '\n';
    }
}
