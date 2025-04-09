#include<stdio.h>
#include<stdint.h>
#include<string.h>

typedef struct pairUniv {
    uint8_t Yonsei;
    uint8_t Korea;
} pairUniv;
/*declare simple structure for clarifying its score sets*/
typedef union easySetup {
    uint16_t superSet;
    pairUniv innerSet;

} eSet;
/*this has superSet, for easy reset. It is a form of union, so it would reset both schools' clan score. */
const char * __PRIMITIVE__compareTwoClan(eSet* eS) {
    uint8_t scholarPrim = eS->innerSet.Yonsei, scholarSecnd= eS->innerSet.Korea;
    eS->superSet=0;
    if(scholarPrim==scholarSecnd) {
        return "Draw";
    }
    return scholarPrim>scholarSecnd?"Yonsei":"Korea";
}
/*this function returns char pointer(C-type raw string).
This is easier to get its implementation at a glance.*/
 
typedef struct easyCalculation {
    eSet data;  /* here, as you know,
    we will store this data type within
    a variable named data. */
    const char * (*finalCalculation)(eSet *); /*We would 
    Roll up its primitive declaration into this pointer. */
} calClass;
int main() {
    calClass a; /* as an object for problem solving;this is fairly acceptable*/
    a.finalCalculation = __PRIMITIVE__compareTwoClan; /*okay, now rolled up into this pointer.*/
    uint8_t requestedMaxLoop; /*Clean, and easy-to-find. better than random alphabets*/
    scanf("%hhu", &requestedMaxLoop);
    for(int v=0;v<requestedMaxLoop;v++) {
        for(int i=0;i<9;i++) {
            uint8_t tempLocal, tempLocalSecnd; /*temporal variables to store currently
            requested information to store. */
            scanf("%hhu %hhu", &tempLocal, &tempLocalSecnd);
            a.data.innerSet.Yonsei+=tempLocal;
            a.data.innerSet.Korea+=tempLocalSecnd;
            /*Just increment this while this loop ends. */
        }
        /*Now it would clean its space into zero, and print its result.
        function pointer's return value will be printed into stdout directly. 
        */
        puts(a.finalCalculation(&a.data));

    }
    return 0;
}