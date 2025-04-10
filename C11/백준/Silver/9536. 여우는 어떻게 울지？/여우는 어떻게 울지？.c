#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{char item[101]; struct node *prev; struct node*next;} node;
typedef struct list{int size; node *head; node *tail;} list;
void init_list(list *l)
{
    l->head=(node *)malloc(sizeof(node));
    l->tail=(node *)malloc(sizeof(node));
    l->size=0;
    l->head->next=l->tail;
    l->tail->next=l->tail;
    l->head->prev=l->head;
    l->tail->prev=l->head;
}
void append(list *l, char *a)
{
    node *t;
    if((t=malloc(sizeof(node)))==NULL)
        return;
    strcpy((char *)t->item, a);
    t->next=l->tail;
    t->prev=l->tail->prev;
    l->tail->prev->next=t;
    l->tail->prev=t;
    l->size++;
}
void printall(list *l)
{
    node *t=l->head;
    while(t->next!=l->tail)
    {
        printf("%s ", t->next->item);
        t=t->next;
    }
    putc('\n',stdout);
}
int find(list *l, char *target)
{
    node *t=l->head;
    while(t!=l->tail)
    {
        t=t->next;
        if((strcmp(t->item,target)==0))
            return 1;
    }
    return 0;
}
void empty_list(list *l)
{
    if(l->size!=0)
    {
        node *t=l->head->next;
        while(t!=l->tail)
        {
            free(t);
            t=t->next;
        }
    }
    l->head->next=l->tail;
    l->tail->prev=l->head;
    l->size=0;
}
void free_list(list *l)
{
    free(l->head);
    free(l->tail);
}
int main()
{
    int y,i;
    list l ,l2;
    scanf("%d", &y);
    getchar();
    for(i=0;i<y;i++)
    {
        init_list(&l);
        init_list(&l2);
        char string2[10001], string3[10001];
        scanf("%[^\n]", string2);
        getchar();
        while(1)
        {
            scanf("%[^\n]", string3); 
            getchar();
            if(strcmp(string3,"what does the fox say?")==0)
                break;
            char *string=strtok(string3," ");
            string=strtok(NULL, " ");
            string=strtok(NULL," ");
            append(&l,string);
        }
        char *string=strtok(string2, " ");
        while(string!=NULL)
        {
            if(!find(&l,string))
                append(&l2,string);
            string=strtok(NULL," ");
        }
        printall(&l2);
        empty_list(&l2);
        empty_list(&l);
    }
    free_list(&l2);
    free_list(&l);
    return 0;
}
