#include <iostream>
#include <cstring>
using namespace std;

int **map;
bool *visited;
int n;

int dfs(int start, int end, int dist) {
    if (start == end) {
        return dist;  //조건 충족 시 return
    }

    visited[start] = true; //백트래킹을 위해 일단 마크
    int min_dist = -1;
    for (int i = 1; i <= n; i++) {
      if (map[start][i] && !visited[i]) {
        int next_dist = dfs(i, end, dist + map[start][i]);
        if (next_dist != -1) {
          if(min_dist == -1 || next_dist < min_dist) { //최소 거리를 찾는 거니까 최소 비교 해줘야함.
            min_dist = next_dist; 
          }
        }
      }
    }
    visited[start] = false; //마크 해제
    return min_dist;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int m;
    cin >> n >> m;

    map = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        map[i] = new int[n + 1];
        memset(map[i], 0, sizeof(int) * (n + 1));
    }

    visited = new bool[n + 1];
    memset(visited, 0, sizeof(bool) * (n + 1));

    for (int i = 0; i < n - 1; i++) {
        int p1, p2, dist;
        cin >> p1 >> p2 >> dist;
        map[p1][p2] = dist;
        map[p2][p1] = dist;
    }

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        int res = dfs(start, end, 0);
        cout << res << '\n';
    }

    for (int i = 0; i <= n; i++) {
        delete[] map[i]; 
    }
    delete[] map;
    delete[] visited; 

    return 0;
}