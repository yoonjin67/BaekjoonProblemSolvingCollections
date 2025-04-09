#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    unordered_map<string,bool> map;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        map[s] = true;
    }
    int res = 0;
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if(map[s]==true) {
            res++;
        }
    }
    cout << res;
}