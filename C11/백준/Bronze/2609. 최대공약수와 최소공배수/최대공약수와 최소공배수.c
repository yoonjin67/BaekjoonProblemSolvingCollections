#include<stdio.h>
int gcd(int a,int b) {
    while(b!=0) {
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int lcm(int a, int b) {
    if (a<b) {
        return a*b/gcd(b,a);
    }
    return a*b/gcd(a,b);
}
int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n%d",gcd(a,b),lcm(a,b));
    return 0;
}