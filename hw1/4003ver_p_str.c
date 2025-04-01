#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000

typedef struct {
    char arr[MAX];
    int top;
}Stack;

void initStack(Stack *s) {
    s->top = -1;
    return ;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s,char c) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = c;
    }
    return ;
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0';
}

int isAlphaNumeric(char c) {
    return isalnum((unsigned int) c); /* If c is a number or letter, return 1 otherwise return 0. */
}

int isPStr(char *s) {
    Stack stack;
    initStack(&stack);
    int len = strlen(s);
    int i;

    for (int i = 0; i < len; i++) {
        if (isAlphaNumeric(s[i])) {
            push(&stack,tolower(s[i]));
        }
    }

    for (int i = 0; i < len; i++) {
        if (isAlphaNumeric(s[i])) {
            if (tolower(s[i]) != pop(&stack)) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    char str[MAX];

    fgets(str, MAX, stdin);

    if (isPStr(str)) {
        printf("true\n");
    } 
    else {
        printf("false\n");
    }

    return 0;
}