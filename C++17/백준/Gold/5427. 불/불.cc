#include<iostream>
#include<vector>
#include<queue>
using namespace std;
constexpr int WALL = 2000000;
constexpr int AVAIL = 1000000;
typedef pair<int,int> point;
vector<point> fires;
vector<vector<int>> fire_dist;
vector<vector<int>> sk_dist;
int Y_MAX = 0;
int X_MAX = 0;
int dy[4] = { -1 , 1 , 0 , 0};
int dx[4] = {  0,  0, -1 , 1};
bool avail(int y, int x) {
    if(y<0 or y>=Y_MAX) return false;
    if(x<0 or x>=X_MAX) return false;
    if(fire_dist[y][x]==WALL) return false;
    return true;
}
void bfs_fire() {
    queue<point> q;
    for(auto p:fires) {
        fire_dist[p.first][p.second] = 1;
        q.push(p);
    }
    while(q.size()) {
        point p = q.front();
        q.pop();
        int y = p.first, x = p.second;
        for(int i = 0; i < 4; i++) {
            int ny = y+dy[i], nx = x+dx[i];
            if(avail(ny,nx)) {
                if(fire_dist[ny][nx]>fire_dist[y][x]+1) {
                    fire_dist[ny][nx] = fire_dist[y][x]+1;
                    q.push(make_pair(ny,nx));
                } else if(fire_dist[ny][nx]==AVAIL) {
                    fire_dist[ny][nx] = fire_dist[y][x]+1;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
}
void bfs(int init_y, int init_x) {
    queue<point> q;
    q.push(make_pair(init_y,init_x));
    while(q.size()) {
        point p = q.front();
        q.pop();
        int y = p.first, x = p.second;
        for(int i = 0; i < 4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if(avail(ny,nx)) {
                if(sk_dist[ny][nx]>sk_dist[y][x]+1) {
                    sk_dist[ny][nx] = sk_dist[y][x]+1;
                    q.push(make_pair(ny,nx));
                } else if (sk_dist[ny][nx]==AVAIL) {
                    sk_dist[ny][nx] = sk_dist[y][x]+1;
                    q.push(make_pair(ny,nx));
                }

            }
        }
    }
}
int main() {
    int rep, init_x, init_y;
    cin >> rep;
    for(int i = 0; i < rep; i++) {
        cin >> X_MAX >> Y_MAX;
        sk_dist = vector<vector<int>>(Y_MAX,vector<int>(X_MAX,AVAIL));
        fire_dist = vector<vector<int>>(Y_MAX,vector<int>(X_MAX,AVAIL));
        for(int j = 0; j < Y_MAX; j++) {
            string s;
            cin >> s;
            for(int k = 0; k < X_MAX; k++) {
                if(s[k] == '#') {
                    fire_dist[j][k] = WALL;
                    sk_dist[j][k] = WALL;
                } else if(s[k]=='*') {
                    fires.push_back(make_pair(j,k));
                } else if(s[k] == '@') {
                    sk_dist[j][k] = 1;
                    init_x = k;
                    init_y = j;
                }
            }
        }
        bfs_fire();
        bfs(init_y,init_x);
        priority_queue<int,vector<int>,greater<int>> times;
        for(int j = 0; j < Y_MAX; j++) {
            if(j==0 or j == Y_MAX-1) {
                for(int k = 0; k < X_MAX; k++) {
                    if(WALL==sk_dist[j][k]) continue;
                    if(sk_dist[j][k]>=fire_dist[j][k]) continue;
                    times.push(sk_dist[j][k]);
                }
            } else {
                if(WALL!=sk_dist[j][0] and sk_dist[j][0]<fire_dist[j][0]) times.push(sk_dist[j][0]);
                if(WALL!=sk_dist[j][X_MAX-1] and sk_dist[j][X_MAX-1]<fire_dist[j][X_MAX-1]) times.push(sk_dist[j][X_MAX-1]);
            }
        }
        if(times.size()==0) {
            cout << "IMPOSSIBLE";
        } else {
            cout << times.top();
        }
        if(i!=rep-1) {
            cout << '\n';
        }
        while(times.size()) {
            times.pop();
        }
        fires.clear();
        fire_dist.clear();
        sk_dist.clear();
    }
    return 0;
}