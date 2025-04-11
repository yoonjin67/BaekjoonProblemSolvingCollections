#include<iostream>
#include<set>
using namespace std;

int cnt = 0;
int depth = 0;
int value[4] = { 1, 5, 10, 50};
set<int> s;

void dfs(int recur, int sum, int start) {
    if(recur==depth) {
        s.insert(sum);
        return;
    }
    for (int i = start; i < 4; i++) {
        cnt++;
        dfs(recur + 1,value[i]+sum,i);
    }
}

int main() {
    cin >> depth;
    dfs(0,0,0);
    cout << s.size();
    return 0;
}
