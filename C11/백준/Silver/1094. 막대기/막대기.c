#include<stdio.h>


int main() 
{
    int x;
    scanf("%d", &x);
    int stick = 0;
    int cnt = 0;
    int n = 64;
    if(x==n) {
        printf("1");
        return 0;
    }
    while(stick != x && stick < x) {
        n >>= 1;
        if(n<=x && stick+n <= x) {
            stick+=n;
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
