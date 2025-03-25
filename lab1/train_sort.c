#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* Define the stack structure. */
typedef struct {
    int data[MAX_SIZE];
    int top;  /* peek is data[top]. */
} Stack;

/* Initialize the stack. */
void initStack(Stack *s) {
    for (int i = 0; i < MAX_SIZE; i++) {
        s->data[i] = 0;
    }
    s->top = -1;
    return ;
}

/* Check if the stack is empty. */
int isStackEmpty(Stack *s) {
    if (s->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

/* Check if the stack is full. */
int isStackFull(Stack *s) {
    if (s->top == MAX_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

/* Push an element onto the stack. */
void push(Stack *s, int value) {
    if (isStackFull(s)) {
        printf("Stack overflow!\n");
        return ;
    }
    s->data[++(s->top)] = value;
    return ;
}

/* Pop an element from the stack. */
int pop(Stack *s) {
    return s->data[(s->top)--];
}

/* Get the top element of the stack. */
int peek(Stack *s) {
    return s->data[s->top];
}

/* Define the queue structure. */
typedef struct {
    int data[MAX_SIZE];
    int front;  /* Head is data[front]. */
    int rear;   /* Tail is data[rear-1]. */
} Queue;

/* Initialize the queue. */
void initQueue(Queue *q) {
    for (int i = 0; i < MAX_SIZE; i++) {
        q->data[i] = 0;
    }
    q->front = 0;
    q->rear = 0;
}

/* Check if the queue is empty. */
int isQueueEmpty(Queue *q) {
    if (q->front == q->rear) {
        return 1;
    }
    else {
        return 0;
    }
}

/* Check if the queue is full. */
int isQueueFull(Queue *q) {
    if (q->rear == MAX_SIZE) {
        return 1;
    }
    else {
        return 0;
    }
}

/* Enqueue an element into the queue. */
void enqueue(Queue *q, int value) {
    q->data[(q->rear)++] = value;
    return ;
}

/* Dequeue an element from the queue. */
int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }
    return q->data[(q->front)++];
}

/* Get the front element of the queue. */
int front(Queue *q) {
    return q->data[q->front];
}

void input_data(Stack *s1, Stack *s2) {
    int temp;
    while (scanf("%d", &temp) == 1) {
        push(s1, temp);
        if (getchar() == '\n') {
            break;
        }
    }
    while (scanf("%d", &temp) == 1) {
        push(s2, temp);
        if (getchar() == '\n') {
            break;
        }
    }
    return ;
}

void sort_data(Stack *s1, Stack *s2, Queue *q) {
    while (!isStackEmpty(s1) && !isStackEmpty(s2)) {
        if (peek(s1) > peek(s2)) {
            enqueue(q, pop(s2));
        } else {
            enqueue(q, pop(s1));
        }
    }

    while (!isStackEmpty(s1)) {
        enqueue(q, pop(s1));   
    }
    while (!isStackEmpty(s2)) {
        enqueue(q, pop(s2));
    }
}

void output_data(Queue *q) {
    while (!isQueueEmpty(q)) {
        printf("%d ",dequeue(q));
    }   
    return ;
}

int main() {
    Stack s1, s2;
    Queue q;
    initStack(&s1);
    initStack(&s2);
    initQueue(&q); 

    input_data(&s1, &s2);
    sort_data(&s1, &s2, &q);
    output_data(&q);
    
    return 0;
}
