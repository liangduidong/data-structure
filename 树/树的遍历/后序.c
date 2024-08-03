#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char str;
    struct node *lchild, *rchild;
}Node;
// 后序打印
void printTree(Node* root){
    if(!root) return;
    printTree(root->lchild);
    printTree(root->rchild);
    printf("%c ", root->str);
    return;
}
