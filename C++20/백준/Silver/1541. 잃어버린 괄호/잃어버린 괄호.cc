#include<iostream>

using namespace std;

int main () {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    bool minus = false;
    int sum = 0;
    string temp = "";
    for(auto c:s) {
        if(c == '-' || c == '+') {
            if(minus) {
                sum -= stoi(temp);
            } else {
                sum += stoi(temp);
            }
            temp = "";
            if(c=='-') minus = true;
        } else {
            temp += c;
        }
    }
    if(minus) {
        sum -= stoi(temp);
    } else {
        sum += stoi(temp);
    }
    cout << sum;
    return 0;
}