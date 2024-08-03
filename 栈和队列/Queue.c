/*顺序存储的循环队列*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
# define Max 10
typedef struct{
    int data[Max];
    int front, rear;
}Queue;

bool Isempty(Queue Q){
    if(Q.front==Q.rear){
        printf("队空!\n");
        return true;
    }
    return false;
}
bool Isfull(Queue Q){
    if(Q.front==(Q.rear+1)%Max){
        printf("队满!\n");
        return true;
    }
    return false;
}
void print(Queue Q){
    if(Isempty(Q)) return;  //判断是否为空
    // printf("%d", Q.data[Q.front+1]);
    for(int i=(Q.front+1)%Max;i!=(Q.rear+1)%Max;i=(i+1)%Max){
        printf("%d ", Q.data[i]);
    }
    printf("\n");
    return;
}
void InitQueue(Queue *Q){
    Q->front=0;
    Q->rear=0;
    printf("已初始化!\n");
    return;
}
// front指向队头前一个元素
void EnQueue(Queue *Q, int x){
    if(Isfull(*Q)) return;
    ++Q->rear;
    Q->data[Q->rear%Max]=x;
    return;
}
void DeQueue(Queue* Q, int *x){
    if(Isempty(*Q)) return;
    ++Q->front;
    *x = Q->data[Q->front%Max];
    return;
}
int main(){
    Queue *Q=(Queue*)malloc(sizeof(Queue));
    InitQueue(Q);
    int x;
    EnQueue(Q, 4);
    EnQueue(Q, 7);
    EnQueue(Q, 9);
    EnQueue(Q, 3);
    EnQueue(Q, 2);
    print(*Q);
    DeQueue(Q, &x);
    print(*Q);
    printf("%d\n", x);
    DeQueue(Q, &x);
    print(*Q);
    printf("%d\n", x);
    return 0;
}