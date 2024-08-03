#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char str;
    struct node *lchild, *rchild;
    int ltag,rtag;
}Node, *ThreadTree;
// 中序打印
void printTree(Node* root){
    if(root!=NULL) return;
    printTree(root->lchild);
    printf("%c ", root->str);
    printTree(root->rchild);
    return;
}
// 创建树
Node *CreatNode(){
    char ch;
    // 清除输入缓冲区的换行符
    while ((ch = getchar()) == '\n');
    if(ch=='#') return NULL;
    Node *NewNode=(Node*)malloc(sizeof(Node));
    NewNode->str=ch;
    NewNode->ltag=0; NewNode->rtag=0;  // 新节点,线索初始化为0
    NewNode->lchild=CreatNode();
    NewNode->rchild=CreatNode();
    return NewNode;
}

/* 二叉树线索化 */
// 先序线索化
void PreOrderThread(Node *pre, Node *p){
    if(p==NULL) return;
    if(p->lchild==NULL){
        p->lchild=pre;
        p->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=p;
        pre->rtag=1;
    }
    pre=p;
    if(p->ltag==0) PreOrderThread(pre, p->lchild);  //先一直查找左节点
    if(p->rtag==0) PreOrderThread(pre, p->rchild);
    return;
}
void MidOrderThread(Node **pre, Node *p){
    if(p==NULL) return;
    MidOrderThread(pre, p->lchild);
    if(p->lchild==NULL){
        p->lchild=(*pre);
        p->ltag=1;
    }
    if((*pre)!=NULL&&(*pre)->rchild==NULL){
        (*pre)->rchild=p;
        (*pre)->rtag=1;
    }
    *pre=p;
    MidOrderThread(pre, p->rchild);
    return;
}
void RearOrderThread(Node **pre, Node *p){
    if(p==NULL) return;
    RearOrderThread(pre, p->lchild);
    RearOrderThread(pre, p->rchild);
    if(p->lchild==NULL){
        p->lchild=(*pre);
        p->ltag=1;
    }
    if((*pre)!=NULL&&(*pre)->rchild==0){
        (*pre)->rchild=p;
        (*pre)->rtag=1;
    }
    *pre=p;
    return;
}
int main(){
    // 创建线索化二叉树
    ThreadTree root=CreatNode();  //124##5##36##7##
    Node *pre=NULL;
    // 二叉树线索化
    // printf("---------先序线索化---------\n");
    // PreOrderThread(pre,root);
    // printf("先序线索化完成!\n");
    // printf("节点4的左子树应该为2: %c", root->lchild->lchild->lchild->str);
    // printf("---------中序线索化---------\n");
    // MidOrderThread(&pre, root);
    // printf("中序线索化完成!\n");
    // printf("节点6的右子树应该为3: %c", root->rchild->lchild->rchild->str);
    printf("---------后序线索化---------\n");
    RearOrderThread(&pre,root);
    printf("后序线索化完成!\n");
    printf("节点4的右子树应该为5: %c", root->lchild->lchild->rchild->str);
    return 0;
}
