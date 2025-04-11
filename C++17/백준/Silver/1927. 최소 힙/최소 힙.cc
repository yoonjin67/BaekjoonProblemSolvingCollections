#include<iostream>
#include<queue>
#include<functional>
using namespace std;
int main () {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    priority_queue<int,vector<int>,greater<int>> q;
    int rep;
    scanf("%d",&rep);
    for(int i=0;i<rep;i++) {
        int v;
        scanf("%d",&v);
        if(v!=0) {
            q.push(v);
        }
        else {
            if(!q.empty()) {
                printf("%d\n",q.top());
                q.pop();
            } else {
                puts("0");
            }
        }
    }
    return 0;
}
