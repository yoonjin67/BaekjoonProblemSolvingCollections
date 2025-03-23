#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<string.h>
using namespace std;
unsigned tree[1000][1000];
unsigned visited[1000];
unsigned printer[1000];
unsigned printer_current = 0;
void add_to_printer(int i) {
    printer[printer_current] =i+1;
    printer_current++;
}
void dfs(unsigned startPoint, int len) {
    if(visited[startPoint]) {
        return;
    }
    visited[startPoint] = 1;
    add_to_printer(startPoint);
    for(unsigned i = 0 ; i < len; i++) {
        if(tree[startPoint][i]) {
            if(!visited[i]) {
                dfs(i,len);
            }
        }
    }
}


void bfs(unsigned startPoint, int len) {
    queue<unsigned> q;
    memset(printer,0,sizeof(printer));
    printer_current = 0;
    q.push(startPoint);
    visited[startPoint] = 1;
    add_to_printer(startPoint);
    while(!q.empty()) {
        unsigned nd = q.front();
        q.pop();
        for(int i = 0; i < len; i++) {
            if(tree[nd][i] == 1 && !visited[i]) {
                add_to_printer(i);
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}


int main() {
    unsigned n,m,v;
    scanf("%u %u %u",&n,&m,&v);
    memset(tree,0,sizeof(tree));
    memset(visited,0,sizeof(visited));
    for(unsigned i = 0; i < m; i++) {
        static unsigned x, y;
        scanf("%u %u", &x,&y);
        x--; y--;  //to fit as index
        tree[x][y] = true;
        tree[y][x] = true;
    }
    v--;
    dfs(v,n);
    for(int i = 0; i < printer_current; i++) {
        if(i==printer_current-1)
            printf("%u\n",printer[i]);
        else
            printf("%u ",printer[i]);
    }
    memset(visited,0,sizeof(visited));

    bfs(v, n);
    for(int i = 0; i < printer_current; i++) {
        if(i==printer_current-1)
            printf("%u",printer[i]);
        else
            printf("%u ",printer[i]);
    }
    return 0;
}
