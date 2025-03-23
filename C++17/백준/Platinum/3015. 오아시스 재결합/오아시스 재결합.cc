#include<iostream>
#include<stack>
using namespace std;
typedef unsigned long long ll;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll n;
  cin >> n;
  ll cnt = 0;
  stack<pair<ll,ll>> st;
  
  for(int i = 0; i < n; i++) {
    ll item;
    cin >> item;
    pair<ll,ll> it = make_pair(item,1);
    while(st.size() && st.top().first<it.first) { //스택이 안 비었다면 탑<현재일때까지 
      cnt+=st.top().second; //쌍 카운트
      st.pop();
    }
    if(st.empty()) st.push(it); //빌 때만 넣는 이유: 안 비면 아래에서 마저 집계하고 넣어 줄 거니까...
    else {
      if(st.top().first == it.first) {
        pair<ll,ll> cur = st.top();
        st.pop();
        cnt+=cur.second;
        it.second = cur.second + 1; //현재 팬과 top팬이 키가 같으니 사람 수 갱신
        if(st.size()) cnt++; //남은 현재 팬보다 키가 작은 한 명은 현재 팬을 볼 수 있음(더 크면 당연히 안 되고)
      } else {
        cnt++;
      }
      st.push(it); //둘 다 전제에 맞으므로 empty() 확인 없이 push
    }
  }
  cout << cnt;
  
  return 0;
}