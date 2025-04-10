
#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
    char key;
    struct node *left;
    struct node *right;
}
node;

node * create(char key)
{
    node *n=(node *)malloc(sizeof(node));
    n->left=NULL;
    n->right=NULL;
    n->key=key;
}
//노드 방문
void visit(node *t)
{
    putc(t->key,stdout);
}
//전위 순회
void preorder_traverse(node *t)
{
    if(t!=NULL)
    {
        visit(t);        
        preorder_traverse(t->left);
        preorder_traverse(t->right);
    }
}
//인오더 순회
void inorder_traverse(node *t)
{
    if(t!=NULL)
    {
        inorder_traverse(t->left);
        visit(t);
        inorder_traverse(t->right);        
    }
}
//후위 순회
void postorder_traverse(node *t)
{
    if(t!=NULL)
    {
        postorder_traverse(t->left);
        postorder_traverse(t->right);
        visit(t);        
    }
}
int main()
{
    int N,i,j;
    scanf("%d", &N);
    getchar();
    //노드 받기
    node *root[N+1];
    char arr[N*3+1][2];
    for(i=0;i<N;i++)
    {
        root[i]=malloc(sizeof(node));
        root[i]->left=NULL;
        root[i]->right=NULL;
        scanf("%c %c %c", &root[i]->key, &arr[i][0], &arr[i][1]);
        getchar();
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(arr[i][0]==root[j]->key)
                root[i]->left=root[j];
            if(arr[i][1]==root[j]->key)
                root[i]->right=root[j];
        }
    }
        //전위 표기법
        preorder_traverse(root[0]);
        putc('\n',stdout);
        // 중위 표기법
        inorder_traverse(root[0]);
        putc('\n',stdout);
        //후위 표기법
        postorder_traverse(root[0]);
        putc('\n',stdout);
    //0을 반환하며 프로그램을 정상적으로 종료
    return 0;
}
