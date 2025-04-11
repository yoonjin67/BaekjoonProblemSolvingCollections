#include<iostream>
#include<unordered_map>
using namespace std;

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    unordered_map<int,int> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(m[x]) {
            m[x]++;
        } else {
            m[x] = 1;
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << m[x];
        if(i!=-1) cout << " ";
    }
    return 0;
}