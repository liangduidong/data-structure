#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char str;
    struct node *lchild, *rchild;
}Node;
// 中序打印
void printTree(Node* root){
    if(!root) return;
    printTree(root->lchild);
    printf("%c ", root->str);
    printTree(root->rchild);
    return;
}
