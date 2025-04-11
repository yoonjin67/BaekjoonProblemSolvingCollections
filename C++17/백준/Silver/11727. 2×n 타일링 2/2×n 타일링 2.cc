#include<iostream>
using namespace std;
int tiles[1000];
int answer(int i, int n);

int main() {
    tiles[0] = 1;
    tiles[1] = 1;
    int n;
    cin >> n;
    if(n==1) {
        cout << n;
        return 0;
    }
    cout << answer(2,n);
    return 0;
}

int answer(int i, int n) {
    tiles[i] = tiles[i-1]%10007+tiles[i-2]*2%10007;
    tiles[i] %= 10007;
    if(i==n) return tiles[i];
    return answer(i+1,n);
}
