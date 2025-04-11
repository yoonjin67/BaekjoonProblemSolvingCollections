#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int,int>> coord;
vector<vector<bool>> visited;
vector<vector<int>> dist;
vector<vector<int>> maze;
int N,M;
void bfs() {
    queue<pair<int,int>> q;
    pair<int,int> startPoint = make_pair(0,0);
    dist[0][0] = 1;
    q.push(startPoint);
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        maze[x][y] = 0;
        visited[x][y] = true;
        if (x+1==N and y+1 == M) return;
        for(auto p:coord) {
            int nx = x+p.first, ny = y+p.second;
            if(nx<0 or nx>=N) continue;
            if(ny<0 or ny>=M) continue;
            if(maze[nx][ny] == 0 or visited[nx][ny]) continue;
            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y]+1;
            q.push(make_pair(nx,ny));
        }   
    }
}

int main() {
    coord.push_back(make_pair(0,-1));
    coord.push_back(make_pair(0, 1));
    coord.push_back(make_pair(-1,0));
    coord.push_back(make_pair( 1,0));
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        maze.push_back(vector<int>());
        dist.push_back(vector<int>());
        visited.push_back(vector<bool>());
        string s;
        cin >> s;
        for(int j = 0; j < M; j++) {
            maze[i].push_back((int)s[j]-(int)'0');
            visited[i].push_back(false);
            dist[i].push_back(0);
        }
    }
    bfs();
    cout << dist[N-1][M-1];
}