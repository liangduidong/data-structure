#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* next;
}Node;
typedef struct{
    Node* front, *rear;
}LinkQueue;

void InitQueue(LinkQueue* Q){
    Node* head=(Node*)malloc(sizeof(Node));  //建立头节点
    Q->front=head;
    Q->rear=head;
    Q->rear->next=NULL;
    printf("已初始化!\n");
    return;
}
void EnQueue(LinkQueue* Q, int x){
    Node* p=(Node*)malloc(sizeof(Node));
    p->data=x;
    Q->rear->next=p;
    p->next=NULL;
    Q->rear=p;
    return;
}
void DeQueue(LinkQueue* Q, int *x){
    if(Q->rear==Q->front) return;  //判空
    *x=Q->front->next->data;
    Node* p=Q->front;
    Q->front=p->next;
    free(p);
    return;
}
void print(LinkQueue* Q){
    Node* p=Q->front->next;
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
    return;
}
int main(){
    LinkQueue *Q=(LinkQueue*)malloc(sizeof(LinkQueue));
    InitQueue(Q);
    int x;
    EnQueue(Q, 4);
    EnQueue(Q, 7);
    EnQueue(Q, 9);
    EnQueue(Q, 3);
    EnQueue(Q, 2);
    print(Q);
    DeQueue(Q, &x);
    printf("%d\n",x);
    print(Q);
    DeQueue(Q, &x);
    printf("%d\n",x);
    print(Q);
    return 0;
}