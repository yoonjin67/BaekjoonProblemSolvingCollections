#include<iostream>
#include<queue>
#include<cstdlib>
#include<functional>
class Compare{
    public:
        bool operator() (int a,int b) {
            if (abs(a)<abs(b)) {
                return false;
            } else if (abs(a)==abs(b)) {
                if (a<0) {
                    return false;
                } else {
                    return true;
                }
            } else {
                return true;
            }
        }
};
using namespace std;
int main () {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    priority_queue<int,vector<int>,Compare> q;
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
