#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
void traverse(vector<int> &arr, int idx) {
        visited[idx] = true;
        for(auto &c : arr) {
                if(!visited[c])
                        traverse(graph[c], c);
        }
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int vertexes, edges;
        cin >> vertexes >> edges;
        graph = vector<vector<int>>(1001,vector<int>());
        visited = vector<bool>(1001,0);
        for(int i = 0; i < edges; i++) {
                int x,y;
                cin >> x >> y;
                x--; y--;
                graph[x].push_back(y);
                graph[y].push_back(x);
        }
        int cnt = 0;
        for(int i = 0; i < vertexes; i++) {
                if(!visited[i]) {
                        traverse(graph[i],i);
                        cnt++;
                }
        }
        cout << cnt;
        graph.clear();
        visited.clear();
        return 0;
}