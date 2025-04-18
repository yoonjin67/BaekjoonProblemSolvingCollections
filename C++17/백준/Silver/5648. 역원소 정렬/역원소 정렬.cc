#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<long> v;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        reverse(str.begin(),str.end());
        v.push_back(stol(str));
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }
    return 0;
}