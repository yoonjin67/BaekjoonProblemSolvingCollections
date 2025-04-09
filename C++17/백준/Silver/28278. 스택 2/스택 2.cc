#include<iostream>
#include<stack>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int len;
    stack<int> st;
    cin >> len;
    for(int i = 0; i < len; i++) {
        int cmd;
        cin >> cmd;
        switch(cmd) {
            case 1:
                int v;
                cin >> v;
                st.push(v);
                break;
            case 2:
                if(!st.size()) {
                    cout << "-1\n";
                    break;
                }
                cout << st.top() << '\n';
                st.pop();
                break;
            case 3:
                cout << st.size() << '\n';
                break;
            case 4:
                if(st.empty()) cout << "1\n";
                else cout << "0\n";
                break;
            case 5:
                if(st.size()) cout << st.top() << '\n';
                else cout << "-1" << '\n';
                break;
        }
    }
}