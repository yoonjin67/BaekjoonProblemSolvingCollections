#include<iostream>
#include<cmath>
using namespace std;

long long GDC(long long a, long long b) {
    while(b!=0) {
        long long n = a%b;
        a = b;
        b = n;
    }
    return a;
}

int main() {
    long long N,M;
    string s;
    cin >> N >> M;
    if(N<M) {
        N = GDC(M,N);
    } else {
        N = GDC(N,M);
    }
    for(int i = 0; i < N; i++) {
        cout << "1";
    }
    return 0;
}