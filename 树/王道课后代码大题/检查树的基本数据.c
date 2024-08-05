#include<stdio.h>
#include<stdlib.h>
#
typedef struct node{
    char str;
    struct node *lchild,*rchild;
}Node,*csTree;

Node *CreatNode(){
    char ch;
    // 清除输入缓冲区的换行符
    while ((ch = getchar()) == '\n');
    if(ch=='#') return NULL;
    Node *NewNode=(Node*)malloc(sizeof(Node));
    NewNode->str=ch;
    NewNode->lchild=CreatNode();
    NewNode->rchild=CreatNode();
    return NewNode;
}
// 度为1的节点数
int onechild(csTree tree){
    if(tree==NULL) return 0;
    int num=0;
    if(tree->lchild==NULL&&tree->rchild!=NULL||tree->lchild!=NULL&&tree->rchild==NULL) num+=1;
    return onechild(tree->lchild)+onechild(tree->rchild)+num;
}
// 度为2的节点数
int towchild(csTree tree){
    if(tree==NULL) return 0;
    int num=0;
    if(tree->lchild!=NULL&&tree->rchild!=NULL) num+=1;
    return towchild(tree->lchild)+towchild(tree->rchild)+num;
}
 // 叶子节点数
int leaves(csTree tree){
    if(tree==NULL) return 0;
    if(tree->lchild==NULL&&tree->rchild==NULL) return 1;
    return leaves(tree->lchild)+leaves(tree->rchild);
}
// 树的高度
int heighth(csTree tree){
    if(tree==NULL) return 0;
    int left=heighth(tree->lchild), right=heighth(tree->rchild);
    int Max = (left > right) ? left:right;
    return 1+Max;
}
// // 计算树的宽度
// int TreeWidth(csTree tree) {
//     if (tree == NULL) {
//         return 0;
//     }
    
//     int maxWidth = 0;
//     Node* currentLevel = tree;
    
//     while (currentLevel != NULL) {
//         int currentWidth = 0;
//         Node* current = currentLevel;
        
//         while (current != NULL) {
//             currentWidth++;
//             current = current->sibling;
//         }
        
//         if (currentWidth > maxWidth) {
//             maxWidth = currentWidth;
//         }
        
//         // 移动到下一层的第一个节点
//         currentLevel = currentLevel->firstchild;
//     }
    
//     return maxWidth;
// }
int maxnum(csTree tree){
    if(tree==NULL) return '0';
    int left=maxnum(tree->lchild), right=maxnum(tree->rchild);
    int Max = (left > right) ? left:right;
    return (Max>tree->str) ? Max:tree->str;
}
int main(){
    // 创建孩子兄弟树
    Node *root=CreatNode();  // 124##5##36##7##
    printf("度为0的节点数: %d\n", leaves(root));
    printf("度为1的节点数: %d\n", onechild(root));
    printf("度为2的节点数: %d\n", towchild(root));
    printf("树高: %d\n", heighth(root));
    printf("树中最大值: %c\n", maxnum(root));
    // printf("树宽: %d\n", width(root));  采用层序遍历的思路
    return 0;
}