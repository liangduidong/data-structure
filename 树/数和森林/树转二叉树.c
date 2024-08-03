#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode *firstChild, *nextSibling;
}Tree;
typedef struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *lchild,*rchild;
}BinaryTree;

BinaryTree *ConvertToBinaryTree(Tree *root){
    if(root==NULL) return NULL;
    BinaryTree *BTree=(BinaryTree*)malloc(sizeof(BinaryTree));
    BTree->lchild=NULL;
    BTree->rchild=NULL;
    BTree->data=root->data;
    printf("测试样例:%d\n", BTree->data); 
    // 如果当前节点有孩子，则第一个孩子作为左节点，其余左孩子的右节点
    BTree->lchild=ConvertToBinaryTree(root->firstChild);
    Tree *sibling = root->firstChild;  // 查看其其余孩子
    if(sibling==NULL) return BTree;
    BinaryTree *temp=(BinaryTree*)malloc(sizeof(BinaryTree));
    BTree->lchild=temp; //指向二叉树的左孩子
    while(sibling!=NULL){  //若该节点右多个孩子
        // if(sibling->nextSibling==NULL) break;
        temp->rchild=ConvertToBinaryTree(sibling);
        temp=temp->rchild;
        sibling=sibling->nextSibling;
    }
    return BTree;
}

// 测试函数
int main() {
    // 创建一个示例的树结构
    Tree *root = (Tree*)malloc(sizeof(Tree));
    root->data = 1;
    // printf("%d\n", root->data);
    root->firstChild = (Tree*)malloc(sizeof(Tree));
    root->firstChild->data = 2;

    root->firstChild->nextSibling = (Tree*)malloc(sizeof(Tree));
    root->firstChild->nextSibling->data = 3;

    root->firstChild->firstChild = (Tree*)malloc(sizeof(Tree));
    root->firstChild->firstChild->data = 4;

    root->firstChild->firstChild->nextSibling = (Tree*)malloc(sizeof(Tree));
    root->firstChild->firstChild->nextSibling->data = 5;

    // 转化为二叉树
    BinaryTree *binaryTree = ConvertToBinaryTree(root);
    //    1                 1
    //  2   3   ===>      2
    // 4 5             4    3
    //                   5
    printf("测试样例:%d", binaryTree->lchild->lchild->rchild->data); 
    return 0;
}