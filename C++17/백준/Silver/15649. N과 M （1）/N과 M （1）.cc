#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> s, v;
    vector<string> r;
    for(int i = 1; i <= n; i++) {
        s.push_back(i);
        v.push_back(0);
    }
    for(int i = 0; i < m; i++) {
        v[i] = 1;
    }
    do {
        vector<int> in;
        for(int i = 0; i < n; i++) {
            if(v[i]) in.push_back(s[i]);
        }
        do {
            ostringstream o;
            for(auto it:in) {
                o << it << ' ';
            }
            r.push_back(o.str());
        } while(next_permutation(in.begin(),in.end()));
    } while(prev_permutation(v.begin(),v.end()));
    sort(r.begin(),r.end());
    for(auto str:r) {
        cout << str << '\n';
    }
    return 0;
}