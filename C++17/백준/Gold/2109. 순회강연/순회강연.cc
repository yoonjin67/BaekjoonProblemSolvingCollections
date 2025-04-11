#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
int main() {
    int n;
    scanf("%d",&n);
    priority_queue<pii,vector<pii>,greater<pii>> store; 
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 1; i <= n; i++) {
        int pay, days;
        scanf("%d %d",&pay,&days);
        store.push(make_pair(days,pay)); //우선순위 큐(오름차)에 넣어서 정렬에 소모되는 시간을 단축
        //또한 날짜을 정렬 파라미터로 사용. (first=day임)
    }
    int sum = 0;
    while(store.size()) {
        pii val = store.top();
        pq.push(val.second); //날짜 순으로 오름차순으로 정렬된 우선순위 큐에서 수업료을 차례대로 가져와서 push
        if(val.first < (int)pq.size()) {
            pq.pop(); //현 시간이 기한을 넘길 시에는 싼 수업료 pop
        }
        store.pop();
    }
    while(pq.size()) {
        sum += pq.top(); //답에 알맞은 해만 남았으니 다 더해주면 됨.
        pq.pop();
    }
    printf("%d",sum);
    return 0;
}
