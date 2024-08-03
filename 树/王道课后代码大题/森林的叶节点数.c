#include<stdio.h>
#include<stdlib.h>
#
typedef struct node{
    char str;
    struct node *firstchild,*sibling;
}Node,*csTree;

Node *CreatNode(){
    char ch;
    // 清除输入缓冲区的换行符
    while ((ch = getchar()) == '\n');
    if(ch=='#') return NULL;
    Node *NewNode=(Node*)malloc(sizeof(Node));
    NewNode->str=ch;
    NewNode->firstchild=CreatNode();
    NewNode->sibling=CreatNode();
    return NewNode;
}

int leaves(csTree tree){
    if(tree==NULL) return 0;
    if(tree->firstchild==NULL&&tree->sibling==NULL) return 1;
    return leaves(tree->firstchild)+leaves(tree->sibling);
}
int main(){
    // 创建孩子兄弟树
    Node *root=CreatNode();  // 124##5##36##7##
    int num=leaves(root);
    printf("该孩子兄弟法表示的森林共有 %d 个叶节点\n",num);
    return 0;
}