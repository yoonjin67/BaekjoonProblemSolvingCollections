#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

//A가 나누는수 B가 나머지

unsigned long long GCD(unsigned long long a,unsigned long long b) {
    while(b!=0) {
        long long n = a%b;
        a = b;
        b = n;
    }
    return a;
}

unsigned long long LCM(unsigned long long a, unsigned long long b) {
    if(a>b) {
        return (a*b)/GCD(a,b);
    }
    else {
        return (a*b)/GCD(b,a);
    } 
}


vector<unsigned long long> divisor(unsigned long long x) {
    vector<unsigned long long> v;
    for(unsigned long long i = 1; i*i <= x; i++) {
        if(x%i==0) {
            v.push_back(i);
            v.push_back(x/i);
        }
    }
    return v;
}

int main() {
    unsigned long long a,b,L;
    cin >> a >> b >> L;
    unsigned long long lcm = LCM(a,b);
    vector<unsigned long long> possibleC = divisor(L);
    sort(possibleC.begin(),possibleC.end());
    unsigned long long res = -1;
    if(lcm == L) {
        cout << "1";
        return 0;
    }
    if(L%lcm !=0) {
        cout << "-1";
        return 0;
    }
    for(auto c:possibleC) { 
        if(LCM(lcm,c) == L) {
            res = c;
            break;
        }
    }
    cout << res;
    
}