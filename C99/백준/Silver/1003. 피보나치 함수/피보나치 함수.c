#include <stdio.h> 
int fiboArr[41];
/*****************************
 * global array's values are *
 * initialized as all-zero   *
 *****************************/



int fibo(int N) {              
    if((N<2)|(fiboArr[N]!=0)) {   /*********************************
                                  *if (N < 2) or fibo(N) is        *
                                  *already generated,              * 
                                  *use predefined value and return.*
                                  **********************************/
        
                           
        return fiboArr[N]; /****************************
                            * call-by value method is  *
                            * better when you can use  *
                            * its return value without *
                            * any other task which     *
                            * require additional       *
                            * variable to store        *
                            * its result.              *
                            ****************************/
    }
    fiboArr[N] = fibo(N-1) + fibo(N-2);          /*************************
                                                  * Okay, there's no data.*
                                                  * Now generate answer   *
                                                  *************************/
    return fiboArr[N];     /*return generated value */
    
}
int main() {
    
    
    
    fiboArr[1]=1; 
                 /*********************
                  *  fibo(0) is zero, *
                  * fibo(1) is 1;     *
                  * fibo(1) is        *
                  * declared here     *
                  *********************/

    
    
    register short i; /******************************
                       * GENERALLY, DON'T USE       *
                       * register flag              *
                       * you will use this variable *
                       * for loop, and the task is  *
                       * just simple increment      *
                       * in this case, you can use  *
                       * register flag;but too much *
                       * register flag (n>4) is bad *
                       ******************************/
    
    
    auto int REP;     /******************************
                       * REP means number of        *
                       *       REPetition.          *
                       * this value does not change *
                       * after scanning its data    *
                       * from STDIN, so DO NOT use  *
                       * register flag              *
                       ******************************/
    
    
    
    scanf("%d", &REP);     /*  scan REP value. */
    
    
    int ARG; /*****************
              * ARG is an     *
              *  argument for *
              *  fibonacci    *
              *****************/
    
    
    for(i = 0; i < REP; i++) { /*************************
                                * do not use c++ form.  *
                                * This is c language    *
                                * loop runs for         *
                                * REP times             *
                                *************************/
        
        /* BEGINNING of repetition part */
        
        
        
    
        /* scan fibo's argument here. */
        
        
        scanf("%d"  /* %d is for integer */
              
                  , &ARG   /********************************
                            * ARG is not pointer; use & to *
                            * use its address              *
                            ********************************/ ); 
        
 
        
        
        switch(!ARG) {    /* using switch; it is faster */
                
            case 1:   /* if ARG is 1, */
                
                puts("1 0");  /* don't call fibo() */

                break; /*breaks the switch loop here */
            default:
                printf("%d %d\n", fibo(ARG-1), fibo(ARG)); /********************
                                                                * use return value * 
                                                                * directly into    *
                                                                * printf args      *
                                                                ********************/
                
                
                break;     /*by default, breaks loop here*/
        }
        
        
        /*************************** 
         * END OF REPETITION PART  *
         * NEXT TASK: repeat AGAIN *
         * from BEGINNING          *
         ***************************/
        
        
    }    
    
    return 0;   /*send return code*/
    
}



