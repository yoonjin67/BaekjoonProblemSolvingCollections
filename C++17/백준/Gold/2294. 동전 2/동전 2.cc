#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<int> coins = vector<int>(n,0);
  vector<int> combi = vector<int>(k+1 ,k+1); //조합으로 풀면 메모리 초과. 가격 자체를 인덱스로 삼는 배열이 필요하다...
  for(int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  combi[0] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = coins[i]; j <= k; j++) {
      combi[j] = min(combi[j-coins[i]]+1,combi[j]); //현재 가격 직전의 것보다 동전을 하나 더 쓴게 조합한 동전의 수. 아직 변경하지 않은 인덱스에 접근하면 값이 커서 어차피 업데이트되지 않아 영향 없음.
    }
  }
  if(combi[k]==k+1) { ///불가능한 조합인지 확인
    cout << -1;
  } else {
    cout << combi[k]; //가격 출력
  }
  return 0;
}

