#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> citymap;
int cnt = 0;
int N = 0;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool avail(int x, int y) {
  if(x<0 or x>=N) return false;
  if(y<0 or y>=N) return false;
  return citymap[x][y] == 1;
}

void dfs(int x, int y) {
  cnt++;
  citymap[x][y]=0;
  for(int i = 0; i < 4; i++) {
    int nx = x+dx[i], ny = y+dy[i];
    if(avail(nx,ny)) {
      citymap[nx][ny] = 0;
      dfs(nx,ny);
    }
  }
}

int main() {
  cin >> N;
  citymap = vector<vector<int>>(N,vector<int>(N,1));
  vector<int> answer;
  for(int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < N; j++) {
      citymap[i][j] = s[j]-'0';
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(citymap[i][j]) {
        dfs(i,j);
        answer.push_back(cnt);
        cnt = 0;
      }
    }
  }
  sort(answer.begin(),answer.end());
  cout << answer.size() << endl;
  for(auto p:answer) {
    cout << p << '\n';
  }
  return 0;
}