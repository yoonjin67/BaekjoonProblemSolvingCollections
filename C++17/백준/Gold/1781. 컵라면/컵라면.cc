#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<pii,vector<pii>,greater<pii>> store;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 1; i <= n; i++) {
        int dline, cups;
        cin >> dline >> cups;
        store.push(make_pair(dline,cups));
    }
    int sum = 0;
    while(store.size()) {
        pii val = store.top();
        pq.push(val.second); //데드라인 순으로 오름차순으로 정렬된 거 삽입
        if(val.first < (int)pq.size()) {
            pq.pop(); //현 시간이 데드라인을 넘길 시에는 컵라면 작은거 pop
        }
        store.pop();
    }
    while(pq.size()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
    return 0;
}
