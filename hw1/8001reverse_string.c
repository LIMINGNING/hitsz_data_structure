#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

typedef struct stack {
    char *str;
    int top;
}Stack;

typedef struct queue {
    char *str;
    int rear;
    int front;
}Queue;

void resetStack(Stack *s) {
    s->top = -1;
    return ;
}

void resetQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
    return ;
}

int isStackFull(Stack s, int n) {
    if (s.top == n - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isQueueFull(Queue q, int n) {
    if (q.front - q.rear == n) {
        return 1;
    }
    else {
        return 0;
    }
}

int isStackEmpty(Stack s) {
    if (s.top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isQueueEmpty(Queue q) {
    if (q.rear == q.front) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(Stack *s, char c) {
    s->str[++(s->top)] = c;
    return ;
}

void pop(Stack *s, char *c) {
    *c = s->str[(s->top)--];
    return ;
}

void deQueue(Queue *q, char c) {
    q->str[++(q->front)] = c;
    return ;
}

void deQueue(Queue *q, char *c) {
    *c = q->str[++(q->rear)];
    return ;
}

/* Pop all elements from s and enqueue them into q,
   then dequeue all elements from qTemp and enqueue them into q. */
void clear(Stack *s, Queue *qTemp, Queue *q) {
    char temp;
    while (!isStackEmpty(*s)) {
        pop(s,&temp);
        deQueue(q,temp);
    }
    while (!isQueueEmpty(*qTemp)) {
        deQueue(qTemp,&temp);
        deQueue(q,temp);
    }
    return ;
}

void print(Queue *q) {
    char temp;
    while (!isQueueEmpty(*q)) {
        deQueue(q,&temp);
        printf("%c",temp);
    }
    return ;
}

void reverseString() {
    char str[MAX];
    scanf("%s",str);
    int len = strlen(str);

    int n;
    scanf("%d",&n);

    Stack s;
    s.str = (char *)malloc(sizeof(char) * n);
    resetStack(&s);

    Queue qTemp;
    qTemp.str = (char *)malloc(sizeof(char) * n);
    resetQueue(&qTemp);

    Queue q;
    q.str = (char *)malloc(sizeof(char) * len);
    resetQueue(&q);

    for (int i = 0; i < len; i++) {
        if (!isStackFull(s,n)) {
            push(&s,str[i]);
            if (i == len - 1) {
                clear(&s,&qTemp,&q);
            }
        }
        else if (isStackFull(s,n) && !isQueueFull(qTemp,n)) {
            deQueue(&qTemp,str[i]);
            if (i == len - 1) {
                clear(&s,&qTemp,&q);
            }
        }
        else {
            clear(&s,&qTemp,&q);
            resetQueue(&qTemp);
            resetStack(&s);
            i--;
        }
    }

    print(&q);
    free(s.str);
    free(qTemp.str);
    free(q.str);

    return ;
}

int main() {
    reverseString();
    return 0;
}