#include <stdio.h>
#include <stdlib.h>
typedef struct _node {int key; struct _node *next;} node;
node *head;
void insert_key(int k)
{
    int i;
    node *t;
    t=(node *)malloc(sizeof(node));
    t->key=1;
    head=t;
    for(i=2;i<=k;i++)
    {
        t->next=(node *)malloc(sizeof(node));
        t=t->next;
        t->key=i;
    }
    t->next=head;
}
void delete_after(node *t)
{
    node *v;
    v=t->next;
    t->next=t->next->next;
    free(v);
}
node* find_key(int k)
{
    node *t;
    t=head;
    while(t->key!=k)
        t=t->next;
    return t;
}
void josephus()
{
    int n,k,i;
    scanf("%d %d", &n, &k);
    insert_key(n);
    putc('<', stdout);
    node *t;
    t=find_key(n);
    while(t!=t->next)
    {
        for(i=0;i<k-1;i++)
            t=t->next;
        printf("%d, ", t->next->key);
        delete_after(t);
    }
    printf("%d>", t->key);
}
int main()
{
    josephus();
}
