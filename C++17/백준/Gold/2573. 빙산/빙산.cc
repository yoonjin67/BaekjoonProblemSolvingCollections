#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int>> sea, toMelt;
vector<vector<bool>> visited;
vector<pair<int,int>> coords;
int X_MAX, Y_MAX;

void initialize() {
    cin >> X_MAX >> Y_MAX;
    sea = vector<vector<int>>(X_MAX,vector<int>(Y_MAX,0));
    toMelt = vector<vector<int>>(X_MAX,vector<int>(Y_MAX,0));
    visited = vector<vector<bool>>(X_MAX,vector<bool>(Y_MAX,false));
    for(auto &rows : sea) {
        for(auto &itm:rows) {
            cin >> itm;
        }
    }
    coords.push_back(make_pair(-1,0));
    coords.push_back(make_pair(1,0));
    coords.push_back(make_pair(0,1));
    coords.push_back(make_pair(0,-1));
}

bool inCoords(int x, int y) {
    if(x<0 or x>=X_MAX) return false;
    if(y<0 or y>=Y_MAX) return false;
    return true;
}

bool avail(int x, int y, vector<vector<bool>> &visit) {
    if(!inCoords(x,y)) return false;
    if(visit[x][y]) return false;
    return true;
}

bool isSea(int x, int y) {
    if(!inCoords(x,y)) return false;
    return sea[x][y] == 0;
}


void melt(int x, int y, vector<vector<bool>> &visit, vector<vector<int>> &toMelt) {
     if(!avail(x,y,visit) || isSea(x,y)) return;
     visit[x][y] = true;
     int count = 0;
     for(auto c:coords) {
        int nx = x+c.first, ny = y+c.second;
        if(isSea(nx,ny)) {
            toMelt[x][y]++;
        } else if(avail(nx,ny,visit)) {
            melt(nx,ny,visit,toMelt);
        }
     }
}

void dfs(int x, int y, vector<vector<bool>> &visit) {
     if(!avail(x,y,visit) || isSea(x,y)) return;
     visit[x][y] = true;
     for(auto c:coords) {
        int nx = x+c.first, ny = y+c.second;
        dfs(nx,ny,visit);
     }
}


int main() {
    initialize();
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int yrs = 0;
    while(true) {
        vector<vector<bool>> reset = visited;
        int icebergs = 0;
        for(int i = 0; i < X_MAX; i++) {
            for(int j  = 0; j < Y_MAX; j++)  {
                if(!isSea(i,j)  and !visited[i][j]) {
                    dfs(i,j,visited);
                    icebergs++;
                }
            }
        }
        if(icebergs >= 2) {
            cout << yrs;
            return 0;
        }
        if(icebergs == 0) {
            cout << 0;
            return 0;
        }
        visited = reset;
        vector<vector<int>> tmp = toMelt;
        for(int i = 0; i < X_MAX; i++) {
            for(int j = 0; j < Y_MAX; j++) {
                if(!isSea(i,j) and !visited[i][j]) {
                    melt(i,j,visited, toMelt);
                }
            }
        }
        for(int i = 0; i < X_MAX; i++) {
            for(int j = 0; j < Y_MAX; j++) {
                sea[i][j] = max(sea[i][j]-toMelt[i][j],0);
            }
        }
        toMelt = tmp;
        visited = reset;
        yrs++;
    }
    return 0;
}
