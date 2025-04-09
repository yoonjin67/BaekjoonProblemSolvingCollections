#include<iostream>
#include<set>
using namespace std;
int main () {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  size_t input_len = s.length();
  set<string> ans;
  for(int i = 0; i < input_len; i++) {
    for(int j = i; j < input_len; j++) {
      string sub = s.substr(i,j-i+1); // substr은 시작 위치부터 해서 두번째 요소만큼의 길이를 썰어줌.
                                      // 문자열 =7 , i = 3일때를 예로 들면 1,2,3,4.
      if(sub.length()) {
        ans.insert(sub);
      }
    }
  }
  cout << ans.size();
  ans.clear();
  return 0;
}