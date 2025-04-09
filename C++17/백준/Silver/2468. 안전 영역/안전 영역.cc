#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
int survived = 0;
constexpr int VISITED = -1;
vector<vector<int>> area;
vector<pair<int,int>> coords;
void initialize() {
    coords.push_back(make_pair(-1,0));
    coords.push_back(make_pair(1,0));
    coords.push_back(make_pair(0,-1));
    coords.push_back(make_pair(0,1));
    area = vector<vector<int>>(N,vector<int>(N,0));
}
int rain = 0;
bool avail(int x, int y) {
    if(x<0 or x>=N) return false;
    if(y<0 or y>=N) return false;
    if(area[x][y] == -1) return false;
    if(area[x][y]<=rain) return false;
    return true;
}
void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(q.size()) {
        pair<int,int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        area[x][y] = VISITED;
        for(auto p:coords) {
            int nx = x+p.first, ny = y+p.second;
            if(avail(nx,ny)) {
                area[nx][ny] = VISITED;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
int main() {
    cin >> N;
    int MAX = 0;
    initialize();
    for(auto &rows:area) {
        for(auto &cols:rows) {
           cin >> cols; 
           MAX = max(cols,MAX);
        }
    }
    vector<vector<int>> initial_state = area;
    for(rain = 0; rain < MAX; rain++) {
        int available = 0;
        for(int i = 0; i < N; i++) {
            for(auto j = 0; j < N; j++) {
                if(area[i][j]!=-1 and area[i][j]>rain) {
                    available++;
                    bfs(i,j);
                }
            }
        }
        area = initial_state;
        survived = max(available, survived);
    }
    cout << survived;
    return 0;
}