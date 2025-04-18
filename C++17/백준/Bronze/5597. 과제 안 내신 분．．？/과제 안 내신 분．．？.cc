#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    vector<int> lst;
    int i;
    for(i=1;i<=30;i++) {
        lst.push_back(i);
    }
    for(i=1;i<=28;i++) {
        int n;
        cin >> n;
        remove(lst.begin(),lst.end(),+n);
    }
    lst.resize(2);
    for(i=0;i<lst.size();i++) {
        cout << lst[i] << endl;
    }
    return 0;
}