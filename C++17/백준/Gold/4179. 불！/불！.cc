#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<string> maze(r);
    queue<tuple<int, int, int>> fireQueue;
    queue<tuple<int, int, int>> jihunQueue;
    vector<vector<int>> fireTime(r, vector<int>(c, -1));
    vector<vector<int>> jihunTime(r, vector<int>(c, -1));

    for (int i = 0; i < r; ++i) {
        cin >> maze[i];
        for (int j = 0; j < c; ++j) {
            if (maze[i][j] == 'F') {
                fireQueue.push({i, j, 0});
                fireTime[i][j] = 0;
            } else if (maze[i][j] == 'J') {
                jihunQueue.push({i, j, 0});
                jihunTime[i][j] = 0;
            }
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    // 불 확산 BFS
    while (!fireQueue.empty()) {
        auto [x, y, time] = fireQueue.front();
        fireQueue.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c && maze[nx][ny] != '#' && fireTime[nx][ny] == -1) {
                fireTime[nx][ny] = time + 1;
                fireQueue.push({nx, ny, time + 1});
            }
        }
    }

    // 지훈이 이동 BFS
    while (!jihunQueue.empty()) {
        auto [x, y, time] = jihunQueue.front();
        jihunQueue.pop();

        if (x == 0 || x == r - 1 || y == 0 || y == c - 1) {
            cout << time + 1 << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c && maze[nx][ny] != '#' && jihunTime[nx][ny] == -1) {
                if (fireTime[nx][ny] == -1 || fireTime[nx][ny] > time + 1) {
                    jihunTime[nx][ny] = time + 1;
                    jihunQueue.push({nx, ny, time + 1});
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}