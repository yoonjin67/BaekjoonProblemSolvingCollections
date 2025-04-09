#include<iostream>
#include<vector>
#include<queue>

using namespace std;
constexpr char visited = 'V';
vector<vector<char>> pic;
vector<pair<int,int>> coords;

int N;

void initialize_coords() {
    coords.push_back(make_pair(-1,0));
    coords.push_back(make_pair(1,0));
    coords.push_back(make_pair(0,-1));
    coords.push_back(make_pair(0,1));
}
bool avail(int x,int y) {
    if(x<0 or x>=N) return false;
    if(y<0 or y>=N) return false;
    return pic[x][y]!='V';
}

void bfs_rg(int a, int b) {
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    while(q.size()) {
        pair<int,int> p = q.front();
        int x = p.first, y = p.second;
        pic[x][y] = visited;
        q.pop();
        for(auto cor:coords) {
            int nx = x+cor.first, ny = y+cor.second;
            if(avail(nx,ny) and ((pic[nx][ny]=='G') or (pic[nx][ny]=='R'))) {
                pic[nx][ny] = visited;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

void bfs(int a, int b, char c) {
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    while(q.size()) {
        pair<int,int> p = q.front();
        int x = p.first, y = p.second;
        q.pop();
        pic[x][y] = visited;
        for(auto cor:coords) {
            int nx = x+cor.first, ny = y+cor.second;
            if(avail(nx,ny) and (pic[nx][ny]==c)) {
                pic[nx][ny] = visited;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main()  {
    initialize_coords();
    cin >> N;
    pic = vector<vector<char>>(N,vector<char>(N,visited));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> pic[i][j];
        }
    }
    vector<vector<char>> origin = pic;
    int normal = 0, abnormal = 0;
    for(auto i = 0; i < N; i++) {
        for(auto j = 0; j < N; j++) {
            if(pic[i][j] != visited) {
                bfs(i,j,pic[i][j]);
                normal++;
            }
        }
    }
    cout << normal << " ";
    pic = origin;
    for(auto i = 0;i < N; i++) {
        for(auto j = 0; j < N; j++) {
            if(pic[i][j]!=visited) {
                if(pic[i][j] == 'B') {
                    abnormal++;
                    bfs(i,j,pic[i][j]);
                } else {
                    abnormal++;
                    bfs_rg(i,j);
                }
            }
        }
    }
    cout << abnormal;
    return 0;
}
