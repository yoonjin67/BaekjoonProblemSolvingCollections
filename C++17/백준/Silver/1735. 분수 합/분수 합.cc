#include<iostream>
using namespace std;
int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}

int lcm(int a, int b) {
    return a*b/gcd(a,b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,n1,m1;
    cin >> n >> m;
    cin >> n1 >> m1;
    int m2 = lcm(m,m1);
    int n2 = n*(m2/m)+n1*(m2/m1);
    int n0 = gcd(n2,m2);
    n2/=n0;
    m2/=n0;
    cout << n2 << " " <<m2;
}