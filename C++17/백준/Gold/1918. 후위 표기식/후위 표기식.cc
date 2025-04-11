#include<iostream>
#include<stack>
using namespace std;

int main() {
    string s;
    stack<char> st;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if('A' <= s[i] && s[i] <= 'Z') {
            cout << s[i];
        } else {
            if(s[i] == ')') {
                while(st.size() and st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
                continue;
            }
           else if(s[i] == '+' or s[i] == '-') {
                while(st.size() and st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
            } else if (s[i] == '*' or s[i] == '/') {
                while(st.size() and (st.top() == '*' or st.top() == '/')) {
                    cout << st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }
    while(st.size()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}