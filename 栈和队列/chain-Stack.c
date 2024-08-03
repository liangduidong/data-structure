/*基于链式结构的栈*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}LinkStack, Node;

void print(LinkStack *linkstack){
    Node *p=linkstack;
    while(p->next!=NULL){
        p=p->next;
        printf("%d ",p->data);
    }
    printf("\n");
    return;
}

void Push(LinkStack *linkstack, int x){
    Node* p=(Node*)malloc(sizeof(Node));
    p->data=x;
    p->next=linkstack->next;
    linkstack->next=p;
    return;
}
void Pop(LinkStack *linkstack, int *x){
    Node* p=linkstack;
    if(!p->next){
        printf("栈为空!");
        return;
    }
    *x=p->next->data;  // 弹出数据
    Node* q=p->next;
    p->next=q->next;
    free(q);  //将该弹出节点销毁
    return;
}

int main(){
    LinkStack *linkstack = (Node*)malloc(sizeof(Node));  //创建头节点
    linkstack->next = NULL;  
    // 采用头插法
    Push(linkstack, 5); 
    Push(linkstack, 7);
    print(linkstack);
    int x;
    Pop(linkstack, &x);
    print(linkstack);
    printf("x=%d\n", x);
    return 0;
}
