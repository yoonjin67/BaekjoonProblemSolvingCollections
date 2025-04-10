#include<iostream>
#include<stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    stack<char> st;
    int sum = 0;
    int accum = 1;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            st.push('('); //괄호가 열렸으니 곱함.
            accum *= 2;
        } else if (s[i] == '[') {
            st.push('[');
            accum *= 3;
        } else if (s[i] == ')') {
            if(st.empty() || st.top() != '(') { //완전하지 못한 괄호쌍
                sum = 0;
                break;
            }
            if(s[i-1]=='(') { //i == 0인지 체크해야 한다고 생각했는데, i == 0이면 st.size() == 0. (이미 처리됨)
                sum += accum; //() 형태의 괄호쌍, 하위 괄호가 없이 끝나는 값이니 상위 괄호들*현재 괄호의 값인
                //현 accum을 sum에 더함.
            }
            st.pop();
            accum /= 2; //괄호를 빠져나갔으니 나눔.
        } else if (s[i] == ']') {
            if(st.empty() || st.top() != '[') {
                sum = 0;
                break;
            }
            if(s[i-1] == '[') {
                sum += accum;
            }
            st.pop();
            accum /= 3;
        }
    }
    if(st.size()) cout << 0;
    else cout << sum;
    return 0;
}