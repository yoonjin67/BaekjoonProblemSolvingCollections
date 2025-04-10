#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int MAX_STAIR  = 0;
int startup_location = 0;
constexpr int AVAIL = 20000000;
pair<int,int> elevator_buttons;
vector<int> elevator;
bool avail(int x) {
    if(x<0) return false;
    if(x>=MAX_STAIR) return false;
    if(elevator[x]!=AVAIL) return false;
   return true;
}

void bfs(int startpoint, int depth) {
    queue<int> q;
    if(!avail(startpoint)) return;
    if(startup_location==startpoint) return;
    elevator[startpoint] = 0;
    q.push(startpoint);
    while(q.size()) {
        int x = q.front();
        q.pop();
        int up = x+elevator_buttons.first;
        int down = x-elevator_buttons.second;
        if(avail(up)) {
            elevator[up] = elevator[x]+1;
            q.push(up);
        }
        if(avail(down)) {
            elevator[down] = elevator[x]+1;
            q.push(down);
        }
    }
}

int main() {
    int gangho_start = 0;
    cin >> MAX_STAIR >> gangho_start >> startup_location >> elevator_buttons.first >> elevator_buttons.second;
    if(gangho_start==startup_location) {
        cout << "0";
        return 0;
    }
    gangho_start--;
    startup_location--;
    elevator = vector<int>(MAX_STAIR,AVAIL);
    bfs(gangho_start,0);
    if(elevator[startup_location]==AVAIL) {
        cout << "use the stairs";
        return 0;
    } else {
        cout << elevator[startup_location];
    }
    return 0; 
}