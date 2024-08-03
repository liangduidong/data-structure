/*基于顺序结构的栈*/
#include<stdio.h>
#include<stdlib.h>
# define Max 10
typedef struct Stack
{
    int data[Max];
    int top;
}Stack;
void InitStack(Stack *stack){
    stack->top=-1;
    return;
}

void print(Stack stack){
    for(int i=0;i<=stack.top;i++)
        printf("%d ",stack.data[i]);
    printf("\n");
    return;
}

void Push(Stack *stack, int x){
    if(stack->top==Max-1){
        printf("栈已满!");
        return;
    }
    stack->data[++stack->top]=x;
    return;
}
void Pop(Stack *stack, int *x){
    if(stack->top==-1){
        printf("栈为空!");
        return;
    }
    *x=stack->data[stack->top--];
    return;
}
void DestroyStack(Stack* stack){
    free(stack);
    printf("栈已销毁!");
}
int main(){
    Stack *stack = (Stack*)malloc(sizeof(Stack)); 
    InitStack(stack);
    Push(stack, 5);
    Push(stack, 7);
    print(*stack);
    int x;
    Pop(stack, &x);
    print(*stack);
    printf("%d\n", x);
    DestroyStack(stack);
    return 0;
}
