#include<iostream>
#include<cctype>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(auto i = 0; i < n; i++) {
        string a,b;
        cin >> a >> b;
        for(int idx = 0 ; idx < a.length(); idx++) {
            if(a[idx]=='x' or a[idx] == 'X') {
                cout << (char)toupper(b[idx]);
            }
        }
    }
   return 0;
}