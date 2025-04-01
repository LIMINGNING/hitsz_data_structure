#include <stdio.h>
#include <stdbool.h>
#define MAX 10000

typedef struct stack
{
    int arr[MAX];
    int top;
}Stack;

void initStack(Stack *s) {
    s->top = -1;
    return ;
}

/**
 * Push an element in stack s.
 * @param s Operation stack.
 * @param num Element to be pushed.
 * @return Return 0 if stack is full, otherwise return 1.
 */
int push(Stack *s,int num) {
    if (s->top == MAX - 1) {
        return 0; /* Stack is full. */
    }
    else {
        s->arr[++(s->top)] = num;
        return 1; /* Operation successful. */
    }
}

/**
 * Pop an element from stack s.
 * @param s Operation stack.
 * @param data Accept element.
 * @return 1 success, 0 fail.
 */
int pop(Stack *s, int *data) {
    if (s->top == -1) {
        return 0;
    }
    else {
        *data = s->arr[(s->top)--];
        return 1;
    }
}

bool isStackEmpty(Stack s) {
    if (s.top == -1) {
        return true;
    }
    else {
        return false;
    }
}

/**
 * Get the top element of stack without deleting it.
 * @param s Operation stack.
 * @param data Accept top element.
 * @return 1 success, 0 fail.
 */
int getTop(Stack s, int *data) {
    if (s.top == -1) {
        return 0;
    }
    else {
        *data = s.arr[s.top];
        return 1;
    }
}

void insertOrderedArray(int n) {
    Stack s1,s2;
    initStack(&s1);
    initStack(&s2);
    int accept = 0;
    for (int i = 0; i < n; i++) { /* Push the received data into stack s1. */
        scanf("%d",&accept);
        push(&s1,accept);
    }

    int insert = 0;
    scanf("%d",&insert);

    int temp = 0;
    getTop(s1,&temp);
    while (!isStackEmpty(s1) && insert < temp) { /* Compare the data to be inserted with the top element of the stack s1. */
        pop(&s1,&temp);
        push(&s2,temp);

        getTop(s1,&temp);
    }

    
    push(&s2,insert);

    while (!isStackEmpty(s1)) { /* Push the remaining elements in s1 into s2. */
        pop(&s1,&temp);
        push(&s2,temp);
    }

    while (!isStackEmpty(s2)) { /* Output. */
        pop(&s2,&temp);
        printf("%d",temp);
        if (s2.top != -1) {
            printf(" ");
        }
    }
    
    return ;
}

int main() {
    int n;
    scanf("%d",&n);
    insertOrderedArray(n);
    return 0;
}