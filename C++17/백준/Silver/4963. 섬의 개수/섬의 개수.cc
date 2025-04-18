#include<iostream>
using namespace std;
int ** arr;
bool ** visited;
int X_MAX, Y_MAX;
int nxt[8][2] = {
  { 0, 1},
  { 1, 0},
  {-1 ,0},
  { 0,-1},
  { 1,-1},
  {-1, 1},
  { 1, 1},
  {-1,-1}

};
bool is_land(int y, int x) {
  if(x<0 or x>=X_MAX) return false;
  if(y<0 or y>=Y_MAX) return false;
  if(visited[y][x]) return false;
  return arr[y][x];
}
void dfs(int y, int x) {
  if(is_land(y,x) == false) return;
  visited[y][x] = true;
  for(int i = 0; i < 8; i++) {
    int nx = x+nxt[i][0], ny = y+nxt[i][1];
    if(is_land(ny,nx)) {
      dfs(ny,nx);
    }
  }
}
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  while(true) {
    cin >> X_MAX >> Y_MAX;
    if(X_MAX==0 && Y_MAX==0) break;
    arr = new int*[Y_MAX];
    visited = new bool*[Y_MAX];
    for(int i = 0; i < Y_MAX; i++){
      arr[i] = new int[X_MAX];
      visited[i] = new bool[X_MAX];
    }
    for(int y = 0; y < Y_MAX; y++) {
      for(int x = 0; x < X_MAX; x++) {
        cin >> arr[y][x];
        visited[y][x] = false;
      }
    }
    int cnt = 0;
    for(int y = 0; y < Y_MAX; y++) {
      for(int x = 0; x < X_MAX; x++) {
        if(is_land(y,x)) {
          dfs(y,x);
          cnt++;
        }
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}