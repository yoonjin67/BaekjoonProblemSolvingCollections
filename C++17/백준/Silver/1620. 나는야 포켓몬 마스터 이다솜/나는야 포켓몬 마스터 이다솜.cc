#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int pokemons, questions;
    cin >> pokemons >> questions;
    unordered_map<string,int> dict;
    unordered_map<int,string> r_dict;
    for(int i = 1; i <= pokemons; i++) {
        string s;
        cin >> s;
        dict[s] = i;
        r_dict[i] = s;
    }
    for(int i = 1; i <= questions; i++) {
        string s;
        cin >> s;
        if(isdigit(s[0])) {
            cout << r_dict[stoi(s)];
        } else {
            cout << dict[s];
        }
        if(i<questions) {
            cout << '\n';
        }
    }
    return 0;
}