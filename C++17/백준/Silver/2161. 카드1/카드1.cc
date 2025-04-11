#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int NUM, i, ret;
    queue<int> lst;
    scanf("%d", &NUM);
    for(i=1;i<=NUM;i++) lst.push(i);
    while(lst.size()>0) {
        ret = lst.front();
        lst.pop();
        printf("%d", ret);
        ret = lst.front();
        lst.pop();
        lst.push(ret);
        if(lst.size()) {
            printf(" ");
        }
    }
    return 0;
}