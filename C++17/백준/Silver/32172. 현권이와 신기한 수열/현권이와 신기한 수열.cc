#include<iostream>
#include<set>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> numset;
  int prev = 0;
  numset.insert(prev);
  for(int i = 1; i <= n; i++) {
    if((prev-i<0) or (numset.find(prev-i) != numset.end())) {
      prev += i;
      numset.insert(prev);
    } else {
      prev -=i;
      numset.insert(prev);
    }
  }
  numset.clear();
  cout << prev;
  return 0;
}

