#include<iostream>
#include<cstring>
using namespace std;
bool alphabets[26];
int main () {
    int n;
    cin >> n;
    int len = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bool flag = true;
        memset(alphabets,0,sizeof(alphabets));
        alphabets[s[0]-'a'] = true;
        for(int i = 1; i < s.length(); i++) {
            if(s[i]!=s[i-1]) {
                if(!alphabets[s[i]-'a']) {
                    alphabets[s[i]-'a'] = true;
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) len++;
    }
    cout << len;
}