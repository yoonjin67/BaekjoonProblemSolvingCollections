#include<iostream>
#include<stack>
using namespace std;

int main() {
    int target, origin;
    cin >> origin >> target;
    int len;
    cin >> len;
    stack<int> s;
    for(int i = 0; i < len; i++) {
        int x;
        cin >> x;
        s.push(x);
    }
    int current_powered_location = 1;
    int res = 0;
    while(s.size()) {
        int x = s.top();
        s.pop();
        x *= current_powered_location;
        res += x;
        current_powered_location *= origin;
    }
    while(res > 0) {
        s.push(res%target);
        res /= target;
    }
    while(s.size()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}