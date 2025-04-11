#include<iostream>
#include<string>
#include<vector>
using namespace std;
int prime(int x) {
    if(x<=2) {
        return 2;
    }
    vector<int> v;
    for(int i = 2; i < 200000; i++) {
        if(i == 2) {
            v.push_back(i);
            continue;
        }
        bool is_prime = true;
        for(auto j: v) {
            if(!(i%j)) {
                is_prime = false;
            }
        }
        if(is_prime) {
            v.push_back(i);
            if(i>=x) break; 
        }
    }
    return v[v.size()-1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    long num = 0;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin,s,'\n');
        int idx = 1;
        while(true) {
            idx = s.find(' ');
            if(idx == string::npos) {
                num += prime(stoi(s));
                break;
            }
            string num_str(s.begin(),s.begin()+idx);
            num += prime(stoi(num_str));
            s = string(s.begin()+idx+1,s.end());
        }
        cout << num << '\n';
        num = 0;
    }
    return 0;
}