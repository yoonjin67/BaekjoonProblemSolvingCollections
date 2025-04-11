#include<stdio.h>
#define EASY_GRADE (int)'A'+4
int main() {
    int i;
    char grade[3];
    double maj_credit = 0.0F;
    double total_cred = 0.0F;
    double g;
    double credit;
    for(i = 0; i < 20; i++) {
        g = 0.0F;
        scanf("%*s %lf %s",&credit,grade);
        if(grade[0] == 'P') continue;
        if(grade[0] == 'F') {
            total_cred+=credit;
            continue;
        }
        else total_cred+=credit;
        if(grade[1]=='+') g+=0.5F;
        g += EASY_GRADE-grade[0];
        credit*=g;
        maj_credit += credit;
    }
    if(maj_credit == 0.0F) {
        printf("0.000000");
        return 0;
    }
    maj_credit /= total_cred;
    printf("%.6f",maj_credit);
    return 0;
}