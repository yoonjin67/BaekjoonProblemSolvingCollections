#include<iostream>
#include<queue>
using namespace std;
int main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            pq.push(x);
        }
        while(pq.size()>n) {
            pq.pop();
        }
    }
    cout << pq.top();
    return 0;
}
