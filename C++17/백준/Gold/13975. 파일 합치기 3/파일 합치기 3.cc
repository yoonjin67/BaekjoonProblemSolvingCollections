#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
int main() {
    ll T;
    scanf("%lld",&T);
    priority_queue<ll,vector<ll>,greater<ll>> q;
    for(int i = 0; i < T; i++) {
        ll len;
        scanf("%lld",&len);
        for(auto i =0; i<len; i++) {
            ll p;
            scanf("%lld",&p);
            q.push(p);
        }
        ll res = 0;
        while(q.size()>1) {
            ll tmp1 = 0, tmp2 = 0;
            if(q.size()) {
                tmp1 = q.top();
                q.pop();
            }
            if(q.size()) {
                tmp2 = q.top();
                q.pop();
            }
                res += tmp1+tmp2;
                q.push(tmp1+tmp2);
        }
        printf("%lld\n",res);
        while(q.size()) q.pop();
    }
}