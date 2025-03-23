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
    que->front->prev=que->front;
    que->rear->next=que->rear;
    que->rear->prev=que->front;
    que->size=0;
}
void empty_queue(queue *que)
{
    node *q=que->front->next;
    while(q->next!=que->rear)
    {
        free(q);
        q=q->next;
    }
    que->size=0;
}
void free_queue(queue *que)
{
    empty_queue(que);
    free(que->front);
    free(que->rear);
}
void push(queue *que, int item)
{
    node *q;
    if((q=(node *)malloc(sizeof(node)))==NULL)
        return ;
    else
    {
        q->key=item;
        que->rear->prev->next=q;
        q->prev=que->rear->prev;
        que->rear->prev=q;
        q->next=que->rear;
    }
    que->size++;
}
void pop(queue *que)
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
        free(q);
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
    char command[6]={'\0',};
    scanf("%s", command);
    if(strcmp(command,"pop")==0)
        pop(que);
    else if(strcmp(command,"size")==0)
        size(que);
    else if(strcmp(command,"empty")==0)
        empty(que);
    else if(strcmp(command,"back")==0)
        back(que);
    else if(strcmp(command,"front")==0)
        front(que);
    else if(strcmp(command,"push")==0)
    {
        int item;
        scanf("%d", &item);
        push(que,item);
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
    free_queue(&que);
    return 0;
}