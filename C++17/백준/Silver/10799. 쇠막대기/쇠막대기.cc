#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<int> st;
    string c;
    cin >> c;
    long long int cnt = 0;
    int len = c.length();
    for(int i=0;i<len;i++) {
        if (i < len-1) {
            if(c[i]=='(' and c[i+1] ==')') {
                cnt+=st.size();
                i++;
            }
            else if(c[i]=='(') {
                st.push(c[i]);
            } else if(c[i] == ')') {
                st.pop();
                cnt++;
            }
        }

        else if(c[i]=='(') {
            st.push(c[i]);
        } else if(c[i] == ')') {
            st.pop();
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
