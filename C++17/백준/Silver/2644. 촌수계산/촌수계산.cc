#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> v;
vector<int> visited;
int rel = 0;

void dfs(int x, int target, int depth) {
  if(visited[x]) return;
  rel++;
  visited[x] = depth;
  if(x == target) return;
  for(auto r:v[x]) {
    dfs(r,target,depth+1);
  }
}

int main() {
  int n;
  cin >> n;
  v = vector<vector<int>>(n,vector<int>());
  visited = vector<int>(n,0);
  int x, target;
  cin >> x >> target;
  x--;
  target--;
  int m;
  cin >> m;
  for(int i = 0; i < m; i++) {
    int parent, child;
    cin >> parent >> child;
    parent--;
    child--;
    v[parent].push_back(child);
    v[child].push_back(parent);
  }
  dfs(x,target,0);
  rel = visited[target];
  if(rel==0) {
    cout << "-1";
    return 0;
  }
  cout << rel;

  return 0;
}