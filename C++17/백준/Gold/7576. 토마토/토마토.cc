#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>> tomatoes;
vector<vector<int>> days;
vector<vector<bool>> visited;
vector<pair<int,int>> coord;
vector<pair<int,int>> startPoints;
int N,M;

void push_coord(int x,int y) {
    coord.push_back(make_pair(x,y));
}

void initialize_coordination() {
    push_coord(-1,0);
    push_coord(1,0);
    push_coord(0,-1);
    push_coord(0,1);
}

bool avail(int x,int y) {
    if(x<0 or x>=N) return false;
    if(y<0 or y>=M) return false;
    if(tomatoes[x][y] == -1) return false;
    if(tomatoes[x][y] == 1) return false;
    if(visited[x][y]) return false;
    return true;
}

void bfs() {
    queue<pair<int,int>> q;
    for(auto p: startPoints) {
        int i = p.first, j = p.second;
        q.push(make_pair(i,j));
        days[i][j] = 0;
    }
    while(!q.empty()) {
        pair<int,int> p = q.front();
        int x = p.first, y = p.second;
        tomatoes[x][y] = 2;
        visited[x][y] = true;
        q.pop();
        for(auto pos:coord) {
            int nx = x+pos.first;
            int ny = y+pos.second;
            if(avail(nx,ny)) {
                if(days[nx][ny]==-2) days[nx][ny] =days[x][y]+1;
                days[nx][ny] = min(days[nx][ny],days[x][y]+1);
                visited[nx][ny] = true;
                tomatoes[nx][ny] = 2;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main() {
    initialize_coordination();
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        tomatoes.push_back(vector<int>());
        days.push_back(vector<int>());
        visited.push_back(vector<bool>());
        for(int j = 0; j < M; j++) {
            int x;
            cin >> x;
            tomatoes[i].push_back(x);
            if(x == -1) {
                days[i].push_back(-1);
            } else {
                days[i].push_back(-2);
            }
            if(x == 1) startPoints.push_back(make_pair(i,j));
            visited[i].push_back(false);
        }
    }

    int res = 0;

    bfs();
    for(auto row:days) {
        sort(row.begin(),row.end());
        if(row[0] == -2) {
            cout << "-1" ;
            return 0;
        }
        res = max(row[M-1],res);
    }
    cout << res;
    return 0;
}