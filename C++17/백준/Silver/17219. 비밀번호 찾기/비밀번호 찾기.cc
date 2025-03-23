#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n,m;
  unordered_map<string,string> map;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    string key, value;
    cin >> key >> value;
    map[key] = value;
  }
  for(int i = 0; i < m; i++) {
    string key;
    cin >> key;
    cout << map[key] << '\n';
  }
  return 0;
}