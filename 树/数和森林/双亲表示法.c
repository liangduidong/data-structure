/*双亲表示法*/
#include<stdio.h>
#include<stdlib.h>
#define Max 100
typedef struct node{
    int data;
    int parent;
}Node;
typedef struct tree{
    Node nodes[Max];
    int len;
}ParentTree;
void initTree(ParentTree *tree){
    tree->len=15;
    for(int i=1;i<=tree->len;i++){
        tree->nodes[i].data=i;
        tree->nodes[i].parent=i/2;
    }
    return;
}
int main(){
    // 初始化双亲表示法的树
    ParentTree tree;
    initTree(&tree);
    printf("%d", tree.nodes[tree.nodes[10].parent]);
    return 0;
}
