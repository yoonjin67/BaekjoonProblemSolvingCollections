#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int N,M;

vector< pair<int,int> > directions;

vector< vector<bool> > pic;
vector<int> res;

int bfs(int x, int y) {
    int size = 0;
    queue< pair<int,int> > q;
    pic[x][y] = false;
    q.push(make_pair(x,y));
    while(!q.empty()) {
        int nx = q.front().first, ny = q.front().second;
        size++;
        q.pop();
        for(auto iter:directions) {
            int newx=nx+iter.first;
            int newy=ny+iter.second;
            if(newx<0 or newx>=N) continue;
            if(newy<0 or newy>=M) continue;
            if(!pic[newx][newy]) continue;
            pic[newx][newy] = false;
            q.push(make_pair(newx,newy));
        }
    }
    return size;
}

int main() {
    directions.push_back(make_pair(-1,0));
    directions.push_back(make_pair(1,0));
    directions.push_back(make_pair(0,1));
    directions.push_back(make_pair(0,-1));
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        pic.push_back(vector<bool>());
        for(auto j = 0; j < M; j++) {
            auto b = 0;
            cin >> b;
            pic[i].push_back((bool)b);
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(pic[i][j]) res.push_back(bfs(i,j));
        }
    }
    sort(res.begin(),res.end());

    cout << res.size() << endl;
    if(res.size()) cout << res[res.size()-1];
    else cout << "0";

}