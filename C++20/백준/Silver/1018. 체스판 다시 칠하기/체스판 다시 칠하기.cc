#include<iostream>
#include<vector>
using namespace std;
namespace problem_1018 {
  short x_len, y_len, c = 0, startx = 0, starty = 0;
  short cnt =0;
  vector<vector<char>> ch;
  vector<vector<char>> a[2];
  vector<vector<bool>> diff[2];
  vector<vector<bool>> v;
  void solve();
  pair<short,short> reset_ch();
  bool avail(short x,short y);
  void dfs(short x,short y);
};
short min(short a, short b) {
  return a>b?b:a;
}
using namespace problem_1018;
bool problem_1018::avail(short y, short x) {
  if(y<starty or y>=starty+8) return false;
  if(x<startx or x>=startx+8) return false;
  return !v[y][x];
}
void problem_1018::dfs(short y, short x) {
  if(diff[c][y][x] and !v[y][x]) cnt++;
  v[y][x] = true;
  static char dx[4] = {-1,1,0,0}, dy[4]{0,0,-1,1};
  for(short i = 0; i < 4; i++) {
    short nx = dx[i]+x, ny = dy[i]+y;
    if(avail(ny,nx)) {
      dfs(ny,nx);
    }
  }
}
pair<short,short> problem_1018::reset_ch() {
  short d = 0, d1 = 0;
  ch = vector<vector<char>>(y_len,vector<char>(x_len,'W'));
  a[0] = vector<vector<char>>(y_len,vector<char>(x_len,'W'));
  a[1] = vector<vector<char>>(y_len,vector<char>(x_len,'B'));
  diff[0] = vector<vector<bool>>(y_len,vector<bool>(x_len,false));
  diff[1] = vector<vector<bool>>(y_len,vector<bool>(x_len,false));
  v = vector<vector<bool>>(y_len,vector<bool>(x_len,false));
  for(short i = 0; i < y_len; i++) {
    string s;
    bool chess_color = !(i%2);
    cin >> s;
    for(short j = 0; j < x_len; j++) {
      ch[i][j] = s[j];
      a[0][i][j] = (bool)(j%2)==chess_color?'B':'W';
      a[1][i][j] = (bool)(j%2)==chess_color?'W':'B';
      diff[0][i][j] = a[0][i][j] != ch[i][j];
      diff[1][i][j] = a[1][i][j] != ch[i][j];
      if(diff[0][i][j]) d++;
      if(diff[1][i][j]) d1++;
    }
  }
  return make_pair(d,d1);
}

void problem_1018::solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> y_len >> x_len;
  pair<short,short> p = reset_ch();
  if(p.first==0 or p.second ==0) {
    return;
  }
  short m = 51*51;
  for(c = 0; c < 2; c++) {
    for(short i = 0; i < y_len; i++) {
      for(short j = 0; j < x_len; j++) {
        startx = j;
        starty = i;
        if(startx+7<x_len and starty+7<y_len) {
          v = vector<vector<bool>>(y_len,vector<bool>(x_len,false));
          if(!avail(i,j)) continue;
          cnt = 0;
          dfs(i,j);
          m = min(cnt,m);
        }
      }
    }
  }
  cnt = m;
}
int main() {
  solve();
  cout << cnt;
  return 0;
}
