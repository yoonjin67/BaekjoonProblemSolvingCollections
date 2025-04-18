#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct coordinate {
  int x;
  int y;
  int z;
} coord;

vector<vector<vector<int>>> building;
vector<vector<vector<int>>> visited;
int x_len, y_len, z_len;

int nxt[6][3] = {
  {1,0,0},
  {0,1,0},
  {0,0,1},
  {-1,0,0},
  {0,-1,0},
  {0,0,-1}
};


bool is_avail(coord c) {
  if(c.x<0 or c.x>=x_len) return false;
  if(c.y<0 or c.y>=y_len) return false;
  if(c.z<0 or c.z>=z_len) return false;
  return true;
}

int bfs(coord startpoint) {
  queue<coord> q;
  q.push(startpoint);
  coord cur = startpoint;
  visited[cur.z][cur.y][cur.x] = 1;
  while(q.size()) {
    cur = q.front();
    q.pop();
    for(int i = 0; i < 6; i++) {
      int nz= cur.z+nxt[i][0], ny = cur.y+nxt[i][1], nx = cur.x+nxt[i][2];
      coord pnt;
      pnt.x = nx;
      pnt.y = ny;
      pnt.z = nz;
      if(!is_avail(pnt)) continue;
      if(building[nz][ny][nx] == '#') continue;
      if(visited[nz][ny][nx]) continue;
      visited[nz][ny][nx] = visited[cur.z][cur.y][cur.x]+1;
      if(building[nz][ny][nx] == 'E') {
        return visited[nz][ny][nx];
      }
      q.push(pnt);
    }
  }
  return -1;
}


int main() {
  while(true) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    coord startpoint;
    cin >> z_len >> y_len >> x_len;
    if(z_len == 0 and y_len == z_len and x_len == y_len) break;
    building = vector<vector<vector<int>>>(z_len,vector<vector<int>>(y_len,vector<int>(x_len,0)));
    visited = vector<vector<vector<int>>>(z_len,vector<vector<int>>(y_len,vector<int>(x_len,0)));
    for(int i = 0; i < z_len; i++) {
      for(int j = 0; j < y_len; j++) {
        string s;
        cin >> s;
        for(int k = 0; k < x_len; k++) {
          building[i][j][k] = s[k];
          if(s[k] == 'S') {
            startpoint.x = k;
            startpoint.y = j;
            startpoint.z = i;
          }
        }
      }
    }
    int res = bfs(startpoint);
    res --;
    if(res<0) {
      cout << "Trapped!\n";

    } else {
      cout << "Escaped in " << res << " minute(s).\n";
    }
  }
  return 0;
}