#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int sum = 1;
typedef struct node {
    int value;
    int childsLen;
    int *childs;
    int parent;
} node;
node *tree;
void task(node *nd) {
    int i;
    if(nd->childsLen==0) {
        nd->value = -2;
    } else {
     for(i=0;i<nd->childsLen;i++) {
        task(&tree[nd->childs[i]]);
     }
      nd->childsLen = 0;
      free(nd->childs);
    }

}


int main() {
    int X=0;
    int i,num=0, rootIdx=0;
    scanf("%d", &X);
    tree=calloc(X,sizeof(node));
    i = 0;
    for(;i<X;i++) {
        scanf("%d",&num);

        if(num==-1) {
            tree[i].value=0;
            rootIdx = i;
        } else {
            tree[i].value=i;
            tree[num].childs = realloc(tree[num].childs,sizeof(int)*(tree[num].childsLen+1));
            tree[num].childs[tree[num].childsLen]=i;
            tree[num].childsLen++;
            tree[i].parent = num;
        }
    }

    scanf("%d",&num);
    if(num==rootIdx) {
        puts("0");
        return 0;
    }
    for(i=0;i<tree[tree[num].parent].childsLen;i++) {
        if(tree[tree[num].parent].childs[i]==num) {
            tree[tree[num].parent].childs[i]=tree[tree[num].parent].childs[tree[tree[num].parent].childsLen];
        }
    }
    tree[tree[num].parent].childsLen--;
    task(&tree[num]);
    for(i=0;i<X;i++) {
        if(tree[i].childsLen==0) {
            if(tree[i].value>=0) {
        	      sum++;
           } else {
               sum--;
           }
        }
    }
    printf("%d", sum);
    return 0;
}
