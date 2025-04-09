#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{int key;struct node *next;struct node *prev;} node;
typedef struct queue{node *front;node *rear;int size;} queue;
void init_queue(queue *que)
{
    que->front=(node *)malloc(sizeof(node));
    que->rear=(node *)malloc(sizeof(node));
    que->front->next=que->rear;
    que->front->prev=que->rear;
    que->rear->next=que->front;
    que->rear->prev=que->front;
    que->size=0;
}
void empty_queue(queue *que)
{
    if(que->size==0) {
        return;
    }
    node *q=que->front;
    while(q->next!=NULL)
    {
        node *p=q->next;
        //free(q);
        q=p;
    }
    que->size=0;
}
void push_back(queue *que, int item)
{
    node *q;
    if((q=(node *)malloc(sizeof(node)))==NULL)
        return ;
    else
    {
        q->key=item;
        q->prev=que->rear->prev;
        q->next=que->rear;
        que->rear->prev->next=q;
        que->rear->prev=q;
    }
    que->size++;
}
void push_front(queue *que, int item)
{
    node *q;
    if((q=(node *)malloc(sizeof(node)))==NULL)
        return ;
    else
    {
        q->key=item;
        node *fptr = que->front->next;
        que->front->next=q;
        q->prev=que->front;
        q->next=fptr;
        fptr->prev=q;
    }
    que->size++;
}
void pop_front(queue *que)
{
    if(que->size==0)
    {
        puts("-1");
        return ;
    }
    else
    {
        node *q=que->front->next;
        que->front->next=que->front->next->next;
        que->front->next->prev=que->front;
        printf("%d\n", q->key);
        //free(q);
        que->size--;
    }
}
void pop_back(queue *que)
{
    if(que->size==0)
    {
        puts("-1");
        return ;
    }
    else
    {
        node *q=que->rear->prev;
        que->rear->prev=que->rear->prev->prev;
        que->rear->prev->next=que->rear;
        printf("%d\n", q->key);
        //free(q);
        que->size--;
    }
}
void empty(queue *que)
{
    if(que->size==0)
        puts("1");
    else
        puts("0");
}
void size(queue *que)
{
    printf("%d\n", que->size);
}
void front(queue *que)
{
    if(que->size==0)
        puts("-1");
    else
        printf("%d\n",que->front->next->key);
}
void back(queue *que)
{
    if(que->size==0)
        puts("-1");
    else
        printf("%d\n",que->rear->prev->key);
}
void task(queue *que)
{
    char command[11]={'\0',};
    scanf("%s", command);
    if(strcmp(command,"pop_back")==0)
        pop_back(que);
    else if(strcmp(command,"pop_front")==0)
        pop_front(que);
    else if(strcmp(command,"size")==0)
        size(que);
    else if(strcmp(command,"empty")==0)
        empty(que);
    else if(strcmp(command,"back")==0)
        back(que);
    else if(strcmp(command,"front")==0)
        front(que);
    else if(strcmp(command,"push_front")==0)
    {
        int item;
        scanf("%d", &item);
        push_front(que,item);
    }
    else if(strcmp(command,"push_back")==0)
    {
        int item;
        scanf("%d", &item);
        push_back(que,item);
    }
    else
        return;
}
int main()
{
    queue que;
    init_queue(&que);
    int i, N;
    scanf("%d", &N);
    for(i=0;i<N;i++)
        task(&que);
    return 0;
}