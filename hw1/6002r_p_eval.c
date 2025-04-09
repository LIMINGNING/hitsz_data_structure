#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct stack {
    int arr[MAX];
    int top;
}Stack;

void initStack(Stack *s) {
    s->top = -1;
    return ;
}

int push(Stack *s, int n) {
    if (s->top == MAX - 1) {
        return 0;
    }
    else {
        s->arr[++(s->top)] = n;
        return 1;
    }
}

int pop(Stack *s, int *n) {
    if (s->top == -1) {
        return 0;
    }
    else {
        *n = s->arr[(s->top)--];
        return 1;
    }
}

int op(char c, int op1, int op2) {
    switch (c)
    {
    case '+':
        return op2 + op1;

    case '-':
        return op2 - op1;

    case '*':
        return op2 * op1;

    case '/':
        return op2 / op1;
    
    default:
        return 0;
    }
}

int isOperator(char *c) {
    return *c == '+' || *c == '-' || *c == '*' || *c == '/';
}

void reversePoNoEval() {
    int n;
    scanf("%d",&n);
    while(getchar() != '\n');
    char *tokens[n];

    Stack s;
    initStack(&s);
    int temp = 0;
    int op1,op2;
    int result;

    for (int i = 0; i < n; i++) {
        tokens[i] = (char *)malloc(sizeof(char) * 20);
        scanf("%s",tokens[i]);
        if (!isOperator(tokens[i])) {
            temp = atoi(tokens[i]);
            push(&s,temp);
        }
        else {
            pop(&s,&op1);
            pop(&s,&op2);
            result = op(*tokens[i],op1,op2);
            if (i == n - 1) {
                break ;
            }
            push(&s,result);
        }
    }

    printf("%d",result);
}

int main() {
    reversePoNoEval();
    return 0;
}