#include <stdio.h>
#include <string.h>
int main() {
    int i;
    int number,price;
    scanf("%d %d",&number, &price);
    int orig_price = price, cal = 0;
    int coins[number] , m_kinds=0;
    for(i=0;i<number;i++) {
        scanf("%d", coins+i);
    }

    for (i=number-1;i>=0;i--) {
        if(price<coins[i]) {
            continue;
        }
        int temp = (int)(price/coins[i]);
        m_kinds += temp;
        cal += temp*coins[i];
        price %= coins[i]; 
    }
    if(orig_price!=cal) {
        m_kinds/=2;
    }
    printf("%d",m_kinds);
}