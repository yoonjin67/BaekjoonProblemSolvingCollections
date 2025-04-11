#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list_int
{
int *list;
int list_size;
};
typedef struct list_int list_int;
list_int listgen()
{
    list_int X;
    X.list=malloc(sizeof(int));
    X.list_size=0;
    return X;
}
list_int push(list_int X)
{
    X.list=(int *)realloc(X.list,(X.list_size+1)*sizeof(int));
    scanf("%d",X.list+X.list_size);
    X.list_size++;
    return X;
}
list_int pop(list_int X)
{
    if(X.list_size==0)
        puts("-1");
    else
    {
        printf("%d\n",X.list[X.list_size-1]);
        X.list_size--;
        X.list=(int *)realloc(X.list,X.list_size*sizeof(int));
    }                                                                                                                                                                                                                                         
    return X;                                                                                                                                                                                                                                 
}                                                                                                                                                                                                                                             
void size(list_int X)                                                                                                                                                                                                                         
{                                                                                                                                                                                                                                             
    if(X.list_size>0)                                                                                                                                                                                                                         
        printf("%d\n",X.list_size);                                                                                                                                                                                                           
    else                                                                                                                                                                                                                                      
        puts("0");                                                                                                                                                                                                                            
}                                                                                                                                                                                                                                             
void empty(list_int X)                                                                                                                                                                                                                        
{                                                                                                                                                                                                                                             
    if(X.list_size==0)                                                                                                                                                                                                                        
        puts("1");                                                                                                                                                                                                                            
    else                                                                                                                                                                                                                                      
        puts("0");                                                                                                                                                                                                                            
}                                                                                                                                                                                                                                             
void top(list_int X)                                                                                                                                                                                                                          
{                                                                                                                                                                                                                                             
    if(X.list_size>0)                                                                                                                                                                                                                         
        printf("%d\n",X.list[X.list_size-1]);                                                                                                                                                                                                 
    else                                                                                                                                                                                                                                      
        puts("-1");                                                                                                                                                                                                                           
}                                                                                                                                                                                                                                             
list_int listinter(list_int X,int N)                                                                                                                                                                                                                
{                                                                                                                                                                                                                                             
    int x,i;                                                                                                                                                                                                                                  
    char command[6];
    list_int Y;
    Y.list_size=X.list_size;
    Y.list=malloc(sizeof(int)*X.list_size);
    for(i=0;i<X.list_size;i++)
        memcpy(Y.list+i,X.list+i,sizeof(int));
    for(i=0;i<N;i++)
    {
        scanf("%s",command);
        if(strcmp(command,"push")==0)
            Y=push(Y);
        else if(strcmp(command,"pop")==0)
            Y=pop(Y);
        else if (strcmp(command,"size")==0)
            size(Y);
        else if (strcmp(command,"empty")==0)
            empty(Y);
        else if(strcmp(command,"top")==0)
            top(Y);
        else
            puts("ERROR");
    }
    X.list=realloc(X.list,sizeof(int)*Y.list_size);
    return Y;
}
int main()
{
    int N;
    scanf("%d",&N);
    list_int intlist=listgen();
    intlist=listinter(intlist,N);
    return 0;
}
