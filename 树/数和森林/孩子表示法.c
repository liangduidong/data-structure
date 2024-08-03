#include<stdio.h>
#include<stdlib.h>
#define Max 100
// 孩子索引节点
typedef struct node{
    int position;
    struct node *nextchild;
}nodechild;
// 树的节点
typedef struct{
    int data;
    nodechild *firstchild;
}Node;
// 孩子表示法的树
typedef struct{
    Node nodes[Max];
    int len; 
}ChildTree;

int main(){
    ChildTree Tree;
}