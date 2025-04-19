//이딴 문제로 chatgpt를 쓴 내가 한심하다.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pii;

int **map;
bool **visited;
vector<pii> virus;
int ny[4] = {0,0,-1,1};
int nx[4] = {-1,1,0,0};
int ans = 0;

int Y, X;

bool is_avail(int y, int x) {
    if(y>=Y) return false;
    if(x>=X) return false;
    if(x<0) return false;
    if(y<0) return false;
    if(map[y][x] == 1) return false;
    return !visited[y][x];
}

void bfs() {
    queue<pii> q;
    int **map_tmp = new int*[Y];
    bool **visited_tmp = new bool*[Y];

    for(int i = 0; i < Y; i++) {
        map_tmp[i] = new int[X];
        visited_tmp[i] = new bool[X];
        for(int j = 0; j < X; j++) {
            map_tmp[i][j] = map[i][j];
            visited_tmp[i][j] = visited[i][j];
        }
    } //문제가 안 풀렸던 게 이딴 노가다성 작업을 피하려다 그랬다고?
    //memcpy는 역시 익숙하지 않으니 안 쓰는게 낫나

    for(auto p:virus) {
        q.push(p);
        visited_tmp[p.first][p.second] = true;
    }

    while(q.size()) {
        pii p = q.front();
        visited_tmp[p.first][p.second] = true;
        map_tmp[p.first][p.second] = 2;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nxt_y = p.first+ny[i], nxt_x = p.second+nx[i];
            pii nxt = make_pair(nxt_y,nxt_x);
            if(is_avail(nxt_y,nxt_x) && !visited_tmp[nxt_y][nxt_x]) {
                visited_tmp[nxt_y][nxt_x] = true;
                map_tmp[nxt_y][nxt_x] = 2;
                q.push(nxt);
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < Y; i++) {
        for(int j = 0; j < X; j++) {
            if(map_tmp[i][j] == 0) cnt++;
        }
    }
    ans = max(cnt, ans);

    for(int i = 0; i < Y; i++) {
        delete[] map_tmp[i];
        delete[] visited_tmp[i];
    }
    delete[] map_tmp;
    delete[] visited_tmp;
}

void we_need_to_build_a_wall(int cnt) {
    if(cnt==3) {
        bfs();
        return;
    }
    for(int i = 0; i < Y; i++) {
        for(int j = 0; j < X; j++) {
            if(!map[i][j]) {
                map[i][j] = 1;
                we_need_to_build_a_wall(cnt+1);
                map[i][j] = 0;
            }
        }
    }
}
//이걸 재귀로 3군데 벽 짓고 브루트포스로 돌려보다니 정말 황당하다..

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> Y >> X;
    map = new int*[Y];
    visited = new bool*[Y];
    for(int i = 0; i < Y; i++) {
        map[i] = new int[X];
        visited[i] = new bool[X];
        for(int j = 0; j < X; j++) {
            cin >> map[i][j];
            visited[i][j] = false;
            if(map[i][j] == 2) virus.push_back(make_pair(i,j));
        }
    }
    we_need_to_build_a_wall(0);
    cout << ans;
    return 0;
}