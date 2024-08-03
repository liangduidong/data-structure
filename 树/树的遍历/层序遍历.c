#include<stdio.h>
#include<stdlib.h>
# define Max 100
typedef struct node{
    char str;
    struct node *lchild, *rchild;
}Node;
typedef struct{
    Node *ch[Max];
    int front, rear;
}Queue;
// 入队操作
void EnQueue(Queue *Q, Node *x){
    if((Q->rear+1)%Max==Q->front){
        printf("队满!\n");
        return;
    }
    Q->rear=(Q->rear+1)%Max;
    Q->ch[Q->rear]=x;
    return;
}
// 出队操作
Node *DeQueue(Queue *Q){
    if(Q->front==Q->rear){
        printf("队空!\n");
        return NULL;
    }
    Q->front=(Q->front+1)%Max;
    return Q->ch[Q->front];
}
void InitQueue(Queue *Q){
    Q->front=-1;
    Q->rear=-1;
    return;
}
// 按照先序遍历创建树
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
// 层序遍历
void LevelOrder(Node *root){
    if(root==NULL){
        printf("树空!\n");
        return;
    }
    Node *temp;
    Queue Q;
    InitQueue(&Q);
    // 根节点入栈
    EnQueue(&Q, root);
    while(Q.front!=Q.rear){
        temp=DeQueue(&Q);
        printf("%c ", temp->str);
        if(temp->lchild!=NULL) EnQueue(&Q, temp->lchild);
        if(temp->rchild!=NULL) EnQueue(&Q, temp->rchild);
    }
    return;
}
int main(){
    Node *root=CreatNode();  // 124##5##36##7##
    Node *temp=root;
    // 层序遍历方式
    printf("---------------\n层序遍历：");
    LevelOrder(root);
    return 0;
}