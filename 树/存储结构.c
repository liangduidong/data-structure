#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *lchild, *rchild;
}Node;

int main(){
    Node *root=(Node*)malloc(sizeof(Node));
    root->lchild=NULL;
    root->rchild=NULL;
    root->data=5;
    printf("%d",root->data);
}