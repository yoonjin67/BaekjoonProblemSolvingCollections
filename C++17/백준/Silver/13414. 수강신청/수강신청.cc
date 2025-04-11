#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
bool cmp(pair<string,int> p1, pair<string,int> p2) {
    return p1.second < p2.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  unordered_map<string,int> succeed;
  int attend_max, student_len;
  cin >> attend_max >> student_len;
  for(int i = 1; i <= student_len; i++) {
    string student_id;
    cin >> student_id;
    succeed[student_id]=i;
  }
  int students = 0;
  int key = 1;
  vector<pair<string,int>> v = vector<pair<string,int>> (succeed.begin(), succeed.end());
  sort(v.begin(),v.end(),cmp);
  for(int i = 0; i < attend_max; i++) {
      if(!(i-v.size())) break;
      cout << v[i].first << '\n';
  }
  v.clear();
  succeed.clear();
  return 0;
}