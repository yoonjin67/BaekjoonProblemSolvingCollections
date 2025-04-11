#include <stdio.h>
#include <stdlib.h>
typedef struct node{int key;struct node *next;} node;
typedef struct stack{node *head;node *tail;}stack;
void init_stack(stack* a)
{
    a->head=(node *)malloc(sizeof(node));
    a->tail=(node *)malloc(sizeof(node));
    a->head->next=a->tail;
    a->tail->next=a->tail;
}
void push(stack *a, int k)
{
    node *t;
    if((t=(node*)malloc(sizeof(node)))==NULL)
    {
        perror("\nOUT OF MEMORY");
       return -1;
    }
    t->key=k;
    t->next=a->head->next;
    a->head->next=t;
}
int empty(stack* a)
{
    if(a->head->next==a->tail)
        return 1;
    else
        return 0;
}
void pop(stack* a)
{
    if(empty(a))
    {
        return -1;
    }
    node *y;
    y=a->head->next;
    int i=y->key;
    a->head->next=y->next;
    free(y);
}
int top(stack* a)
{
    if(empty(a))
        return -1;
    node *y;
    y=a->head->next;
    return y->key;
}
void clear_stack(stack* a)
{
    node *t, *s;
    t=a->head->next;
    while(t!=a->tail)
    {
        s=t;
        t=t->next;
        free(s);
    }
    a->head->next=a->tail;
}
void free_stack (stack *a)
{
    clear_stack(a);
    free(a->head);
    free(a->tail);
}
int main()
{
    register int i,j=1, l=0,strcnt=0;
    int a,b;
    stack st_1;
    init_stack(&st_1);
    scanf("%d", &a);
    char string[500000];
    for(i=1;i<=a;i++)
    {
        scanf("%d", &b);
            if(empty(&st_1))
            {
                push(&st_1,j);
                string[strcnt]='+';
                string[strcnt+1]='\n';
                strcnt+=2;
                j++;
            }
            while(top(&st_1)!=b)
            {
                if(j<=a)
                {
                    push(&st_1,j);
                string[strcnt]='+';
                string[strcnt+1]='\n';
                strcnt+=2;
                    j++;
                }
                else
                    break;
            }
            if(top(&st_1)==b)
            {
                pop(&st_1);
                l++;
                string[strcnt]='-';
                string[strcnt+1]='\n';
                strcnt+=2;
            }
    }
    if(l!=a)
    {
        puts("NO");
        return 0;
   }
    free_stack(&st_1);
    printf("%s", string);
    return 0;

}