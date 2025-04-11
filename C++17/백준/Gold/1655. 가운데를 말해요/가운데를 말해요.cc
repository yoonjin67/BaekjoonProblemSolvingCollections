#include<iostream>
#include<queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int,vector<int>,less<int>> q1; //최대 힙, 중간~중간보다 작은 것을 담을 것
    priority_queue<int,vector<int>,greater<int>> q2; //최소 힙, 중간보다 큰 것을 담을 것

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (q2.size()<q1.size()) {
            q2.push(x);
        } else {
            q1.push(x);
        }
        if(q1.size() and q2.size()) {
            if(q1.top()>q2.top()) {
                int q1top = q1.top();
                int q2top = q2.top();
                q2.pop();
                q1.pop();
                q1.push(q2top);
                q2.push(q1top);
                //경곗값 중 큰 것은 중간보다 큰 것으로 간주하고 이동!
            }
        }
        cout << q1.top() <<'\n';
    }
    return 0;
}