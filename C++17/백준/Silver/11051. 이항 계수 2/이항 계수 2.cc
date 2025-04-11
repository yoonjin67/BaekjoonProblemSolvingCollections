#include<iostream>
#include<vector>

//DP입문
using namespace std;
int main () {
    int n,r;
    cin >> n >> r;
    vector<vector<int>> vec(n+1,vector<int>(r+1,0));
    //벡터 깔끔하게 초기화하는법!!!
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= r; j++) {
            if(i==j or j ==0) vec[i][j] = 1; //이항계수는 i==j거나 j==0일때 1, 이거 없으면 아래쪽도 당연히 점화x
            else vec[i][j] = (vec[i-1][j]+vec[i-1][j-1])%10007; //나머지는 이렇게
        }
    }
    cout << vec[n][r]; //이렇게 출력
    return 0;
}