#include<iostream>
#include<queue>
using namespace std;

typedef pair<int,int> pii;

int h, w;
int dx[4] = { 0,0,-1,1};
int dy[4] = {-1,1,0,0};
int ** dist;
char ** map;

bool is_avail(int x, int y) {
    if(x<0) return false;
    if(y<0) return false;
    if(x>=w) return false;
    if(y>=h) return false;
    return dist[x][y] == -1 && map[x][y] == 'L';
}

int bfs(int x, int y) {
    queue<pii> q;
    q.push(make_pair(x,y));
    dist[x][y] = 0;
    int fin_dist = 0;
    while(q.size()) {
        pii nd = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i]+nd.first, ny = dy[i]+nd.second;
            if(is_avail(nx,ny)) {
                dist[nx][ny] = dist[nd.first][nd.second]+1;
                fin_dist = max(fin_dist, dist[nx][ny]);
                q.push(make_pair(nx,ny));
            }
        }
    }
    return fin_dist;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> h >> w;
    dist = new int*[w];
    map = new char*[w];
    for(int i = 0; i < w; i++) {
        map[i] = new char[h];
        dist[i] = new int[h];
    }

    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            dist[i][j] = -1;
        }
    }
    for(int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < w; j++) {
            map[j][i] = s[j];
        }
    }
    int res = 0;
    for(int x = 0; x < w; x++) {
        for(int y = 0; y < h; y++) {
            if(is_avail(x,y)) {
                res = max(res, bfs(x,y));
                for(int i = 0; i < w; i++) {
                    for(int j = 0; j < h; j++) {
                        dist[i][j] = -1;
                    }
                }
            }
        }
    }
    cout << res;
    return 0;
}