#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++) {
        if(i==n) {
            for(int k = 1; k <n*2; k++) cout << "*";
            return 0;
        }
        for(int k = n-i-1; k>=0; k--) cout << " ";
        cout << "*";
        for(int j = 0; j<2*i-3; j++) cout <<" ";
        if(i>1)
            cout << "*";
        cout << endl;
    }
    return 0;
}