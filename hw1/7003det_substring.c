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

/* Push char c to stack s. */
int push(Stack *s, char c) {
    if (s->top == MAX - 1) {
        return 0;
    }
    else {
        s->str[++(s->top)] = c;
        return 1;
    }
}

/* Get top element of stack without deleting it. */
char getTop(Stack s) {
    return s.str[s.top];
}

/* Delete top element of stack. */
int deleteTop(Stack *s) {
    if (s->top == -1) {
        return 0;
    }
    else {
        (s->top)--;
        return 1;
    }
}

void pushAll(int len,Stack *s,char *temp) {
    for (int i = 0; i < len; i++) {
        push(s,*(temp+i));
    }
    return ;
}

int isEmpty(Stack s) {
    if (s.top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void detSubstring() {
    Stack s1,s2;
    initStack(&s1);
    initStack(&s2);
    char temp[MAX];

    fgets(temp,MAX,stdin);
    int len = strlen(temp);   
    pushAll(len,&s1,temp);

    fgets(temp,MAX,stdin);
    len = strlen(temp);
    pushAll(len,&s2,temp);

    while (!isEmpty(s1) && !isEmpty(s2)) {
        char tops1 = getTop(s1);
        char tops2 = getTop(s2);
        if (tops1 == tops2) {
            deleteTop(&s1);
            deleteTop(&s2);
        }
        else {
            deleteTop(&s1);
        }
    }

    if (isEmpty(s2)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
}

int main() {
    detSubstring();
    return 0;
}