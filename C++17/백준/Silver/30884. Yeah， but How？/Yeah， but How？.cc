#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
    string s;
    vector<char> v;
    cin >> s;
    for(int i = 0; i < s.length()-1; i++) {
        v.push_back(s[i]);
        if(s[i] == '(' and s[i+1] == ')') v.push_back('1');
        if(s[i] == ')' and s[i+1] == '(') v.push_back('+');
    }
    v.push_back(s[s.length()-1]);
    string  str(v.begin(),v.end());
    cout << str;
   return 0;
}