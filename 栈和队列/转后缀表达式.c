#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define Max 100

typedef struct {
    char data[Max];
    int top;
} Stack;

void InitStack(Stack *stack) {
    stack->top = -1;
}

int IsEmpty(Stack *stack) {
    return stack->top == -1;
}

void Push(Stack *stack, char ch) {
    if (stack->top < Max - 1) {
        stack->data[++stack->top] = ch;
    }
}

char Pop(Stack *stack) {
    if (!IsEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

char Peek(Stack *stack) {
    if (!IsEmpty(stack)) {
        return stack->data[stack->top];
    }
    return '\0';
}

int IsOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int Precedence(char op) {
    if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

void InfixToPostfix(char* infix, char* postfix) {
    Stack stack;
    InitStack(&stack);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isdigit(ch) || isalpha(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            Push(&stack, ch);
        } else if (ch == ')') {
            while (!IsEmpty(&stack) && Peek(&stack) != '(') {
                postfix[k++] = Pop(&stack);
            }
            Pop(&stack); // pop '('
        } else if (IsOperator(ch)) {
            while (!IsEmpty(&stack) && Precedence(Peek(&stack)) >= Precedence(ch)) {
                postfix[k++] = Pop(&stack);
            }
            Push(&stack, ch);
        }
    }

    while (!IsEmpty(&stack)) {
        postfix[k++] = Pop(&stack);
    }

    postfix[k] = '\0';
}

int main() {
    char infix[Max] = "a+b*(c^d-e)^(f+g*h)-i";
    char postfix[Max];

    InfixToPostfix(infix, postfix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);

    return 0;
}
