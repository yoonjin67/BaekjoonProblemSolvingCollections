#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int item;
        cin >> item;
        v.push_back(item);
    }
    vector<int> orig_v = v;
    if(!next_permutation(v.begin(),v.end())) {
        cout << -1;
        return 0;
    }
    for(auto c: v) {
        cout << c << ' ';
    }
    return 0;
}