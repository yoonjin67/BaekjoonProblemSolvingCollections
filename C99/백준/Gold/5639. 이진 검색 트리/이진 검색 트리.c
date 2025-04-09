#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct node {
    struct node *left, *right;
    int key;
} node;

void add_node(node *nd, int value) {
    if(nd->key < value) {
        if(nd->left!=NULL) {
            return (add_node(nd->left,value));
        }
        nd->left = (node *)malloc(sizeof(node));
        nd->left->key = value;
    } else {
        if(nd->right != NULL) {
            return (add_node(nd->right,value));
        }
        nd->right = (node *)malloc(sizeof(node));
        nd->right->key = value;
    }
}

void print_node(node *ptr) {
    if(ptr!=NULL) {
        printf("%d\n", ptr->key);
    }
}

void traverse(node *ptr) {
    if(ptr->right!=NULL) {
        traverse(ptr->right);
    }
    if(ptr->left!=NULL) {
        traverse(ptr->left);
    }
    print_node(ptr);
}
int main() {
    int len = 0;
    node root;
    memset(&root,0,sizeof(node));
    node * ptr = &root;
    char str[101];
    int x;
    while(1) {
        char *r = fgets(str,101,stdin);
        if(r==NULL) {
            break;
        }
       x = atoi(str);
       if(x==0) {
           break;
       }
       if(len==0) {
           ptr->key = x;
       } else {
           add_node(ptr,x);
       }
       len++;
    }
    traverse(ptr);

    return 0;
}