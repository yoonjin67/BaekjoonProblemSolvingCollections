#include<iostream>
#include<queue>
using namespace std;
bool visited[100000];
void bfs(int a, int dest) {
    queue<pair<int,int>> q;
    q.push(make_pair(0,a));
    while(q.size()) {
        pair<int,int> x = q.front();
        visited[x.second] = true;
        if(x.second == dest) {
            cout << x.first;
            exit(0);
        }
        q.pop();
        if(x.second-1>=0 and !visited[x.second-1]) q.push(make_pair(x.first+1,x.second-1));
        if(x.second+1<=100000 and !visited[x.second+1]) q.push(make_pair(x.first+1,x.second+1));
        if(x.second*2<=100000 and !visited[x.second*2]) q.push(make_pair(x.first+1,x.second*2));

    }
}
int main() {
    int a,b;
    cin >> a >> b;
    bfs(a,b);
    return 0;
}