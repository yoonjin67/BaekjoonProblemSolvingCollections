#include<iostream>
#include<vector>

using namespace std;

int n;
int m;
vector<int> s;
vector<bool> v;
void dfs(int cnt) {
    if(m==cnt-1) {
        for(int i = 1; i <= m; i++) {
            cout << s[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = s[cnt-1]; i <= n; i++) {
        s[cnt] = i;
        dfs(cnt+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    s.push_back(1);
    for(int i = 1; i <= n; i++) {
        s.push_back(i);
        v.push_back(false);
    }
    dfs(1);
    return 0;
}