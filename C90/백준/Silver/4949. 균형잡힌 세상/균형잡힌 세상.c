#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct node
{
    char key ;
    struct node * next ; /*this is pointer reserved for moving to
                           next node */
} node;
#define NODE sizeof(node)  /* use macro instead of calling sizeof(node) 
                              every time */
typedef struct stack 
{ 
    node * head , * tail ; /*simple stack; head, and tail defined*/
}
stack ;

// STACK DEFINITION
void init_stack(stack *a)
{
    a -> head = (node *) malloc (NODE); 
    a -> tail = (node *) malloc (NODE);
    a -> head -> next = a -> tail ; /* singly linked list. initial structure */
    a -> tail -> next = a -> tail ; /* avoid nullptr exception               */
}
char push( stack * a , char k )
{
    node * t ;
    if( ( t = ( node *) malloc (NODE) )  ==  NULL ) { 
        perror ( "OUT OF MEMORY\n" ) ;
        return -ENOMEM ;  
    }  /* when memory is full, return -ENOMEM */
    
    t -> key = k; /*store its key */
    t -> next = a -> head -> next ; /* link new node's next node as head->next */
    a -> head -> next = t ; /* link new node as head->next */
    
    return k;  /* return k value when it is alright */
    
}
int empty(stack * a)
{
    if(a -> head -> next  ==  a -> tail ) {  /* if it is empty */
        return 1; /* so return 1 to say it is empty */
    }
    else {
        
        return 0 ;  /* it is not empty, return 0 */
        
    }
}
char pop(stack *a)
{
    static char c;  /* for storing key */ 
    node *y; /* it will store the node to be deleted */

    if( empty(a) ) {
        
        return -1; /* no data to pop */
    
    }
    
    
    y = a -> head -> next ; /*Latest data IN*/
    c = y -> key ; /* this is the key */
    a -> head -> next = y -> next ;
    free(y) ; /* First Out */
    
    return c ; /* return its key */
}
char top( stack *a )
{
    
    node * y ;
    if( empty ( a ) ) {
        return -1 ; /* no data to show */
    }
    
    y=a->head->next ; /* latest node is here. */
    
    return y->key ; /* return its key */
}
void clear_stack( stack *a )
{
    node *t, *s ;
    
    t=a->head->next ; /* FIRST DATA */
    
    while ( t != a->tail ) { /* till the end, */
    
        s = t; /* this is the current node */
        t = t -> next; /* this is the next node */
        free( s ); /* free current node */
    
    }
    
    a -> head -> next = a -> tail ;  /* set initial state */
}
void free_stack( stack *a ) {
    clear_stack (    a    ); /* clear all data */
    free ( a->head ); /* free head */
    free ( a->tail ); /* and tail  */
}

int main()
{
    stack a;
    
    
    init_stack(&a);
    
    /* init_stack called. Now, stack is ready to use. */
    
    
    
    
    int k;
    
    char  b[101];
    
    while(1)
    
    {
    
        k=0;
        
        scanf("%[^\n]%*c", b) ; /*scan a value while keycode <RETURN>*/
        
        
        clear_stack(&a) ; /*lear stack into initial state while in a loop.*/
        
        if(b[0]=='.') {
        
            break;
            
        } /*when b [ 0 ] is '.' ascii character , break the loop. ( no required string )*/
        
        while(b[k]!='.') {
            
            if( ( b[k] == '(' ) | ( b[k] == '[' ) ) {  /*if b[k] is ( or [ */
                
                 push(&a,b[k]); /*push it */
            }  /*while End of line ( in this case 
            , using ascii character '.' instead of EOL) */
            
            
            else if( ( b[k] == ')' ) | ( b[k] == ']' ) ) { /* if it is opposite */
                
                if( empty (&a) ) { /*stack should not be empty!*/
                    
                    puts ( "no" ) ;
                    break ;
                    
                }  
                
               else if( ( top ( &a ) != '(' ) & ( b[k]==')' ) ) { /*latest data and b[k] 
                                                                   should not be matched */
                   
                   puts ( "no" ) ;
                   break ;
                   
               }
                
               else if( ( top(&a)!='[' ) & ( b[k]==']' ) ) {
                   
                   puts ( "no" ) ;
                   break ;
                   
               } /*unmatch ERROR ; breaking the loop.*/
               else {
                   
                    pop ( &a ) ;
                   
                   /*pop the value if error is not occured.*/
            
               }
                
            }
            
           k++ ;
            
        }
        if(b[k]=='.') {
            
            
            if( empty(&a) ) {
            
                
                puts( "yes" ) ;  /*if stack is clear and
                current cursor index is at the end of the line , 
                print yes . */
            
            }
            
            else {
            
                puts( "no" ) ; /*if it is not empty ,
                but it is at the end of the line ,
                it's an error! */
            
            }
        
        }
        
        
    }
    
    free_stack ( &a ) ; /*problem solved
                        free the allocated stack before exit. */
    return 0 ;
}
