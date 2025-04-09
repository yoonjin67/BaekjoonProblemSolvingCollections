#include<iostream>
#include<queue>
using namespace std;
int main() {
  int deque_size, itm_to_pop;
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  deque<int> dq;
  cin >> deque_size >> itm_to_pop;
  for(int i = 1; i <= deque_size; i++) {
    dq.push_back(i);
  }
  int res = 0;
  for(int i = 0; i < itm_to_pop && dq.size(); i++) {
    int target;
    cin >> target;
    int dest = 0;
    for(int i = 0; i < dq.size(); i++) {
      if(dq[i]==target) {
        dest = i;
        break;
      }
    }
    int tmp; 
    while(dq.size()) {
      tmp=dq.front(); 
      if(tmp==target) {
        dq.pop_front();
        break;
      }
      if(dest <= dq.size()/2) {
        res++;
        tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
      } else {
        res++;
        tmp = dq.back();
        dq.pop_back();
        dq.push_front(tmp);
      }
    }
  }
  cout << res;
  return 0;
}