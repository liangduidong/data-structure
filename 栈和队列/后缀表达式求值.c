#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define Max 100

typedef struct {
    double data[Max];
    int top;
} Stack;

void InitStack(Stack *stack) {
    stack->top = -1;
}

int IsEmpty(Stack *stack) {
    return stack->top == -1;
}

void Push(Stack *stack, double value) {
    if (stack->top < Max - 1) {
        stack->data[++stack->top] = value;
    }
}

double Pop(Stack *stack) {
    if (!IsEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return 0.0;
}

double Peek(Stack *stack) {
    if (!IsEmpty(stack)) {
        return stack->data[stack->top];
    }
    return 0.0;
}

double EvaluatePostfix(char* postfix) {
    Stack stack;
    InitStack(&stack);
    int i = 0;
    char token[Max];

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            int k = 0;
            while (isdigit(postfix[i]) || postfix[i] == '.') {
                token[k++] = postfix[i++];
            }
            token[k] = '\0';
            Push(&stack, atof(token));
        } else if (postfix[i] == ' ') {
            i++;
        } else {
            double operand2 = Pop(&stack);
            double operand1 = Pop(&stack);
            switch (postfix[i]) {
                case '+': Push(&stack, operand1 + operand2); break;
                case '-': Push(&stack, operand1 - operand2); break;
                case '*': Push(&stack, operand1 * operand2); break;
                case '/': Push(&stack, operand1 / operand2); break;
                case '^': Push(&stack, pow(operand1, operand2)); break;
                default: printf("Unsupported operator: %c\n", postfix[i]); break;
            }
            i++;
        }
    }
    return Pop(&stack);
}

int main() {
    char postfix[Max] = "3 4 2 * 1 5 - 2 3 ^ ^ / +";
    double result = EvaluatePostfix(postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %lf\n", result);

    return 0;
}
