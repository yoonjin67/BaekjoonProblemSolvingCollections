#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> farm;
vector<pair<int,int>> coords;
vector<pair<int,int>> cabbages;
int M, N;

void initialize_coords() {
    coords.push_back(make_pair(-1, 0));
    coords.push_back(make_pair( 1, 0));
    coords.push_back(make_pair( 0,-1));
    coords.push_back(make_pair( 0, 1));
}


int avail(int x, int y) {
    if(x<0 or x>=N) return false;
    if(y<0 or y>=M) return false;
    if(farm[x][y]==0) return false;
    return true;
}


void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(q.size()) {
        pair<int,int> p = q.front();
        int x = p.first, y = p.second;
        q.pop();
        farm[x][y] = 0;
        for(auto cor:coords) {
            int nx = x+cor.first, ny = y+cor.second;
            if(avail(nx,ny)) {
                farm[nx][ny] = 0;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main() {
   int rep;
   cin >> rep;
   initialize_coords();
   for(int i = 0; i < rep; i++) {
       static int answer;
       answer = 0;
       static int k;
       cin >> M >> N >> k;
       farm = vector<vector<int>>(N,vector<int>(M,0));
       for(int j = 0; j < k; j++) {
           static int x,y;
           cin >> y >> x;
           cabbages.push_back(make_pair(x,y));
           farm[x][y] = 1;
       }

       for(auto p:cabbages) {
           static int cx, cy;
           cx = p.first;
           cy = p.second;
           if(farm[cx][cy]) {
               bfs(cx,cy);
               answer++;
           }
       }
       cout << answer;
       if(i!=rep-1) cout << endl;
       farm.clear();
       cabbages.clear();
   }
}
