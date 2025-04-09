#include <stdio.h>
short int acal() {
    short x;
    short cnt = 99;
    scanf("%hd",&x);
    if(x<=99) {
        return x;
    } else if (x==1000) {
        return 144;
    }else {
        short i;
        for(i=100;i<=x;i++) {
            short hund = i/100;
            short ten = i%100/10;
            short one = i%100%10;
            if((hund-ten)==(ten-one)) {
                cnt++;
            }
        }
        return cnt;
    }
}
int main() {
    printf("%hd",acal());
    return 0;
}