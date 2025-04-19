#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int N;
vector<vector<int>> coms;
vector<bool> visited;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,0};
int cnt = -1;
bool avail(int x, int y) {
  if(x<0 or x>=N) return false;
  if(y<0 or y>=N) return false;
  return coms[x][y];
}
void dfs(int node) {
  if(visited[node]) return;
  cnt++;
  visited[node] = true;
  for(auto p:coms[node]) {
    dfs(p);
  }
}
int main() {
  cin >> N;
  for(int i =0; i < N; i++) {
    coms.push_back(vector<int>());
    visited.push_back(false);
  }
  int M;
  cin >> M;
  for(int i = 0; i < M; i++) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    coms[x].push_back(y);
    coms[y].push_back(x);
  }
  dfs(0);
  cout << cnt;
  return 0;
}