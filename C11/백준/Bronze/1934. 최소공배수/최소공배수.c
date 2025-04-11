#include <stdio.h>

int N;

int function(int a, int b) {
    if(b == 0)
        return a;
    return function(b, a % b);
}

int main() {
    int i, x, y;
    
    scanf("%d", &N);
    
    for(i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", x * y / function(x, y));
    }
    
}