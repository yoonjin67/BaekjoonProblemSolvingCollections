#include <cstdio>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    scanf("%d", &n);
    if (n == 1) {
        int res;
        scanf("%d", &res);
        printf("%d", 0);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        q.push(m);
    }
    int res = 0;
    while (q.size() > 1) {
        int tmp = q.top();
        q.pop();
        int tmp2 = q.top();
        q.pop();
        res += tmp + tmp2;
        q.push(tmp + tmp2);
    }
    printf("%d", res);
    return 0;
}
