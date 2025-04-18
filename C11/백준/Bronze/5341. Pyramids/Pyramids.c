#include <stdio.h>
main () {
    while(1) {
        float i;
        float I;
        scanf("%f",&i);
        if(!i) {
            return i;
        }
        I=(float)i/2.0F;
        i++;
        i/=2;
        i*=I*2;
    
        printf("%d\n",(int)i);
    }
}