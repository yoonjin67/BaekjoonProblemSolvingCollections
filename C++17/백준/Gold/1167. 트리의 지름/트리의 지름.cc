#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
vector<pii> *childs;
bool * visited;
int n;
int far_nd = 0;
int _dist = 0;
void traverse(int nd, int dist) {
    if(visited[nd]) return;
    if(dist>_dist) {
        far_nd = nd;
        _dist = dist;
    }
    visited[nd] = true;
    for(auto nxt:childs[nd]) {
        int nxt_nd = nxt.first;
        int nxt_dist = nxt.second;
        if(!visited[nxt_nd]) traverse(nxt_nd,nxt_dist+dist);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    childs = new vector<pii>[n+1];
    visited = new bool[n+1];
    for(int i = 0; i < n; i++) {
        int start, end, dist;
        cin >> start;
        while(true) {
            cin >> end;
            if(end == -1) break;
            cin >> dist;
            childs[start].push_back(make_pair(end,dist));
        }
    }
    traverse(1,0);
    memset(visited,0,sizeof(bool)*(n+1));
    traverse(far_nd,0);
    cout << _dist;
    return 0;
}