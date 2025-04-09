#include<iostream>
#include<vector>

using namespace std;

int n;
int m;
vector<int> s;
vector<bool> v;
void dfs(int cnt) {
    if(m==cnt) {
        for(int i = 0; i < m; i++) {
            cout << s[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        s[cnt] = i;
        dfs(cnt+1);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        s.push_back(i);
        v.push_back(false);
    }
    dfs(0);
    return 0;
}