#include <stdio.h>
#include <string.h>
#define MAX 1000

typedef struct stack {
    char str[MAX];
    int top;
}Stack;

void initStack(Stack *s) {
    s->top = -1;
    return ;
}

/**
 * Push a character into stack.
 * @param s Operation stack.
 * @param c Char c.
 * @return 1 success, 0 fail.
 */
int push(Stack *s, char c) {
    if (s->top == MAX - 1) {
        return 0;
    }
    else {
        s->str[++(s->top)] = c;
        return 1;
    }
}

/**
 * Delete the top element of stack.
 * @param s Operation stack.
 * @return 1 success, 0 fail.
 */
int pop(Stack *s) {
    if (s->top == -1) {
        return 0;
    }
    else {
        (s->top)--;
        return 1;
    }
}

char getTop(Stack s) {
    if (s.top == -1) {
        return '\0';
    }
    else {
        return s.str[s.top];
    }   
}

int isMatch(char left, char right) {
    return (left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}');
}

void parMatch() {
    char str[MAX];
    Stack s;
    initStack(&s);
    scanf("%s",str);
    int len = strlen(str);
    int halfLen = len / 2;

    if (len % 2 == 1) {
        printf("False\n");
        return;
    }

    /* When encountering a left parenthesis,
       push it onto the stack;
       when encountering a right parenthesis,
       pop the top element from the stack and compare whether it matches. */
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{') {
            /* char top = getTop(s);
            if (s.top != -1) {
                if (c > top) {
                    printf("False\n");
                    return ;
                }
            } */
            push(&s,c);
        }
        else {
            char top = getTop(s);
            if (!isMatch(top,c)) {
                printf("False\n");
                return ;
            }
            pop(&s);
        }
    }

    /* If stack is empty at last,
       it means that match is successful.  */
    if (s.top == -1) {
        printf("True\n");
    }
    else {
        printf("False\n");
    }
    return ;
}

int main() {
    parMatch();
    return 0;
}