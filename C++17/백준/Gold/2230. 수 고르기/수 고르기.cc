#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main() {
    int vec_len, m;
    cin >> vec_len >> m;
    int v[vec_len];
    for(int i = 0; i < vec_len; i++) {
        cin >> v[i];
    }
    sort(v,v+vec_len);
    int current = INT_MAX, i = 0, j = 0;
    while(i<vec_len and j<vec_len) {
        int c = v[j]-v[i];
        if(c<m) {
            j++;
        } else if(c==m) {
            cout << m;
            return 0;
        } else {
            current = min(c,current);
            i++;
        }
    }
    cout << current;
    return 0;
}
