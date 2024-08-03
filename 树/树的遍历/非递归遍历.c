#include<stdio.h>
#include<stdlib.h>
# define Max 100
typedef struct node{
    char str;
    struct node *lchild, *rchild;
}Node;
typedef struct{
    Node *ch[Max];
    int len;
}Stack;
// 进栈操作
void Push(Stack *stack, Node *x){
    if(!x) return;
    if(stack->len==Max){
        printf("栈满!");
        return;
    }
    stack->ch[stack->len]=x;
    stack->len++;
    return;
}
// 出栈操作
Node *Pop(Stack *stack){
    if(stack->len==0){
        printf("空栈!");
        return NULL;
    }
    stack->len--;
    return stack->ch[stack->len]; 
}
Node *GetTopNode(Stack *stack){
    if(stack->len==0){
        printf("空栈!");
        return NULL;
    }
    return stack->ch[stack->len-1];
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
// 先序打印
void printTree(Node* root){
    if(!root) return;
    printf("%c ", root->str);
    printTree(root->lchild);
    printTree(root->rchild);
    return;
}
// // 非递归先序遍历----栈
// void PreOrder(Node *root){
//     if(!root){
//         printf("树空!\n");
//         return;
//     }
//     // 初始化栈
//     Stack stack;
//     stack.len=0;
//     // 根节点入栈
//     Push(&stack, root);
//     Node *temp;
//     while(stack.len!=0){
//         temp=Pop(&stack);
//         printf("%c ",temp->str);
//         if(temp->rchild!=NULL) Push(&stack, temp->rchild); 
//         if(temp->lchild!=NULL) Push(&stack, temp->lchild);
//     }
//     return;
// }
// 非递归先序遍历----栈
void PreOrder(Node *root){
    if(!root){
        printf("树空!\n");
        return;
    }
    // 初始化栈
    Stack stack;
    stack.len=0;
    // 根节点入栈
    Node *temp=root;
    while(stack.len!=0||temp!=NULL){
        while(temp){
            Push(&stack, temp);
            printf("%c ",temp->str);
            temp=temp->lchild;
        }
        temp=Pop(&stack)->rchild;
    }
    return;
}
// 非递归中序遍历----栈
void MidOrder(Node *root){
    if(!root){
        printf("树空!\n");
        return;
    }
    // 初始化栈
    Stack stack;
    stack.len=0;
    // 根节点入栈
    Push(&stack, root);
    Node *temp=root->lchild;
    while(stack.len!=0||temp!=NULL){
        while(temp){
            Push(&stack, temp);  // 如果有左子树,则左子树先入栈
            temp=temp->lchild;
        }
        if(stack.len!=0){
            temp=Pop(&stack);  //无左子树时,开始出栈
            printf("%c ",temp->str);
            temp=temp->rchild;
        }
    }
    return;
}
// 非递归后序遍历----栈
void RearOrder(Node *root) {
    if (!root) {
        printf("树空!\n");
        return;
    }
    // 初始化栈
    Stack stack;
    stack.len = 0;
    Node *temp = root;
    Node *lastVisited = NULL; 

    while (stack.len != 0 || temp != NULL) {
        //将所有左节点优先入栈
        while (temp != NULL) { 
            Push(&stack, temp);
            temp = temp->lchild;
        }
        // 当没有左节点时,访问右节点
        temp = GetTopNode(&stack); 
        if (temp->rchild == NULL || temp->rchild == lastVisited) { //右节点为空或已访问则该节点出栈
            printf("%c ", temp->str);
            Pop(&stack);
            lastVisited = temp; //将最后访问节点指针，指向刚访问过并出栈大的指针
            temp = NULL; // 方便继续出栈
        } else {
            temp = temp->rchild; // 将右节点当作根节点，继续新一轮的后序遍历
        }
    }
}

int main(){
    Node *root=CreatNode();  // 124##5##36##7##
    Node *temp=root;
    Stack stack;
    stack.len=0;
    while(temp!=NULL){
            Push(&stack, temp);  // 如果有左子树,则左子树先入栈
            printf("%c\n", temp->str);
            temp=temp->lchild;
        }
    // 三种遍历方式
    printTree(root);
    printf("\n---------------\n先序：");
    PreOrder(root);
    printf("\n---------------\n中序：");
    MidOrder(root);
    printf("\n---------------\n后序：");
    RearOrder(root);
    return 0;
}