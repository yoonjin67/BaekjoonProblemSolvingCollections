#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> point;
vector<vector<int> > board;
vector<vector<bool> > visited;
int board_size;
constexpr int DEFAULT_VAL = 1000000;
point dest;
vector<point> coords;
void initialize_coords() {
  coords.push_back(make_pair(-2,-1));
  coords.push_back(make_pair(2,-1));
  coords.push_back(make_pair(2,1));
  coords.push_back(make_pair(-2,1));
  coords.push_back(make_pair(-1,-2));
  coords.push_back(make_pair(1,-2));
  coords.push_back(make_pair(1,2));
  coords.push_back(make_pair(-1,2));
}
bool avail(point p) {
  if(p.first<0 or p.first>=board_size) return false;
  if(p.second<0 or p.second>=board_size) return false;
  return !visited[p.first][p.second];

}
void bfs(point p) {
  if(!avail(p)) return;
  board[p.first][p.second] = 0;
  queue<point> q;
  q.push(p);
  while(q.size()) {
    point cur = q.front();
    visited[cur.first][cur.second] = true;
    q.pop();
    if(dest == cur) return;
    for(auto cor:coords) {
      point np = make_pair(cur.first+cor.first,cur.second+cor.second);
      if(avail(np)) {
        visited[np.first][np.second] = true;
        board[np.first][np.second] = min(board[np.first][np.second],board[cur.first][cur.second]+1);
        q.push(np);
      }
    }
  }
  return; //it should not be printed
}

int main() {
  initialize_coords();
  int rep;
  cin >> rep;
  for(int i = 0; i < rep; i++) {
    cin >> board_size;
    board = vector<vector<int>>(board_size,vector<int>(board_size,DEFAULT_VAL));
    visited = vector<vector<bool>>(board_size,vector<bool>(board_size,false));
    point p;
    cin >> p.second >> p.first;
    cin >> dest.second >> dest.first;
    bfs(p);
    cout << board[dest.first][dest.second];
    if(i!=rep-1) {
      cout << endl;
    }
  }
  return 0;
}