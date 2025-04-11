#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;
vector<int> s;
vector<bool> visited;
vector<int> v;
void dfs(int count) {
    if(count == m) {
        for(int i = 0; i < m; i++) {
            cout << s[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        s[count] = v[i];
        dfs(count+1);
    }
}
inline void input() {
    cin >> n >> m;
    s.resize(m);
    v.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        visited[i] = false;
    }
    sort(v.begin(),v.end());
}

int main() {
    input();
    dfs(0);
    return 0;
}