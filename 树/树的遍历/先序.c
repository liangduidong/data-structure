#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char str;
    struct node *lchild, *rchild;
}Node;
// 先序打印
void printTree(Node* root){
    if(!root) return;
    printf("%c ", root->str);
    printTree(root->lchild);
    printTree(root->rchild);
    return;
}
