#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char str;
    struct node *lchild, *rchild;
}Node;

// 按照先序遍历创建树
Node *CreatNode(){
    char ch;
    printf("node:");
    // 清除输入缓冲区的换行符
    while ((ch = getchar()) == '\n');
    if(ch=='#') return NULL;
    Node *NewNode=(Node*)malloc(sizeof(Node));
    NewNode->str=ch;
    NewNode->lchild=CreatNode();
    NewNode->rchild=CreatNode();
    return NewNode;
}
// 先序打印
void printTree(Node* root){
    if(!root) return;
    printf("%c ", root->str);
    printTree(root->lchild);
    printTree(root->rchild);
    return;
}

int main(){
    Node *root=CreatNode();
    printTree(root);
    return 0;
}