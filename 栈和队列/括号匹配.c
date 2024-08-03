#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define Max 100
typedef struct{
    char str[Max];
    int top;
}Stack;
void initstack(Stack *stack){
    stack->top=0;
    return;
}
void Push(Stack *stack, char x){
    if(stack->top==Max){
        printf("栈满!");
        return;
    }
    stack->str[stack->top++]=x;
    return;
}
void Pop(Stack *stack, char *x){
    if(stack->top==0){
        printf("栈空!");
        return;
    }
    *x=stack->str[--stack->top];
    return;
}
bool BracketsCheck(Stack stack, char str[]){
    int i=0;
    char ch=' ';
    while(str[i]!='\0'){
        switch(str[i]){
            case '(':Push(&stack, str[i]); break;
            case '[':Push(&stack, str[i]); break;
            case '{':Push(&stack, str[i]); break;
            case ')':Pop(&stack, &ch); if(ch!='(') return false; break;
            case ']':Pop(&stack, &ch); if(ch!='[') return false; break;
            case '}':Pop(&stack, &ch); if(ch!='{') return false; break;
            default:break;
        }
        i++;
    }
    if(stack.top==0) return true;
    return false;
}
int main(){
    Stack stack;
    initstack(&stack);
    char str[Max]="{a/b+[(c*d)-(d*f)]}";
    if(BracketsCheck(stack, str)) printf("匹配成功！");
    else printf("匹配失败!");
    return 0;
}