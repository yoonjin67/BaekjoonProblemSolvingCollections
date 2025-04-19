#include<iostream>
#include<vector>
using namespace std;

class solve {
    public:
        vector<string> croatian;
        vector<char> v;
        string s;
        void initialize();
        void slice(int start, int len);
        void answer();
        int deleted_alphabets();
        void delete_splitter();
};

void solve::initialize() {
    cin >> s;
    v=vector<char>(s.begin(),s.end());
    croatian.push_back("dz=");
    croatian.push_back("lj");
    croatian.push_back("nj");
    croatian.push_back("c=");
    croatian.push_back("c-");
    croatian.push_back("d-");
    croatian.push_back("s=");
    croatian.push_back("z=");
}

void solve::slice(int start, int len) {
    for(int i = start; i < len+start; i++) {
        v[i] = '_';
    }
    s = string(v.begin(),v.end());
}

void solve::delete_splitter() {
    vector<char> v1;
    for(auto c:v) {
        if(c=='_') continue;
        v1.push_back(c);
    }
    v=v1;
    s = string(v.begin(),v.end());
}


int solve::deleted_alphabets() {
    int cnt  = 0;
    for(auto c:croatian) {
        int n = s.find(c);
        while(n!=string::npos) {
            slice(n,c.length());
            cnt++;
            n = s.find(c);
        }
    }
    delete_splitter();
    return cnt;
}

void solve::answer() {
    initialize();
    cout << deleted_alphabets()+s.length();
    exit(0);
}

int main() {
    solve prob;
    prob.answer();
    return 0;
}
