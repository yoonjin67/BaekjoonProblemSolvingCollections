#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> s, v;
    for(int i = 1; i <= n; i++) {
        s.push_back(i);
        v.push_back(0);
    }
    for(int i = 0; i < m; i++) {
        v[i] = 1;
    }
    do {
        for(int i = 0; i < n; i++) {
            if(v[i]) cout << s[i] << ' ';
        }
        cout << '\n';
    } while(prev_permutation(v.begin(),v.end()));
    return 0;
}