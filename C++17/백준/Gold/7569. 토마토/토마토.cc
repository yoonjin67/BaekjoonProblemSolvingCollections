#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int m, n, h;
    cin >> m >> n >> h;

    vector<vector<vector<int>>> tomato(h, vector<vector<int>>(n, vector<int>(m)));
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) {
                    q.push({i, j, k});
                }
            }
        }
    }

    int dx[] = {0, 0, 1, -1, 0, 0};
    int dy[] = {1, -1, 0, 0, 0, 0};
    int dz[] = {0, 0, 0, 0, 1, -1};

    while (!q.empty()) {
        auto [z, y, x] = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h && tomato[nz][ny][nx] == 0) {
                tomato[nz][ny][nx] = tomato[z][y][x] + 1;
                q.push({nz, ny, nx});
            }
        }
    }

    int maxTime = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (tomato[i][j][k] == 0) {
                    cout << -1 << endl;
                    return 0;
                }
                maxTime = max(maxTime, tomato[i][j][k]);
            }
        }
    }

    cout << maxTime - 1 << endl;

    return 0;
}