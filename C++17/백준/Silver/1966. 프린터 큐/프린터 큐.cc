#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> pii;


int main() {
    int n;
    cin >> n;
    for(int r = 0; r < n; r++) {
        int doc_len, cur;
        cin >> doc_len >> cur;
         vector<pii> q;
        for(int i = 0; i < doc_len; i++) {
            int pri;
            cin >> pri;
            q.push_back(make_pair(pri,i));
        }
        int queued_num = 0;
        while(q.size()) {
            pii top = q.front();
            q.erase(q.begin());
            int good = true;
            for(auto it: q) {
                if(it.first>top.first) {
                    q.push_back(top);
                    good = !good;
                    break;
                }
            }
            if(!good) {
                continue;
            }
            queued_num++;
            if(top.second==cur) break;
        }
        cout << queued_num << '\n';
    }
    return 0;
}